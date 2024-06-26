#include "Kodgen/InfoStructures/StructClassInfo.h"

#include <cassert>

#include "Kodgen/InfoStructures/NestedStructClassInfo.h"

using namespace kodgen;

StructClassInfo::ParentInfo::ParentInfo(EAccessSpecifier access, TypeInfo&& parentType) noexcept:
	inheritanceAccess{access},
	type{std::forward<TypeInfo>(parentType)}
{
}

StructClassInfo::StructClassInfo() noexcept:
	EntityInfo(),
	qualifiers{false},
	isForwardDeclaration{false},
	isImportExport{false}
{
}

StructClassInfo::StructClassInfo(CXCursor const& cursor, std::vector<Property>&& properties, bool isForwardDeclaration, bool isImportExport) noexcept:
	EntityInfo(cursor, std::forward<std::vector<Property>>(properties), (getCursorKind(cursor) == CXCursorKind::CXCursor_StructDecl) ? EEntityType::Struct : EEntityType::Class),
	qualifiers{false},
	isForwardDeclaration{isForwardDeclaration},
	isImportExport{isImportExport},
	type(cursor)
{
}

CXCursorKind StructClassInfo::getCursorKind(CXCursor cursor) noexcept
{
	switch (cursor.kind)
	{
		case CXCursorKind::CXCursor_ClassDecl:
			return CXCursorKind::CXCursor_ClassDecl;

		case CXCursorKind::CXCursor_StructDecl:
			return CXCursorKind::CXCursor_StructDecl;

		case CXCursorKind::CXCursor_ClassTemplate:
			return clang_getTemplateCursorKind(cursor);

		default:
			assert(false);
			return CXCursorKind::CXCursor_UnexposedExpr; //Always assert first, or return an absurd value
	}
}

void StructClassInfo::refreshOuterEntity() noexcept
{
	for (std::shared_ptr<NestedStructClassInfo>& nestedClass : nestedClasses)
	{
		nestedClass->refreshOuterEntity();
		nestedClass->outerEntity = this;
	}

	for (std::shared_ptr<NestedStructClassInfo>& nestedStruct : nestedStructs)
	{
		nestedStruct->refreshOuterEntity();
		nestedStruct->outerEntity = this;
	}

	for (NestedEnumInfo& nestedEnum : nestedEnums)
	{
		nestedEnum.refreshOuterEntity();
		nestedEnum.outerEntity = this;
	}

	for (FieldInfo& field : fields)
	{
		field.outerEntity = this;
	}

	for (MethodInfo& method : methods)
	{
		method.outerEntity = this;
	}
}