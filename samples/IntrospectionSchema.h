// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include <memory>
#include <string>
#include <vector>

#include "GraphQLService.h"

namespace facebook {
namespace graphql {
namespace introspection {

class Schema;

enum class __TypeKind
{
	SCALAR,
	OBJECT,
	INTERFACE,
	UNION,
	ENUM,
	INPUT_OBJECT,
	LIST,
	NON_NULL
};

enum class __DirectiveLocation
{
	QUERY,
	MUTATION,
	SUBSCRIPTION,
	FIELD,
	FRAGMENT_DEFINITION,
	FRAGMENT_SPREAD,
	INLINE_FRAGMENT,
	SCHEMA,
	SCALAR,
	OBJECT,
	FIELD_DEFINITION,
	ARGUMENT_DEFINITION,
	INTERFACE,
	UNION,
	ENUM,
	ENUM_VALUE,
	INPUT_OBJECT,
	INPUT_FIELD_DEFINITION
};

namespace object {

class __Schema;
class __Type;
class __Field;
class __InputValue;
class __EnumValue;
class __Directive;

class __Schema
	: public service::Object
{
protected:
	__Schema();

public:
	virtual std::future<std::vector<std::shared_ptr<__Type>>> getTypes(service::RequestId requestId) const = 0;
	virtual std::future<std::shared_ptr<__Type>> getQueryType(service::RequestId requestId) const = 0;
	virtual std::future<std::shared_ptr<__Type>> getMutationType(service::RequestId requestId) const = 0;
	virtual std::future<std::shared_ptr<__Type>> getSubscriptionType(service::RequestId requestId) const = 0;
	virtual std::future<std::vector<std::shared_ptr<__Directive>>> getDirectives(service::RequestId requestId) const = 0;

private:
	std::future<response::Value> resolveTypes(service::ResolverParams&& params);
	std::future<response::Value> resolveQueryType(service::ResolverParams&& params);
	std::future<response::Value> resolveMutationType(service::ResolverParams&& params);
	std::future<response::Value> resolveSubscriptionType(service::ResolverParams&& params);
	std::future<response::Value> resolveDirectives(service::ResolverParams&& params);

	std::future<response::Value> resolve__typename(service::ResolverParams&& params);
};

class __Type
	: public service::Object
{
protected:
	__Type();

public:
	virtual std::future<__TypeKind> getKind(service::RequestId requestId) const = 0;
	virtual std::future<std::unique_ptr<response::StringType>> getName(service::RequestId requestId) const = 0;
	virtual std::future<std::unique_ptr<response::StringType>> getDescription(service::RequestId requestId) const = 0;
	virtual std::future<std::unique_ptr<std::vector<std::shared_ptr<__Field>>>> getFields(service::RequestId requestId, std::unique_ptr<response::BooleanType>&& includeDeprecated) const = 0;
	virtual std::future<std::unique_ptr<std::vector<std::shared_ptr<__Type>>>> getInterfaces(service::RequestId requestId) const = 0;
	virtual std::future<std::unique_ptr<std::vector<std::shared_ptr<__Type>>>> getPossibleTypes(service::RequestId requestId) const = 0;
	virtual std::future<std::unique_ptr<std::vector<std::shared_ptr<__EnumValue>>>> getEnumValues(service::RequestId requestId, std::unique_ptr<response::BooleanType>&& includeDeprecated) const = 0;
	virtual std::future<std::unique_ptr<std::vector<std::shared_ptr<__InputValue>>>> getInputFields(service::RequestId requestId) const = 0;
	virtual std::future<std::shared_ptr<__Type>> getOfType(service::RequestId requestId) const = 0;

private:
	std::future<response::Value> resolveKind(service::ResolverParams&& params);
	std::future<response::Value> resolveName(service::ResolverParams&& params);
	std::future<response::Value> resolveDescription(service::ResolverParams&& params);
	std::future<response::Value> resolveFields(service::ResolverParams&& params);
	std::future<response::Value> resolveInterfaces(service::ResolverParams&& params);
	std::future<response::Value> resolvePossibleTypes(service::ResolverParams&& params);
	std::future<response::Value> resolveEnumValues(service::ResolverParams&& params);
	std::future<response::Value> resolveInputFields(service::ResolverParams&& params);
	std::future<response::Value> resolveOfType(service::ResolverParams&& params);

	std::future<response::Value> resolve__typename(service::ResolverParams&& params);
};

class __Field
	: public service::Object
{
protected:
	__Field();

public:
	virtual std::future<response::StringType> getName(service::RequestId requestId) const = 0;
	virtual std::future<std::unique_ptr<response::StringType>> getDescription(service::RequestId requestId) const = 0;
	virtual std::future<std::vector<std::shared_ptr<__InputValue>>> getArgs(service::RequestId requestId) const = 0;
	virtual std::future<std::shared_ptr<__Type>> getType(service::RequestId requestId) const = 0;
	virtual std::future<response::BooleanType> getIsDeprecated(service::RequestId requestId) const = 0;
	virtual std::future<std::unique_ptr<response::StringType>> getDeprecationReason(service::RequestId requestId) const = 0;

private:
	std::future<response::Value> resolveName(service::ResolverParams&& params);
	std::future<response::Value> resolveDescription(service::ResolverParams&& params);
	std::future<response::Value> resolveArgs(service::ResolverParams&& params);
	std::future<response::Value> resolveType(service::ResolverParams&& params);
	std::future<response::Value> resolveIsDeprecated(service::ResolverParams&& params);
	std::future<response::Value> resolveDeprecationReason(service::ResolverParams&& params);

	std::future<response::Value> resolve__typename(service::ResolverParams&& params);
};

class __InputValue
	: public service::Object
{
protected:
	__InputValue();

public:
	virtual std::future<response::StringType> getName(service::RequestId requestId) const = 0;
	virtual std::future<std::unique_ptr<response::StringType>> getDescription(service::RequestId requestId) const = 0;
	virtual std::future<std::shared_ptr<__Type>> getType(service::RequestId requestId) const = 0;
	virtual std::future<std::unique_ptr<response::StringType>> getDefaultValue(service::RequestId requestId) const = 0;

private:
	std::future<response::Value> resolveName(service::ResolverParams&& params);
	std::future<response::Value> resolveDescription(service::ResolverParams&& params);
	std::future<response::Value> resolveType(service::ResolverParams&& params);
	std::future<response::Value> resolveDefaultValue(service::ResolverParams&& params);

	std::future<response::Value> resolve__typename(service::ResolverParams&& params);
};

class __EnumValue
	: public service::Object
{
protected:
	__EnumValue();

public:
	virtual std::future<response::StringType> getName(service::RequestId requestId) const = 0;
	virtual std::future<std::unique_ptr<response::StringType>> getDescription(service::RequestId requestId) const = 0;
	virtual std::future<response::BooleanType> getIsDeprecated(service::RequestId requestId) const = 0;
	virtual std::future<std::unique_ptr<response::StringType>> getDeprecationReason(service::RequestId requestId) const = 0;

private:
	std::future<response::Value> resolveName(service::ResolverParams&& params);
	std::future<response::Value> resolveDescription(service::ResolverParams&& params);
	std::future<response::Value> resolveIsDeprecated(service::ResolverParams&& params);
	std::future<response::Value> resolveDeprecationReason(service::ResolverParams&& params);

	std::future<response::Value> resolve__typename(service::ResolverParams&& params);
};

class __Directive
	: public service::Object
{
protected:
	__Directive();

public:
	virtual std::future<response::StringType> getName(service::RequestId requestId) const = 0;
	virtual std::future<std::unique_ptr<response::StringType>> getDescription(service::RequestId requestId) const = 0;
	virtual std::future<std::vector<__DirectiveLocation>> getLocations(service::RequestId requestId) const = 0;
	virtual std::future<std::vector<std::shared_ptr<__InputValue>>> getArgs(service::RequestId requestId) const = 0;

private:
	std::future<response::Value> resolveName(service::ResolverParams&& params);
	std::future<response::Value> resolveDescription(service::ResolverParams&& params);
	std::future<response::Value> resolveLocations(service::ResolverParams&& params);
	std::future<response::Value> resolveArgs(service::ResolverParams&& params);

	std::future<response::Value> resolve__typename(service::ResolverParams&& params);
};

} /* namespace object */

void AddTypesToSchema(std::shared_ptr<introspection::Schema> schema);

} /* namespace introspection */
} /* namespace graphql */
} /* namespace facebook */