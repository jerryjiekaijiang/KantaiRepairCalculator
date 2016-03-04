#ifndef __DOCK_H__
#define __DOCK_H__

using namespace std;

#include "ShipGirl.h"

class Dock {
private:    
    vector<ShipGirl> shipList;
    vector<ShipGirl> dock1;
    vector<ShipGirl> dock2;
    vector<ShipGirl> dock3;
    int dockSize;
public:
    Dock();
    Dock(vector<ShipGirl>);
    void checkTwoDocks();
    void checkThreeDocks();
    int dock1Sum() const;
    int dock2Sum() const;
    int dock3Sum() const;
    void printDocks(int) const;
    int getHighest(int) const;
    vector<ShipGirl>* getHighestDock(int docks);
private:
    void assignTwoDocks();
    void assignThreeDocks();
};

#endif