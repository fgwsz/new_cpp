#include<iostream>
#include"reflect/meta.h"
int main(void) {
	::std::cout << StaticStringValue<STATIC_STRING_LITERAL("hello world")>::value_ << ::std::endl;
	// StaticAutoValue Match StaticStringValue £¿
	// StaticValue Match StaticStringValue £¿
	return 0;
}