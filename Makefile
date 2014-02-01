# Makefile - used to build the client/server educational project
# Copyright (C) 2014 John F. Sullivan, III
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

CPP=g++
all: server

SERVEROBJS := server/server.o
OBJS := $(SERVEROBJS)

bin/:
	mkdir -p bin/

server/server.o: server/server.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

server: bin/ $(SERVEROBJS)
	$(CPP) $(CPPFLAGS) $(SERVEROBJS) -o bin/server

clean:
	rm -rf *.o lib/*.o $(OBJS) doc/ bin/
