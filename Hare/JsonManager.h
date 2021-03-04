#ifndef JSONMANAGER_H_
#define JSONMANAGER_H_

#include <json/json.h>

struct JsonManager
{
	/* Opens a JSON file. Returns a JSON Value. */
	static Json::Value OpenJson(const char* arg);
};

#endif
