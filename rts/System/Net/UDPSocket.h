#ifndef _UDPSOCKET
#define _UDPSOCKET

#include <boost/noncopyable.hpp>
#include <string>

#ifdef _WIN32
#include "Platform/Win/win32.h"
#else
#include <netinet/in.h>
#endif

namespace netcode {

/**
@brief Wrapper class over BSD-style UDP-sockets (non-blocking)
@author Karl-Robert Ernst

Provides easy to use access to network sockets: just construct this with a given portnum and you will have an valid, local bound UDP-Socket where you can sendto / recvfrom. If it gets deleted, the socket is closed automagically for you (this means you are not able to copy this class).
*/
class UDPSocket : public boost::noncopyable
{
public:
	/**
	@brief perform initialisations
	@param port The local port to bind our socket (0 means OS-select)
	@throw network_error When any error occurs, this is thrown
	*/
	UDPSocket(const int port);
	
	/**
	@brief Close our socket
	*/
	~UDPSocket();
	
	/**
	@brief get data from the socket
	@param buf the space to fill the data in
	@param bufLength The size of the passed Buffer should be bufLength bytes (of course it can be larger)
	@param fromAddress The network address of the sender get stored here
	@throw network_error when a error occurs
	@return The amount of bytes read (0 means no data)
	 */
	unsigned RecvFrom(unsigned char* const buf, const unsigned bufLength, sockaddr_in* const fromAddress) const;
	
	/**
	@brief Send data to the socket
	@param buf the data
	@param dataLength The length of the data to be sent
	@param destination The address we want to send to
	@throw network_error when data could not be sent
	 */
	void SendTo(const unsigned char* const buf, const unsigned dataLength, const sockaddr_in* const destination) const;
	
	sockaddr_in ResolveHost(const char* const address, const unsigned port) const;
	
protected:
	/// return the last errormessage from the OS
	std::string GetErrorMsg() const;
	/// Check if last error is a real error (not EWOULDBLOCK etc.)
	bool IsFakeError() const;

#ifndef _WIN32
	typedef int SOCKET;
#else
	/// track number of open sockets ()
	static unsigned numSockets;
#endif

	/// our descriptor
	SOCKET mySocket;
	/// our local address
	sockaddr_in myAddr;
};


} // namespace netcode

#endif
 
