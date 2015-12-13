//
// Created by apean on 11-12-2015.
//

#ifndef HLS_UNITTEST_HLS_UNITTEST_H
#define HLS_UNITTEST_HLS_UNITTEST_H

#include <iostream>

namespace hls_unitTest
{


  template <typename T>
  class unitTest
  {
   protected:
    unitTest()
    {

      std::cout << "unitTest constructor" << std::endl;

    }
  };

  struct TestSuite_t
  {
    int k;
  };

}



#define TestSuite typedef hls_unitTest::TestSuite_t

#define HLS_TEST(tc_name, test_name) struct TC_##tc_name : hls_unitTest::unitTest<tc_name> { void operator()();}; void TC_##tc_name::operator()()


#endif //HLS_UNITTEST_HLS_UNITTEST_H
