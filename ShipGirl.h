#ifndef __SHIPGIRL_H__
#define __SHIPGIRL_H__

using namespace std;

class ShipGirl {
private:
    int repairTime;
    string shipName;
public:
    ShipGirl();
    ShipGirl(int, string);
    int getTime() const;
    string getName() const;
    void display() const;
};

#endif