//
// Created by apean on 13-12-2015.
//

#include <iostream>
#include <sstream>
#include "unitTest.h"

hls_unitTest::UnitTest::UnitTest(std::string str)
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
	hls_unitTest::Runner::getInstance()->addTest(str, std::bind(&UnitTest::TestBody, this));
}

void hls_unitTest::UnitTest::TestBody()
{

}

void hls_unitTest::UnitTest::assert_eq(bool assert_equation, std::string TCName, std::string expression,
		std::string file, int line)
{
	if (!assert_equation)
	{
		std::ostringstream Convert;
		Convert << line;
		if (file.find_last_of('/')!=std::string::npos)
		{
			file = file.substr(file.find_last_of('/')+1);
		}

		if (TCName.find_last_of('_')!=std::string::npos)
		{
			TCName = TCName.substr(0, TCName.find_last_of('_')).substr(TCName.find_last_of(' ')+1);
			TCName = TCName.substr(0, TCName.find_last_of('_'))+"::"+TCName.substr(TCName.find_last_of('_')+1);
		}

		throw std::logic_error(TCName+" -> "+file+"("+Convert.str()+"): Error: "+expression);
	}
}
