//
// Created by apean on 13-12-2015.
//

#include "Runner.h"
#include <algorithm>
#include <iostream>
#include <chrono>


hls_unitTest::Runner* instance = nullptr;

std::string Plural(size_t n)
{
	return (n>1) ? "s" : "";
}

int hls_unitTest::Runner::start(int argc, char** argv)
{
	Runner* r = getInstance();

	size_t NumberOfTest = r->TestMap.size();

	std::cout << "[============] " << "Running " << NumberOfTest << " test" << Plural(NumberOfTest) << std::endl;

	std::for_each(r->TestMap.begin(), r->TestMap.end(), handler());

	std::cout << "[------------] " << std::endl << std::endl;

	std::cout << "[============] " << "Status" << std::endl;


	//			 "[============]
	std::cout << "[   PASSED   ] " << NumberOfTest-r->errorVect.size() << " test"
			<< Plural(NumberOfTest-r->errorVect.size()) << std::endl;

	if (r->errorVect.size())
	{
		std::cout << "[------------] " << std::endl;
		//			 "[============]
		std::cout << "[   FAILED   ] " << r->errorVect.size() << " test" << Plural(r->errorVect.size())
				<< ", listed below:" << std::endl;
		std::for_each(r->errorVect.begin(), r->errorVect.end(), [](std::string ErrorMsg)
		{
			std::cout << "[   FAILED   ] " << ErrorMsg << std::endl;
		});
	}
	std::cout << "[============] " << std::endl << std::endl;

	std::cout << "[============] " << "Finished running test" << Plural(NumberOfTest) << std::endl;

	// At the moment only return OK!
	return 0;
}

hls_unitTest::Runner* hls_unitTest::Runner::getInstance()
{
	if (instance==nullptr)
	{
		instance = new hls_unitTest::Runner();
	}

	return instance;
}

hls_unitTest::Runner::Runner()
{

}

void hls_unitTest::Runner::addTest(std::string TestName, std::function<void(void)> cb)
{
	TestMap.insert(std::pair<std::string, std::function<void(void)> >(TestName, cb));
}

template<typename Chrono>
auto subTime(Chrono&& a, Chrono&& b) -> decltype(a-b)
{
	return a-b;
}

void hls_unitTest::handler::operator()(std::pair<std::string, std::function<void(void)>> pair)
{
	std::chrono::time_point<std::chrono::system_clock> start, end;

	std::cout << "[------------] " << std::endl;
	std::cout << "[ RUN        ] " << pair.first << std::endl;

	try
	{
		start = std::chrono::system_clock::now();
		pair.second();
		end = std::chrono::system_clock::now();

		auto diff = std::chrono::duration_cast<std::chrono::microseconds>(
				end.time_since_epoch()-start.time_since_epoch()).count();

		std::cout << "[         OK ] " << pair.first << " (" << diff << " us)" << std::endl;
		//			  [      ERROR ]
	}
	catch (std::exception& exception)
	{
		end = std::chrono::system_clock::now();
		hls_unitTest::Runner* r = hls_unitTest::Runner::getInstance();
		r->addError(exception.what());
		auto diff = std::chrono::duration_cast<std::chrono::microseconds>(
				end.time_since_epoch()-start.time_since_epoch()).count();
		std::cout << "[      ERROR ] " << pair.first << " (" << diff << " us)" << std::endl;

	}


}

void hls_unitTest::Runner::addError(std::string string)
{
	errorVect.push_back(string);
}
