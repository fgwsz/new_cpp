#pragma once
#include"boolean.h"
#include"number.h"
#include<string>
#include<vector>
#include<unordered_map>
#include<functional>
#include<variant>
#include<type_traits>
namespace dynamic {
	class Null       final { public: }                  ;
	using String   = ::std::string                      ;
	class Value                                         ;
	using Array    = ::std::vector<Value>               ;
	using Object   = ::std::unordered_map<String, Value>;
	using Function = ::std::function<Value(Value)>      ;

	class Value {
	private:
		::std::variant<Null,Boolean, Number, String, Array, Object, Function> data_;
	public:
		Value(Null     const& value) { this->data_ = value; }
		Value(Boolean  const& value) { this->data_ = value; }
		Value(Number   const& value) { this->data_ = value; }
		Value(String   const& value) { this->data_ = value; }
		Value(Array    const& value) { this->data_ = value; }
		Value(Object   const& value) { this->data_ = value; }
		Value(Function const& value) { this->data_ = value; }

		Value():Value(Null{}){}
		Value(Value const& value):Value() {
			*this = value;
		}
		Value(Value && value):Value() {
			*this = ::std::move(value);
		}

		Value& operator=(Value const& value) {
			if (this != &value) {
				this->data_ = value.data_;
			}
			return *this;
		}
		Value& operator=(Value&& value) {
			if (this != &value) {
				this->data_ = ::std::move(value.data_);
			}
			return *this;
		}

		bool isNull    () const { return ::std::holds_alternative<Null    >(this->data_); }
		bool isBoolean () const { return ::std::holds_alternative<Boolean >(this->data_); }
		bool isNumber  () const { return ::std::holds_alternative<Number  >(this->data_); }
		bool isString  () const { return ::std::holds_alternative<String  >(this->data_); }
		bool isArray   () const { return ::std::holds_alternative<Array   >(this->data_); }
		bool isObject  () const { return ::std::holds_alternative<Object  >(this->data_); }
		bool isFunction() const { return ::std::holds_alternative<Function>(this->data_); }

		Null    & getNull    () { return ::std::get<Null    >(this->data_); }
		Boolean & getBoolean () { return ::std::get<Boolean >(this->data_); }
		Number  & getNumber  () { return ::std::get<Number  >(this->data_); }
		String  & getString  () { return ::std::get<String  >(this->data_); }
		Array   & getArray   () { return ::std::get<Array   >(this->data_); }
		Object  & getObject  () { return ::std::get<Object  >(this->data_); }
		Function& getFunction() { return ::std::get<Function>(this->data_); }

		Null     const & getConstNull    () const { return ::std::get<Null    >(this->data_); }
		Boolean  const & getConstBoolean () const { return ::std::get<Boolean >(this->data_); }
		Number   const & getConstNumber  () const { return ::std::get<Number  >(this->data_); }
		String   const & getConstString  () const { return ::std::get<String  >(this->data_); }
		Array    const & getConstArray   () const { return ::std::get<Array   >(this->data_); }
		Object   const & getConstObject  () const { return ::std::get<Object  >(this->data_); }
		Function const & getConstFunction() const { return ::std::get<Function>(this->data_); }
	};
}
