#include<iostream>
#include"reflect/meta.h"
int main(void) {
	::std::cout << typeid(TypeList<
		StaticAutoValue<true>,
		StaticAutoValue<100,200>,
		StaticAutoValue<3.14,2.2>,
		STATIC_STRING("hello world")
	>).name() << ::std::endl;
	::std::cout << typeid(STATIC_STRING("time")::value_).name() << ::std::endl;
	return 0;
}