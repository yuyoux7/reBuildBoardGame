#pragma once
#ifdef UNICODE
#undef UNICODE
#endif 
#include <easyx.h>
#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include <math.h>
using std::string;
using nlohmann::json;
using std::ifstream;
using std::ofstream;
using std::unique_ptr;
using std::make_unique;
string TimeToString(time_t t);