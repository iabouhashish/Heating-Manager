/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EnergyRating.cpp
 * Author: ibrah
 * 
 * Created on November 10, 2017, 9:25 PM
 */

#include "EnergyRating.h"

EnergyRating::EnergyRating() {
    name = 'l';
    cost = 0;
    reduction = 0;
    suitable[0] = 0;
    suitable[1] = 0;
    suitable[2] = 0;
}

EnergyRating::EnergyRating(char newName, double newCost, int newReduction) {
    name = newName;
    cost = newCost;
    reduction = newReduction;
    suitable[0] = cost;
    suitable[1] = reduction;
    suitable[2] = 0;
}


EnergyRating::~EnergyRating() {
}

//Access Methods
char EnergyRating::getName() {
    return name;
}

int EnergyRating::getCost() {
    return cost;
}

int EnergyRating::getReduction() {
    return reduction;
}

double EnergyRating::getPayback() {
    return suitable[2];
}

//Mutator Methods
void EnergyRating::setName(char newName) {
    name = newName;
}

void EnergyRating::setCost(int newCost) {
    cost = newCost;
}

void EnergyRating::setReduction(int newRed) {
    reduction = newRed;
}

//Utility method
void EnergyRating::setSuitable(double payback) {
    suitable[2] = payback;
}
