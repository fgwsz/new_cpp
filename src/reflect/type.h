#pragma once
#include"meta.h"
#include<string>
using StringType = ::std::string;
template<typename _Type>
struct TypeInfo{
	static auto string() const { 
		return StringType{ typeid(_Type).name() }; 
	}
};
template<typename _Type>
struct TypeInfo<_Type const> {
	static auto string() const {
		return StringType{"{"} + TypeInfo<_Type>::string() + StringType{" const}"};
	}
};
template<typename _Type>
struct TypeInfo<_Type volatile> {
	static auto string() const {
		return StringType{"{"} + TypeInfo<_Type>::string() + StringType{" volatile}"};
	}
};
template<typename _Type>
struct TypeInfo<_Type const volatile> {
	static auto string() const {
		return StringType{"{"} + TypeInfo<_Type>::string() + StringType{" const volatile}"};
	}
};
template<typename _Type>
struct TypeInfo<_Type *> {
	static auto string() const {
		return StringType{"{"} + TypeInfo<_Type>::string() + StringType{" *"};
	}
};
template<typename _Type>
struct TypeInfo<_Type &> {
	static auto string() const {
		return StringType{"{"} + TypeInfo<_Type>::string() + StringType{" &"};
	}
};
template<typename _Type>
struct TypeInfo<_Type &&> {
	static auto string() const {
		return StringType{"{"} + TypeInfo<_Type>::string() + StringType{" &&"};
	}
};
template<typename _Type>
struct TypeInfo<_Type[]> {
	static auto string() const {
		return StringType{"{"} + TypeInfo<_Type>::string() + StringType{" []"};
	}
};
template<typename _Type>
struct TypeInfo<_Type const[]> {
	static auto string() const {
		return StringType{"{"} + TypeInfo<_Type>::string() + StringType{" const []"};
	}
};
template<typename _Type>
struct TypeInfo<_Type volatile[]> {
	static auto string() const {
		return StringType{"{"} + TypeInfo<_Type>::string() + StringType{" volatile []"};
	}
};
template<typename _Type>
struct TypeInfo<_Type const volatile[]> {
	static auto string() const {
		return StringType{"{"} + TypeInfo<_Type>::string() + StringType{" const volatile []"};
	}
};
template<typename _Type,SizeType _N>
struct TypeInfo<_Type[_N]> {
	static auto string() const {
		return StringType{ "{" } + TypeInfo<_Type>::string() + 
			StringType{ " [" } + ::std::to_string(_N) + StringType{"]"};
	}
};
template<typename _Type,SizeType _N>
struct TypeInfo<_Type const[_N]> {
	static auto string() const {
		return StringType{ "{" } + TypeInfo<_Type>::string() + 
			StringType{ " const [" } + ::std::to_string(_N) + StringType{"]"};
	}
};
template<typename _Type,SizeType _N>
struct TypeInfo<_Type volatile[_N]> {
	static auto string() const {
		return StringType{ "{" } + TypeInfo<_Type>::string() + 
			StringType{ " volatile [" } + ::std::to_string(_N) + StringType{"]"};
	}
};
template<typename _Type,SizeType _N>
struct TypeInfo<_Type const volatile[_N]> {
	static auto string() const {
		return StringType{ "{" } + TypeInfo<_Type>::string() + 
			StringType{ " const volatile [" } + ::std::to_string(_N) + StringType{"]"};
	}
};
template<typename _ClassType,typename _Type>
struct TypeInfo<_Type _ClassType::*> {
	static auto string() const {
		return StringType{ "{" } + TypeInfo<_Type>::string() + 
			StringType{ "} " } + TypeInfo<_Type>::string() + StringType{" ::*"};
	}
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)const> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)volatile> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)const volatile> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)&> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)const&> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)volatile&> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)const volatile&> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)&&> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)const&&> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)volatile&&> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)const volatile&&> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)const> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)volatile> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)const volatile> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)&> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)const&> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)volatile&> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)const volatile&> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)&&> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)const&&> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)volatile&&> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)const volatile&&> {
};

template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)const noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)volatile noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)const volatile noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)& noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)const& noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)volatile& noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)const volatile& noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)&& noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)const&& noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)volatile&& noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...)const volatile&& noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...) noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)const noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)volatile noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)const volatile noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)& noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)const& noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)volatile& noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)const volatile& noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)&& noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)const&& noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)volatile&& noexcept> {
};
template<typename _RetType,typename..._Types>
struct TypeInfo<_RetType(_Types...,...)const volatile&& noexcept> {
};
