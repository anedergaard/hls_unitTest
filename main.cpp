//
// Created by apean on 11-12-2015.
//

#include <iostream>
#include "hls_unitTest.h"

TestSuite adder;

HLS_TEST(adder, test3)
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
	HLS_ASSERT_EQ(1==2);
}

HLS_TEST(adder, test4)
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
	HLS_ASSERT_EQ(true);
}

HLS_TEST(adder, test5)
{
	HLS_ASSERT_EQ((5>4 ? false : true));
}

int main(int argc, char** argv)
{
	hls_unitTest::Runner::start(argc, argv);

	return 0;
}

