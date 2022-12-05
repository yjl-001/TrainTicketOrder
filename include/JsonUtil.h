//
// Created by whd on 2022/11/30.
//

#ifndef TRAINTICKETORDER_JSONUTIL_H
#define TRAINTICKETORDER_JSONUTIL_H
#include <fstream> //读写文件 c++标准库
#include <sstream> //字符串流 c++标准库
#include <iostream>
#include "../lib/jsoncpp/json/json.h"

using namespace std;
class JsonUtil {
public:
    static std::string readFileIntoString(const char * filename);
    static Json::Value readJsonFile(const std::string & filename);
    static Json::Value readJsonFromString(const std::string& mystr );
    static void writeJsonFile(const std::string & filename,const Json::Value & root);
    static void writeFileFromString(const std::string& filename,const std::string& body); //
};


#endif //TRAINTICKETORDER_JSONUTIL_H
