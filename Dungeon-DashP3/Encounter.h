#ifndef ENCOUNTER_H
#define ENCOUNTER_H
using namespace std;

class Encounter {
    private:
        int enemies;
        string type;
        int eneLevel;
        int treasure;
        
    public:
        Encounter();
        Encounter(int);
        
        int getEnemies();
        string getType();
        int getTreasure();
        //Driver for encounter using while enemies > 0
        //Fight()
};
#endif