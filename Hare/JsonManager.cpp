#include "JsonManager.h"
#include "Debug.h"

#include <fstream>
#include <iostream>

Json::Value JsonManager::OpenJson(const char* arg)
{
    Json::Value jsonFile;

    std::ifstream ifs;
    ifs.open(arg);

    Json::CharReaderBuilder builder;

    builder["collectComments"] = true;
    JSONCPP_STRING errs;
    if (!parseFromStream(builder, ifs, &jsonFile, &errs)) {
        DEBUG_LOG << errs;
        return -1;
    }

    ifs.close();

	return jsonFile;
}
