//
// Created by yjl on 2022/11/30.
//
#include "../include/User.h"
#include "../include/LoginAndRegister.h"
#include "../lib/jsoncpp/json/json.h"
#include "../include/JsonUtil.h"
extern User user;
void login_in(){
    std::string username ;
    std::cout<<"username: ";
    std::cin>>username;
    std::string password ;
    std::cout<<"password: ";
    std::cin>>password;
    if(login_in_logic(username, password)){
        std::cout<<"success to login in"<<std::endl;
        //TODO 进入系统
    }else{
        std::cout<<"failed to login in, please check your username or password!"<<std::endl;
        login_in();
    }
}

void user_register(){
    std::string username;
    std::cout<<"username: ";
    std::cin>>username;
    std::string password;
    std::cout<<"password: ";
    std::cin>>password;
    if(register_logic(username, password)){
        std::cout<<"success to register"<<std::endl;
        login_in();
    }else{
        std::cout<<"failed to login in, please check your username or password!"<<std::endl;
        user_register();
    }
}

bool login_in_logic(const std::string& username, const std::string& password){
    Json::Value root = JsonUtil::readJsonFile("../data/userInfo.json");
    if(username=="admin"){// 管理员登录
        Json::Value admin = root.get("admin","null");
        if(password==admin.get(username,"null").asString()){//验证密码是否正确
            user = User();
            return true;
        }else{
            return false;
        }
    }else{ // 普通用户登录
        Json::Value usr = root.get("user","null");
        if(password==usr.get(username,"null").asString()){
            user = User(1, username, password);
            return true;
        }else{
            return false;
        }
    }
}

bool register_logic(const std::string& username, const std::string& password){
    Json::Value root = JsonUtil::readJsonFile("../data/userInfo.json");
    Json::Value usr = root.get("user","null");
    usr[username] = password;
    root["user"] = usr;
    JsonUtil::writeJsonFile("../data/userInfo.json", root);
    return true;
}

