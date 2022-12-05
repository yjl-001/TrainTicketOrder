cmake_minimum_required(VERSION 3.20)
project(TrainTicketOrder)

set(CMAKE_CXX_STANDARD 14)

add_executable(TrainTicketOrder src/main.cpp src/Ticket.cpp include/Ticket.h include/ConstValue.h src/User.cpp include/User.h lib/jsoncpp/json/json.h
        lib/jsoncpp/json/json-forwards.h lib/jsoncpp/jsoncpp.cpp src/JsonUtil.cpp include/JsonUtil.h include/LoginAndRegister.h src/LoginAndRegister.cpp include/OperationForTickets.h src/OperationForTickets.cpp src/Order.cpp include/Order.h)
