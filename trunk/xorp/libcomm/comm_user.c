/* -*-  Mode:C; c-basic-offset:4; tab-width:8; indent-tabs-mode:t -*- */
/* vim:set sts=4 ts=8: */
/*
 * Copyright (c) 2001
 * YOID Project.
 * University of Southern California/Information Sciences Institute.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ident "$XORP: xorp/libcomm/comm_user.c,v 1.30 2007/11/16 22:29:18 pavlin Exp $"

/*
 * COMM socket library higher `sock' level implementation.
 */

#include "comm_module.h"

#include "libxorp/xorp.h"
#include "libxorp/xlog.h"
#include "libxorp/debug.h"

#include <signal.h>

#ifdef HAVE_WINDOWS_H
#include <windows.h>
#endif
#ifdef HAVE_WINSOCK2_H
#include <winsock2.h>
#endif
#ifdef HAVE_WS2TCPIP_H
#include <ws2tcpip.h>
#endif

#include "comm_api.h"
#include "comm_private.h"


int
comm_init(void)
{
    static int init_flag = 0;

    if (init_flag)
	return (XORP_OK);

#ifdef HOST_OS_WINDOWS
    {
	int result;
	WORD version;
	WSADATA wsadata;

	version = MAKEWORD(2, 2);
	result = WSAStartup(version, &wsadata);
	if (result != 0) {
	    return (XORP_ERROR);
	}
	if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wVersion) != 2) {
	    (void)WSACleanup();
	    return (XORP_ERROR);
	}
    }
#endif /* HOST_OS_WINDOWS */

    init_flag = 1;

    return (XORP_OK);
}

void
comm_exit(void)
{
#ifdef HOST_OS_WINDOWS
    (void)WSACleanup();
#endif
}

int
comm_get_last_error(void)
{
    return _comm_serrno;
}

char const *
comm_get_error_str(int serrno)
{
#ifdef HOST_OS_WINDOWS
    static char msgbuf[1024];

    FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS |
		  FORMAT_MESSAGE_MAX_WIDTH_MASK, NULL, serrno,
		  MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		  (LPSTR)msgbuf, sizeof(msgbuf), NULL);
    return (const char *)msgbuf;
#else
    return (const char *)strerror(serrno);
#endif
}

char const *
comm_get_last_error_str(void)
{
    return comm_get_error_str(comm_get_last_error());
}

int
comm_ipv4_present(void)
{
    return XORP_OK;
}

int
comm_ipv6_present(void)
{
#ifdef HAVE_IPV6
    return XORP_OK;
#else
    return XORP_ERROR;
#endif /* HAVE_IPV6 */
}

xsock_t
comm_open_tcp(int family, int is_blocking)
{
    xsock_t sock;

    comm_init();
    sock = comm_sock_open(family, SOCK_STREAM, 0, is_blocking);
    if (sock == XORP_BAD_SOCKET)
	return (XORP_BAD_SOCKET);

    return (sock);
}

xsock_t
comm_open_udp(int family, int is_blocking)
{
    xsock_t sock;

    comm_init();
    sock = comm_sock_open(family, SOCK_DGRAM, 0, is_blocking);
    if (sock == XORP_BAD_SOCKET)
	return (XORP_BAD_SOCKET);

    return (sock);
}

int
comm_close(xsock_t sock)
{
    if (comm_sock_close(sock) != XORP_OK)
	return (XORP_ERROR);

    return (XORP_OK);
}

int
comm_listen(xsock_t sock, int backlog)
{
    if (comm_sock_listen(sock, backlog) != XORP_OK)
	return (XORP_ERROR);

    return (XORP_OK);
}

xsock_t
comm_bind_tcp4(const struct in_addr *my_addr, unsigned short my_port,
	       int is_blocking)
{
    xsock_t sock;

    comm_init();
    sock = comm_sock_open(AF_INET, SOCK_STREAM, 0, is_blocking);
    if (sock == XORP_BAD_SOCKET)
	return (XORP_BAD_SOCKET);
    if (comm_set_reuseaddr(sock, 1) != XORP_OK) {
	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }
    if (comm_sock_bind4(sock, my_addr, my_port) != XORP_OK) {
	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }

    return (sock);
}

xsock_t
comm_bind_tcp6(const struct in6_addr *my_addr, unsigned int my_ifindex,
	       unsigned short my_port, int is_blocking)
{
#ifdef HAVE_IPV6
    xsock_t sock;

    comm_init();
    sock = comm_sock_open(AF_INET6, SOCK_STREAM, 0, is_blocking);
    if (sock == XORP_BAD_SOCKET)
	return (XORP_BAD_SOCKET);
    if (comm_set_reuseaddr(sock, 1) != XORP_OK) {
	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }
    if (comm_sock_bind6(sock, my_addr, my_ifindex, my_port) != XORP_OK) {
	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }

    return (sock);

#else /* ! HAVE_IPV6 */
    comm_sock_no_ipv6("comm_bind_tcp6", my_addr, my_ifindex, my_port,
		      is_blocking);
    return (XORP_BAD_SOCKET);
#endif /* ! HAVE_IPV6 */
}

xsock_t
comm_bind_tcp(const struct sockaddr *sock, int is_blocking)
{
    switch (sock->sa_family) {
    case AF_INET:
	{
	    const struct sockaddr_in *sin =
		(const struct sockaddr_in *)((const void *)sock);
	    return comm_bind_tcp4(&sin->sin_addr, sin->sin_port, is_blocking);
	}
	break;
#ifdef HAVE_IPV6
    case AF_INET6:
	{
	    const struct sockaddr_in6 *sin =
		(const struct sockaddr_in6 *)((const void *)sock);
	    return comm_bind_tcp6(&sin->sin6_addr, sin->sin6_scope_id,
				  sin->sin6_port, is_blocking);
	}
	break;
#endif /* HAVE_IPV6 */
    default:
	XLOG_FATAL("Error comm_bind_tcp invalid family = %d", sock->sa_family);
	return (XORP_ERROR);
    }

    XLOG_UNREACHABLE();

    return XORP_ERROR;
}

xsock_t
comm_bind_udp4(const struct in_addr *my_addr, unsigned short my_port,
	       int is_blocking)
{
    xsock_t sock;

    comm_init();
    sock = comm_sock_open(AF_INET, SOCK_DGRAM, 0, is_blocking);
    if (sock == XORP_BAD_SOCKET)
	return (XORP_BAD_SOCKET);
    if (comm_sock_bind4(sock, my_addr, my_port) != XORP_OK) {
	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }

    return (sock);
}

xsock_t
comm_bind_udp6(const struct in6_addr *my_addr, unsigned int my_ifindex,
	       unsigned short my_port, int is_blocking)
{
#ifdef HAVE_IPV6
    xsock_t sock;

    comm_init();
    sock = comm_sock_open(AF_INET6, SOCK_DGRAM, 0, is_blocking);
    if (sock == XORP_BAD_SOCKET)
	return (XORP_BAD_SOCKET);
    if (comm_sock_bind6(sock, my_addr, my_ifindex, my_port) != XORP_OK) {
	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }

    return (sock);

#else /* ! HAVE_IPV6 */
    comm_sock_no_ipv6("comm_bind_udp6", my_addr, my_ifindex, my_port,
		      is_blocking);
    return (XORP_BAD_SOCKET);
#endif /* ! HAVE_IPV6 */
}

xsock_t
comm_bind_join_udp4(const struct in_addr *mcast_addr,
		    const struct in_addr *join_if_addr,
		    unsigned short my_port,
		    int reuse_flag, int is_blocking)
{
    xsock_t sock;

    comm_init();
    sock = comm_sock_open(AF_INET, SOCK_DGRAM, 0, is_blocking);
    if (sock == XORP_BAD_SOCKET)
	return (XORP_BAD_SOCKET);

    if (reuse_flag) {
	if (comm_set_reuseaddr(sock, 1) != XORP_OK) {
	    comm_sock_close(sock);
	    return (XORP_BAD_SOCKET);
	}
	if (comm_set_reuseport(sock, 1) != XORP_OK) {
	    comm_sock_close(sock);
	    return (XORP_BAD_SOCKET);
	}
    }
    /* Bind the socket */
    if (comm_sock_bind4(sock, NULL, my_port) != XORP_OK) {
	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }
    /* Join the multicast group */
    if (comm_sock_join4(sock, mcast_addr, join_if_addr) != XORP_OK) {
	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }

    return (sock);
}

xsock_t
comm_bind_join_udp6(const struct in6_addr *mcast_addr,
		    unsigned int my_ifindex,
		    unsigned short my_port,
		    int reuse_flag, int is_blocking)
{
#ifdef HAVE_IPV6
    xsock_t sock;

    comm_init();
    sock = comm_sock_open(AF_INET6, SOCK_DGRAM, 0, is_blocking);
    if (sock == XORP_BAD_SOCKET)
	return (XORP_BAD_SOCKET);

    if (reuse_flag) {
	if (comm_set_reuseaddr(sock, 1) != XORP_OK) {
	    comm_sock_close(sock);
	    return (XORP_BAD_SOCKET);
	}
	if (comm_set_reuseport(sock, 1) != XORP_OK) {
	    comm_sock_close(sock);
	    return (XORP_BAD_SOCKET);
	}
    }
    /* Bind the socket */
    if (comm_sock_bind6(sock, NULL, 0, my_port) != XORP_OK) {
	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }

    /* Join the multicast group */
    if (comm_sock_join6(sock, mcast_addr, my_ifindex) != XORP_OK) {
	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }

    return (sock);

#else /* ! HAVE_IPV6 */
    comm_sock_no_ipv6("comm_bind_join_udp6", mcast_addr, my_ifindex,
		      my_port, reuse_flag, is_blocking);
    return (XORP_BAD_SOCKET);
#endif /* ! HAVE_IPV6 */
}

xsock_t
comm_connect_tcp4(const struct in_addr *remote_addr,
		  unsigned short remote_port, int is_blocking,
		  int *in_progress)
{
    xsock_t sock;

    if (in_progress != NULL)
	*in_progress = 0;

    comm_init();
    sock = comm_sock_open(AF_INET, SOCK_STREAM, 0, is_blocking);
    if (sock == XORP_BAD_SOCKET)
	return (XORP_BAD_SOCKET);
    if (comm_sock_connect4(sock, remote_addr, remote_port, is_blocking,
			   in_progress)
	!= XORP_OK) {
	/*
	 * If this is a non-blocking socket and the connect couldn't
	 * complete, then return the socket.
	 */
	if ((! is_blocking) && (in_progress != NULL) && (*in_progress == 1))
	    return (sock);

	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }

    return (sock);
}

xsock_t
comm_connect_tcp6(const struct in6_addr *remote_addr,
		  unsigned short remote_port, int is_blocking,
		  int *in_progress)
{
#ifdef HAVE_IPV6
    xsock_t sock;

    if (in_progress != NULL)
	*in_progress = 0;

    comm_init();
    sock = comm_sock_open(AF_INET6, SOCK_STREAM, 0, is_blocking);
    if (sock == XORP_BAD_SOCKET)
	return (XORP_BAD_SOCKET);
    if (comm_sock_connect6(sock, remote_addr, remote_port, is_blocking,
			   in_progress)
	!= XORP_OK) {
	/*
	 * If this is a non-blocking socket and the connect couldn't
	 * complete, then return the socket.
	 */
	if ((! is_blocking) && (in_progress != NULL) && (*in_progress == 1))
	    return (sock);

	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }

    return (sock);

#else /* ! HAVE_IPV6 */
    if (in_progress != NULL)
	*in_progress = 0;

    comm_sock_no_ipv6("comm_connect_tcp6", remote_addr, remote_port,
		      is_blocking, in_progress);
    return (XORP_BAD_SOCKET);
#endif /* ! HAVE_IPV6 */
}

xsock_t
comm_connect_udp4(const struct in_addr *remote_addr,
		  unsigned short remote_port, int is_blocking,
		  int *in_progress)
{
    xsock_t sock;

    if (in_progress != NULL)
	*in_progress = 0;

    comm_init();
    sock = comm_sock_open(AF_INET, SOCK_DGRAM, 0, is_blocking);
    if (sock == XORP_BAD_SOCKET)
	return (XORP_BAD_SOCKET);
    if (comm_sock_connect4(sock, remote_addr, remote_port, is_blocking,
			   in_progress)
	!= XORP_OK) {
	/*
	 * If this is a non-blocking socket and the connect couldn't
	 * complete, then return the socket.
	 */
	if ((! is_blocking) && (in_progress != NULL) && (*in_progress == 1))
	    return (sock);

	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }

    return (sock);
}

xsock_t
comm_connect_udp6(const struct in6_addr *remote_addr,
		  unsigned short remote_port, int is_blocking,
		  int *in_progress)
{
#ifdef HAVE_IPV6
    xsock_t sock;

    if (in_progress != NULL)
	*in_progress = 0;

    comm_init();
    sock = comm_sock_open(AF_INET6, SOCK_DGRAM, 0, is_blocking);
    if (sock == XORP_BAD_SOCKET)
	return (XORP_BAD_SOCKET);
    if (comm_sock_connect6(sock, remote_addr, remote_port, is_blocking,
			   in_progress)
	!= XORP_OK) {
	/*
	 * If this is a non-blocking socket and the connect couldn't
	 * complete, then return the socket.
	 */
	if ((! is_blocking) && (in_progress != NULL) && (*in_progress == 1))
	    return (sock);

	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }

    return (sock);

#else /* ! HAVE_IPV6 */
    if (in_progress != NULL)
	*in_progress = 0;

    comm_sock_no_ipv6("comm_connect_udp6", remote_addr, remote_port,
		      is_blocking, in_progress);
    return (XORP_BAD_SOCKET);
#endif /* ! HAVE_IPV6 */
}

xsock_t
comm_bind_connect_tcp4(const struct in_addr *local_addr,
		       unsigned short local_port,
		       const struct in_addr *remote_addr,
		       unsigned short remote_port,
		       int is_blocking,
		       int *in_progress)
{
    xsock_t sock;

    if (in_progress != NULL)
	*in_progress = 0;

    comm_init();
    sock = comm_sock_open(AF_INET, SOCK_STREAM, 0, is_blocking);
    if (sock == XORP_BAD_SOCKET)
	return (XORP_BAD_SOCKET);
    if (comm_set_reuseaddr(sock, 1) != XORP_OK) {
	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }
    if (comm_sock_bind4(sock, local_addr, local_port) != XORP_OK) {
	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }
    if (comm_sock_connect4(sock, remote_addr, remote_port, is_blocking,
			   in_progress)
	!= XORP_OK) {
	/*
	 * If this is a non-blocking socket and the connect couldn't
	 * complete, then return the socket.
	 */
	if ((! is_blocking) && (in_progress != NULL) && (*in_progress == 1))
	    return (sock);

	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }

    return (sock);
}

xsock_t
comm_bind_connect_tcp6(const struct in6_addr *local_addr,
		       unsigned int my_ifindex,
		       unsigned short local_port,
		       const struct in6_addr *remote_addr,
		       unsigned short remote_port,
		       int is_blocking,
		       int *in_progress)
{
#ifdef HAVE_IPV6
    xsock_t sock;

    if (in_progress != NULL)
	*in_progress = 0;

    comm_init();
    sock = comm_sock_open(AF_INET6, SOCK_STREAM, 0, is_blocking);
    if (sock == XORP_BAD_SOCKET)
	return (XORP_BAD_SOCKET);
    if (comm_set_reuseaddr(sock, 1) != XORP_OK) {
	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }
    if (comm_sock_bind6(sock, local_addr, my_ifindex, local_port) != XORP_OK) {
	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }
    if (comm_sock_connect6(sock, remote_addr, remote_port, is_blocking,
			   in_progress)
	!= XORP_OK) {
	/*
	 * If this is a non-blocking socket and the connect couldn't
	 * complete, then return the socket.
	 */
	if ((! is_blocking) && (in_progress != NULL) && (*in_progress == 1))
	    return (sock);

	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }

    return (sock);

#else /* ! HAVE_IPV6 */
    if (in_progress != NULL)
	*in_progress = 0;

    comm_sock_no_ipv6("comm_bind_connect_tcp6", local_addr, my_ifindex,
		      local_port, remote_addr, remote_port, is_blocking,
		      in_progress);
    return (XORP_BAD_SOCKET);
#endif /* ! HAVE_IPV6 */
}

xsock_t
comm_bind_connect_udp4(const struct in_addr *local_addr,
		       unsigned short local_port,
		       const struct in_addr *remote_addr,
		       unsigned short remote_port,
		       int is_blocking,
		       int *in_progress)
{
    xsock_t sock;

    if (in_progress != NULL)
	*in_progress = 0;

    comm_init();
    sock = comm_sock_open(AF_INET, SOCK_DGRAM, 0, is_blocking);
    if (sock == XORP_BAD_SOCKET)
	return (XORP_BAD_SOCKET);
    if (comm_sock_bind4(sock, local_addr, local_port) != XORP_OK) {
	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }
    if (comm_sock_connect4(sock, remote_addr, remote_port, is_blocking,
			   in_progress)
	!= XORP_OK) {
	/*
	 * If this is a non-blocking socket and the connect couldn't
	 * complete, then return the socket.
	 */
	if ((! is_blocking) && (in_progress != NULL) && (*in_progress == 1))
	    return (sock);

	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }

    return (sock);
}

xsock_t
comm_bind_connect_udp6(const struct in6_addr *local_addr,
		       unsigned int my_ifindex,
		       unsigned short local_port,
		       const struct in6_addr *remote_addr,
		       unsigned short remote_port,
		       int is_blocking,
		       int *in_progress)
{
#ifdef HAVE_IPV6
    xsock_t sock;

    if (in_progress != NULL)
	*in_progress = 0;

    comm_init();
    sock = comm_sock_open(AF_INET6, SOCK_DGRAM, 0, is_blocking);
    if (sock == XORP_BAD_SOCKET)
	return (XORP_BAD_SOCKET);
    if (comm_sock_bind6(sock, local_addr, my_ifindex, local_port) != XORP_OK) {
	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }
    if (comm_sock_connect6(sock, remote_addr, remote_port, is_blocking,
			   in_progress)
	!= XORP_OK) {
	/*
	 * If this is a non-blocking socket and the connect couldn't
	 * complete, then return the socket.
	 */
	if ((! is_blocking) && (in_progress != NULL) && (*in_progress == 1))
	    return (sock);

	comm_sock_close(sock);
	return (XORP_BAD_SOCKET);
    }

    return (sock);

#else /* ! HAVE_IPV6 */
    if (in_progress != NULL)
	*in_progress = 0;

    comm_sock_no_ipv6("comm_bind_connect_udp6", local_addr, my_ifindex,
		      local_port, remote_addr, remote_port, is_blocking,
		      in_progress);
    return (XORP_BAD_SOCKET);
#endif /* ! HAVE_IPV6 */
}
