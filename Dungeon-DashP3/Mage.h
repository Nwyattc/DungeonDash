#ifndef MAGE_H
#define MAGE_H
using namespace std;

class Mage {
    private:
        int health;
        int currHealth;
        int attack;
        int level;
        string name;
        //planned 1 more data member to make mage unique
        
    public:
        Mage();
        Mage(int, int, int, string);
        
        void MsetHealth(int);
        int MgetHealth();
        void MsetCurrHealth(int);
        int MgetCurrHealth();
        
        void MsetAttack(int);
        int MgetAttack();
        void MsetLevel(int);
        int MgetLevel();
        void MsetName(string);
        string MgetName();
        
        //method associated with his special talent
    
};
#endif