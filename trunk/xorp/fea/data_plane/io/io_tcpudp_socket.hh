// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2007 International Computer Science Institute
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software")
// to deal in the Software without restriction, subject to the conditions
// listed in the XORP LICENSE file. These conditions include: you must
// preserve this copyright notice, and you cannot mention the copyright
// holders in advertising related to the Software without their permission.
// The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
// notice is a summary of the XORP LICENSE file; the license in that file is
// legally binding.

// $XORP: xorp/fea/data_plane/io/io_tcpudp_socket.hh,v 1.2 2007/08/11 05:49:44 pavlin Exp $


#ifndef __FEA_DATA_PLANE_IO_IO_TCPUDP_SOCKET_HH__
#define __FEA_DATA_PLANE_IO_IO_TCPUDP_SOCKET_HH__


//
// I/O TCP/UDP socket support.
//

#include "libxorp/xorp.h"
#include "libxorp/eventloop.hh"

#include "fea/io_tcpudp.hh"


/**
 * @short A base class for I/O TCP/UDP socket communication.
 */
class IoTcpUdpSocket : public IoTcpUdp {
public:
    /**
     * Constructor for a given address family.
     * 
     * @param fea_data_plane_manager the corresponding data plane manager
     * (@see FeaDataPlaneManager).
     * @param iftree the interface tree to use.
     * @param family the address family (AF_INET or AF_INET6 for IPv4 and IPv6
     * respectively).
     */
    IoTcpUdpSocket(FeaDataPlaneManager& fea_data_plane_manager,
		   const IfTree& iftree, int family);

    /**
     * Virtual destructor.
     */
    virtual ~IoTcpUdpSocket();

    /**
     * Start operation.
     *
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int		start(string& error_msg);

    /**
     * Stop operation.
     *
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int		stop(string& error_msg);

    /**
     * Open a TCP socket.
     *
     * @param is_blocking if true then the socket will be blocking, otherwise
     * non-blocking.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int tcp_open(bool is_blocking, string& error_msg);

    /**
     * Open an UDP socket.
     *
     * @param is_blocking if true then the socket will be blocking, otherwise
     * non-blocking.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int udp_open(bool is_blocking, string& error_msg);

    /**
     * Create a bound TCP socket.
     *
     * @param local_addr the interface address to bind socket to.
     * @param local_port the port to bind socket to.
     * @param is_blocking if true then the socket will be blocking, otherwise
     * non-blocking.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int tcp_open_and_bind(const IPvX& local_addr, uint16_t local_port,
			  bool is_blocking, string& error_msg);

    /**
     * Create a bound UDP socket.
     *
     * @param local_addr the interface address to bind socket to.
     * @param local_port the port to bind socket to.
     * @param is_blocking if true then the socket will be blocking, otherwise
     * non-blocking.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int udp_open_and_bind(const IPvX& local_addr, uint16_t local_port,
			  bool is_blocking, string& error_msg);

    /**
     * Create a bound UDP multicast socket.
     *
     * @param local_addr the interface address to bind socket to.
     * @param local_port the port to bind socket to.
     * @param mcast_addr the multicast group address to join.
     * @param ttl the TTL to use for this multicast socket.
     * @param reuse allow other sockets to bind to same multicast group.
     * @param is_blocking if true then the socket will be blocking, otherwise
     * non-blocking.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int udp_open_bind_join(const IPvX& local_addr, uint16_t local_port,
			   const IPvX& mcast_addr, uint8_t ttl, bool reuse,
			   bool is_blocking, string& error_msg);

    /**
     * Create a bound and connected TCP socket.
     *
     * @param local_addr the interface address to bind socket to.
     * @param local_port the port to bind socket to.
     * @param remote_addr the address to connect to.
     * @param remote_port the remote port to connect to.
     * @param is_blocking if true then the socket will be blocking, otherwise
     * non-blocking.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int tcp_open_bind_connect(const IPvX& local_addr, uint16_t local_port,
			      const IPvX& remote_addr, uint16_t remote_port,
			      bool is_blocking, string& error_msg);

    /**
     * Create a bound and connected UDP socket.
     *
     * @param local_addr the interface address to bind socket to.
     * @param local_port the port to bind socket to.
     * @param remote_addr the address to connect to.
     * @param remote_port the remote port to connect to.
     * @param is_blocking if true then the socket will be blocking, otherwise
     * non-blocking.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int udp_open_bind_connect(const IPvX& local_addr, uint16_t local_port,
			      const IPvX& remote_addr, uint16_t remote_port,
			      bool is_blocking, string& error_msg);

    /**
     * Bind a socket.
     *
     * @param local_addr the interface address to bind socket to.
     * @param local_port the port to bind socket to.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int bind(const IPvX& local_addr, uint16_t local_port, string& error_msg);

    /**
     * Join multicast group on already bound socket.
     *
     * @param mcast_addr group to join.
     * @param join_if_addr interface address to perform join on.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int udp_join_group(const IPvX& mcast_addr, const IPvX& join_if_addr,
		       string& error_msg);

    /**
     * Leave multicast group on already bound socket.
     *
     * @param mcast_addr group to leave.
     * @param leave_if_addr interface address to perform leave on.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int udp_leave_group(const IPvX& mcast_addr, const IPvX& leave_if_addr,
			string& error_msg);

    /**
     * Close socket.
     *
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int close(string& error_msg);

    /**
     * Listen for inbound connections on socket.
     *
     * When a connection request is received the socket creator will receive
     * notification.
     *
     * @param backlog the maximum number of pending connections.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int tcp_listen(uint32_t backlog, string& error_msg);

    /**
     * Send data on socket.
     *
     * @param data block of data to be sent.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int send(const vector<uint8_t>& data, string& error_msg);

    /**
     * Send data on socket to a given destination.
     *
     * The packet is not routed as the forwarding engine sending the packet
     * may not have access to the full routing table.
     *
     * @param remote_addr destination address for data.
     * @param remote_port destination port for data.
     * @param data block of data to be sent.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int send_to(const IPvX& remote_addr, uint16_t remote_port,
		const vector<uint8_t>& data, string& error_msg);

    /**
     * Send data on socket to a given multicast group from a given interface.
     *
     * @param group_addr destination address for data.
     * @param group_port destination port for data.
     * @param ifaddr interface address.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int send_from_multicast_if(const IPvX& group_addr, uint16_t group_port,
			       const IPvX& ifaddr, const vector<uint8_t>& data,
			       string& error_msg);

    /**
     * Set a named socket option.
     *
     * @param optname name of option to be set. Valid values are:
     * "multicast_loopback" "multicast_ttl"
     * @param optval value of option to be set. If value is logically boolean
     * then zero represents false and any non-zero value true.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int set_socket_option(const string& optname, uint32_t optval,
			  string& error_msg);

    /**
     * Accept or reject a pending connection.
     *
     * @param is_accepted if true, the connection is accepted, otherwise is
     * rejected.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int accept_connection(bool is_accepted, string& error_msg);

protected:
    /**
     * Set the file descriptor of the socket.
     *
     * @param fd the file descriptor of the socket.
     */
    void set_socket_fd(XorpFd fd) { _socket_fd = fd; }

private:
    /**
     * Enable receiving of data.
     *
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int enable_data_recv(string& error_msg);

    /**
     * I/O event callback: new connection is ready to be accepted.
     *
     * @param fd the file descriptor of the socket with the new connection.
     * @param io_event_type the event type (@see IoEventType).
     */
    void accept_io_cb(XorpFd fd, IoEventType io_event_type);

    /**
     * I/O event callback: data is received.
     *
     * @param fd the file descriptor of the socket with the data.
     * @param io_event_type the event type (@see IoEventType).
     * @param is_tcp if true, this is TCP connection, otherwise UDP.
     */
    void data_io_cb(XorpFd fd, IoEventType io_event_type, bool is_tcp);

    /**
     * I/O event callback: the peer has closed the connection.
     *
     * This callback is used only for Windows, and only for TCP sockets.
     *
     * @param fd the file descriptor of the socket with the data.
     * @param io_event_type the event type (@see IoEventType).
     */
    void disconnect_io_cb(XorpFd fd, IoEventType io_event_type);

    XorpFd	_socket_fd;
    IPvX	_peer_address;		// Peer address (valid for TCP only)
    uint16_t	_peer_port;		// Peer port (valid for TCP only)
};

#endif // __FEA_DATA_PLANE_IO_IO_TCPUDP_SOCKET_HH__
