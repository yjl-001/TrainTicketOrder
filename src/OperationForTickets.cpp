//
// Created by whd on 2022/12/2.
//
#include "../include/OperationForTickets.h"
#include "../lib/jsoncpp/json/json.h"
#include <iostream>
#include <map>
extern Json::Value station_root;
extern Json::Value order_root;
void checkTickets(){
    // 输入数据
    std::string origin_station, dest_station;
    std::string train_id;
    std::cout<<"input origin station:"<<std::endl;
    std::cin>>origin_station;
    std::cout<<"input destination station:"<<std::endl;
    std::cin>>dest_station;
    std::cout<<"input your train_id, CZ6111 or CZ6112 or none"<<std::endl;
    std::cin>>train_id;
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
    if(is_train_service){ // 如果列车在服务范围内， 查询和列车相关的车躺
        //获取该列车的站点
        Json::Value train_station = station_root.get("train_station","null").get(trainMap.get(train_id,"mull").asString(),"null");
        Json::Value::Members members = train_station.getMemberNames();
        // 判断起始地或目的地在提供的服务范围内
        bool is_origin_service = false;
        bool is_dest_service = false;
        for(auto & member : members){ // 检查起始地
            if(member==stationsMap.get(origin_station,"null").asString()){
                is_origin_service = true;
                break;
            }
        }
        for(auto & member : members){ // 检查目的地
            if(member==stationsMap.get(dest_station,"null").asString()){
                is_dest_service = true;
                break;
            }
        }
        if(is_origin_service && is_dest_service){
            std::cout<<"searching......."<<std::endl;
            std::string origin = stationsMap.get(origin_station,"0").asString(); //出发站编号
            int destination = stationsMap.get(dest_station,"0").asInt(); // 目的站的编号
            Json::Value station_tickets = station_root.get("ticket","null").get(trainMap.get(train_id,"null").asString(),"null");
            Json::Value tickets = station_tickets.get(origin,"null");
            for(int i=0;i<tickets.size();i++){
                if(tickets.get(i,"null").get("destination","0").asInt()==destination){
                    std::cout<<"\ttrain No. is "<<train_id<<std::endl;
                    std::cout<<"\torigin station: "<<origin_station<<std::endl;
                    std::cout<<"\tdestination station: "<<dest_station<<std::endl;
                    std::cout<<"\tstart time: "<<station_root.get("time-start","null").get(trainMap.get(train_id,"null").asString(),"null").get(origin,"null").asString()<<std::endl;
                    std::cout<<"\tend time: "<<station_root.get("time-end","null").get(trainMap.get(train_id,"null").asString(),"null").get(std::to_string(destination),"null").asString()<<std::endl;
                    std::cout<<"\t"<<tickets.get(i,"null").get("number","0").asInt()<<" tickets remains"<<std::endl;
                    std::cout<<"\tprice is: "<<tickets.get(i,"null").get("price","0").asInt()<< " yuan"<<std::endl;
                }
            }
        }else{
            std::cout<<"your origin station or destination station isn't our service"<<std::endl;
        }
    }else{ // 如果列车不在服务范围内， 查询所有列车
        for(auto & train : trains){
            // 获取该列车的站点
            Json::Value train_station = station_root.get("train_station","null").get(trainMap.get(train,"mull").asString(),"null");
            Json::Value::Members members = train_station.getMemberNames();
            // 判断起始地或目的地在提供的服务范围内
            bool is_origin_service = false;
            bool is_dest_service = false;
            for(auto & member : members){ // 检查起始地
                if(member==stationsMap.get(origin_station,"null").asString()){
                    is_origin_service = true;
                    break;
                }
            }
            for(auto & member : members){ // 检查目的地
                if(member==stationsMap.get(dest_station,"null").asString()){
                    is_dest_service = true;
                    break;
                }
            }
            if(is_origin_service && is_dest_service){
                std::cout<<"searching......."<<std::endl;
                std::cout<<"all plans are as followed:"<<std::endl;
                std::string origin = stationsMap.get(origin_station,"0").asString(); //出发站编号
                int destination = stationsMap.get(dest_station,"0").asInt(); // 目的站的编号
                Json::Value station_tickets = station_root.get("ticket","null").get(trainMap.get(train,"null").asString(),"null");
                Json::Value tickets = station_tickets.get(origin,"null");
                for(int i=0;i<tickets.size();i++){
                    if(tickets.get(i,"null").get("destination","0").asInt()==destination){
                        std::cout<<"\ttrain No. is "<<train<<std::endl;
                        std::cout<<"\torigin station: "<<origin_station<<std::endl;
                        std::cout<<"\tdestination station: "<<dest_station<<std::endl;
                        std::cout<<"\tstart time: "<<station_root.get("time-start","null").get(trainMap.get(train,"null").asString(),"null").get(origin,"null").asString()<<std::endl;
                        std::cout<<"\tend time: "<<station_root.get("time-end","null").get(trainMap.get(train,"null").asString(),"null").get(std::to_string(destination),"null").asString()<<std::endl;
                        std::cout<<"\t"<<tickets.get(i,"null").get("number","0").asInt()<<" tickets remains"<<std::endl;
                        std::cout<<"\tprice is: "<<tickets.get(i,"null").get("price","0").asInt()<< " yuan"<<std::endl;
                    }
                }
            }
        }
    }
}

void buyTicket(){
    // 定义Order
    Order order = Order();
    if(order.generateOrder(station_root)){
        if(order.save(order_root)){
            std::cout<<"order successfully"<<std::endl;
            order.toString();
        }
    }
}

void refundTicket(){
    Json::Value user_order = order_root.get(user.getUsername(),"null");//JsonArray
    std::map<int, Json::Value> orders;
    std::cout<<"\tOrder NO."<<"\tOrder Info"<<std::endl;
    for(int i=0; i<user_order.size();i++){
        if(user_order.get(i,"null").get("order_state","null").asInt()==0){
            int orderNo = user_order.get(i,"null").get("orderNumber","null").asInt();
            orders[orderNo] = user_order.get(i,"null");
            std::cout<<"\t"<<orderNo<<"\ttrainNO. is: "<<user_order.get(i,"null").get("train_NO","null").asString()<<std::endl;
            std::cout<<"\t\tOriginal Station: "<<user_order.get(i,"null").get("original_station","null").asString()<<std::endl;
            std::cout<<"\t\tStart time: "<<user_order.get(i,"null").get("start_time","null").asString()<<std::endl;
            std::cout<<"\t\tDestination Station: "<<user_order.get(i,"null").get("destination_station","null").asString()<<std::endl;
            std::cout<<"\t\tEnd time: "<<user_order.get(i,"null").get("end_time","null").asString()<<std::endl;
            std::cout<<"\t\tPrice: "<<user_order.get(i,"null").get("price","null").asString()<<std::endl;
        }
    }
    std::cout<<"please input your choose to refund the ticket"<<std::endl;
    int choose;
    std::cin>>choose;
    Json::Value trainMap = station_root.get("train_map","null");
    Json::Value stationsMap = station_root.get("map","null");
    std::string train_id = orders[choose].get("train_NO","null").asString();
    Json::Value des = station_root["ticket"][trainMap.get(train_id, "null").asString()][stationsMap.get(orders[choose].get("original_station","null").asString(),"null").asString()];
    for(int i=0;i<des.size();i++){
        if(des.get(i,"0").get("destination","0").asInt()==stationsMap.get(orders[choose].get("destination_station","null").asString(),"null").asInt()){
            int new_num = des.get(i,"0").get("number","0").asInt()+1;
            station_root["ticket"][trainMap.get(train_id, "null").asString()][stationsMap.get(orders[choose].get("original_station","null").asString(),"null").asString()][i]["number"] = new_num;
        }
    }
    JsonUtil::writeJsonFile("../data/station.json",station_root);
    orders.erase(choose);
    user_order.resize(0);
    std::map<int, Json::Value>::iterator it = orders.begin();
    std::map<int, Json::Value>::iterator itEnd = orders.end();
    while (it != itEnd){
        user_order.append(it->second);
        it++;
    }
    order_root[user.getUsername()] = user_order;
    JsonUtil::writeJsonFile("../data/consumeTicket.json", order_root);

}
