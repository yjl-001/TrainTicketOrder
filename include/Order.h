//
// Created by yjl on 2022/12/5.
//

#ifndef TRAINTICKETORDER_ORDER_H
#define TRAINTICKETORDER_ORDER_H

#include <iostream>
#include "../lib/jsoncpp/json/json.h"
#include "../include/User.h"
#include "../include/JsonUtil.h"
extern User user;
class Order {
private:
    int orderNo;
    std::string realName;
    std::string identificationID;
    std::string trainNo;
    std::string originalStation;
    std::string startTime;
    std::string destinationStation;
    std::string endTime;
    int price;
    int orderState;
public:
    Order();
    bool save(Json::Value station_root);
    bool generateOrder(Json::Value station_root);
    void toString();

    const int &getOrderNo() const;

    void setOrderNo(const int &orderNo);

    const std::string &getRealName() const;

    void setRealName(const std::string &realName);

    const std::string &getIdentificationId() const;

    void setIdentificationId(const std::string &identificationId);

    const std::string &getTrainNo() const;

    void setTrainNo(const std::string &trainNo);

    const std::string &getOriginalStation() const;

    void setOriginalStation(const std::string &originalStation);

    const std::string &getStartTime() const;

    void setStartTime(const std::string &startTime);

    const std::string &getDestinationStation() const;

    void setDestinationStation(const std::string &destinationStation);

    const std::string &getEndTime() const;

    void setEndTime(const std::string &endTime);

    int getPrice() const;

    void setPrice(int price);

    int getOrderState() const;

    void setOrderState(int orderState);

};


#endif //TRAINTICKETORDER_ORDER_H
