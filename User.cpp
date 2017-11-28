/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   User.cpp
 * Author: ibrah
 * 
 * Created on November 10, 2017, 2:11 PM
 */

#include "User.h"
#include "EnergyRating.h"
#include "Room.h"
#include "Rooms.h"

#include <iostream>

User::User() {
    //Create all 6 ratings
    allRatings.push_back(EnergyRating('A', 3.2, 5));
    allRatings.push_back(EnergyRating('B', 12.75, 10));
    allRatings.push_back(EnergyRating('C', 32.20, 15));
    allRatings.push_back(EnergyRating('D', 45.33, 20));
    allRatings.push_back(EnergyRating('E', 77.80, 25));
    allRatings.push_back(EnergyRating('F', 143.50, 33));

    cost = 0.015;
}

User::~User() {
}

//Access Methods

vector<Room> User::getBuilding() {
    return building;
}

double User::getCost() {
    return cost;
}

EnergyRating User::getChosen() {
    return chosen;
}

//Mutator Methods

void User::addRoom(int size, double hours, double days, double temp) {
    if (size > cluster.getRooms().size()) {
        cout << "Error Room Size doesn't exist" << endl;
    } else {
        Room newRoom = cluster.getRooms().at(size - 1);
        newRoom.setDays(days);
        newRoom.setTime(hours);
        newRoom.setTemp(temp);
        building.push_back(newRoom);
        setSuitable();
    }
}

void User::setCost(double newCost) {
    cost = newCost;
    setSuitable();
}

void User::setScenarios(char A, char B, char C) {
    scenarios[0] = A;
    scenarios[1] = B;
    scenarios[2] = C;
}

void User::setChosen(char A) {
    for (int i = 0; i < allRatings.size(); i++) {
        if (allRatings.at(i).getName() == A) {
            chosen = allRatings.at(i);
        }
    }
}

//Utility method

double User::getAnnualCost() {
    int rooms = building.size();
    double annual = 0;
    for (int i = 0; i < rooms; i++) {
        double size, temperature, hours;
        Room temp = building.at(i);
        hours = temp.getDays() * temp.getTime();
        size = temp.getSize();
        temperature = temp.getTemp();
        annual += hours * size * temperature*cost;
    }
    return annual;
}

void User::compareScenarios() {
    /*
     * Display Cost of Heating the building at cost rate. the cost of 
     * upgrading the building energy efficiency rate, the pay-back period
     * to the nearest day.
     * In A Table.
     * Which one is the best based on shortest pay-back period.
     */
    //Total Size of the building in m^2
    int totalSize = 0;
    for (int j = 0; j < building.size(); j++) {
        totalSize += building.at(j).getSize();
    }
    //Cost of heating of the building at c.
    cout << "Cost of Heating before upgrade is " 
            << getAnnualCost() << "$"<< endl;
    for (int i = 0; i < 3; i++) {
        EnergyRating scenario;
        bool found = false;
        for (int y = 0; y < allRatings.size(); y++) {
            if (allRatings.at(y).getName() == scenarios[i]) {
                scenario = allRatings.at(y);
                found = true;
            }
        }
        if (found) {
            cout << "For Scenario " << scenario.getName() << ": the Cost "
                "Of Upgrade is " << totalSize * scenario.getCost()
                << "$ The Payback period to the nearest day is in "
                << scenario.getPayback()*365 << " days" << endl;
        } else {
            cout << "Scenario Specified Does not exist" << endl;
        }
        
    }
}

void User::setSuitable() {
    int rooms = building.size();
    for (int y = 0; y < allRatings.size(); y++) {
        EnergyRating currentRating = allRatings.at(y);
        double noSavingCost = 0;
        double payback, upgradeCost, reduction;
        reduction = allRatings.at(y).getReduction();
        upgradeCost = allRatings.at(y).getCost();

        for (int i = 0; i < rooms; i++) {
            double size, temperature, hours;
            Room temp = building.at(i);
            hours = temp.getDays() * temp.getTime();
            size = temp.getSize();
            temperature = temp.getTemp();
            noSavingCost += hours * size * temperature*cost;
        }
        noSavingCost = noSavingCost*reduction;
        payback = upgradeCost / noSavingCost;
        allRatings.at(y).setSuitable(payback * 365);
    }
}