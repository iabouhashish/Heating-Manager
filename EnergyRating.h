/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EnergyRating.h
 * Author: ibrah
 *
 * Created on November 10, 2017, 9:25 PM
 */

#ifndef ENERGYRATING_H
#define ENERGYRATING_H

//Libraries
//Files

class EnergyRating {
private:
    char name;
    double cost;
    int reduction;
    double suitable[3];
public:
    EnergyRating();
    EnergyRating(char newName, double newCost, int newReduction);
    virtual ~EnergyRating();
    
    //Access Methods
    char getName();
    int getCost();
    int getReduction();
    double getPayback();
    
    //Mutator Methods
    void setName(char newName);
    void setCost(int newCost);
    void setReduction(int newRed);
    void setSuitable(double payback);


};

#endif /* ENERGYRATING_H */

