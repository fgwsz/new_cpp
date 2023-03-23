#pragma once
#include<string>
using StringType = ::std::string;
using SizeType = unsigned long long;
template<typename _Type>
struct TypeInfo {
private:
	static constexpr StringType typeName() {
		StringType ret{ __FUNCTION__ };
		auto begin_index = ret.find_first_of('<') + 1;
		auto end_index = ret.find_last_of('>');
		return ret.substr(begin_index, end_index - begin_index);
	}
public:
	static constexpr auto string() { 
		return TypeInfo<_Type>::typeName();
	}
};
#define _TYPE_INFO_BASE_IMPL(__EXT__) \
template<typename _Type> \
struct TypeInfo<_Type __EXT__> { \
	static auto string() { \
		return StringType{"{"} + TypeInfo<_Type>::string() + StringType{"}"} + StringType{ #__EXT__ }; \
	} \
}; \
//
#define _TYPE_INFO_ARRAY_IMPL(__EXT__) \
template<typename _Type,SizeType _N> \
struct TypeInfo<_Type __EXT__[_N]> { \
	static auto string() { \
		return StringType{ "{" } + TypeInfo<_Type>::string() + \
			StringType{ "}"} + StringType{ #__EXT__ } + \
            StringType{ "[" } + ::std::to_string(_N) + StringType{"]"}; \
	} \
}; \
//
template<typename _ClassType,typename _Type>
struct TypeInfo<_Type _ClassType::*> {
	static auto string() { 
		return StringType{ "{" } + TypeInfo<_Type>::string() + 
			StringType{ "}{" } + TypeInfo<_ClassType>::string() + StringType{"}::*"};
	}
};
#define _TYPE_INFO_FUNCTION_IMPL(__EXT__) \
template<typename _RetType,typename..._Types> \
struct TypeInfo<_RetType(_Types...)__EXT__> { \
	static auto string() { \
		if constexpr (sizeof...(_Types) != 0) { \
			StringType arg_list = (TypeInfo<_Types>::string().append(StringType{ "," }) + ...); \
            arg_list.pop_back(); \
			return StringType{ "{" } + TypeInfo<_RetType>::string() + \
				StringType{ "}(" } + arg_list + StringType{ ")" } + StringType{ #__EXT__ }; \
		} \
		else { \
			return StringType{ "{" } + TypeInfo<_RetType>::string() + \
				StringType{ "}(void)" } + StringType{ #__EXT__ }; \
		} \
	} \
}; \
template<typename _RetType,typename..._Types> \
struct TypeInfo<_RetType(_Types...,...)__EXT__> { \
	static auto string() { \
		if constexpr (sizeof...(_Types) != 0) { \
			; \
			return StringType{ "{" } + TypeInfo<_RetType>::string() + \
				StringType{ "}(" } + (TypeInfo<_Types>::string().append(StringType{ "," }) + ...) + \
                StringType{ "...)" } + StringType{ #__EXT__ }; \
		} \
		else { \
			return StringType{ "{" } + TypeInfo<_RetType>::string() + \
				StringType{ "}(...)" } + StringType{ #__EXT__ }; \
		} \
	} \
}; \
//
_TYPE_INFO_BASE_IMPL(const)
_TYPE_INFO_BASE_IMPL(volatile)
_TYPE_INFO_BASE_IMPL(const volatile)
_TYPE_INFO_BASE_IMPL(*)
_TYPE_INFO_BASE_IMPL(&)
_TYPE_INFO_BASE_IMPL(&&)
_TYPE_INFO_BASE_IMPL([])
_TYPE_INFO_BASE_IMPL(const[])
_TYPE_INFO_BASE_IMPL(volatile[])
_TYPE_INFO_BASE_IMPL(const volatile[])
#undef _TYPE_INFO_BASE_IMPL
// C Style Array[_N]
_TYPE_INFO_ARRAY_IMPL() 
_TYPE_INFO_ARRAY_IMPL(const) 
_TYPE_INFO_ARRAY_IMPL(volatile) 
_TYPE_INFO_ARRAY_IMPL(const volatile) 
#undef _TYPE_INFO_ARRAY_IMPL
//
_TYPE_INFO_FUNCTION_IMPL()
_TYPE_INFO_FUNCTION_IMPL(const)
_TYPE_INFO_FUNCTION_IMPL(volatile)
_TYPE_INFO_FUNCTION_IMPL(const volatile)
_TYPE_INFO_FUNCTION_IMPL(&)
_TYPE_INFO_FUNCTION_IMPL(const&)
_TYPE_INFO_FUNCTION_IMPL(volatile&)
_TYPE_INFO_FUNCTION_IMPL(const volatile&)
_TYPE_INFO_FUNCTION_IMPL(&&)
_TYPE_INFO_FUNCTION_IMPL(const&&)
_TYPE_INFO_FUNCTION_IMPL(volatile&&)
_TYPE_INFO_FUNCTION_IMPL(const volatile&&)
// noexcept
_TYPE_INFO_FUNCTION_IMPL(noexcept)
_TYPE_INFO_FUNCTION_IMPL(const noexcept)
_TYPE_INFO_FUNCTION_IMPL(volatile noexcept)
_TYPE_INFO_FUNCTION_IMPL(const volatile noexcept)
_TYPE_INFO_FUNCTION_IMPL(&noexcept)
_TYPE_INFO_FUNCTION_IMPL(const&noexcept)
_TYPE_INFO_FUNCTION_IMPL(volatile&noexcept)
_TYPE_INFO_FUNCTION_IMPL(const volatile&noexcept)
_TYPE_INFO_FUNCTION_IMPL(&&noexcept)
_TYPE_INFO_FUNCTION_IMPL(const&&noexcept)
_TYPE_INFO_FUNCTION_IMPL(volatile&&noexcept)
_TYPE_INFO_FUNCTION_IMPL(const volatile&&noexcept)
#undef _TYPE_INFO_FUNCTION_IMPL
