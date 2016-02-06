#include <cmath>
#include <vector>
#include <iostream>
#include <string>

using namespace std;
#include "ShipGirl.h"
#include "Dock.h"

Dock::Dock() {
    vector<ShipGirl> temp;
    shipList = temp;
    dock1 = temp;
    dock2 = temp;
}


Dock::Dock(vector<ShipGirl> shipList) {
    vector<ShipGirl> temp;
    this->shipList = shipList;
    dock1 = temp;
    dock2 = temp;
}
    
int Dock::dock1Sum() const {
    int sum = 0;
    for (int i = 0; i < dock1.size(); i++) {
        sum += dock1.at(i).getTime();
    }
    return sum;
}
int Dock::dock2Sum() const {
    int sum = 0;
    for (int i = 0; i < dock2.size(); i++) {
        sum+= dock2.at(i).getTime();
    }
    return sum;
}

void Dock::checkTwoDocks() {
    assignTwoDocks();
    
    if (shipList.size() <= 2) {
        return;
    }
    
    int sumDock1 = dock1Sum();
    int sumDock2 = dock2Sum();
    int currentDifference = abs(dock1Sum() - dock2Sum());
    
    //across
    int iterations;
    
    do {
        iterations = 0;
        
        for (int i = 0; i < dock1.size(); i++) {
            for (int j = 0; j < dock2.size(); j++) {
                if (currentDifference > abs(dock1.at(i).getTime() - dock2.at(j).getTime())) {
                    ShipGirl swapTemp = dock1.at(i);
                    dock1.at(i) = dock2.at(j);
                    dock2.at(j) = swapTemp;
                    if (currentDifference < abs(dock1Sum() - dock2Sum())) {
                        swapTemp = dock1.at(i);
                        dock1.at(i) = dock2.at(j);
                        dock2.at(j) = swapTemp;
                    } else {
                        currentDifference = abs(dock1Sum() - dock2Sum());
                        iterations++;
                    }
                }
            }
        }
    } while (iterations > 0);
    
    return;
}

void Dock::printTwoDocks() const {
    cout << "Dock 1:" << endl;
    for (int i = 0; i < dock1.size(); i++) {
        dock1.at(i).display();
    }
    cout << endl << "Dock 2:" << endl;
    for (int i = 0; i < dock2.size(); i++) {
        dock2.at(i).display();
    }
    
    return;
}

void Dock::assignTwoDocks() {
    int sumDock1 = dock1Sum();
    int sumDock2 = dock2Sum();
    //int reversed = 0;
    ShipGirl swapTemp;
    int max;
    vector<ShipGirl> temp = shipList;
    
    for (unsigned int i = 0; i < temp.size(); i++) {
        max = i;
        for (unsigned int j = i + 1; j < temp.size(); j++) {
            if (temp.at(i).getTime() > temp.at(j).getTime()) {
                max = j;
            }
        }
        swapTemp = temp.at(i);
        temp.at(i) = temp.at(max);
        temp.at(max) = swapTemp;
    }
    
    for (unsigned int i = 0; i < shipList.size(); i++) {
        sumDock1 = dock1Sum();
        sumDock2 = dock2Sum();

        if (sumDock1 == sumDock2) {
            dock1.push_back(shipList.at(i)); 
        } else if (sumDock1 < sumDock2) {
            dock1.push_back(shipList.at(i));
        } else if (sumDock1 > sumDock2) {
            dock2.push_back(shipList.at(i));
        }
    }
    return;
}