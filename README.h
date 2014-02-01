/**
@file README.txt

@mainpage SocketCommPlusPlus Version 1.0

@tableofcontents

@section purpose Purpose

The purpose of this project is to practice writing a client/server
application in C++, both to sharpen and to demonstrate my skills.

@section description Description

Version 1.0 consists of two applications, "client" and "server", that
communicate with each other via a UNIX domain socket.

The server application sends everything it receive via the socket to
STDOUT.

The client connects to the server and sends a Very Important
Message(tm).

@section buildrequirements Requirements to Build

The following packages are required to build this software:

@li UNIX build environment - not tested on Windows
@li doxygen - for generating documentation
@li gcc
@li GNU Make

@section howtobuild How to Build

To build this project, simply type 'make' in the top-level project
directory.  The following components will be built:

@li client - the client application
@li server - the server application

To build the applications with debug symbols, type 'make DEBUG=1' in
the top-level project directory.

@section howtorun How to Run

To execute the code, execute the "server" application BEFORE executing
the "client" application.
*/
