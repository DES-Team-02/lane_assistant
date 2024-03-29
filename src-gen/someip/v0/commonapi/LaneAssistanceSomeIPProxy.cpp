/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.14.v202310241606.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#include <v0/commonapi/LaneAssistanceSomeIPProxy.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v0 {
namespace commonapi {

std::shared_ptr<CommonAPI::SomeIP::Proxy> createLaneAssistanceSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection) {
    return std::make_shared< LaneAssistanceSomeIPProxy>(_address, _connection);
}

void initializeLaneAssistanceSomeIPProxy() {
    CommonAPI::SomeIP::AddressTranslator::get()->insert(
        "local:commonapi.LaneAssistance:v0_1:commonapi.LaneAssistance",
        0x1b58, 0x1b59, 0, 1);
    CommonAPI::SomeIP::Factory::get()->registerProxyCreateMethod(
        "commonapi.LaneAssistance:v0_1",
        &createLaneAssistanceSomeIPProxy);
}

INITIALIZER(registerLaneAssistanceSomeIPProxy) {
    CommonAPI::SomeIP::Factory::get()->registerInterface(initializeLaneAssistanceSomeIPProxy);
}

LaneAssistanceSomeIPProxy::LaneAssistanceSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection)
        : CommonAPI::SomeIP::Proxy(_address, _connection),
          steering_(*this, CommonAPI::SomeIP::eventgroup_id_t(0x1bbc), CommonAPI::SomeIP::event_id_t(0x11558), CommonAPI::SomeIP::method_id_t(0x1bbd), true, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE, false, static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr)),
          throttle_(*this, CommonAPI::SomeIP::eventgroup_id_t(0x1c20), CommonAPI::SomeIP::event_id_t(0x11940), CommonAPI::SomeIP::method_id_t(0x1c21), true, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE, false, static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr))
{
}

LaneAssistanceSomeIPProxy::~LaneAssistanceSomeIPProxy() {
}

LaneAssistanceSomeIPProxy::SteeringAttribute& LaneAssistanceSomeIPProxy::getSteeringAttribute() {
    return steering_;
}
LaneAssistanceSomeIPProxy::ThrottleAttribute& LaneAssistanceSomeIPProxy::getThrottleAttribute() {
    return throttle_;
}


void LaneAssistanceSomeIPProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
    ownVersionMajor = 0;
    ownVersionMinor = 1;
}

std::future<void> LaneAssistanceSomeIPProxy::getCompletionFuture() {
    return CommonAPI::SomeIP::Proxy::getCompletionFuture();
}

} // namespace commonapi
} // namespace v0
