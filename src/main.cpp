#include<iostream>
#include"reflect/meta.h"
#include"reflect/type.h"
class Class {
public:
	int func(int&&, ...)const volatile&& noexcept;
	static int func2(int&&, ...)noexcept;
	int func3();
};
int main(void) {
	::std::cout << TypeInfo<decltype(& Class::func)>::name() << ::std::endl;
	::std::cout << TypeInfo<decltype(Class::func2)>::name() << ::std::endl;
	::std::cout << TypeInfo<decltype(& Class::func2)>::name() << ::std::endl;
	::std::cout << TypeInfo<decltype(& Class::func3)>::name() << ::std::endl;
	::std::cout << TypeInfo<decltype(*&main)>::name() << ::std::endl;
	::std::cout << TypeInfo<int const volatile(&)[1][2][3]>::name() << ::std::endl;
	::std::cout << TypeInfo<int const volatile *const volatile* const volatile(&)[1][2][3]>::name() << ::std::endl;
	::std::cout << TypeInfo<decltype(& ::std::string::push_back)>::name() << ::std::endl;
	::std::cout << TypeInfo<decltype([]() {return true; }())> ::name() << ::std::endl;
	::std::cout << TypeInfo<STATIC_STRING("hello world")> ::name() << ::std::endl;
	::std::cout << TypeInfo<typename STATIC_STRING("hello world")::Type>::name() << ::std::endl;

	//::std::cout << typeid(STATIC_STRING("hello world")::value_).name() << ::std::endl;
	// char const[12]
	// decltype(STATIC_STRING("hello world")::value_) array{}; 	
	// ::std::cout << TypeInfo<const char[12]>::name() << ::std::endl;
	// {char}const[12]
	// ::std::cout << TypeInfo<decltype(array)>::name() << ::std::endl;
	// error !

	return 0;
}