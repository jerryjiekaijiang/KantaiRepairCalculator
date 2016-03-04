#ifndef __SHIPGIRL_H__
#define __SHIPGIRL_H__

using namespace std;

class ShipGirl {
private:
    int repairTime;
    string shipName;
    bool akashi;
public:
    ShipGirl();
    ShipGirl(int, string);
    ShipGirl(int, string, bool);
    int getTime() const;
    string getName() const;
    bool getAkashi() const;
    void display() const;
};

#endif