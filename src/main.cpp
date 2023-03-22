#include<iostream>
#include"reflect/meta.h"
int main(void) {
	::std::cout << typeid(TypeList<
		StaticAutoValue<true>,
		StaticAutoValue<100,200>,
		StaticAutoValue<3.14,2.2>,
		STATIC_STRING_VALUE("hello world")
	>).name() << ::std::endl;
	::std::cout << STATIC_STRING_VALUE("hello world")::value_ << ::std::endl;
	return 0;
}