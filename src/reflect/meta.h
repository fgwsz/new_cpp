#pragma once
template<template<typename...>class _ClassTemplate>
struct ClassTemplateWrapper {
	template<typename..._Args>
	struct Derived : _ClassTemplate<_Args...> {};
	template<typename..._Args>
	using Instance = _ClassTemplate<_Args...>;
};
template<typename _Type>
struct GetType {
	using Type = _Type;
};
template<typename _Type,_Type _value>
struct StaticValue {
	using Type = _Type;
	static constexpr _Type value_ = _value;
};
template<auto _value>
using StaticAutoValue = StaticValue<decltype(_value),_value>;
using TrueType = StaticAutoValue<true>;
using FalseType = StaticAutoValue<false>;
struct UndefinedType;
using NullType = void;
using SizeType = unsigned long long;
template<SizeType _value>
using StaticSizeValue = StaticValue<SizeType, _value>;
struct EmptyType{};
template<typename..._Args>
struct IfThenElse {
	// _BoolExpr:StaticValue<bool,_bool_expr>
	template<typename _BoolExpr,typename _TrueCase,typename _FalseCase>
	struct Impl;
	template<typename _TrueCase, typename _FalseCase>
	struct Impl<TrueType,_TrueCase,_FalseCase> {
		using Type = _TrueCase;
	};
	template<typename _TrueCase, typename _FalseCase>
	struct Impl<FalseType,_TrueCase,_FalseCase> {
		using Type = _FalseCase;
	};
	using Type = typename Impl<_Args...>::Type;
};
template<typename..._Args>
struct IfThen {
	// _BoolExpr:StaticValue<bool,_bool_expr>
	template<typename _BoolExpr,typename _TrueCase>
	struct Impl;
	template<typename _TrueCase>
	struct Impl<TrueType, _TrueCase> {
		using Type = _TrueCase;
	};
	template<typename _TrueCase>
	struct Impl<FalseType, _TrueCase> {
		using Type = UndefinedType;
	};
	using Type = typename Impl<_Args...>::Type;
};
template<typename..._Args>
struct IsSame {
	template<typename _Type1, typename _Type2>
	struct Impl;
	template<typename _Type1, typename _Type2>
	struct Impl {
		using Type = FalseType;
	};
	template<typename _Type>
	struct Impl<_Type, _Type> {
		using Type = TrueType;
	};
	using Type = typename Impl<_Args...>::Type;
};
template<typename..._Args>
struct TypeList{};
template<typename..._Args>
struct TypeList_From {
	template<typename _ClassTemplateType>
	struct Impl;
	template<template<typename...>class _ClassTemplate, typename..._Types>
	struct Impl<_ClassTemplate<_Types...>>{
		using Type = TypeList<_Types...>;
	};
	using Type = typename Impl<_Args...>::Type;
};
template<typename..._Args>
struct TypeList_To {
	template<typename _TypeList,typename _ClassTemplateWrapper>
	struct Impl;
	template<typename..._Types,typename _ClassTemplateWrapper>
	struct Impl<TypeList<_Types...>,_ClassTemplateWrapper>{
		using Type = typename _ClassTemplateWrapper::template Instance<_Types...>;
	};
	using Type = typename Impl<_Args...>::Type;
};
template<typename..._Args>
struct TypeList_Length {
	template<typename _TypeList>
	struct Impl;
	template<typename..._Types>
	struct Impl<TypeList<_Types...>> {
		using Type = StaticAutoValue<sizeof...(_Types)>;
	};
	using Type = typename Impl<_Args...>::Type;
};
template<typename..._Args>
struct TypeList_Head {
	template<typename _TypeList>
	struct Impl;
	template<typename _HeadType,typename..._Types>
	struct Impl<TypeList<_HeadType,_Types...>> {
		using Type = _HeadType;
	};
	template<>
	struct Impl<TypeList<>> {
		using Type = UndefinedType;
	};
	using Type = typename Impl<_Args...>::Type;
};
template<typename..._Args>
struct TypeList_Tail {
	template<typename _TypeList>
	struct Impl;
	template<typename _HeadType,typename..._Types>
	struct Impl<TypeList<_HeadType,_Types...>> {
		using Type = TypeList<_Types...>;
	};
	template<>
	struct Impl<TypeList<>> {
		using Type = UndefinedType;
	};
	using Type = typename Impl<_Args...>::Type;
};
template<typename..._Args>
struct TypeList_Empty {
	template<typename _TypeList>
	struct Impl;
	template<typename _HeadType,typename..._Types>
	struct Impl<TypeList<_HeadType, _Types...>> {
		using Type = FalseType;
	};
	template<>
	struct Impl<TypeList<>> {
		using Type = TrueType;
	};
	using Type = typename Impl<_Args...>::Type;
};
template<typename..._Args>
struct TypeList_GetElem {
	// _Index:StaticValue<SizeType,_size_value>
	template<typename _TypeList,typename _Index>
	struct Impl;
	/*
	* if index >= length then: return Underfined Type
	* else if index != 0 then: --index and return IndexOf(index,Tail Type)
	* else return Head Type
	*/
	template<typename _TypeList,typename _Index>
	struct Impl {
		template<typename...>
		struct Case_0 {
			using Type = UndefinedType;
		};
		template<typename __TypeList,typename __Index>
		struct Case_1{
			using Type = typename Case_1<
				typename TypeList_Tail<__TypeList>::Type,
				StaticValue<SizeType, __Index::value_ == 0 ? 0 : __Index::value_ - 1>
			>::Type;
		};
		template<typename __HeadType,typename...__Types>
		struct Case_1<TypeList<__HeadType, __Types...>,StaticValue<SizeType, 0>> {
			using Type = __HeadType;
		};
		template<typename __Index>
		struct Case_1<TypeList<>,__Index> {
			using Type = UndefinedType;
		};
		using Type = typename IfThenElse<
			StaticAutoValue<_Index::value_ >= TypeList_Length<_TypeList>::Type::value_>,
			ClassTemplateWrapper<Case_0>,
			ClassTemplateWrapper<Case_1>
		>::Type::template Instance<_TypeList,_Index>::Type;
	};
	using Type = typename Impl<_Args...>::Type;
};
template<typename..._Args>
struct TypeList_Concat {
	template<typename _TypeList,typename..._TypeLists>
	struct Impl;
	template<typename..._Types1,typename..._Types2,typename..._TypeLists>
	struct Impl<TypeList<_Types1...>, TypeList<_Types2...>,_TypeLists...> {
		using Type = typename Impl<
			TypeList<_Types1..., _Types2...>,
			_TypeLists...
		>::Type;
	};
	template<typename..._Types>
	struct Impl<TypeList<_Types...>> {
		using Type = TypeList<_Types...>;
	};
	using Type = typename Impl<_Args...>::Type;
};
using PlaceHolderType = UndefinedType;
using _ = PlaceHolderType;
template<typename..._Args>
struct TypeList_SetElem {
	// _Index:StaticValue<SizeType,_size_value>
	template<typename _TypeList,typename _Index,typename _NewType>
	struct Impl;
	template<typename _TypeList,typename _Index,typename _NewType>
	struct Impl {
		template<typename...>
		struct Case_0 {
			using Type = _TypeList;
		};
		template<typename __TypeList,typename __Index,typename __NewType>
		struct Case_1 {
			using Type = typename TypeList_Concat<
				TypeList<typename TypeList_Head<__TypeList>::Type>,
				typename Case_1<
					typename TypeList_Tail<__TypeList>::Type,
					StaticValue<SizeType, __Index::value_ == 0 ? 0 : __Index::value_ - 1>,
					__NewType
				>::Type
			>::Type;
		};
		template<typename __HeadType,typename...__Types,typename __NewType>
		struct Case_1<TypeList<__HeadType, __Types...>,StaticValue<SizeType, 0>,__NewType> {
			using Type = TypeList<__NewType,__Types...>;
		};
		template<typename __Index,typename __NewType>
		struct Case_1<TypeList<>,__Index,__NewType> {
			using Type = TypeList<>;
		};
		using Type = typename IfThenElse<
			StaticAutoValue<_Index::value_ >= TypeList_Length<_TypeList>::Type::value_>,
			ClassTemplateWrapper<Case_0>,
			ClassTemplateWrapper<Case_1>
		>::Type::template Instance<_TypeList,_Index,_NewType>::Type;
	};
	using Type = typename Impl<_Args...>::Type;
};

