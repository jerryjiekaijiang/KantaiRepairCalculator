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
    dock3 = temp;
}


Dock::Dock(vector<ShipGirl> shipList) {
    vector<ShipGirl> temp;
    dock1 = temp;
    dock2 = temp;
    dock3 = temp;
    
    ShipGirl swapTemp;
    int max;
    temp = shipList;
    
    if (shipList.empty()) {
        this->shipList = temp;
        return;
    }
    
    for (unsigned int i = 0; i < temp.size() - 1; i++) {
        max = i;
        for (unsigned int j = i + 1; j < temp.size(); j++) {
            if (temp.at(i).getTime() < temp.at(j).getTime()) {
                max = j;
            }
        }
        swapTemp = temp.at(i);
        temp.at(i) = temp.at(max);
        temp.at(max) = swapTemp;
    }
    
    this->shipList = temp;
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
int Dock::dock3Sum() const {
    int sum = 0;
    for (int i = 0; i < dock3.size(); i++) {
        sum+= dock3.at(i).getTime();
    }
    return sum;
}

void Dock::checkTwoDocks() {
    assignTwoDocks();
    
    if (shipList.size() <= 2) {
        return;
    }
    
    int iterations;
    //across
    do {
        iterations = 0;
        int highest = getHighest(2);
        
        for (int i = 0; i < dock1.size(); i++) {
            for (int j = 0; j < dock2.size(); j++) {
                highest = getHighest(2);
                ShipGirl temp = dock1.at(i);
                dock1.at(i) = dock2.at(j);
                dock2.at(j) = temp;
                if (getHighest(2) < highest) {
                    iterations++;
                } else {
                    temp = dock1.at(i);
                    dock1.at(i) = dock2.at(j);
                    dock2.at(j) = temp;
                }
            }
        }
    } while (iterations > 0);
    // do {
    //     iterations = 0;
        
    //     for (int i = 0; i < dock1.size(); i++) {
    //         for (int j = 0; j < dock2.size(); j++) {
    //             if (currentDifference > abs(dock1.at(i).getTime() - dock2.at(j).getTime())) {
    //                 ShipGirl swapTemp = dock1.at(i);
    //                 dock1.at(i) = dock2.at(j);
    //                 dock2.at(j) = swapTemp;
    //                 if (currentDifference < abs(dock1Sum() - dock2Sum())) {
    //                     swapTemp = dock1.at(i);
    //                     dock1.at(i) = dock2.at(j);
    //                     dock2.at(j) = swapTemp;
    //                 } else {
    //                     currentDifference = abs(dock1Sum() - dock2Sum());
    //                     iterations++;
    //                 }
    //             }
    //         }
    //     }
    // } while (iterations > 0);
    
    return;
}

void Dock::printDocks(int docks) const {
    cout << "Dock 1:" << endl;
    for (int i = 0; i < dock1.size(); i++) {
        dock1.at(i).display();
    }
	cout << dock1Sum() << endl;
    cout << "Dock 2:" << endl;
    for (int i = 0; i < dock2.size(); i++) {
        dock2.at(i).display();
    }
	cout << dock2Sum() << endl;
    
    if (docks > 2) {
        cout << "Dock 3:" << endl;
        for (int i = 0; i < dock3.size(); i++) {
            dock3.at(i).display();
        }
    	cout << dock3Sum() << endl;
    }
    return;
}



void Dock::assignTwoDocks() {
    int sumDock1;
    int sumDock2;
    //int reversed = 0;
    
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

void Dock::assignThreeDocks() {
    int sumDock1, sumDock2, sumDock3;
    
    for (unsigned int i = 0; i < shipList.size(); i++) {
        sumDock1 = dock1Sum();
        sumDock2 = dock2Sum();
        sumDock3 = dock3Sum();

        if (sumDock1 == sumDock2 && sumDock2 == sumDock3) {
            dock1.push_back(shipList.at(i));
        } else if (sumDock1 < sumDock2 && sumDock1 < sumDock3) {
            dock1.push_back(shipList.at(i));
        } else if (sumDock2 < sumDock1 && sumDock2 < sumDock3) {
            dock2.push_back(shipList.at(i));
        } else if (sumDock3 < sumDock2 && sumDock3 < sumDock1) {
            dock3.push_back(shipList.at(i));
        } else if (sumDock1 < sumDock2 || sumDock1 < sumDock3) {
            dock1.push_back(shipList.at(i));
        } else if (sumDock2 < sumDock1 || sumDock2 < sumDock3) {
            dock2.push_back(shipList.at(i));
        } else if (sumDock3 < sumDock2 || sumDock3 < sumDock1) {
            dock3.push_back(shipList.at(i));
        } else {
            cout << "You forgot a case: " << shipList.at(i).getName() << endl;
            return;
        }
    }
    return;
}

int Dock::getHighest(int docks) const {
    if (docks < 2 || docks > 4) {
        return 0;
    }
    vector<int> temp;
    
    temp.push_back(dock1Sum());
    temp.push_back(dock2Sum());
    if (docks > 2) {
        temp.push_back(dock3Sum());
    }
    int max = dock1Sum();
    for (int i = 0; i < temp.size(); i++) {
        if (max < temp.at(i)) {
            max = temp.at(i);
        }
    }
    
    return max;
}

vector<ShipGirl>* Dock::getHighestDock(int docks) {
    if (docks < 2 || docks > 4) {
        return 0;
    }
    vector<int> temp;
    
    temp.push_back(dock1Sum());
    temp.push_back(dock2Sum());
    if (docks > 2) {
        temp.push_back(dock3Sum());
    }
    
    int max = dock1Sum();
    int maxIndex = 0;
    for (int i = 0; i < temp.size(); i++) {
        if (max < temp.at(i)) {
            max = temp.at(i);
            maxIndex = i;
        }
    }
    vector<ShipGirl>* ptr = &dock1;
    if (maxIndex == 0) {
        return ptr;
    }
    if (maxIndex == 1) {
        ptr = &dock2;
        return ptr;
    }
    if (maxIndex == 2) {
        ptr = &dock3;
        return ptr;
    }
}

void Dock::checkThreeDocks() {
    assignThreeDocks();
    
    if (shipList.size() <= 3) {
        return;
    }
    int iterations;
    //across
    do {
        iterations = 0;
        int highest = getHighest(3);
        vector<ShipGirl>* biggestDock = getHighestDock(3);
        
        for (int i = 0; i < biggestDock->size(); i++) {
            for (int j = 0; biggestDock != &dock1 && j < dock1.size(); j++) {
                highest = getHighest(3);
                ShipGirl temp = biggestDock->at(i);
                biggestDock->at(i) = dock1.at(j);
                dock1.at(j) = temp;
                if (getHighest(3) < highest) {
                    iterations++;
                } else {
                    temp = biggestDock->at(i);
                    biggestDock->at(i) = dock1.at(j);
                    dock1.at(j) = temp;
                }
            }
            for (int j = 0; biggestDock != &dock2 && j < dock2.size(); j++) {
                highest = getHighest(3);
                ShipGirl temp = biggestDock->at(i);
                biggestDock->at(i) = dock2.at(j);
                dock2.at(j) = temp;
                if (getHighest(3) < highest) {
                    iterations++;
                } else {
                    temp = biggestDock->at(i);
                    biggestDock->at(i) = dock2.at(j);
                    dock2.at(j) = temp;
                }
            }
            for (int j = 0; biggestDock != &dock3 && j < dock3.size(); j++) {
                highest = getHighest(3);
                ShipGirl temp = biggestDock->at(i);
                biggestDock->at(i) = dock3.at(j);
                dock3.at(j) = temp;
                if (getHighest(3) < highest) {
                    iterations++;
                } else {
                    temp = biggestDock->at(i);
                    biggestDock->at(i) = dock3.at(j);
                    dock3.at(j) = temp;
                }
            }
        }
    } while (iterations > 0);
    
    return;
}

// void Dock::checkTwoDocks() {
//     assignTwoDocks();
    
//     if (shipList.size() <= 2) {
//         return;
//     }
    
//     int sumDock1 = dock1Sum();
//     int sumDock2 = dock2Sum();
//     int currentDifference = abs(dock1Sum() - dock2Sum());
    
//     //across
//     int iterations;
    
//     do {
//         iterations = 0;
        
//         for (int i = 0; i < dock1.size(); i++) {
//             for (int j = 0; j < dock2.size(); j++) {
//                 if (currentDifference > abs(dock1.at(i).getTime() - dock2.at(j).getTime())) {
//                     ShipGirl swapTemp = dock1.at(i);
//                     dock1.at(i) = dock2.at(j);
//                     dock2.at(j) = swapTemp;
//                     if (currentDifference < abs(dock1Sum() - dock2Sum())) {
//                         swapTemp = dock1.at(i);
//                         dock1.at(i) = dock2.at(j);
//                         dock2.at(j) = swapTemp;
//                     } else {
//                         currentDifference = abs(dock1Sum() - dock2Sum());
//                         iterations++;
//                     }
//                 }
//             }
//         }
//     } while (iterations > 0);
    
//     return;
// }
