#ifndef SHOP_H
#define SHOP_H
using namespace std;

class Shop {
    private:
        int potions;
        int supplies;
        
        int currGold;
        int boughtP;
        int boughtS;

        //int upgrade[10]; //scrapped
        //int upgradeNum;
        
    public:
        //Shop(); no default constructor
        Shop(int, int);
        
        int buyPotion();
        int showPotion();
        int buySupplies();
        int showSupplies();
        int getCurrGold();
        int getBoughtP();
        int getBoughtS();
        
        
        //int buyUpgrades(int, int); //scrapped?
        //int showUpgrades();
        
};
#endif