#include<iostream>
#include"reflect/meta.h"
#include"reflect/type.h"
int main(void) {
	::std::cout << TypeInfo<int(int[], char)>::string() << ::std::endl;
	return 0;
}