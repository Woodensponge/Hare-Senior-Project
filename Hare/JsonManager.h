#ifndef JSONMANAGER_H_
#define JSONMANAGER_H_

#include <json/json.h>

struct JsonManager
{
	static Json::Value OpenJson(const char* arg);
};

#endif
