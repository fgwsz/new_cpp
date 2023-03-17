#include"to_std_string.h"
#include<sstream>
namespace dynamic {
	::std::string toStdString(Null const& value) {
		return "null";
	}
	::std::string toStdString(Boolean const& value) {
		return value.getConstBool() ? "true" : "false";
	}
	::std::string toStdString(Number const& value) {
		if (value.isShort()) {
			return ::std::to_string(value.toShort().value());
		}
		else if (value.isUnsignedShort()) {
			return ::std::to_string(value.toUnsignedShort().value());
		}
		else if (value.isInt()) {
			return ::std::to_string(value.toInt().value());
		}
		else if (value.isUnsignedInt()) {
			return ::std::to_string(value.toUnsignedInt().value());
		}
		else if (value.isLong()) {
			return ::std::to_string(value.toLong().value());
		}
		else if (value.isUnsignedLong()) {
			return ::std::to_string(value.toUnsignedLong().value());
		}
		else if (value.isLongLong()) {
			return ::std::to_string(value.toLongLong().value());
		}
		else if (value.isUnsignedLongLong()) {
			return ::std::to_string(value.toUnsignedLongLong().value());
		}
		else if (value.isFloat()) {
			return ::std::to_string(value.toFloat().value());
		}
		else if (value.isDouble()) {
			return ::std::to_string(value.toDouble().value());
		}
		else { return "error"; }
	}
	::std::string toStdString(String const& value) {
		return "\"" + value + "\"";
	}
	::std::string toStdString(Array const& value) {
		::std::string ret{""};
		ret.append("[");
		for (::std::size_t index = 0; index < value.size(); ++index) {
			ret.append(toStdString(value.at(index)));
			if (index + 1 != value.size()) {
				ret.append(",");
			}
		}
		return ret.append("]");
	}
	::std::string toStdString(Object const& value) {
		::std::string ret{ "" };
		ret.append("{");
		::std::size_t index = 0;
		for (auto const& pair : value) {
			ret.append(toStdString(pair.first)).append(":").append(toStdString(pair.second));
			if (index + 1 != value.size()) {
				ret.append(",");
			}
			++index;
		}
		return ret.append("}");
	}
	::std::string toStdString(Function const& value) {
		return "<Function Value(Value)>";
	}
	::std::string toStdString(Pointer  const& value) {
		::std::ostringstream oss;
		oss << ::std::hex << reinterpret_cast<unsigned long long>(value);
		auto ret = oss.str();
		for (auto& element : ret) {
			if (element >= 'a' && element <= 'z') {
				element += 'A' - 'a';
			}
		}
		return "<Pointer " + ret + ">";
	}
	::std::string toStdString(Value const& value) {
		if (value.isNull()) {
			return toStdString(value.getConstNull());
		}
		else if (value.isBoolean()) {
			return toStdString(value.getConstBoolean());
		}
		else if (value.isNumber()) {
			return toStdString(value.getConstNumber());
		}
		else if (value.isString()) {
			return toStdString(value.getConstString());
		}
		else if (value.isArray()) {
			return toStdString(value.getConstArray());
		}
		else if (value.isObject()) {
			return toStdString(value.getConstObject());
		}
		else if (value.isFunction()) {
			return toStdString(value.getConstFunction());
		}
		else if (value.isPointer()) {
			return toStdString(value.getConstPointer());
		}
		else { return "error"; }
	}
}
