#pragma once
#include<string>
template<typename _Type>
struct TypeInfo;
template<typename _Type>
struct TypeInfo {
	static constexpr auto name() { 
		::std::string ret(__FUNCTION__);
		auto begin_index = ret.find_first_of('<') + 1;
		auto end_index = ret.find_last_of('>');
		return ret.substr(begin_index, end_index - begin_index);
	}
};
#define _TYPE_INFO_BASE_IMPL(__EXT__) \
template<typename _Type> \
struct TypeInfo<_Type __EXT__> { \
	static auto name() { \
		return ::std::string("{") \
			.append(TypeInfo<_Type>::name()) \
			.append("}"#__EXT__); \
	} \
}; \
//
#define _TYPE_INFO_ARRAY_IMPL(__EXT__) \
template<typename _Type,::std::size_t _N> \
struct TypeInfo<_Type __EXT__[_N]> { \
	static auto name() { \
		return ::std::string{ "{" } \
            .append(TypeInfo<_Type>::name()) \
			.append("}"#__EXT__"[") \
            .append(::std::to_string(_N)) \
            .append("]"); \
	} \
}; \
//
template<typename _ClassType,typename _Type>
struct TypeInfo<_Type _ClassType::*> {
	static auto name() { 
		return ::std::string("{")
			.append(TypeInfo<_Type>::name())
			.append("}{")
			.append(TypeInfo<_ClassType>::name())
			.append("}::*");
	}
};
#define _TYPE_INFO_FUNCTION_IMPL(__EXT__) \
template<typename _RetType,typename..._Types> \
struct TypeInfo<_RetType(_Types...)__EXT__> { \
	static auto name() { \
		if constexpr (sizeof...(_Types) != 0) { \
			::std::string arg_list = ( \
				TypeInfo<_Types>::name() \
				.append(",") + ... \
			); \
            arg_list.pop_back(); \
			return ::std::string("{") \
				.append(TypeInfo<_RetType>::name()) \
				.append("}(") \
				.append(arg_list) \
				.append(")"#__EXT__); \
		} \
		else { \
			return ::std::string("{") \
                .append(TypeInfo<_RetType>::name()) \
				.append("}(void)"#__EXT__); \
		} \
	} \
}; \
template<typename _RetType,typename..._Types> \
struct TypeInfo<_RetType(_Types...,...)__EXT__> { \
	static auto name() { \
		if constexpr (sizeof...(_Types) != 0) { \
			::std::string arg_list = ( \
				TypeInfo<_Types>::name() \
				.append(",") + ... \
			); \
			return ::std::string("{") \
				.append(TypeInfo<_RetType>::name()) \
				.append("}(") \
                .append(arg_list) \
                .append("...)"#__EXT__); \
		} \
		else { \
			return ::std::string("{") \
                .append(TypeInfo<_RetType>::name()) \
				.append("}(...)"#__EXT__); \
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
