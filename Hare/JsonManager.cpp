#include "JsonManager.h"
#include "Debug.h"

#include <fstream>
#include <iostream>

Json::Value JsonManager::OpenJson(const char* arg)
{
    Json::Value jsonFile;                                       //Create a Json::Value object

    std::ifstream ifs;                                          //Open a file with the ifstream
    ifs.open(arg);

    if (!ifs.good())                                            //If the file doesn't exist...
    {
        DEBUG_LOG << "JSON FILE CANNOT BE FOUND! RETURNING NULL!";
        return Json::Value();                                   //Return an empty object (all members are null)
    }
    Json::CharReaderBuilder builder;                            //Create a jsoncpp builder

    builder["collectComments"] = true;                          //Collect metadata
    JSONCPP_STRING errs;                                        //Collect any errors
    if (!parseFromStream(builder, ifs, &jsonFile, &errs)) {     //Parse from the stream (jsoncpp)
        DEBUG_LOG << errs;
        return -1;
    }

    ifs.close();

	return jsonFile;
}
