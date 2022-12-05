//
// Created by whd on 2022/11/30.
//

#include "../include/User.h"

User::User() {
    this->type = 0;
    this->username = "admin";
    this->password = "admin";
}

User::User(const int type, const std::string &username, const std::string &password) {
    if(type!=0){
        this->type = 1;
        this->username = username;
        this->password = password;
    }
}

 int User::getType() {
    return this->type;
}

std::string User::getUsername() {
    return this->username;
}

std::string User::getPasswaord() {
    return this->password;
}


void User::setUsername(std::string username) {
    if(this->type!=0){ //管理员不允许改名
        this->username = username;
    }
}

void User::setPassword(std::string password) {
    if(this->type!=0){ //管理员不允许改密码
        this->password = password;
    }
}



