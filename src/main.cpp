#include <iostream>
#include "../include/Ticket.h"
#include "../include/JsonUtil.h"
#include "../include/LoginAndRegister.h"

// 定义全局变量
User user; //用户
Json::Value station_root = JsonUtil::readJsonFile("../data/station.json");

int main() {
    std::cout<<"welcome to our system!"<<std::endl;
    std::cout<<"please login in  if you have an account, or please register first"<<std::endl;
    std::cout<<"please type your choose:1 for login in, 0 for register"<<std::endl;
    int login_int_or_register = 0;
    std::cout<<"input your choose:";
    std::cin>>login_int_or_register;
    user = User();
    user.setUsername("admin");
    switch (login_int_or_register) {
        case 1:
            std::cout<<"login in"<<std::endl;
            login_in();// 登录
            break;
        case 0:
            std::cout<<"register"<<std::endl;
            user_register(); //注册
            break;
    }
    return 0;
}

