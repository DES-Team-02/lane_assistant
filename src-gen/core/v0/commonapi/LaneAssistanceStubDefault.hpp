/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.14.v202310241605.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V0_COMMONAPI_Lane_Assistance_STUB_DEFAULT_HPP_
#define V0_COMMONAPI_Lane_Assistance_STUB_DEFAULT_HPP_


#include <CommonAPI/Export.hpp>

#include <v0/commonapi/LaneAssistanceStub.hpp>
#include <cassert>
#include <sstream>

# if defined(_MSC_VER)
#  if _MSC_VER >= 1300
/*
 * Diamond inheritance is used for the CommonAPI::Proxy base class.
 * The Microsoft compiler put warning (C4250) using a desired c++ feature: "Delegating to a sister class"
 * A powerful technique that arises from using virtual inheritance is to delegate a method from a class in another class
 * by using a common abstract base class. This is also called cross delegation.
 */
#    pragma warning( disable : 4250 )
#  endif
# endif

namespace v0 {
namespace commonapi {

/**
 * Provides a default implementation for LaneAssistanceStubRemoteEvent and
 * LaneAssistanceStub. Method callbacks have an empty implementation,
 * remote set calls on attributes will always change the value of the attribute
 * to the one received.
 *
 * Override this stub if you only want to provide a subset of the functionality
 * that would be defined for this service, and/or if you do not need any non-default
 * behaviour.
 */
class COMMONAPI_EXPORT_CLASS_EXPLICIT LaneAssistanceStubDefault
    : public virtual LaneAssistanceStub {
public:
    COMMONAPI_EXPORT LaneAssistanceStubDefault()
        : remoteEventHandler_(this),
          interfaceVersion_(LaneAssistance::getInterfaceVersion()) {
    }

    COMMONAPI_EXPORT const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> _client) {
        (void)_client;
        return interfaceVersion_;
    }

    COMMONAPI_EXPORT LaneAssistanceStubRemoteEvent* initStubAdapter(const std::shared_ptr< LaneAssistanceStubAdapter> &_adapter) {
        CommonAPI::Stub<LaneAssistanceStubAdapter, LaneAssistanceStubRemoteEvent>::stubAdapter_ = _adapter;
        return &remoteEventHandler_;
    }

    COMMONAPI_EXPORT virtual const std::string &getSteeringAttribute() {
        return steeringAttributeValue_;
    }
    COMMONAPI_EXPORT virtual const std::string &getSteeringAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) {
        (void)_client;
        return getSteeringAttribute();
    }
    COMMONAPI_EXPORT virtual void setSteeringAttribute(std::string _value) {
        const bool valueChanged = trySetSteeringAttribute(std::move(_value));
        if (valueChanged) {
            fireSteeringAttributeChanged(steeringAttributeValue_);
        }
    }
    COMMONAPI_EXPORT virtual const std::string &getThrottleAttribute() {
        return throttleAttributeValue_;
    }
    COMMONAPI_EXPORT virtual const std::string &getThrottleAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) {
        (void)_client;
        return getThrottleAttribute();
    }
    COMMONAPI_EXPORT virtual void setThrottleAttribute(std::string _value) {
        const bool valueChanged = trySetThrottleAttribute(std::move(_value));
        if (valueChanged) {
            fireThrottleAttributeChanged(throttleAttributeValue_);
        }
    }


protected:
    COMMONAPI_EXPORT virtual bool trySetSteeringAttribute(std::string _value) {
        if (!validateSteeringAttributeRequestedValue(_value))
            return false;

        bool valueChanged;
        std::shared_ptr<LaneAssistanceStubAdapter> stubAdapter = CommonAPI::Stub<LaneAssistanceStubAdapter, LaneAssistanceStubRemoteEvent>::stubAdapter_.lock();
        if(stubAdapter) {
            stubAdapter->lockSteeringAttribute(true);
            valueChanged = (steeringAttributeValue_ != _value);
            steeringAttributeValue_ = std::move(_value);
            stubAdapter->lockSteeringAttribute(false);
        } else {
            valueChanged = (steeringAttributeValue_ != _value);
            steeringAttributeValue_ = std::move(_value);
        }

       return valueChanged;
    }
    COMMONAPI_EXPORT virtual bool validateSteeringAttributeRequestedValue(const std::string &_value) {
        (void)_value;
        return true;
    }
    COMMONAPI_EXPORT virtual bool trySetThrottleAttribute(std::string _value) {
        if (!validateThrottleAttributeRequestedValue(_value))
            return false;

        bool valueChanged;
        std::shared_ptr<LaneAssistanceStubAdapter> stubAdapter = CommonAPI::Stub<LaneAssistanceStubAdapter, LaneAssistanceStubRemoteEvent>::stubAdapter_.lock();
        if(stubAdapter) {
            stubAdapter->lockThrottleAttribute(true);
            valueChanged = (throttleAttributeValue_ != _value);
            throttleAttributeValue_ = std::move(_value);
            stubAdapter->lockThrottleAttribute(false);
        } else {
            valueChanged = (throttleAttributeValue_ != _value);
            throttleAttributeValue_ = std::move(_value);
        }

       return valueChanged;
    }
    COMMONAPI_EXPORT virtual bool validateThrottleAttributeRequestedValue(const std::string &_value) {
        (void)_value;
        return true;
    }
    class COMMONAPI_EXPORT_CLASS_EXPLICIT RemoteEventHandler: public virtual LaneAssistanceStubRemoteEvent {
    public:
        COMMONAPI_EXPORT RemoteEventHandler(LaneAssistanceStubDefault *_defaultStub)
            : 
              defaultStub_(_defaultStub) {
        }


    private:
        LaneAssistanceStubDefault *defaultStub_;
    };
protected:
    LaneAssistanceStubDefault::RemoteEventHandler remoteEventHandler_;

private:

    std::string steeringAttributeValue_ {};
    std::string throttleAttributeValue_ {};

    CommonAPI::Version interfaceVersion_;
};

} // namespace commonapi
} // namespace v0


// Compatibility
namespace v0_1 = v0;

#endif // V0_COMMONAPI_Lane_Assistance_STUB_DEFAULT