#pragma once
#include<numeric>
namespace dynamic {
	struct Number {
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
		Number& operator=(Number const& value) { this->data_ == value.data_; return *this; }
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
		operator short             () const { return static_cast<short             >(this->data_); }
		operator int               () const { return static_cast<int               >(this->data_); }
		operator long              () const { return static_cast<long              >(this->data_); }
		operator long long         () const { return static_cast<long long         >(this->data_); }
		operator float             () const { return static_cast<float             >(this->data_); }
		operator double            () const { return static_cast<double            >(this->data_); }
		operator unsigned short    () const { return static_cast<unsigned short    >(this->data_); }
		operator unsigned int      () const { return static_cast<unsigned int      >(this->data_); }
		operator unsigned long     () const { return static_cast<unsigned long     >(this->data_); }
		operator unsigned long long() const { return static_cast<unsigned long long>(this->data_); }
		short              toShort             () const { return static_cast<short             >(this->data_); }
		int                toInt               () const { return static_cast<int               >(this->data_); }
		long               toLong              () const { return static_cast<long              >(this->data_); }
		long long          toLongLong          () const { return static_cast<long long         >(this->data_); }
		float              toFloat             () const { return static_cast<float             >(this->data_); }
		double             toDouble            () const { return static_cast<double            >(this->data_); }
		unsigned short     toUnsignedShort     () const { return static_cast<unsigned short    >(this->data_); }
		unsigned int       toUnsignedInt       () const { return static_cast<unsigned int      >(this->data_); }
		unsigned long      toUnsignedLong      () const { return static_cast<unsigned long     >(this->data_); }
		unsigned long long toUnsignedLongLong  () const { return static_cast<unsigned long long>(this->data_); }
	};
}
