#include <string>
#include <iostream>
#include "ShipGirl.h"

using namespace std;

ShipGirl::ShipGirl() {
    shipName = "YOUR WAIFU IS TRASH";
    repairTime = 0;
}

ShipGirl::ShipGirl(int repairTime, string shipName) {
    this->shipName = shipName;
    this->repairTime = repairTime;
}

int ShipGirl::getTime() const {
    return repairTime;
}

string ShipGirl::getName() const {
    return shipName;
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