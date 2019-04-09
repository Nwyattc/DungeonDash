#ifndef RANGER_H
#define RANGER_H
using namespace std;

class Ranger {
    private:
        int health;
        int currHealth;
        int attack;
        int level;
        string name;
        //planned 1 more data member to make Ranger unique
        
    public:
        Ranger();
        Ranger(int, int, int, string);
        
        void RsetHealth(int);
        int RgetHealth();
        void RsetCurrHealth(int);
        int RgetCurrHealth();
        
        void RsetAttack(int);
        int RgetAttack();
        void RsetLevel(int);
        int RgetLevel();
        void RsetName(string);
        string RgetName();
        
        //method associated with his special talent
    
};
#endif