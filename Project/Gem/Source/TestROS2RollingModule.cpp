
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "TestROS2RollingSystemComponent.h"

#include <TestROS2Rolling/TestROS2RollingTypeIds.h>

namespace TestROS2Rolling
{
    class TestROS2RollingModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(TestROS2RollingModule, TestROS2RollingModuleTypeId, AZ::Module);
        AZ_CLASS_ALLOCATOR(TestROS2RollingModule, AZ::SystemAllocator);

        TestROS2RollingModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                TestROS2RollingSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<TestROS2RollingSystemComponent>(),
            };
        }
    };
}// namespace TestROS2Rolling

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), TestROS2Rolling::TestROS2RollingModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_TestROS2Rolling, TestROS2Rolling::TestROS2RollingModule)
#endif
