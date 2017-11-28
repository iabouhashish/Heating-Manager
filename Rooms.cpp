/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rooms.cpp
 * Author: Omar Raef
 * 
 * Created on November 10, 2017, 12:04 PM
 */

#include "Rooms.h"
#include "Room.h"
#include <iostream>
#include <fstream>
using namespace std;

Rooms::Rooms() {
    path = "rooms.txt";
    getAllRooms();
}

Rooms::~Rooms() {
}
void Rooms::getAllRooms() {
    ifstream roomFile;
    roomFile.open(path.c_str());
    string line;
    while(!roomFile.eof()) {
        int number, size;
        string name;
        roomFile >> number >> name >> size;
        Room temp(name, size);
        addRoom(temp);
        getline(roomFile, line);
    }
    roomFile.close();
}

//Access Methods
vector<Room> Rooms::getRooms(){
    return rooms;
}

string Rooms::getPath() {
    return "";
}

//Mutator Methods
void Rooms::addRoom(Room newRoom) {
    rooms.push_back(newRoom);
}
void Rooms::setPath(string newPath) {
    path = newPath;
}

void Rooms::editRoom(int index, string name, int size) {
    rooms.at(index).setName(name);
    rooms.at(index).setSize(size);
}