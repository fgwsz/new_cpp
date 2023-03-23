#include<iostream>
#include"reflect/type.h"
class Class {
public:
	int func(int&&, ...)const volatile&& noexcept;
	static int func2(int&&, ...)noexcept;
};
int main(void) {
	::std::cout << TypeInfo<decltype(& Class::func)>::string() << ::std::endl;
	::std::cout << TypeInfo<decltype(Class::func2)>::string() << ::std::endl;
	::std::cout << TypeInfo<decltype(& Class::func2)>::string() << ::std::endl;
	::std::cout << TypeInfo<decltype(& ::std::string::push_back)>::string() << ::std::endl;
	return 0;
}