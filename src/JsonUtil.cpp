//
// Created by whd on 2022/11/30.
//

#include "../include/JsonUtil.h"

std::string JsonUtil::readFileIntoString(const char *filename) {
    ifstream ifile(filename);
    if(!ifile.is_open()){
        std::cerr<<"文件打开错误";
    }
    ostringstream buf;
    std::string filestr;
    char ch;
    while(buf && ifile.get(ch)){
        buf.put(ch);
    }
    filestr = buf.str();
    return filestr;
}

Json::Value JsonUtil::readJsonFile(const std::string &filename) {
    //1.打开文件
    ifstream ifile;
    ifile.open(filename);

    //2.创建json读工厂对象
    Json::CharReaderBuilder ReaderBuilder;
    ReaderBuilder["emitUTF8"] = true;//utf8支持，不加这句，utf8的中文字符会编程\uxxx

    //3.创建json对象，等会要返回这个对象
    Json::Value root;

    //4.把文件转变为json对象，要用到上面的三个变量,数据写入root
    std::string strerr;
    bool ok = Json::parseFromStream(ReaderBuilder,ifile,&root,&strerr);
    if(!ok){
        cerr<<"json解析错误";
    }
    //5.返回存有数据的json，这个json对象已经能用了
    return root;
}

Json::Value JsonUtil::readJsonFromString(const std::string &mystr) {
    //1.创建工厂对象
    Json::CharReaderBuilder ReaderBuilder;
    ReaderBuilder["emitUTF8"] = true;//utf8支持,不加这句,utf8的中文字符会编程\uxxx
    //2.通过工厂对象创建 json阅读器对象
    unique_ptr<Json::CharReader> charread(ReaderBuilder.newCharReader());
    //3.创建json对象
    Json::Value root;
    //4.把字符串转变为json对象,数据写入root
    std::string strerr;
    bool isok = charread->parse(mystr.c_str(),mystr.c_str()+mystr.size(),&root,&strerr);
    if(!isok || strerr.size() != 0){
        cerr<<"json解析出错";
    }
    //5.返回有数据的json对象,这个json对象已经能用了
    return root;
}

void JsonUtil::writeJsonFile(const std::string &filename, const Json::Value &root) {
    //1.写json的工厂对象
    Json::StreamWriterBuilder writebuild;
    writebuild["emitUTF8"] = true;//utf8支持,加这句,utf8的中文字符会编程\uxxx
    //2.把json对象转变为字符串
    std::string document = Json::writeString(writebuild,root);
    //3.调用前面的写文件函数,写入文件
    writeFileFromString(filename,document);
}

void JsonUtil::writeFileFromString(const std::string &filename, const std::string &body) {
    ofstream ofile(filename);
    ofile<<body;
    ofile.close();
}
