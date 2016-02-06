#ifndef __DOCK_H__
#define __DOCK_H__

using namespace std;

#include "ShipGirl.h"

class Dock {
private:    
    vector<ShipGirl> shipList;
    vector<ShipGirl> dock1;
    vector<ShipGirl> dock2;
    int dockSize;
public:
    Dock();
    Dock(vector<ShipGirl>);
    void checkTwoDocks();
    int dock1Sum() const;
    int dock2Sum() const;
    void printTwoDocks() const;
private:
    void assignTwoDocks();
};

#endif