#pragma once
template<template<typename...>class _ClassTemplate,typename..._Args>
struct ClassTemplateWrapper;
template<template<typename...>class _ClassTemplate>
struct ClassTemplateWrapper<_ClassTemplate> {
	template<typename..._Args>
	using Instance = _ClassTemplate<_Args...>;
	template<typename..._Args>
	using Binder = ClassTemplateWrapper<_ClassTemplate,_Args...>;
};
template<typename _Type,_Type..._value>
struct StaticValue;
template<typename _Type,_Type _value>
struct StaticValue<_Type,_value> {
	using Type = _Type;
	static constexpr _Type value_ = _value;
};
template<typename _Type,_Type _first_value,_Type _seconde_value,_Type..._values>
struct StaticValue<_Type,_first_value,_seconde_value,_values...> {
	static constexpr _Type value_[sizeof...(_values) + 2] { _first_value,_seconde_value,_values... };
	using Type = decltype(value_);
};
template<auto _first_value,auto..._values>
using StaticAutoValue = StaticValue<decltype(_first_value),_first_value,_values...>;
using TrueType = StaticAutoValue<true>;
using FalseType = StaticAutoValue<false>;
struct UndefinedType;
using SizeType = unsigned long long;
template<SizeType _value>
using StaticSizeValue = StaticValue<SizeType, _value>;
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
				StaticValue<SizeType, __Index::value_ == 0 ? 0 : (__Index::value_ - 1)>
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
struct PlaceHolder;
using _ = PlaceHolder;
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
					StaticValue<SizeType, __Index::value_ == 0 ? 0 : (__Index::value_ - 1)>,
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
template<typename..._Args>
struct TypeList_CreateN {
	// _Count:StaticValue<SizeType,_size_value>
	template<typename _Count,typename _ElemType>
	struct Impl;
	template<typename _Count,typename _ElemType>
	struct Impl {
		using Type = typename TypeList_Concat <
			TypeList<_ElemType>,
			typename Impl<StaticSizeValue<_Count::value_ == 0 ? 0 : (_Count::value_ - 1)>, _ElemType > ::Type
		>::Type;
	};
	template<typename _ElemType>
	struct Impl<StaticSizeValue<0>,_ElemType> {
		using Type = TypeList<>;
	};
	using Type = typename Impl<_Args...>::Type;
};
template<typename..._Args>
struct TypeList_Replace {
	template<typename _TypeList,typename _ElemType,typename _NewTypeList>
	struct Impl;
	template<typename _CanLoop,typename _Result,typename _ElemType,typename _TypeList,typename _NewTypeList>
	struct _Impl;
	template<typename _TypeList,typename _ElemType,typename _NewTypeList>
	struct Impl {
		using CanLoop = StaticAutoValue<
			(!TypeList_Empty<_TypeList>::Type::value_) &&
			(!TypeList_Empty<_NewTypeList>::Type::value_)
		>;
		using Type = typename _Impl<CanLoop,TypeList<>,_ElemType,_TypeList,_NewTypeList>::Type;
	};
	template<typename _Result,typename _ElemType,typename _TypeList,typename _NewTypeList>
	struct _Impl <TrueType, _Result, _ElemType, _TypeList, _NewTypeList> {
		using ElemTypeIsMatch = typename IsSame<
			typename TypeList_Head<_TypeList>::Type,
			_ElemType
		>::Type;
		using TypeListIsEmpty = typename TypeList_Empty<_TypeList>::Type;
		using NewTypeListIsEmpty = typename TypeList_Empty<_NewTypeList>::Type;
		using NextTypeList = typename IfThenElse<
			TypeListIsEmpty,
			TypeList<>,
			typename TypeList_Tail<_TypeList>::Type
		>::Type;
		using NextNewTypeList = typename IfThenElse< 
			ElemTypeIsMatch,
			typename IfThenElse<
			    NewTypeListIsEmpty,
			    TypeList<>,
			    typename TypeList_Tail<_NewTypeList>::Type
			>::Type,
			_NewTypeList
		>::Type;
		using NextCanLoop = StaticAutoValue<
			(!TypeList_Empty<NextTypeList>::Type::value_) &&
			(!TypeList_Empty<NextNewTypeList>::Type::value_)
		>;
		using CurrentElemType = typename IfThenElse<
			ElemTypeIsMatch,
			typename TypeList_Head<_NewTypeList>::Type,
			typename TypeList_Head<_TypeList>::Type
		>::Type;
		using NextResult = typename TypeList_Concat<
			_Result,
			typename IfThenElse<
			    TypeListIsEmpty,
			    TypeList<>,
			    TypeList<CurrentElemType>
			>::Type
		>::Type;
		using Type = typename _Impl<NextCanLoop, NextResult, _ElemType, NextTypeList, NextNewTypeList>::Type;
	};
	template<typename _Result,typename _ElemType,typename _TypeList,typename _NewTypeList>
	struct _Impl <FalseType, _Result, _ElemType, _TypeList, _NewTypeList> {
		using Type = typename TypeList_Concat<
			_Result,
			_TypeList
		>::Type;
	};
	using Type = typename Impl<_Args...>::Type;
};
template<template<typename...>class _ClassTemplate, typename _HeadType, typename..._Types>
struct ClassTemplateWrapper<_ClassTemplate,_HeadType,_Types...> {
	template<typename..._Args>
	using Instance = typename TypeList_To<
		typename TypeList_Replace<TypeList<_HeadType, _Types...>, PlaceHolder, TypeList<_Args...>>::Type,
		ClassTemplateWrapper<_ClassTemplate>
	>::Type;
private:
	template<typename ClassTemplateInstance>
	struct _BinderImpl;
	template<template<typename...>class __ClassTemplate,typename...__Types>
	struct _BinderImpl<__ClassTemplate<__Types...>> {
		using Type = ClassTemplateWrapper<__ClassTemplate, __Types...>;
	};
public:
	template<typename..._Args>
	using Binder = typename _BinderImpl<Instance<_Args...>>::Type;
};
template<typename..._Args>
struct TypeList_CreateIndexSeq {
	// _BeginIndex:StaticValue<SizeType,_value>
	// _EndIndex:StaticValue<SizeType,_value>
	// _BeginIndex < _EndIndex
	// return Type:TypeList<StaticValue<SizeType,_BeginIndex>,...,StaticValue<SizeType,_EndIndex>>
	template<typename _BeginIndex,typename _EndIndex>
	struct Impl;
	template<typename _InputIsValid,typename _BeginIndex,typename _EndIndex>
	struct _Impl;
	template<typename _BeginIndex,typename _EndIndex>
	struct Impl {
		using Type = typename _Impl <
			StaticAutoValue<_BeginIndex::value_ < _EndIndex::value_>,
			_BeginIndex,
			_EndIndex
		>::Type;
	};
	template<typename _BeginIndex,typename _EndIndex>
	struct _Impl<TrueType, _BeginIndex, _EndIndex> {
		using Type = typename TypeList_Concat<
			TypeList<_BeginIndex>,
			typename _Impl<TrueType, StaticAutoValue<_BeginIndex::value_ + 1>, _EndIndex>::Type
		>::Type;
	};
	template<typename _CurrentIndex>
	struct _Impl<TrueType, _CurrentIndex, _CurrentIndex> {
		using Type = TypeList<>;
	};
	template<typename _BeginIndex,typename _EndIndex>
	struct _Impl<FalseType,_BeginIndex,_EndIndex> {
		using Type = UndefinedType;
	};
	using Type = typename Impl<_Args...>::Type;
};
template<typename _StaticStringImpl,SizeType..._Indexs>
constexpr decltype(auto) __staticStringImpl(_StaticStringImpl impl,TypeList<StaticSizeValue<_Indexs>...>) {
	return StaticAutoValue<impl.value()[_Indexs]...>();
}
template<typename _StaticStringImpl>
constexpr decltype(auto) _staticStringImpl(_StaticStringImpl impl) {
	return ::__staticStringImpl(
		impl,
		typename TypeList_CreateIndexSeq< 
			StaticSizeValue<0>,
			StaticSizeValue<(
				sizeof(impl.value())    /
				sizeof(impl.value()[0]) 
		   ) - 1>
	   >::Type()
	);
}
#define STATIC_STRING(__C_STYLE_STRING_LITERAL__) \
decltype(::_staticStringImpl( \
	[]{ \
		struct _StaticStringImpl { \
			constexpr decltype(auto) value() const { return __C_STYLE_STRING_LITERAL__; } \
		}; \
		return _StaticStringImpl(); \
	}() \
)) \
//
