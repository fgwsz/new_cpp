#pragma once
namespace dynamic {
	class Boolean final {
	private:
		bool data_;
	public:
		explicit Boolean(bool value) { this->data_ = value; }
		Boolean():Boolean(false){}
		Boolean(Boolean const& value) :Boolean() { *this = value; }
		Boolean& operator=(Boolean const& value) { this->data_ = value.data_; return *this; }
		bool& getBool() { return this->data_; }
		bool const& getConstBool() const { return this->data_; }
	};
}
