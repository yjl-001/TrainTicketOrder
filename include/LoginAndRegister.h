//
// Created by yjl on 2022/11/30.
//

#ifndef TRAINTICKETORDER_LOGINANDREGISTER_H
#define TRAINTICKETORDER_LOGINANDREGISTER_H
# include "iostream"
#include "../include/User.h"
void login_in();
void user_register();

bool login_in_logic(const std::string& username, const std::string& password);
bool register_logic(const std::string& username, const std::string& password);

#endif //TRAINTICKETORDER_LOGINANDREGISTER_H
