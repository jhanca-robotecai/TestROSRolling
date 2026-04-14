
#pragma once

#include <TestROS2Rolling/TestROS2RollingTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace TestROS2Rolling
{
    class TestROS2RollingRequests
    {
    public:
        AZ_RTTI(TestROS2RollingRequests, TestROS2RollingRequestsTypeId);
        virtual ~TestROS2RollingRequests() = default;
        // Put your public methods here
    };

    class TestROS2RollingBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using TestROS2RollingRequestBus = AZ::EBus<TestROS2RollingRequests, TestROS2RollingBusTraits>;
    using TestROS2RollingInterface = AZ::Interface<TestROS2RollingRequests>;

} // namespace TestROS2Rolling
