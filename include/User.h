//
// Created by whd on 2022/11/30.
//

#ifndef TRAINTICKETORDER_USER_H
#define TRAINTICKETORDER_USER_H
#include<iostream>

class User {
private:
    int type; // 管理元or普通用户
    std::string username;
    std::string password;
public:
    User();
    User(const int type, const std::string& username, const std::string& password);
    int getType();
    std::string getUsername();
    std::string getPasswaord();

    void setUsername(std::string username);
    void setPassword(std::string password);
};


#endif //TRAINTICKETORDER_USER_H
