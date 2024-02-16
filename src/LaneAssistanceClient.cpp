#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <CommonAPI/CommonAPI.hpp>
#include "../src-gen/core/v0/commonapi/LaneAssistanceProxy.hpp"
#include <thread>

using namespace v0::commonapi;

int main()
{
    /* Create Proxy */
    std::shared_ptr < CommonAPI::Runtime > runtime = CommonAPI::Runtime::get();
    std::string domain      = "local";
    std::string instance    = "commonapi.LaneAssistance";
    std::string connection  = "service-LaneAssistance";
    auto myProxy = runtime->buildProxy<LaneAssistanceProxy>(domain, instance, connection);
    std::cout << "Waiting for service to become available." << std::endl;
    while (!myProxy->isAvailable()){
        std::this_thread::sleep_for(std::chrono::microseconds(10));
    }

    /* Subscribe to Service Notifyer */
    CommonAPI::CallStatus callStatus;
    CommonAPI::CallInfo info(1000);
    info.sender_ = 1234;
    // throttle Subscription
    myProxy->getThrottleAttribute().getChangedEvent().subscribe([&](const std::string& throttle) {
        std::cout << " ---------------------------" << std::endl;
        std::cout << "Service Notification: 'Throttle' changed to : " << throttle << std::endl;
        std::cout << " ---------------------------" << std::endl;
    });
    // steering Subscription
    myProxy->getSteeringAttribute().getChangedEvent().subscribe([&](const std::string& steering) {
        std::cout << " ---------------------------" << std::endl;
        std::cout << "Service Notification: 'Steering' changed to : " << steering << std::endl;
        std::cout << " ---------------------------" << std::endl;
    });

    while (true) {
        std::cout << " ---------------------------" << std::endl;
        std::cout << " Ideas?                   : " << returnMessage << std::endl;
        std::cout << " ---------------------------" << std::endl;
        // wait for 5 seconds
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    return 0;
}

