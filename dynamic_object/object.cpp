#pragma once
#include<string>
#include<vector>
#include<unordered_map>
#include<functional>
namespace dynamic {
	class Object;
	struct _Void {};
	//
	using Void = _Void;
	using Number = double;
	using String = ::std::string;
	using Boolean= bool;
	using List = ::std::vector<Object>;
	using Dictionary = ::std::unordered_map<String, Object>;
	using Function = ::std::function<List(List)>;
	//
}
