//
// Created by apean on 11-12-2015.
//

#ifndef HLS_UNITTEST_HLS_UNITTEST_H
#define HLS_UNITTEST_HLS_UNITTEST_H

#include "Runner.h"
#include "unitTest.h"

#define TestSuite struct

#define str(s) #s

#define HLS_TEST_CLASS_NAME(tc_name, test_name)\
  tc_name##_##test_name##_Test

#define HLS_TEST_CLASS_OBJ_NAME(tc_name, test_name)\
  obj_test_case_name##_##test_name##_Test

#define HLS_TEST_TC_NAME_STR(tc_name, test_name) str(tc_name) "::" str(test_name)

#define HLS_TEST(tc_name, test_name) \
class HLS_TEST_CLASS_NAME(tc_name,test_name) : hls_unitTest::UnitTest \
{\
public:\
    void TestBody();\
    HLS_TEST_CLASS_NAME(tc_name,test_name) () : hls_unitTest::UnitTest(HLS_TEST_TC_NAME_STR(tc_name,test_name))\
    {\
        \
    }\
};\
HLS_TEST_CLASS_NAME(tc_name,test_name) HLS_TEST_CLASS_OBJ_NAME(tc_name,test_name);\
void HLS_TEST_CLASS_NAME(tc_name,test_name)::TestBody()

#define HLS_ASSERT_TRUE(x) this->assert_eq((x),__PRETTY_FUNCTION__,#x " is not true",__FILE__,__LINE__)
#define HLS_ASSERT_FALSE(x) this->assert_eq(!(x),__PRETTY_FUNCTION__,#x " is not false",__FILE__,__LINE__)
#define HLS_ASSERT_EQ(expected, actual) this->assert_eq(((expected) == (actual)),__PRETTY_FUNCTION__,#actual " is not " #expected,__FILE__,__LINE__)
#endif //HLS_UNITTEST_HLS_UNITTEST_H
