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
#include <time.h>
#include <memory>
#include <thread>
#include <set>
#include <direct.h>
using std::string;
#define TYPE_IMG (string)"Image"
#define TYPE_CFG (string)"Config"
#define TYPE_DFT (string)"Default"
using nlohmann::json;
using std::ifstream;
using std::ofstream;
using std::unique_ptr;
using std::make_unique;
string TimeToString(time_t t);