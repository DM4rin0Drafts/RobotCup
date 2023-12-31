/*
 * Copyright (c) 1999 - 2001, Artur Merke <amerke@ira.uka.de> 
 *
 * This code is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * It is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef _UDPSOCKET_H_
#define _UDPSOCKET_H_

#include <arpa/inet.h>

#include <string>

class UDPsocket
{
private:
    int                socket_fd;
    struct sockaddr_in serv_addr;

public:
    static const int MAXMESG = 4096;

    UDPsocket();

    int get_socket_fd();

    bool init_socket_fd( int port = 0 );
    bool init_serv_addr( const char *host, int port );

    bool send_msg( const char *buf, int len );
    bool send_msg( std::string message );
    bool recv_msg( char *buf, int &len, bool redirect = false );
    bool recv_msg( char *buf, int &len, int max_len, bool redirect = false );

    static void set_fd_nonblock( int fd );
    static void set_fd_sigio( int fd );

    void set_fd_nonblock();
    void set_fd_sigio();
    void close_socket_fd();
};

#endif
