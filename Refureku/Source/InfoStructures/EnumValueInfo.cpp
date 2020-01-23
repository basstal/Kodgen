#include "InfoStructures/EnumValueInfo.h"

using namespace refureku;

EnumValueInfo::EnumValueInfo(std::string&& entityName, PropertyGroup&& propertyGroup) noexcept:
	EntityInfo(std::forward<std::string>(entityName), std::forward<PropertyGroup>(propertyGroup), EType::EnumValue)
{
}