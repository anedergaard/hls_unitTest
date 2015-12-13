//
// Created by apean on 13-12-2015.
//

#ifndef HLS_UNITTEST_RUNNER_H
#define HLS_UNITTEST_RUNNER_H

#include <string>
#include <map>
#include <functional>
#include <vector>

namespace hls_unitTest
{

	class Runner
	{
	public:

		static void start(int argc, char** argv);

		static Runner* getInstance();

		Runner(Runner const&) = delete;

		void operator=(Runner const&) = delete;

		void addTest(std::string TestName, std::function<void(void)> cb);

		void addError(std::string);

	private:
		Runner();

		std::map<std::string, std::function<void(void)>> TestMap;
		std::vector<std::string> errorVect;
	};

	struct handler
	{
		void operator()(std::pair<std::string, std::function<void(void)> >);
	};


}
#endif //HLS_UNITTEST_RUNNER_H
