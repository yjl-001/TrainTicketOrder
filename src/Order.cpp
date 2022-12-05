//
// Created by yjl on 2022/12/5.
//

#include "../include/Order.h"

Order::Order() {

}
const int &Order::getOrderNo() const {
    return this->orderNo;
}

void Order::setOrderNo(const int &orderNo) {
    this->orderNo = orderNo;
}

const std::string &Order::getRealName() const {
    return this->realName;
}

void Order::setRealName(const std::string &realName) {
    this->realName = realName;
}

const std::string &Order::getIdentificationId() const {
    return this->identificationID;
}

void Order::setIdentificationId(const std::string &identificationId) {
    this->identificationID = identificationId;
}

const std::string &Order::getTrainNo() const {
    return this->trainNo;
}

void Order::setTrainNo(const std::string &trainNo) {
    this->trainNo = trainNo;
}

const std::string &Order::getOriginalStation() const {
    return this->originalStation;
}

void Order::setOriginalStation(const std::string &originalStation) {
    this->originalStation = originalStation;
}

const std::string &Order::getStartTime() const {
    return this->startTime;
}

void Order::setStartTime(const std::string &startTime) {
    this->startTime = startTime;
}

const std::string &Order::getDestinationStation() const {
    return this->destinationStation;
}

void Order::setDestinationStation(const std::string &destinationStation) {
    this->destinationStation = destinationStation;
}

const std::string &Order::getEndTime() const {
    return this->endTime;
}

void Order::setEndTime(const std::string &endTime) {
    this->endTime = endTime;
}

int Order::getPrice() const {
    return this->price;
}

void Order::setPrice(int price) {
    this->price = price;
}

int Order::getOrderState() const {
    return this->orderState;
}

void Order::setOrderState(int orderState) {
    this->orderState = orderState;
}

bool Order::save(Json::Value order_root) {
    Json::Value::Members users = order_root.getMemberNames();
    bool is_user_exit = false;
    for(auto &usr : users){
        if(usr==user.getUsername()){
            is_user_exit = true;
            break;
        }
    }
    if(!is_user_exit) {
        order_root[user.getUsername()].resize(0);
    }
    Json::Value user_order = order_root.get(user.getUsername(), "null");
    this->setOrderNo(user_order.size() + 1);
    if(!user_order.isNull()){
        Json::Value orderItem;
        orderItem["orderNumber"] = this->getOrderNo();
        orderItem["trueName"] = this->getRealName();
        orderItem["identificationID"] = this->getIdentificationId();
        orderItem["train_NO"] = this->getTrainNo();
        orderItem["original_station"] = this->getOriginalStation();
        orderItem["start_time"] = this->getStartTime();
        orderItem["destination_station"] = this->getDestinationStation();
        orderItem["end_time"] = this->getEndTime();
        orderItem["price"] = this->getPrice();
        orderItem["order_state"] = this->getOrderState();
        user_order.append(orderItem);
        order_root[user.getUsername()] = user_order;
        JsonUtil::writeJsonFile("../data/consumeTicket.json", order_root);
        return true;
    }else {
        return false;
    }
}

void Order::toString() {
    std::cout<<"order information is as followed:"<<std::endl;
    std::cout<<"\tOrder NO: "<< this->getOrderNo()<<std::endl;
    std::cout<<"\tTrainNO: "<< this->getTrainNo()<<std::endl;
    std::cout<<"\tReal Name: "<< this->getRealName()<<std::endl;
    std::cout<<"\tIdentificationID is: "<<this->getIdentificationId()<<std::endl;
    std::cout<<"\tOriginal Station is: "<<this->getOriginalStation()<<std::endl;
    std::cout<<"\tStart time is: "<<this->getStartTime()<<std::endl;
    std::cout<<"\tDestination Station is: "<<this->getDestinationStation()<<std::endl;
    std::cout<<"\tEnd time is: "<< this->getEndTime()<<std::endl;
    std::cout<<"\tPrice is: "<< this->getPrice()<<std::endl;
    std::cout<<"\tOrder State: "<< this->getOrderState()<<std::endl;
}

bool Order::generateOrder(Json::Value station_root) {
    std::cout<<"please input your origin station, destination station and train NO. "<<std::endl;
    std::string origin_station, destination_station, train_id;
    std::cout<<"input origin station:"<<std::endl;
    std::cin>>origin_station;
    this->setOriginalStation(origin_station);
    std::cout<<"input destination station:"<<std::endl;
    std::cin>>destination_station;
    this->setDestinationStation(destination_station);
    std::cout<<"input train NO."<<std::endl;
    std::cin>>train_id;
    this->setTrainNo(train_id);
    std::string trueName, identificationID;
    std::cout<<"please input passenger's true name and identification number"<<std::endl;
    std::cout<<"input your real name:"<<std::endl;
    std::cin>>trueName;
    this->setRealName(trueName);
    std::cout<<"input your identificationID:"<<std::endl;
    std::cin>>identificationID;
    this->setIdentificationId(identificationID);
    // 搜索文件
    // 1、获取两个map
    Json::Value stationsMap = station_root.get("map","null");
    Json::Value trainMap = station_root.get("train_map","null");
    // 2、获取map对应的key
    Json::Value::Members trains = trainMap.getMemberNames();
    // 判断车次在不在服务范围内
    bool is_train_service = false;
    for(auto & train: trains){
        if(train==train_id){
            is_train_service = true;
            break;
        }
    }
    if(is_train_service) { // 如果列车在服务范围内， 查询和列车相关的车躺
        //获取该列车的站点
        Json::Value train_station = station_root.get("train_station", "null").get(
                trainMap.get(train_id, "mull").asString(), "null");
        Json::Value::Members members = train_station.getMemberNames();
        // 判断起始地或目的地在提供的服务范围内
        bool is_origin_service = false;
        bool is_dest_service = false;
        for (auto &member: members) { // 检查起始地
            if (member == stationsMap.get(origin_station, "null").asString()) {
                is_origin_service = true;
                break;
            }
        }
        for (auto &member: members) { // 检查目的地
            if (member == stationsMap.get(destination_station, "null").asString()) {
                is_dest_service = true;
                break;
            }
        }
        if (is_origin_service && is_dest_service) {
            std::string origin = stationsMap.get(origin_station, "0").asString(); //出发站编号
            int destination = stationsMap.get(destination_station, "0").asInt(); // 目的站的编号
            Json::Value station_tickets = station_root.get("ticket", "null").get(
                    trainMap.get(train_id, "null").asString(), "null");
            Json::Value tickets = station_tickets.get(origin, "null");
            for (int i = 0; i < tickets.size(); i++) {
                if (tickets.get(i, "null").get("destination", "0").asInt() == destination) {
                    std::cout<<"generating....."<<std::endl;
                    this->setStartTime(station_root.get("time-start", "null")
                                        .get(trainMap.get(train_id, "null").asString(),"null")
                                        .get(origin, "null").asString());
                    this->setEndTime(station_root.get("time-end", "null")
                                        .get(trainMap.get(train_id, "null").asString(),"null")
                                        .get(std::to_string(destination),"null").asString());
                    this->setPrice(tickets.get(i, "null").get("price", "0").asInt());
                    this->setOrderState(0);
                }
            }
            return true;
        }else{
            return false;
        }
    }
    return false;
}

