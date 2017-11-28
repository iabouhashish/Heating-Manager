/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Room.h
 * Author: Omar Raef
 *
 * Created on November 10, 2017, 11:35 AM
 */

#ifndef ROOM_H
#define ROOM_H

//Libraries
#include <string>
//Files


using namespace std;

class Room {
private:
    string name;
    int size;
    double timePerDay;
    double daysPerYear;
    double temp;
public:
    Room();
    Room(string& Name, int& Size);
    virtual ~Room();
    
    //Access Methods
    string getName();
    int getSize();
    double getTime();
    double getDays();
    double getTemp();
    
    //Mutator Methods
    void setName(string newName);
    void setSize(int newSize);
    void setTime(double newTime);
    void setDays(double newDays);
    void setTemp(double newTemp);
    
    //Utility method
    void print();


};

#endif /* ROOM_H */

