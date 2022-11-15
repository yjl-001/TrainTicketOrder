//
// Created by whd on 2022/11/15.
//

#ifndef TRAINTICKETORDER_TICKET_H
#define TRAINTICKETORDER_TICKET_H

using namespace std;


class Ticket {
    /**
     * 火车票
     */
private:
    double price; //价格
    int number; //数量
public:
    Ticket(double price);
    ~Ticket();
    double getPrice();
    int getTicketNumber();
};


#endif //TRAINTICKETORDER_TICKET_H
