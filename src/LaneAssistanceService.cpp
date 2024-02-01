/*includes*/
#include <CommonAPI/CommonAPI.hpp>
#include "LaneAssistanceStubImpl.hpp"
#include "GamePad.hpp"
#include "PiRacer.hpp"
#include <iostream>
#include <chrono>
#include <csignal>
#include <cstdlib>
#include <vector>
#include <unistd.h>
#include <Python.h>
#include <thread>

/* signal handler */
void signalHandler(int signum)
{
	std::cout << "\n signal: " << signum << std::endl;
	std::cout << "Shutting down..." << std::endl;
	exit(128 + signum);
}

/* clean up */
void cleanUp()
{
    // delete singeltons
	GamePad* gamepad = GamePad::getInstance();
	PiRacer* piracer = PiRacer::getInstance();
	piracer->deleteInstance();
	gamepad->deleteInstance();
    // finalize python interpreter
	Py_Finalize();
	std::cout << "cleanUp(): Python Interpreter Finalized." << std::endl;
}

/*main*/
int main() { 
    /*runtime setups*/
    // signal handler
    signal(SIGINT, signalHandler);
	signal(SIGQUIT, signalHandler);
    // python interpreter
	setenv("PYTHONPATH", "../lane_assistance", 0);
	Py_Initialize();
	atexit(cleanUp);

    /*create singelton of lane_assistance */
	LaneAssistance* laneassistance = PiRacer::getInstance();

    /*setup CommonAPI service*/
    // get runtime
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    // define service's domain, instance, connection
    std::string domain      = "local";
    std::string instance    = "commonapi.LaneAssistance";
    std::string connection  = "service-LaneAssistance";
    // create service
    std::shared_ptr<LaneAssistanceStubImpl> myService = std::make_shared<LaneAssistanceStubImpl>();
    // register service
    bool successfullyRegistered = runtime->registerService(domain, instance, myService, connection);
    // if registration failed, try again
    while (!successfullyRegistered) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        successfullyRegistered = runtime->registerService(domain, instance, myService, connection);
    }
    std::cout << "Successfully Registered Service!" << std::endl;
	
    /*main loop */
    while (true)
	{
		// locks python interpreter
		PyGILState_STATE gilState = PyGILState_Ensure();
		// release python interpreter
		PyGILState_Release(gilState);
	}
    return 0;
}