/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rooms.h
 * Author: Omar Raef
 *
 * Created on November 10, 2017, 12:04 PM
 */

#ifndef ROOMS_H
#define ROOMS_H

//Libraries
#include <fstream>
#include <vector>
//Files
#include "Room.h"

using namespace std;

class Rooms {

private:
    vector<Room> rooms;
    string path;
    void getAllRooms();
public:
    Rooms();
    virtual ~Rooms();
    
    //Access Methods
    vector<Room> getRooms();
    string getPath();
    
    //Mutator Methods
    void addRoom(Room newRoom);
    void setPath(string newPath);
    void editRoom(int index, string name, int size);
    
    //Helper Methods
};

#endif /* ROOMS_H */

