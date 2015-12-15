//
// Created by apean on 11-12-2015.
//

#include <iostream>
#include "hls_unitTest.h"

TestSuite adder;

HLS_TEST(adder, test1)
{
	HLS_ASSERT_TRUE(true);
}

HLS_TEST(adder, test7)
{
	HLS_ASSERT_EQUAL(true, true);
}

HLS_TEST(adder,test8)
{
	HLS_ASSERT_FALSE(false);
}

HLS_TEST(adder, test10)
{
	HLS_ASSERT_GREATER(5, 4);
}

HLS_TEST(adder, test11)
{
	HLS_ASSERT_SMALLER(4, 5);
}

int main(int argc, char** argv)
{
	return hls_unitTest::Runner::start(argc, argv);
}

