// @file  connector.cpp
// @brief Base class that defines a socket connection.
//
// Copyright (C) 2014 John F. Sullivan, III
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

#include <sys/un.h>     // sockaddr_un support
#include <sys/socket.h> // socket() support
#include <errno.h>      // errno support
#include <stdio.h>      // sys_errlist support
#include <unistd.h>     // close() support
#include <connector.h>
#include <iostream>

Connector::Connector()
{
    CreateSocket(SOCK_DGRAM);
}

Connector::~Connector()
{
    close(sock);
}

int Connector::getSocket()
{
    return sock;
}

/// CreateSocket() - create a UNIX domain socket.
///
/// @param type   - [in]     type of socket to create (i.e., SOCK_DGRAM)
///
/// @return @c 0 on success, @c errno value on error
void Connector::CreateSocket(int type)
{
    using namespace std;
    int status = 0;  // Be optimistic.

    // (Attempt to) create the socket.
    if ((sock = socket(AF_LOCAL, type, 0)) == -1)
    {
	// Capture the error from errno.
	status = errno;
	std::cout << "*** " << __FILE__ << ":" << __LINE__
		  << ":" << __FUNCTION__ << "() socket() error: "
		  << status << std::endl;
	std::cout << "*** Error details: " << sys_errlist[status]
		  << std::endl;
	throw status;
    }
}
