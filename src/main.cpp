#include<iostream>
#include"reflect/meta.h"
int main(void) {
	using Type2 = ClassTemplateWrapper<IsSame>::template Binder<_,_>
		::template Binder<_,bool>
		::template Binder<int>
		::template Instance<>::Type;
	return 0;
}