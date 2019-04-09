#ifndef HERO_H
#define HERO_H
using namespace std;

class Hero {
    private:
        int health;
        int currHealth;
        int attack;
        int level;
        string name;
        //planned 1 more data member to make hero unique
        
    public:
        Hero();
        Hero(int, int, int, string);
        
        void HsetHealth(int);
        int HgetHealth();
        void HsetCurrHealth(int);
        int HgetCurrHealth();
        
        void HsetAttack(int);
        int HgetAttack();
        void HsetLevel(int);
        int HgetLevel();
        void HsetName(string); //Maybe could set name first
        string HgetName();
        
        //method associated with his special talent
    
};
#endif