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
all: server tests runtests

INC := -Iinclude/
LIBINC := include/connector.h
LIBOBJS := lib/connector.o
SERVEROBJS := server/server.o
SERVEROUTPUT := bin/server
TESTOBJS := tests/connector-test.o
TESTOUTPUT := bin/tests
OBJS := $(SERVEROBJS) $(LIBOBJS) $(TESTOBJS) $(SERVEROUTPUT) $(TESTOUTPUT)
CPPFLAGS=-Wall $(INC)

lib/connector.o: lib/connector.cpp $(LIBINC)
	$(CPP) $(CPPFLAGS) -c $< -o $@

server/server.o: server/server.cpp $(LIBINC)
	$(CPP) $(CPPFLAGS) -c $< -o $@

tests/connector-test.o: tests/connector-test.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

lib: $(LIBOBJS)

bin/:
	mkdir -p bin
server: bin/ lib $(SERVEROBJS)
	$(CPP) $(CPPFLAGS) $(SERVEROBJS) $(LIBOBJS) -o $(SERVEROUTPUT)

tests: bin/ lib $(TESTOBJS) $(LIBOBJS)
	$(CPP) $(CPPFLAGS) -lcppunit $(TESTOBJS) $(LIBOBJS) -o $(TESTOUTPUT)

runtests: $(SERVEROUTPUT) $(TESTOUTPUT)
	bin/tests

clean:
	rm -rf $(OBJS) doc/ bin/
