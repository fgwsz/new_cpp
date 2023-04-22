#include<iostream>
#include"reflect/meta.h"
#include"reflect/type.h"
#include"start/extern_c.h"
#include"start/memory.h"
#include"start/any.h"
class Class {
public:
	int func(int&&, ...)const volatile&& noexcept;
	static int func2(int&&, ...)noexcept;
	int func3();
};
int main(void) {
	::std::cout << TypeInfo<decltype(&Class::func)>::name() << ::std::endl;
	::std::cout << TypeInfo<decltype(Class::func2)>::name() << ::std::endl;
	::std::cout << TypeInfo<decltype(&Class::func2)>::name() << ::std::endl;
	::std::cout << TypeInfo<decltype(&Class::func3)>::name() << ::std::endl;
	::std::cout << TypeInfo<decltype(*&main)>::name() << ::std::endl;
	::std::cout << TypeInfo<int const volatile(&)[1][2][3]>::name() << ::std::endl;
	::std::cout << TypeInfo<int const volatile* const volatile* const volatile(&)[1][2][3]>::name() << ::std::endl;
	::std::cout << TypeInfo<decltype(&::std::string::push_back)>::name() << ::std::endl;
	::std::cout << TypeInfo<decltype([]() {return true; }()) > ::name() << ::std::endl;
	::std::cout << TypeInfo<STATIC_STRING("hello world")> ::name() << ::std::endl;
	::std::cout << TypeInfo<typename STATIC_STRING("hello world")::Type>::name() << ::std::endl;

	//::std::cout << typeid(STATIC_STRING("hello world")::value_).name() << ::std::endl;
	// char const[12]
	// decltype(STATIC_STRING("hello world")::value_) array{}; 	
	// ::std::cout << TypeInfo<const char[12]>::name() << ::std::endl;
	// {char}const[12]
	// ::std::cout << TypeInfo<decltype(array)>::name() << ::std::endl;
	// error !
	int* lv_arr = (int*)gf_memory_alloc(sizeof(int) * 10);
	for (int lv_index = 0; lv_index < 10; ++lv_index) {
		::std::cout << lv_arr[lv_index] << ' ';
	}
	::std::cout << ::std::endl;
	gf_memory_set(lv_arr, 1, sizeof(int) * 10);
	for (int lv_index = 0; lv_index < 10; ++lv_index) {
		::std::cout << lv_arr[lv_index] << ' ';
	}
	::std::cout << ::std::endl;
	for (int lv_index = 0; lv_index < 10; ++lv_index) {
		lv_arr[lv_index] = lv_index;
	}
	for (int lv_index = 0; lv_index < 10; ++lv_index) {
		::std::cout << lv_arr[lv_index] << ' ';
	}
	::std::cout << ::std::endl;
	gf_memory_copy(lv_arr, lv_arr + 1, sizeof(int) * 9);
	for (int lv_index = 0; lv_index < 10; ++lv_index) {
		::std::cout << lv_arr[lv_index] << ' ';
	}
	::std::cout << ::std::endl;
	gf_memory_free((void*)lv_arr);
	tt_any lv_any_object{};
	gf_any_construct(&lv_any_object);
	int lv_number = 100;
	gf_any_set_value(&lv_any_object, &lv_number, sizeof(lv_number));
	tt_any lv_any_object2{};
	gf_any_assign(&lv_any_object2, &lv_any_object);
	int lv_number2 = 0;
	gf_any_get_value(&lv_any_object2, &lv_number2);
	::std::cout << lv_number2 << ::std::endl;
	auto func_ptr = &main;
	gf_any_set_value(&lv_any_object, &func_ptr, sizeof(func_ptr));
	::std::cout << &main << ::std::endl;
	::std::cout << *(decltype(func_ptr)*)(lv_any_object.mv_data) << ::std::endl;
	gf_any_destory(&lv_any_object);
	gf_any_destory(&lv_any_object2);
	return 0;
}