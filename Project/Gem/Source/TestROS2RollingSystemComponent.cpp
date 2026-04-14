
#include <AzCore/Serialization/SerializeContext.h>

#include "TestROS2RollingSystemComponent.h"

#include <TestROS2Rolling/TestROS2RollingTypeIds.h>

namespace TestROS2Rolling
{
    AZ_COMPONENT_IMPL(TestROS2RollingSystemComponent, "TestROS2RollingSystemComponent",
        TestROS2RollingSystemComponentTypeId);

    void TestROS2RollingSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<TestROS2RollingSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void TestROS2RollingSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("TestROS2RollingService"));
    }

    void TestROS2RollingSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("TestROS2RollingService"));
    }

    void TestROS2RollingSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void TestROS2RollingSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    TestROS2RollingSystemComponent::TestROS2RollingSystemComponent()
    {
        if (TestROS2RollingInterface::Get() == nullptr)
        {
            TestROS2RollingInterface::Register(this);
        }
    }

    TestROS2RollingSystemComponent::~TestROS2RollingSystemComponent()
    {
        if (TestROS2RollingInterface::Get() == this)
        {
            TestROS2RollingInterface::Unregister(this);
        }
    }

    void TestROS2RollingSystemComponent::Init()
    {
    }

    void TestROS2RollingSystemComponent::Activate()
    {
        TestROS2RollingRequestBus::Handler::BusConnect();
    }

    void TestROS2RollingSystemComponent::Deactivate()
    {
        TestROS2RollingRequestBus::Handler::BusDisconnect();
    }
}
