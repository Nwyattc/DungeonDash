#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "Party.h"
#include "Hero.h"
#include "Mage.h"
#include "Paladin.h"
#include "Ranger.h"
#include "Shop.h"
using namespace std;

Party::Party(){
    numMembers = 0;
    numHeroes = 0;
    numMages = 0;
    numPaladins = 0;
    numRangers = 0;
    
    distance = 0; //measure of travel
    myGold = 50;
    myPotions = 0;
    mySupplies = 0;
}


//Party functions
int Party::getNumMembers(){
    return numMembers;
}

//HERO
void Party::setHeroes(int num){ //add to num and numMembers
    numHeroes = numHeroes + num;
    numMembers += num;
}
bool Party::makeHero(Hero h){ //add object to array
    int index = numHeroes;
    if(index >= 5) return false;
    Heroes[index] = h;
    return true;
}
int Party::getHeroes(){
    return numHeroes;
}
  
//MAGE        
void Party::setMages(int num){
    numMages = numMages + num;
    numMembers += num;
}
bool Party::makeMage(Mage m){ //add object to array
    int index = getMages();
    if(index >= 5) return false;
    Mages[index] = m; 
    return true;
}
int Party::getMages(){
    return numMages;
}
  
//PALADIN        
void Party::setPaladins(int num){
    numPaladins = numPaladins + num;
    numMembers += num;
}
bool Party::makePaladin(Paladin p){ //add object to array
    int index = getPaladins();
    if(index >= 5) return false;
    Paladins[index] = p; 
    return true;
}
int Party::getPaladins(){
    return numPaladins;
}
       
//RANGER      
void Party::setRangers(int num){
    numRangers = numRangers + num;
    numMembers += num;
}
bool Party::makeRanger(Ranger r){ //add object to array
    int index = getRangers();
    if(index >= 5) return false;
    Rangers[index] = r; 
    return true;
}
int Party::getRangers(){
    return numRangers;
}
////////////////////////////////////////////////////////////////////////////////


//Track progress
void Party::addToDistance(int num){
    distance = distance + num;
}
int Party::getDistance(){
    return distance;
}
////////////////////////////////////////////////////////////////////////////////


//"Inventory"
void Party::setMyGold(int num){
    myGold = num; //may need to be "myGold -= num"
    cout << "You have " << myGold << " gold in your bag\n";
}
void Party::addToMyGold(int num){
    myGold += num;
    cout << "You have " << myGold << " gold in your bag\n";
}
int Party::getMyGold(){
    return myGold;
}

void Party::setMyPotions(int num){
    myPotions += num;
    cout << "You have " << myPotions << " potion(s) in your bag\n";
}
int Party::getMyPotions(){
    return myPotions;
}

void Party::setMySupplies(int num){
    mySupplies += num;
    if(mySupplies < 0) mySupplies = 0;
    cout << "You have " << mySupplies << " supplie(s) in your bag\n\n";
}
int Party::getMySupplies(){
    return mySupplies;
}
////////////////////////////////////////////////////////////////////////////////


//Display Party
void Party::displayParty(){
    cout << "Your Party: \n";
    for(int i = 0; i < numHeroes; i++) //Hero
    {
        int CH = Heroes[i].HgetCurrHealth();
        int MH = Heroes[i].HgetHealth();
        cout << "Hero" << i << "    " << "(lvl " << Heroes[i].HgetLevel() << ")" << " has " << CH << "/" << MH << " health and " << Heroes[i].HgetAttack() << " attack" << endl;
    }
    for(int i = 0; i < numMages; i++) //Mage
    {
        int CH = Mages[i].MgetCurrHealth();
        int MH = Mages[i].MgetHealth();
        cout << "Mage" << i << "    " << "(lvl " << Mages[i].MgetLevel() << ")" << " has " << CH << "/" << MH << " health and " << Mages[i].MgetAttack() << " attack" << endl;
    }
    for(int i = 0; i < numPaladins; i++) //Paladin
    {
        int CH = Paladins[i].PgetCurrHealth();
        int MH = Paladins[i].PgetHealth();
        cout << "Paladin" << i << " " << "(lvl " << Paladins[i].PgetLevel() << ")" << " has " << CH << "/" << MH << " health and " << Paladins[i].PgetAttack() << " attack" << endl;
    }
    for(int i = 0; i < numRangers; i++) //Ranger
    {
        int CH = Rangers[i].RgetCurrHealth();
        int MH = Rangers[i].RgetHealth();
        cout << "Ranger" << i << "  " << "(lvl " << Rangers[i].RgetLevel() << ")" <<  " has " << CH << "/" << MH << " health and " << Rangers[i].RgetAttack() << " attack" << endl;
    }
    cout << endl;
}
////////////////////////////////////////////////////////////////////////////////


//Display Inventory
void Party::displayInventory(){
    cout << "Gold:     " << myGold << "\nPotions:  " << myPotions << "\nSupplies: " << mySupplies << endl;
}
////////////////////////////////////////////////////////////////////////////////

//Function to heal
void Party::Heal(int cls, int indx){
    if(cls == 1){
        //HOW TO CHECK IF EXIST
        if(indx > (numPaladins - 1)){ //check if exist
            cout << "That character doesn't exist!\n\n";
            return;
        }
        Paladins[indx].PsetCurrHealth(5); //set the health 
        int CH = Paladins[indx].PgetCurrHealth(); //display
        int MH = Paladins[indx].PgetHealth();
        cout << "\nPaladin" << indx << "'s health is now " << CH << "/" << MH << endl;
    }
    if(cls == 2){
        if(indx > (numHeroes - 1)){ //check if exist
            cout << "That character doesn't exist!\n\n";
            return;
        }
        Heroes[indx].HsetCurrHealth(5);
        int CH = Heroes[indx].HgetCurrHealth();
        int MH = Heroes[indx].HgetHealth();
        cout << "\nHero" << indx << "'s health is now " << CH << "/" << MH << endl;
    }
    if(cls == 3){
        if(indx > (numRangers - 1)){ //check if exist
            cout << "That character doesn't exist!\n\n";
            return;
        }
        Rangers[indx].RsetCurrHealth(5);
        int CH = Rangers[indx].RgetCurrHealth();
        int MH = Rangers[indx].RgetHealth();
        cout << "\nRanger" << indx << "'s health is now " << CH << "/" << MH << endl;
    }
    if(cls == 4){
        if(indx > (numMages - 1)){ //check if exist
            cout << "That character doesn't exist!\n\n";
            return;
        }
        Mages[indx].MsetCurrHealth(5);
        int CH = Mages[indx].MgetCurrHealth();
        int MH = Mages[indx].MgetHealth();
        cout << "\nMage" << indx << "'s health is now " << CH << "/" << MH << endl;
    }
    myPotions--;
    cout << "You have " << myPotions << " potions left.\n";
}
////////////////////////////////////////////////////////////////////////////////


void Party::Fight(int Enum, string Etype, int Etreas){
    ///////////SKELETONS
    if(Etype == "Skeletons"){
        cout << "You run into " << Enum << " Skeleton(s)! Do you fight or run?\nFight (Y) ----- Run (N)  ";
        string x;
        getline(cin, x);
        while(x != "Y" && x!= "y" && x!= "N" && x!= "n"){
            cout << "Please enter a valid input:  ";
            getline(cin, x);
        }
        if(x == "Y" || x == "y"){
            int partyAttack = 0;
            for(int i = 0; i < numHeroes; i++){
                partyAttack += Heroes[i].HgetAttack();
            }
            for(int i = 0; i < numMages; i++){
                partyAttack += Mages[i].MgetAttack();
            }
            for(int i = 0; i < numPaladins; i++){
                partyAttack += Paladins[i].PgetAttack();
            }
            for(int i = 0; i < numRangers; i++){
                partyAttack += Rangers[i].RgetAttack();
            }
            //cout << "PA:" << partyAttack << endl; //FLAG
            
            if(partyAttack >= (Enum * 3)){
                cout << "Your party overpowers and destroys the skeleton(s), taking little damage\n";
                for(int i = 0; i < numHeroes; i++){
                    Heroes[i].HsetCurrHealth(-1);
                }
                for(int i = 0; i < numMages; i++){
                    Mages[i].MsetCurrHealth(-1);
                }
                for(int i = 0; i < numPaladins; i++){
                    Paladins[i].PsetCurrHealth(-1);
                }
                for(int i = 0; i < numRangers; i++){
                    Rangers[i].RsetCurrHealth(-1);
                }
            }
            else if(partyAttack < (Enum * 3)){
                int dmg = rand() % 2 + 2;
                cout << "Your party fights hard and defeats the skeleton(s), taking significant damage\n";
                for(int i = 0; i < numHeroes; i++){
                    Heroes[i].HsetCurrHealth(-1*dmg);
                }
                for(int i = 0; i < numMages; i++){
                    Mages[i].MsetCurrHealth(-1*dmg);
                }
                for(int i = 0; i < numPaladins; i++){
                    Paladins[i].PsetCurrHealth(-1*dmg);
                }
                for(int i = 0; i < numRangers; i++){
                    Rangers[i].RsetCurrHealth(-1*dmg);
                }
            }
            cout << "You find some treasure on the skeletons' remains too\n";
            if(Etreas == 1){
                cout << "You find 10 gold\n";
                myGold += 10;
            }
            if(Etreas == 2){
                cout << "You found a potion\n";
                myPotions++;
            }
            if(Etreas == 3){
                cout << "You find some supplies\n";
                mySupplies += (2*numMembers);
            }
        }
        if(x == "N" || x == "n"){ //FLEE
            cout << "Your party flees backwards, losing some progress to your destination!\n";
            distance -= 3;
        }
    }
    
    ////////////BANDITS
    else if(Etype == "Bandits"){
        cout << "You run into " << Enum << " Bandits! They are too fast to run from but will take your gold in "
        "exchange for leaving you alone. Do you fight or be robbed?\nFight (Y) ----- Give gold (N)  ";
        string x;
        getline(cin, x);
        while(x != "Y" && x!= "y" && x!= "N" && x!= "n"){
            cout << "Please enter a valid input:  ";
            getline(cin, x);
        }
        if(x == "Y" || x == "y"){
            int partyAttack = 0;
            for(int i = 0; i < numHeroes; i++){
                partyAttack += Heroes[i].HgetAttack();
            }
            for(int i = 0; i < numMages; i++){
                partyAttack += Mages[i].MgetAttack();
            }
            for(int i = 0; i < numPaladins; i++){
                partyAttack += Paladins[i].PgetAttack();
            }
            for(int i = 0; i < numRangers; i++){
                partyAttack += Rangers[i].RgetAttack();
            }
            //cout << "PA:" << partyAttack << endl; //FLAG
            if(partyAttack >= (Enum * 4)){ //if party attack is high enough
                cout << "Your party easily beats down the bandits, taking no damage.\n";
            }
            else if(partyAttack < (Enum * 4)){
                cout << "Your party fights hard, routing the bandits but taking some damage.\n";
                for(int i = 0; i < numHeroes; i++){
                    Heroes[i].HsetCurrHealth(-2);
                }
                for(int i = 0; i < numMages; i++){
                    Mages[i].MsetCurrHealth(-2);
                }
                for(int i = 0; i < numPaladins; i++){
                    Paladins[i].PsetCurrHealth(-2);
                }
                for(int i = 0; i < numRangers; i++){
                    Rangers[i].RsetCurrHealth(-2);
                }
            }
            cout << "You find some treasure on the bandits too\n";
            if(Etreas == 1){
                cout << "You find 10 gold\n";
                myGold += 10;
            }
            if(Etreas == 2){
                cout << "You found a potion\n";
                myPotions++;
            }
            if(Etreas == 3){
                cout << "You find some supplies\n";
                mySupplies += (2*numMembers);
            }
        }
        if(x == "N" || x == "n"){ //FLEE
            if(myGold < (Enum * 2)){
                cout << "You don't have enough gold for them! You have to fight!\n"; //Copied the other attack code
                int partyAttack = 0;
                cout << "numHeroes " << numHeroes << endl;
                for(int i = 0; i < numHeroes; i++){
                    //cout << "HA: " << Heroes[i].HgetAttack() << endl; //FLAG
                    partyAttack += Heroes[i].HgetAttack();
                }
                for(int i = 0; i < numMages; i++){
                    partyAttack += Mages[i].MgetAttack();
                }
                for(int i = 0; i < numPaladins; i++){
                    //cout << "PalaA: " << Paladins[i].PgetAttack() << endl; //FLAG
                    partyAttack += Paladins[i].PgetAttack();
                }
                for(int i = 0; i < numRangers; i++){
                    partyAttack += Rangers[i].RgetAttack();
                }
                //cout << "PA:" << partyAttack << endl; //FLAG
                if(partyAttack >= (Enum * 4)){ //if party attack is high enough
                    cout << "Your party easily beats down the bandits, taking no damage.\n";
                }
                else if(partyAttack < (Enum * 4)){
                    cout << "Your party fights hard, routing the bandits but taking some damage.\n";
                    for(int i = 0; i < numHeroes; i++){
                        Heroes[i].HsetCurrHealth(-2);
                    }
                    for(int i = 0; i < numMages; i++){
                        Mages[i].MsetCurrHealth(-2);
                    }
                    for(int i = 0; i < numPaladins; i++){
                        Paladins[i].PsetCurrHealth(-2);
                    }
                    for(int i = 0; i < numRangers; i++){
                        Rangers[i].RsetCurrHealth(-2);
                    }
                }
                cout << "You find some treasure on the bandits too\n";
                if(Etreas == 1){
                    cout << "You find 10 gold\n";
                    myGold += 10;
                }
                if(Etreas == 2){
                    cout << "You found a potion\n";
                    myPotions++;
                }
                if(Etreas == 3){
                    cout << "You find some supplies\n";
                    mySupplies += (2*numMembers);
                }
            }
            else if(myGold >= (Enum * 2)){
                cout << "You lose " << Enum * 2 << " gold, but leave unscathed.\n";
                myGold -= (Enum * 2);
            }
        }
    }
    
    ///////////TRAP
    else if(Etype == "Trap"){
        int avoid = rand() % 3 + 1;
        cout << "You were caught in a trap that shoots darts from the walls!\n";
        if(avoid == 1 || avoid == 2){
            for(int i = 0; i < numHeroes; i++){
                Heroes[i].HsetCurrHealth(-2);
            }
            for(int i = 0; i < numMages; i++){
                Mages[i].MsetCurrHealth(-2);
            }
            for(int i = 0; i < numPaladins; i++){
                Paladins[i].PsetCurrHealth(-2);
            }
            for(int i = 0; i < numRangers; i++){
                Rangers[i].RsetCurrHealth(-2);
            }
            cout << "Your party members all took 2 damage!\n";
        }
        if(avoid == 3){
            cout << "Your party avoided the darts and found some loot!\n";
            if(Etreas == 1){
                cout << "You find 10 gold\n";
                myGold += 10;
            }
            if(Etreas == 2){
                cout << "You found a potion\n";
                myPotions++;
            }
            if(Etreas == 3){
                cout << "You find some supplies\n";
                mySupplies += (2*numMembers);
            }
        }
    }
    
    ///////////OBSTACLE
    else if(Etype == "Obstacle"){
        cout << "Your party runs into a large field of boulders, would you like to take time and supplies to go around "
        "or try to climb over?\nRisk the climb (Y) ----- Go around (N)\n";
        string x;
        getline(cin, x);
        while(x != "Y" && x!= "y" && x!= "N" && x!= "n"){
            cout << "Please enter a valid input:  ";
            getline(cin, x);
        }
        if(x == "Y" || x == "y"){
            int dmg = rand() % 2 + 1;
            if(dmg == 1){
                for(int i = 0; i < numHeroes; i++){
                    Heroes[i].HsetCurrHealth(-1);
                }
                for(int i = 0; i < numMages; i++){
                    Mages[i].MsetCurrHealth(-1);
                }
                for(int i = 0; i < numPaladins; i++){
                    Paladins[i].PsetCurrHealth(-1);
                }
                for(int i = 0; i < numRangers; i++){
                    Rangers[i].RsetCurrHealth(-1);
                }
                cout << "Your party members all took 1 damage climbing the boulders!\n";
            }
            else if(dmg == 2){
                cout << "Your party safely naviagated the boulders\n";
            }
        }
        if(x == "N" || x == "n"){
            cout << "Your party safely makes it around the boulderfield but uses supplies to do so.\n";
            mySupplies -= (-1*numMembers);
        }
    }
}
////////////////////////////////////////////////////////////////////////////////

void Party::Rest(){
    if(mySupplies < numMembers){
        cout << "You don't have enough supplies to rest!\n";
        return;
    }
    else{
        cout << "You take a few hours to rest and eat and recover HP\n";
        mySupplies -= numMembers;
        for(int i = 0; i < numHeroes; i++){
            Heroes[i].HsetCurrHealth(2);
        }
        for(int i = 0; i < numMages; i++){
            Mages[i].MsetCurrHealth(2);
        }
        for(int i = 0; i < numPaladins; i++){
            Paladins[i].PsetCurrHealth(2);
        }
        for(int i = 0; i < numRangers; i++){
            Rangers[i].RsetCurrHealth(2);
        }
    }
}
////////////////////////////////////////////////////////////////////////////////

void Party::Damage(int x){ //party takes x amount of damage
    for(int i = 0; i < numHeroes; i++){
        Heroes[i].HsetCurrHealth(-1*x);
    }
    for(int i = 0; i < numMages; i++){
        Mages[i].MsetCurrHealth(-1*x);
    }
    for(int i = 0; i < numPaladins; i++){
        Paladins[i].PsetCurrHealth(-1*x);
    }
    for(int i = 0; i < numRangers; i++){
        Rangers[i].RsetCurrHealth(-1*x);
    }
}
////////////////////////////////////////////////////////////////////////////////

int Party::checkDeath(){
    for(int i = 0; i < numHeroes; i++){
        if(Heroes[i].HgetCurrHealth() < 1){
            cout << "\nHero" << i << " has perished. He will be remembered.\n\n";
            for(int j = i + 1; j < numHeroes; j++){
                Heroes[j - 1] = Heroes[j];
            }
            numMembers--;
            numHeroes--;
        }    
    }
    for(int i = 0; i < numMages; i++){
        if(Mages[i].MgetCurrHealth() < 1){
            cout << "\nMage" << i << " has perished. He will be remembered.\n\n";
            for(int j = i + 1; j < numMages; j++){
                Mages[j - 1] = Mages[j];
            }
            numMembers--;
            numMages--;
        }   
    }
    for(int i = 0; i < numPaladins; i++){
        if(Paladins[i].PgetCurrHealth() < 1){
            cout << "\nPaladin" << i << " has perished. He will be remembered.\n\n";
            for(int j = i + 1; j < numPaladins; j++){
                Paladins[j - 1] = Paladins[j];
            }
            numMembers--;
            numPaladins--;
        }
    }
    for(int i = 0; i < numRangers; i++){
        if(Rangers[i].RgetCurrHealth() < 1){
            cout << "\nRanger" << i << " has perished. He will be remembered.\n\n";
            for(int j = i + 1; j < numRangers; j++){
                Rangers[j - 1] = Rangers[j];
            }
            numMembers--;
            numRangers--;
        }
    }
}