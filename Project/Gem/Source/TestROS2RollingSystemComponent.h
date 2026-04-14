
#pragma once

#include <AzCore/Component/Component.h>

#include <TestROS2Rolling/TestROS2RollingBus.h>

namespace TestROS2Rolling
{
    class TestROS2RollingSystemComponent
        : public AZ::Component
        , protected TestROS2RollingRequestBus::Handler
    {
    public:
        AZ_COMPONENT_DECL(TestROS2RollingSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        TestROS2RollingSystemComponent();
        ~TestROS2RollingSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // TestROS2RollingRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
