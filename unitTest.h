//
// Created by apean on 13-12-2015.
//

#ifndef HLS_UNITTEST_UNITTEST_H
#define HLS_UNITTEST_UNITTEST_H

#include "Runner.h"

namespace hls_unitTest
{

	class UnitTest
	{

	public:
		//virtual void operator()();
		virtual void TestBody();

	protected:
		UnitTest(std::string str);

		void assert_eq(bool assert_equation, std::string TCName, std::string expression, std::string file, int line);

	};


}

#endif //HLS_UNITTEST_UNITTEST_H
