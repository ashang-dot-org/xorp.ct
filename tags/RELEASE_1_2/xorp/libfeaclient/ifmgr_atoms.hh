// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2005 International Computer Science Institute
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

// $XORP: xorp/libfeaclient/ifmgr_atoms.hh,v 1.21 2005/10/18 01:25:45 pavlin Exp $

#ifndef __LIBFEACLIENT_IFMGR_ATOMS_HH__
#define __LIBFEACLIENT_IFMGR_ATOMS_HH__

#include "libxorp/xorp.h"

#include <map>
#include <string>

#include "libxorp/ipv4.hh"
#include "libxorp/ipv6.hh"
#include "libxorp/ipvx.hh"
#include "libxorp/ipv4net.hh"
#include "libxorp/ipv6net.hh"
#include "libxorp/ipvxnet.hh"
#include "libxorp/mac.hh"

class IfMgrIfAtom;
class IfMgrVifAtom;
class IfMgrIPv4Atom;
class IfMgrIPv6Atom;

/**
 * @short Interface configuration tree container.
 *
 * The IfMgrIfTree is the top-level container of interface
 * configuration state.  The tree contains a collection of @ref
 * IfMgrIfAtom objects, each of which represents the configuration
 * state of a physical interface.
 */
class IfMgrIfTree {
public:
    typedef map<const string, IfMgrIfAtom> IfMap;

public:

    /**
     * Interface collection accessor.
     */
    inline const IfMap& ifs() const			{ return _ifs; }

    /**
     * Interface collection accessor.
     */
    inline IfMap& ifs()					{ return _ifs; }

    /**
     * Clear all interface state.
     */
    inline void clear();

    /**
     * Find interface.
     * @param ifname name of interface to find.
     * @return pointer to interface structure on success, 0 otherwise.
     */
    const IfMgrIfAtom* find_if(const string& ifname) const;

    /**
     * Find interface.
     * @param ifname name of interface to find.
     * @return pointer to interface structure on success, 0 otherwise.
     */
    IfMgrIfAtom* find_if(const string& ifname);

    /**
     * Find virtual interface.
     * @param ifname name of interface responsible for virtual interface.
     * @param vifname name of virtual interface.
     * @return pointer to virtual interface structure on success, 0 otherwise.
     */
    const IfMgrVifAtom* find_vif(const string& ifname,
				 const string& vifname) const;

    /**
     * Find virtual interface.
     * @param ifname name of interface responsible for virtual interface.
     * @param vifname name of virtual interface.
     * @return pointer to virtual interface structure on success, 0 otherwise.
     */
    IfMgrVifAtom* find_vif(const string& ifname,
			   const string& vifname);

    /**
     * Find IPv4 address structure.
     * @param ifname name of interface responsible for address.
     * @param vifname name of virtual interface responsible for address.
     * @param addr IPv4 address.
     * @return pointer to virtual interface structure on success, 0 otherwise.
     */
    const IfMgrIPv4Atom* find_addr(const string& ifname,
				   const string& vifname,
				   const IPv4&	 addr) const;

    /**
     * Find IPv4 address structure.
     * @param ifname name of interface responsible for address.
     * @param vifname name of virtual interface responsible for address.
     * @param addr IPv4 address.
     * @return pointer to virtual interface structure on success, 0 otherwise.
     */
    IfMgrIPv4Atom* find_addr(const string&	ifname,
			     const string&	vifname,
			     const IPv4&	addr);

    /**
     * Find IPv6 address structure.
     * @param ifname name of interface responsible for address.
     * @param vifname name of virtual interface responsible for address.
     * @param addr IPv6 address.
     * @return pointer to virtual interface structure on success, 0 otherwise.
     */
    const IfMgrIPv6Atom* find_addr(const string& ifname,
				   const string& vifname,
				   const IPv6&	 addr) const;

    /**
     * Find IPv6 address structure.
     * @param ifname name of interface responsible for address.
     * @param vifname name of virtual interface responsible for address.
     * @param addr IPv6 address.
     * @return pointer to virtual interface structure on success, 0 otherwise.
     */
    IfMgrIPv6Atom* find_addr(const string&	ifname,
			     const string&	vifname,
			     const IPv6&	addr);

    /**
     * Equality operator.
     * @param o tree to compare against.
     * @return true if this instance and o are the same, false otherwise.
     */
    bool operator==(const IfMgrIfTree& o) const;

    /**
     * Test if an IPv4 address is directly connected to an interface.
     * 
     * If an interface toward an address is down, then the address is not
     * considered as directly connected.
     * 
     * @param addr the address to test.
     * @param ifname the return-by-reference name of the interface toward
     * the address if the address is directly connected otherwise an empty
     * string.
     * @param vifname the return-by-reference name of the vif toward
     * the address if the address is directly connected otherwise an empty
     * string.
     * @return true if the address is directly connected, otherwise false.
     */
    bool is_directly_connected(const IPv4& addr, string& ifname,
			       string& vifname) const;

    /**
     * Test if an IPv6 address is directly connected to an interface.
     * 
     * If an interface toward an address is down, then the address is not
     * considered as directly connected.
     * 
     * @param addr the address to test.
     * @param ifname the return-by-reference name of the interface toward
     * the address if the address is directly connected otherwise an empty
     * string.
     * @param vifname the return-by-reference name of the vif toward
     * the address if the address is directly connected otherwise an empty
     * string.
     * @return true if the address is directly connected, otherwise false.
     */
    bool is_directly_connected(const IPv6& addr, string& ifname,
			       string& vifname) const;

    /**
     * Test if an IPvX address is directly connected to an interface.
     * 
     * If an interface toward an address is down, then the address is not
     * considered as directly connected.
     * 
     * @param addr the address to test.
     * @param ifname the return-by-reference name of the interface toward
     * the address if the address is directly connected otherwise an empty
     * string.
     * @param vifname the return-by-reference name of the vif toward
     * the address if the address is directly connected otherwise an empty
     * string.
     * @return true if the address is directly connected, otherwise false.
     */
    bool is_directly_connected(const IPvX& addr, string& ifname,
			       string& vifname) const;

protected:
    IfMap _ifs;
};


/**
 * @short Interface configuration atom.
 *
 * Represents a physical interface in XORP's model of forwarding h/w.
 * The configuration state includes attributes of the interface and a
 * collection of @ref IfMgrVifAtom objects representing the virtual
 * interfaces associated with the physical interface.
 */
class IfMgrIfAtom {
public:
    typedef map<const string, IfMgrVifAtom> VifMap;

public:
    inline IfMgrIfAtom(const string& name);

    inline const string& name() const			{ return _name; }

    inline bool		enabled() const			{ return _en; }
    inline void		set_enabled(bool en)		{ _en = en; }

    inline bool		discard() const			{ return _discard; }
    inline void		set_discard(bool discard)	{ _discard = discard; }

    inline uint32_t	mtu_bytes() const		{ return _mtu; }
    inline void		set_mtu_bytes(uint32_t mtu) 	{ _mtu = mtu; }

    inline const Mac&	mac() const			{ return _mac; }
    inline void		set_mac(const Mac& mac)		{ _mac = mac; }

    inline uint32_t	pif_index() const		{ return _pif; }
    inline void		set_pif_index(uint32_t pif)	{ _pif = pif; }

    inline bool		no_carrier() const		{ return _no_carrier; }
    inline void		set_no_carrier(bool no_carrier)	{ _no_carrier = no_carrier; }

    inline const VifMap& vifs() const			{ return _vifs; }
    inline VifMap& vifs()				{ return _vifs; }
    const IfMgrVifAtom*	find_vif(const string& vifname) const;
    IfMgrVifAtom*	find_vif(const string& vifname);

    bool operator==(const IfMgrIfAtom& o) const;

private:
    IfMgrIfAtom();					// not implemented

protected:
    string	_name;

    bool	_en;		// enabled
    bool	_discard;	// is a discard interface
    uint32_t	_mtu;		// mtu in bytes
    Mac		_mac;		// MAC address
    uint32_t	_pif;		// Physical interface index
    bool	_no_carrier;	// True if no carrier

    VifMap	_vifs;		// map of vifname-vif
};


/**
 * @short Virtual Interface configuration atom.
 *
 * Represents a virtual interface in XORP's model of forwarding h/w.
 */
class IfMgrVifAtom {
public:
    typedef map<const IPv4, IfMgrIPv4Atom> V4Map;
    typedef map<const IPv6, IfMgrIPv6Atom> V6Map;

public:
    inline IfMgrVifAtom(const string& name);

    inline const string& name() const			{ return _name; }

    inline bool		enabled() const			{ return _en; }
    inline void		set_enabled(bool en)		{ _en = en; }

    inline bool		multicast_capable() const 	{ return _mcap; }
    inline void		set_multicast_capable(bool cap)	{ _mcap = cap; }

    inline bool		broadcast_capable() const 	{ return _bcap; }
    inline void		set_broadcast_capable(bool cap)	{ _bcap = cap; }

    inline bool		p2p_capable() const		{ return _p2pcap; }
    inline void		set_p2p_capable(bool cap)	{ _p2pcap = cap; }

    inline bool		loopback() const		{ return _loopback; }
    inline void		set_loopback(bool l)		{ _loopback = l; }

    inline uint32_t	pif_index() const		{ return _pif; }
    inline uint32_t	set_pif_index(uint32_t i) 	{ return _pif = i; }

    inline const V4Map&	ipv4addrs() const		{ return _v4addrs; }
    inline V4Map&	ipv4addrs() 			{ return _v4addrs; }
    const IfMgrIPv4Atom* find_addr(const IPv4& a) const;
    IfMgrIPv4Atom*	find_addr(const IPv4& a);

    inline const V6Map&	ipv6addrs() const		{ return _v6addrs; }
    inline V6Map&	ipv6addrs() 			{ return _v6addrs; }
    const IfMgrIPv6Atom* find_addr(const IPv6& a) const;
    IfMgrIPv6Atom*	find_addr(const IPv6& a);

    bool 		operator==(const IfMgrVifAtom& o) const;

private:
    IfMgrVifAtom();					// not implemented

protected:
    string	_name;

    bool	_en;		// enabled
    bool	_mcap;		// multicast capable
    bool	_bcap;		// broadcast capable
    bool	_p2pcap;	// point-to-point capable
    bool	_loopback;	// true if loopback Vif
    uint32_t	_pif;		// physical interface index

    V4Map	_v4addrs;
    V6Map	_v6addrs;
};


/**
 * @short IPv4 configuration atom.
 *
 * Represents an address associated with a virtual interface in XORP's model
 * of forwarding h/w.
 */
class IfMgrIPv4Atom {
public:
    inline IfMgrIPv4Atom(const IPv4& addr);

    inline IPv4		addr() const			{ return _addr; }

    inline uint32_t	prefix_len() const		{ return _prefix_len; }
    inline void		set_prefix_len(uint32_t p)	{ _prefix_len = p; }

    inline bool		enabled() const			{ return _en; }
    inline void		set_enabled(bool en)		{ _en = en; }

    inline bool		multicast_capable() const 	{ return _mcap; }
    inline void		set_multicast_capable(bool cap)	{ _mcap = cap; }

    inline bool		loopback() const		{ return _loop; }
    inline void		set_loopback(bool l) 		{ _loop = l; }

    inline bool		has_broadcast() const		{ return _bcast; }
    inline void		remove_broadcast()		{ _bcast = false; }
    inline void		set_broadcast_addr(const IPv4 baddr);
    inline IPv4		broadcast_addr() const;

    inline bool		has_endpoint() const		{ return _p2p; }
    inline void		remove_endpoint()		{ _p2p = false; }
    inline void		set_endpoint_addr(const IPv4 endpoint);
    inline IPv4		endpoint_addr() const;

    bool 		operator==(const IfMgrIPv4Atom& o) const;

private:
    IfMgrIPv4Atom();		// not implemented

protected:
    IPv4	  _addr;
    uint32_t	  _prefix_len;	// network prefix length
    bool	  _en;		// enabled
    bool	  _mcap;	// multicast capable
    bool	  _loop;	// Is a loopback address
    bool	  _bcast;	// _oaddr refers to a broadcast addr
    bool	  _p2p;		// _oaddr refers to a point-to-point address

    IPv4	  _oaddr;	// Other address [bcast|p2p]
};


/**
 * @short IPv6 configuration atom.
 *
 * Represents an address associated with a virtual interface in XORP's model
 * of forwarding h/w.
 */

class IfMgrIPv6Atom {
public:
    inline IfMgrIPv6Atom(const IPv6& addr);

    inline const IPv6&  addr() const			{ return _addr; }

    inline bool		enabled() const			{ return _en; }
    inline void		set_enabled(bool en)		{ _en = en; }

    inline uint32_t	prefix_len() const		{ return _prefix_len; }
    inline void		set_prefix_len(uint32_t p)	{ _prefix_len = p; }

    inline bool		multicast_capable() const 	{ return _mcap; }
    inline void		set_multicast_capable(bool cap)	{ _mcap = cap; }

    inline bool		loopback() const		{ return _loop; }
    inline void		set_loopback(bool l) 		{ _loop = l; }

    inline bool		has_endpoint() const		{ return _p2p; }
    inline void		remove_endpoint()		{ _p2p = false; }
    inline void		set_endpoint_addr(const IPv6& endpoint);
    inline const IPv6&	endpoint_addr() const;

    bool 		operator==(const IfMgrIPv6Atom& o) const;

private:
    IfMgrIPv6Atom();		// not implemented

protected:
    IPv6	_addr;
    uint32_t	_prefix_len;	// network prefix length
    bool	_en;		// enabled
    bool	_mcap;		// multicast capable
    bool	_loop;		// Is a loopback address
    bool	_p2p;		// _oaddr refers to a point-to-point address

    IPv6	_oaddr;
};


/**
 * Class specialized to provide a way to find IfMgrIPv{4,6}Atom given
 * IPv{4,6} type.  This is useful for code that is solely interested
 * in common attributes and methods of IfMgrIPv4Atom and IfMgrIPv6Atom.
 *
 * Example usage:
 * <pre>
 * template <typename A>
 * bool addr_exists_and_enabled(IfMgrVifAtom& vif, const A& a)
 * {
 *     const typename IfMgrIP<A>::Atom* a = vif.find_addr(a);
 *     return a != 0 && a->enabled();
 * }
 * </pre>
 */
template <typename A>
struct IfMgrIP
{};

template <>
struct IfMgrIP<IPv4>
{
    typedef IfMgrIPv4Atom Atom;
};

template <>
struct IfMgrIP<IPv6>
{
    typedef IfMgrIPv6Atom Atom;
};


// ----------------------------------------------------------------------------
// Inline IfMgrIfTree methods

inline void
IfMgrIfTree::clear()
{
    _ifs.clear();
}


// ----------------------------------------------------------------------------
// Inline IfMgrIfAtom methods

inline
IfMgrIfAtom::IfMgrIfAtom(const string& name)
    : _name(name), _en(false), _discard(false), _mtu(0), _pif(0),
      _no_carrier(false)
{}


// ----------------------------------------------------------------------------
// Inline IfMgrVifAtom methods

inline
IfMgrVifAtom::IfMgrVifAtom(const string& name)
    : _name(name),
      _en(false), _mcap(false), _bcap(false), _p2pcap(false), _loopback(false),
      _pif(0)
{}

// ----------------------------------------------------------------------------
// Inline IfMgrIPv4Atom methods

inline
IfMgrIPv4Atom::IfMgrIPv4Atom(const IPv4& addr)
    : _addr(addr), _prefix_len(0),
      _en(false), _mcap(false), _loop(false), _bcast(false), _p2p(false)
{
}

inline void
IfMgrIPv4Atom::set_broadcast_addr(const IPv4 oaddr)
{
    if (oaddr == IPv4::ZERO()) {
	_bcast = false;
    } else {
	_bcast = true;
	_p2p = false;
	_oaddr = oaddr;
    }
}

inline IPv4
IfMgrIPv4Atom::broadcast_addr() const
{
    return _bcast ? _oaddr : IPv4::ZERO();
}

inline void
IfMgrIPv4Atom::set_endpoint_addr(const IPv4 oaddr)
{
    if (oaddr == IPv4::ZERO()) {
	_p2p = false;
    } else {
	_p2p = true;
	_bcast = false;
	_oaddr = oaddr;
    }
}

inline IPv4
IfMgrIPv4Atom::endpoint_addr() const
{
    return _p2p ? _oaddr : IPv4::ZERO();
}


// ----------------------------------------------------------------------------
// Inline IfMgrIPv6Atom methods

inline
IfMgrIPv6Atom::IfMgrIPv6Atom(const IPv6& addr)
    : _addr(addr), _prefix_len(0),
      _en(false), _mcap(false), _loop(false), _p2p(false)
{
}

inline void
IfMgrIPv6Atom::set_endpoint_addr(const IPv6& oaddr)
{
    if (oaddr == IPv6::ZERO()) {
	_p2p = false;
    } else {
	_p2p = true;
	_oaddr = oaddr;
    }
}

inline const IPv6&
IfMgrIPv6Atom::endpoint_addr() const
{
    return _p2p ? _oaddr : IPv6::ZERO();
}

#endif // __LIBFEACLIENT_IFMGR_ATOMS_HH__
