#ifndef PARTY_H
#define PARTY_H
#include "Hero.h"
#include "Mage.h"
#include "Paladin.h"
#include "Ranger.h"
#include "Shop.h"
using namespace std;

//PARTY CLASS- Overarching class to control 

class Party {
     
    private:
        int numMembers;
        
        Hero Heroes[10];
        int numHeroes;
        
        Mage Mages[10];
        int numMages;
         
        Paladin Paladins[10];
        int numPaladins;
        
        Ranger Rangers[10];
        int numRangers;
        
        int distance;
        int myGold;
        int myPotions;
        int mySupplies;
        
    public:
        Party();
        
        int getNumMembers();
        
        void setHeroes(int); //add to num and numMembers
        bool makeHero(Hero); //add into obj array
        int getHeroes(); //return numHeroes
        
        void setMages(int);
        bool makeMage(Mage);
        int getMages();
        
        void setPaladins(int);
        bool makePaladin(Paladin);
        int getPaladins();
        
        void setRangers(int);
        bool makeRanger(Ranger);
        int getRangers();
        
        
        void addToDistance(int);
        int getDistance();
        
        
        void setMyGold(int);
        void addToMyGold(int);
        int getMyGold();
        
        void setMyPotions(int);
        int getMyPotions();
        
        void setMySupplies(int);
        int getMySupplies();
        
        void displayParty();
        void displayInventory();
        
        void Heal(int, int);

        void Fight(int, string, int);
        
        void Rest();
        void Damage(int);
        int checkDeath();

};
#endif