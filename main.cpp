#include<iostream>
#include"dynamic/to_std_string.h"
using namespace dynamic;
int main(void) {
	static Value val = Object();
	val.getObject()["Null"] = Null();
	val.getObject()["Boolean"] = Boolean(false);
	val.getObject()["Number"] = Number(3.1415926);
	val.getObject()["String"] = String("ƒ„∫√ ¿ΩÁ£°");
	val.getObject()["Array"] = Array{ Number(0),Number(1),Number(2),Number(3),Number(4),Number(5) };
	val.getObject()["Function"] = Function([](Value) { return Null{}; });
	val.getObject()["Pointer"] = Pointer(& val);
	::std::cout << toStdString(val) << ::std::endl;
	::std::cout << "&val = " << & val << ::std::endl;
	::std::cout << "sizeof(val) = " << sizeof(val) << ::std::endl;
	return 0;
}