//
// Created by apean on 11-12-2015.
//

#include "hls_unitTest.h"
#include <gtest/gtest.h>

TestSuite AdderTC;

TEST(mytest, test2)
{
	EXPECT_EQ(0, 0);
}

HLS_TEST(AdderTC, test1)
{
	int k = 0;

	std::cout << "det virker!!!" << std::endl;
}

TEST(mytest, test3)
{

}