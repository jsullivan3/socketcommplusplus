// @file  connector-test.cpp
// @brief Tests for the Connector class
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

#include <connector.h>
#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

class ConnectorTest : public CppUnit::TestFixture
{
private:
    Connector *connector;
public:
    void setUp()
    {
	connector = new Connector();
    }

    void tearDown()
    {
	delete connector;
    }

    /// testExists() - make sure the connector object was instantiated
    void testExists()
    {
	CPPUNIT_ASSERT(connector != NULL);
    }

    /// testSocketCreated() - ensure the socket object exists
    void testSocketCreated()
    {
	CPPUNIT_ASSERT(connector->getSocket() != -1);
	CPPUNIT_ASSERT(connector->getSocket() != 0);
    }

    /// suite() - Create a suite of unit tests
    ///
    /// @return CppUnit::TestSuite pointer to suite
    static CppUnit::TestSuite *suite()
    {
	CppUnit::TestSuite *ts = new CppUnit::TestSuite("ConnectorTest");
	ts->addTest( new CppUnit::TestCaller<ConnectorTest>(
			 "testExists", &ConnectorTest::testExists) );
	ts->addTest( new CppUnit::TestCaller<ConnectorTest>(
			 "testSocketCreated", &ConnectorTest::testSocketCreated) );
	return ts;
    }
};

int main(int argc, char **argv)
{
    CppUnit::TextUi::TestRunner runner;

    runner.addTest(ConnectorTest::suite());
    runner.run();

    return(0);
		   
}

