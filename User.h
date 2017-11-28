/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   User.h
 * Author: ibrah
 *
 * Created on November 10, 2017, 2:11 PM
 */

#ifndef USER_H
#define USER_H

//Libraries
#include <fstream>
#include <vector>

//Files
#include "EnergyRating.h"
#include "Room.h"
#include "Rooms.h"

class User {
private:
    vector<Room> building;
    Rooms cluster;
    vector<EnergyRating> allRatings;
    EnergyRating chosen;
    char scenarios[3];
    double cost;
public:
    User();
    virtual ~User();
    
    //Access Methods
    vector<Room> getBuilding();
    double getCost();
    EnergyRating getChosen();
    
    //Mutator Methods
    void addRoom(int size, double hours, double days, double temp);
    void setCost(double newCost);
    void setScenarios(char A, char B, char C);
    void setChosen(char A);
    
    //Utility method
    double getAnnualCost();
    void compareScenarios();
    void setSuitable();


};

#endif /* USER_H */

