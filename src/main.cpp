#include<iostream>
#include"reflect/meta.h"
#include<vector>
template<typename T>
::std::vector<T>& replaceAll(::std::vector<T>& list,T const& old_elem,::std::vector<T>const& new_elems) {
	if (list.empty() || new_elems.empty()) {
		return list;
	}
	::std::size_t count = 0;
	for (::std::size_t index = 0; count < new_elems.size() && index < list.size();++index) {
		if (list[index] == old_elem) {
			list[index] = new_elems[count++];
		}
	}
	return list;
}

template<typename _ClassTemplateWrapper,typename..._Types1>
struct Bind {
	template<typename _TypeList,typename _OldType,typename _NewTypeList>
	struct Impl;
	template<typename _TypeList,typename _OldType,typename _NewTypeList>
	struct Impl {
		template<typename...>
		struct Step_0 {
			using Type = _TypeList;
		};
		using Count = StaticSizeValue<0>;
		template<typename __TypeList,typename __OldType,typename __NewTypeList>
		using Step_1 = void;// TODO
		using Type = typename IfThenElse<
			StaticAutoValue<TypeList_Empty<_TypeList>::Type::value_ || TypeList_Empty<_NewTypeList>::Type::value_>,
			ClassTemplateWrapper<Step_0>,
			ClassTemplateWrapper<Step_1>
		>::Type::template Instance<_TypeList,_OldType,_NewTypeList>::Type;
	};

//	template<typename..._Types2>
//	using Instance = _ClassTemplateWrapper::template Instance<
//		typename TypeList_ReplaceAll<TypeList<_Types1...>,_,TypeList<_Types2...>>::Type
//	>;
};
int main(void) {
	::std::cout << ::std::boolalpha << IsSame<TrueType, StaticValue<bool, true>>::Type::value_ << ::std::endl;
	::std::cout << TypeList_Empty<TypeList<void>>::Type::value_ << ::std::endl;
	using type = typename TypeList_GetElem<TypeList<int[4],int[1],int[2],int[3]>,StaticSizeValue<4>>::Type;
	using type1 = typename TypeList_SetElem<TypeList<int[4],int[1],int[2],int[3]>,StaticSizeValue<7>,void>::Type;
	using type2 = typename TypeList_Concat<
		TypeList<>
	>::Type;
	using type3 = typename TypeList_To<TypeList<_,UndefinedType>,ClassTemplateWrapper<IsSame>>::Type::Type;
	// using type4 = typename Bind<ClassTemplateWrapper<IsSame>, _, int>::template Instance<int>;
	::std::vector<::std::string> vec{ "_","int","bool","_","char" };
	replaceAll(vec, ::std::string{ "_" }, ::std::vector<::std::string>{"void", "nullptr","void","nullptr"});
	for (auto const& elem : vec) {
		::std::cout << elem << ::std::endl;
	}
	return 0;
}