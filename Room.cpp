/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Room.cpp
 * Author: Omar Raef
 * 
 * Created on November 10, 2017, 11:35 AM
 */

#include "Room.h"
#include <iostream>
#include <sstream>

using namespace std;

Room::Room() {
    name = "";
    size = 0;
    timePerDay = 0;
    daysPerYear = 0;
    temp = 0;
}

Room::Room(string& Name, int& Size) {
    size = Size;
    name = Name;
    timePerDay = 0;
    daysPerYear = 0;
    temp = 0;
}

Room::~Room() {
}

//Access Methods

string Room::getName() {
    return name;
}

int Room::getSize() {
    return size;
}

double Room::getTime() {
    return timePerDay;
}

double Room::getDays() {
    return daysPerYear;
}

double Room::getTemp() {
    return temp;
}

//Mutator Methods

void Room::setName(string newName) {
    name = newName;
}

void Room::setSize(int newSize) {
    size = newSize;
}

void Room::setTime(double newTime) {
    timePerDay = newTime;
}

void Room::setDays(double newDays) {
    daysPerYear = newDays;
}

void Room::setTemp(double newTemp) {
    temp = newTemp;
}

//Utility method

void Room::print() {
    cout << "Room Size is " << size << "\n";
}