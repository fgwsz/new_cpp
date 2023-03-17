#pragma once
#include<string>
#include"value.h"
namespace dynamic {
	::std::string toStdString(Null     const& value);
	::std::string toStdString(Boolean  const& value);
	::std::string toStdString(Number   const& value);
	::std::string toStdString(String   const& value);
	::std::string toStdString(Array    const& value);
	::std::string toStdString(Object   const& value);
	::std::string toStdString(Function const& value);
	::std::string toStdString(Value    const& value);
}
