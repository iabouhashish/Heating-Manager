/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ibrah
 *
 * Created on November 8, 2017, 10:29 PM
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Rooms.h"
#include "Room.h"
#include "User.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    User user;
    string line;
    string command;
    cout << "> Add a room (R), see annual cost of heating (H), "
            "set cost of heating (C), savings plan (S) "
            "or Exit (E)" << endl;
    cout << "> ";
    getline(cin, line);
    while (!cin.eof()) {
        stringstream lineStream(line);
        lineStream >> command;
        if (command == "R" || command == "r") {
            int number;
            double hours, days, temp;
            cout << "Please enter type of room, followed by number "
                    "of hours used per day, followed by the number "
                    "of days used per year, followed by the temperature "
                    "(example: 1 3.5 50 20)" << endl;
            cout << "> ";
            getline(cin, line);
            stringstream newCom(line);
            newCom >> number;
            bool input = true;
            if (newCom.fail()) {
                input = false;
            }
            newCom >> hours;
            if (newCom.fail()) {
                input = false;
            }
            newCom >> days;
            if (newCom.fail()) {
                input = false;
            }
            newCom >> temp;
            if (newCom.fail()) {
                input = false;
            }
            if (input == false) {
                cout << "Inputs Are Wrong Please Make sure that you follow"
                        "the structure of the example." << endl;
            } else {
                user.addRoom(number, hours, days, temp);
            }
        } else if (command == "H" || command == "h") {
            cout << user.getAnnualCost() << " $ a year" << endl;
        } else if (command == "C" || command == "c") {
            cout << "Please enter cost of heating" << endl;
            cout << "> ";
            double newCost;
            getline(cin, line);
            stringstream newCom(line);
            newCom >> newCost;
            user.setCost(newCost);
        } else if (command == "S" || command == "s") {
            cout << "Please pick 3 scenarios to compare "
                    "from A, B, C, D, E and F" << endl;
            cout << "> ";
            char first, second, third;
            getline(cin, line);
            stringstream newCom(line);
            newCom >> first;
            bool input = true;
            if (newCom.fail()) {
                input = false;
            }
            newCom >> second;
            if (newCom.fail()) {
                input = false;
            }
            newCom >> third;
            if (newCom.fail()) {
                input = false;
            }
            if (input) {
                user.setScenarios(first, second, third);
                user.compareScenarios();
            }
        } else if (command == "E" || command == "e") {
            cout << "Goodbye" << endl;
            break;
        } else {
            cout << "Error: invalid command" << endl;
        }
        cout << "> Edit rooms (R), see average cost of heating (H), "
                "set cost of heating (C), "
                "compare savings plan (S) or Exit (E)" << endl;
        cout << "> ";
        getline(cin, line);
    }
    return 0;
}

