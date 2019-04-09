#ifndef PALADIN_H
#define PALADIN_H
using namespace std;

class Paladin {
    private:
        int health;
        int currHealth;
        int attack;
        int level;
        string name;
        //planned 1 more data member to make Paladin unique
        
    public:
        Paladin();
        Paladin(int, int, int, string);
        
        void PsetHealth(int);
        int PgetHealth();
        void PsetCurrHealth(int);
        int PgetCurrHealth();        
        
        void PsetAttack(int);
        int PgetAttack();
        void PsetLevel(int);
        int PgetLevel();
        void PsetName(string);
        string PgetName();
        
        //method associated with his special talent
    
};
#endif