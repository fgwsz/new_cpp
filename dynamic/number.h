#pragma once
#include<numeric>
#include<optional>
namespace dynamic {
	class Number final {
	private:
		using data_t = double;
		data_t data_;
	public:
		explicit Number(short              value){ this->data_ = static_cast<decltype(this->data_)>(value); }
		explicit Number(int                value){ this->data_ = static_cast<decltype(this->data_)>(value); }
		explicit Number(long               value){ this->data_ = static_cast<decltype(this->data_)>(value); }
		explicit Number(long long          value){ this->data_ = static_cast<decltype(this->data_)>(value); }
		explicit Number(float              value){ this->data_ = static_cast<decltype(this->data_)>(value); }
		explicit Number(double             value){ this->data_ = static_cast<decltype(this->data_)>(value); }
		explicit Number(unsigned short     value){ this->data_ = static_cast<decltype(this->data_)>(value); }
		explicit Number(unsigned int       value){ this->data_ = static_cast<decltype(this->data_)>(value); }
		explicit Number(unsigned long      value){ this->data_ = static_cast<decltype(this->data_)>(value); }
		explicit Number(unsigned long long value){ this->data_ = static_cast<decltype(this->data_)>(value); }
		Number():Number(0.0){}
		Number(Number const& value) :Number() { *this = value; }
		Number& operator=(Number const& value) { this->data_ = value.data_; return *this; }
		bool isShort() const { 
			return this->data_ >= static_cast<decltype(this->data_)>(::std::numeric_limits<short>::min()) && 
				   this->data_ <= static_cast<decltype(this->data_)>(::std::numeric_limits<short>::max()); 
		}
		bool isInt() const {
			return this->data_ >= static_cast<decltype(this->data_)>(::std::numeric_limits<int>::min()) && 
				   this->data_ <= static_cast<decltype(this->data_)>(::std::numeric_limits<int>::max()); 
		}
		bool isLong() const {
			return this->data_ >= static_cast<decltype(this->data_)>(::std::numeric_limits<long>::min()) && 
				   this->data_ <= static_cast<decltype(this->data_)>(::std::numeric_limits<long>::max()); 
		}
		bool isLongLong() const {
			return this->data_ >= static_cast<decltype(this->data_)>(::std::numeric_limits<long long>::min()) && 
				   this->data_ <= static_cast<decltype(this->data_)>(::std::numeric_limits<long long>::max()); 
		}
		bool isFloat() const {
			return this->data_ >= static_cast<decltype(this->data_)>(::std::numeric_limits<float>::min()) && 
				   this->data_ <= static_cast<decltype(this->data_)>(::std::numeric_limits<float>::max()); 
		}
		bool isDouble() const {
			return this->data_ >= static_cast<decltype(this->data_)>(::std::numeric_limits<double>::min()) && 
				   this->data_ <= static_cast<decltype(this->data_)>(::std::numeric_limits<double>::max()); 
		}
		bool isUnsignedShort() const { 
			return this->data_ >= static_cast<decltype(this->data_)>(::std::numeric_limits<unsigned short>::min()) && 
				   this->data_ <= static_cast<decltype(this->data_)>(::std::numeric_limits<unsigned short>::max()); 
		}
		bool isUnsignedInt() const {
			return this->data_ >= static_cast<decltype(this->data_)>(::std::numeric_limits<unsigned int>::min()) && 
				   this->data_ <= static_cast<decltype(this->data_)>(::std::numeric_limits<unsigned int>::max()); 
		}
		bool isUnsignedLong() const {
			return this->data_ >= static_cast<decltype(this->data_)>(::std::numeric_limits<unsigned long>::min()) && 
				   this->data_ <= static_cast<decltype(this->data_)>(::std::numeric_limits<unsigned long>::max()); 
		}
		bool isUnsignedLongLong() const {
			return this->data_ >= static_cast<decltype(this->data_)>(::std::numeric_limits<unsigned long long>::min()) && 
				   this->data_ <= static_cast<decltype(this->data_)>(::std::numeric_limits<unsigned long long>::max()); 
		}
		::std::optional<short> toShort() const {
			if (this->isShort()) {
				return static_cast<short>(this->data_);
			}
			return {};
		}
		::std::optional<int> toInt() const {
			if (this->isInt()) {
				return static_cast<int>(this->data_);
			}
			return {};
		}
		::std::optional<long> toLong() const {
			if (this->isLong()) {
				return static_cast<long>(this->data_);
			}
			return {};
		}
		::std::optional<long long> toLongLong() const {
			if (this->isLongLong()) {
				return static_cast<long long>(this->data_);
			}
			return {};
		}
		::std::optional<float> toFloat() const {
			if (this->isFloat()) {
				return static_cast<float>(this->data_);
			}
			return {};
		}
		::std::optional<double> toDouble() const {
			if (this->isDouble()) {
				return static_cast<double>(this->data_);
			}
			return {};
		}
		::std::optional<unsigned short> toUnsignedShort() const {
			if (this->isUnsignedShort()) {
				return static_cast<unsigned short>(this->data_);
			}
			return {};
		}
		::std::optional<unsigned int> toUnsignedInt() const { 
			if (this->isUnsignedInt()) {
				return static_cast<unsigned int>(this->data_);
			}
			return {};
		}
		::std::optional<unsigned long> toUnsignedLong() const {
			if (this->isUnsignedLong()) {
				return static_cast<unsigned long>(this->data_);
			}
			return {};
		}
		::std::optional<unsigned long long> toUnsignedLongLong() const {
			if (this->isUnsignedLongLong()) {
				return static_cast<unsigned long long>(this->data_);
			}
			return {};
		}
	};
}
