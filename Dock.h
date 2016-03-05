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
    vector<ShipGirl> dock4;
    int dockSize;
public:
    Dock();
    Dock(vector<ShipGirl>);
    void checkTwoDocks();
    void checkThreeDocks();
    void checkFourDocks();
    int dock1Sum() const;
    int dock2Sum() const;
    int dock3Sum() const;
    int dock4Sum() const;
    void printDocks(int) const; // update for 4
    vector<ShipGirl> recommendBuckets();
private:
    void assignTwoDocks();
    void assignThreeDocks();
    void assignFourDocks();
    int getHighest(int) const; // update for 4
    vector<ShipGirl>* getHighestDock(int docks);
};

#endif