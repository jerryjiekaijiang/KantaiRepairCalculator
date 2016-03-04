#include <string>
#include <iostream>
#include "ShipGirl.h"

using namespace std;

ShipGirl::ShipGirl() {
    shipName = "";
    repairTime = 0;
    akashi = false;
}

ShipGirl::ShipGirl(int repairTime, string shipName) {
    this->shipName = shipName;
    this->repairTime = repairTime;
    akashi = false;
}

ShipGirl::ShipGirl(int repairTime, string shipName, bool akashi) {
    this->shipName = shipName;
    this->repairTime = repairTime;
    this->akashi = akashi;
}

int ShipGirl::getTime() const {
    return repairTime;
}

string ShipGirl::getName() const {
    return shipName;
}

bool ShipGirl::getAkashi() const {
    return akashi;
}

void ShipGirl::display() const {
    int total = repairTime;
    int hours = total / 3600;
    total %= 3600;
    int minutes = total / 60;
    total %= 60;
    int seconds = total;
    
    cout << shipName << ": ";
    
    if (hours < 10) {
        cout << "0" << hours;
    } else {
        cout << hours;
    }
    if (minutes < 10) {
        cout << ":0" << minutes;
    } else {
        cout << ":" << minutes;
    }
    if (seconds < 10) {
        cout << ":0" << seconds;
    } else {
        cout << ":" << seconds;
    }
    cout << endl;
    
    return;
}