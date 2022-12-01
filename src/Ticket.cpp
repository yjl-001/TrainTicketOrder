//
// Created by whd on 2022/11/15.
//

#include "../include/Ticket.h"

Ticket::Ticket(double price) {
    this->price = price;
}

Ticket::~Ticket() {
    this->price = 0;
}

double Ticket::getPrice() {
    return this->price;
}


int Ticket::getTicketNumber() {
    return this->number;
}
