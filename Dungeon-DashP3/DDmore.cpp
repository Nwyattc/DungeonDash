//Dungeon Dash driver/main file

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include "Shop.h"
#include "Party.h"
#include "Shop.h"
#include "Hero.h"
#include "Mage.h"
#include "Paladin.h"
#include "Ranger.h"
#include "Encounter.h"
using namespace std;

//SELF NOTES: 
        //File input output for milestones as well as ending Stats
        //Limit text to about 90 characters
        //Party& means pass by reference so other functions can see the changes

//Simple beginning message
void beginMessage(){
    cout << "\nWelcome to Dungeon Dash! In this game you must take a party of adventurers through a deadly \n";
    cout << "dungeon filled with monsters, traps, and obstacles, and emerge with as much gold as possible. \n\n";
    cout << "To begin you will be taken to the first shop where you can choose which classes of adventurers \nto take with ";
    cout << "you and buy rations and other items to keep you alive in the dungeon. \nGood luck!\n\n";
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MILEFILE
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mileFile(){ //milestones
    string milestones[3] = {"Nordor", "Shopopilus", "The Lonely Cave"};
    ofstream mlstnFile;
    mlstnFile.open("milestones.txt");
    
    if(!mlstnFile){
        cout << "File opening failed.\n";
    }
    else{
        cout << "Successful file open.\n";
        for(int i = 0; i < 3; i++)
        {
            string info = milestones[i];
            mlstnFile << info << endl;
        }
    }
    mlstnFile.close();
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MILEEVENT
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Special event for each milestone
void mileEvent(string x, Party& Party1){
    if(x == "Nordor"){
        int guessnum = 0; //3 guesses
        cout << "\nYour path is block once again by a large door. You see written on the door is a simple question:\n"
        "-What is light as a feather, but becomes harder to hold the longer you hold it?-\n\n"
        "You see a stick of charcoal indicating you are to write a word to answer the riddle on the door\n"
        "What do you write?(all lower case) :  ";
        string guess;
        while(guessnum != 2){
            getline(cin, guess);
            if(guess == "breath" && guessnum == 0){ //1st try
                cout << "\nA hidden compartment in the wall opens up, revealing 25 gold and 10 supplies, and the door opens\n";
                Party1.addToMyGold(25);
                Party1.setMySupplies(10);
                Party1.addToDistance(1);
                return;
            }
            else if(guess == "breath" && guessnum == 1){ //2nd try
                cout << "\nThe door opens and lets you pass\n";
                Party1.addToDistance(1);
                return;
            }
            else if(guess != "breath" && guessnum == 0){
                cout << "\nThe text on the door changes. 'You may try once more, but that is it': ";
            }
            else if(guess != "breath" && guessnum == 1){
                cout << "\nJets of flame suddenly burst up from the ground! Your party runs back the way they came,\nbut are scorched and take 2 damage\n";
                Party1.Damage(2);
                Party1.checkDeath();
                return;
            }
            guessnum++;
        }
        
    }
    /**if(x == "Shopopilus"){
        cout << 
    }
    if(x == "The Lonely Cave"){
        cout << 
    }*/
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//NEWMEMBER
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Introduce a new character to the party
void newMember(int x, Party& Party1){ 
    
    if(Party1.getNumMembers() == 5){ //Extra catch for making sure the party isnt full
        cout << "Party is full.\n";
        return;
    }
    
    if(x == 1){
        Paladin P1;
        Party1.makePaladin(P1); //Add a paladin object to the array
        Party1.setPaladins(1); //Add 1 to numPaladins
    }
    else if(x == 2){
        Hero H1;
        Party1.makeHero(H1);
        Party1.setHeroes(1);
    }
    else if(x == 3){
        Ranger R1;
        Party1.makeRanger(R1);
        Party1.setRangers(1);
    }
    else if(x == 4){
        Mage M1;
        Party1.makeMage(M1);
        Party1.setMages(1);
    }
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//INTROSHOP
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Build the party using party and shop objects
void introShop(Party& Party1){
    //Party Party1; //probably don't need
    cout << "To get through the dungeon you must build a party of adventurers of a variety of specialties. \n";
    cout << "Please choose 2 characters out of the 4 classes of adventurers to start with. You will encounter\n";
    cout << "more travelers inside of the dungeon to bolster your party with up to 5 members.\n";
    cout << "You can choose from these for characters arranged from most health and least attack to least\n";
    cout << "health and most attack.\n\n";
    
    for(int i = 0; i < 2; i++)
    {
        cout << "You have " << (2 - i) << " picks left.\nPaladin: 10 Health - 1 Attack (1)\n"
        "Hero:     8 Health - 2 Attack (2)\nRanger:   6 Health - 3 Attack (3)\nMage:     4 Health - 4 Attack (4)\n\n";
        string x;
        getline(cin, x); //always use getline and stoi instead of just cin
        while(x != "1" && x != "2" && x != "3" && x != "4") //input validation loop
        { 
            cout << "Please enter 1, 2, 3, or 4\n";
            cout << "You have " << (2 - i) << " picks left.\nPaladin: 10 Health - 1 Attack (1)\n"
            "Hero:     8 Health - 2 Attack (2)\nRanger:   6 Health - 3 Attack (3)\nMage:     4 Health - 4 Attack (4)\n\n";
            getline(cin, x);
        }
        int y = stoi(x);
        newMember(y, Party1);
    }
    
    //First shop
    cout << "Good choices!   Now you will be taken to your first shop. Shops sell supplies and potions.\n-Supplies are your "
    "food and water and general things to keep you alive. They will be used up as\nyou traverse the dungeon. Running out means "
    "your party will lose health until they all perish.\n-Potions are used to heal members of your party when they take damage "
    "in battle or due to traps\nand obstacles. You have 50 gold to start out with. Use it wisely.\n\n";
    
    Shop beginShop(5, 50); //Beginning level 5 shop to get first supplies
    Party1.setMyGold(beginShop.getCurrGold()); //Set Party's gold to currGold from Shop.h
    Party1.setMyPotions(beginShop.getBoughtP());
    Party1.setMySupplies(beginShop.getBoughtS()); //I know I shouldnt have done the functionality in the constructor so I could return things
    
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//GAMEMENU
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int gameMenu(){
    cout << "~~~~ Menu ~~~~\nTravel Quickly (1)\nTravel Slowly  (2)\nRest           (3)\nHeal           (4)\nExplore        (5)\n"
    "Display Party  (6)\nDisplay Bag    (7)\nQuit           (8)\n";
    string x;
    getline(cin, x);
    while(x != "1" && x != "2" && x != "3" && x != "4" && x != "5" && x != "6" && x != "7" && x != "8"){
        cout << "\nPlease enter a valid input  ";
        getline(cin, x);
    }
    int y = stoi(x);
    cout << endl;
    return y;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//HEAL
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Heal(Party& Party1){
    bool heel = true; //exit condition for heal
    while(heel == true)
    {
        if(Party1.getMyPotions() == 0){
            cout << "You have no potions!\n";
            return;
        }
        Party1.displayParty();
        cout << "Enter the class and the number of the character you would like to heal\n";
        cout << "Class: Paladin(1), Hero(2), Ranger(3), Mage(4), Quit(5)-  ";
        string cls;
        getline(cin, cls);
        if(cls == "5") return;
        while(cls != "1" && cls != "2" && cls != "3" && cls != "4"){
            cout << "Please enter a valid class:  ";
            getline(cin, cls);
        }
        int x = stoi(cls);
        cout << "\nNumber/Index: 0,1,2,3,4 -  ";
        string indx;
        getline(cin, indx);
        while(indx != "0" && indx != "1" && indx != "2" && indx != "3" && indx != "4"){
            cout << "Please enter a valid number:  ";
            getline(cin, indx);
        }
        int y = stoi(indx);
        Party1.Heal(x,y);
    }
    
    
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DUNGEONRNG
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int DungeonRNG(Party& Party1, int x){ //Roll the dice to return a number signifying what will happen
    int num = rand() % 20 + 1; //like rolling 20 sided die
    //cout <<  "x: " << x << "  Num: " << num << endl;
    
    if(x == 1){ //quick
        if(num <= 10) return 1; //encounter
        else if(num > 10 && num <= 15) return 2; //nothing
        else if(num > 15 && num <= 18) return 3; //treasure
        else if(num == 19) return 4; //shop
        if(num == 20 && Party1.getNumMembers() < 5) return 5; //newmember
        else if(num == 20 && Party1.getNumMembers() == 5) return 3; //treasure for if party is full
    }
    else if(x == 2){ //slow
        if(num <= 6) return 1; //encounter
        else if(num > 6 && num <= 13) return 2; //nothing
        else if(num > 13 && num <= 18) return 3; //treasure
        else if(num == 19) return 4; //shop
        if(num == 20 && Party1.getNumMembers() < 5) return 5; //newmember
        else if(num == 20 && Party1.getNumMembers() == 5) return 3; //treasure
    }
    else if(x == 3){ //rest
        if(num <= 5) return 1; //encounter
        else if(num > 5) return 2; //nothing
    }
    else if(x == 4){ //explore
        if(num <= 6) return 1; //encounter
        else if(num > 6 && num <= 10) return 2; //nothing
        else if(num > 10 && num <= 18) return 3; //treasure
        else if(num == 19) return 4; //shop
        if(num == 20 && Party1.getNumMembers() < 5) return 5; //newmember
        else if(num == 20 && Party1.getNumMembers() == 5) return 3; //treasure
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Dungeon- Actual gameplay driven by while loop   //lots of distance dependent stuff planned
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Dungeon(Party& Party1){
    cout << "You make your way with your party to a huge stone door. You see it's covered entirely by strange runes\n"
    "that appear occult. You go to open the door but it suddenly swings open as if taunting you. You step\nthrough the doorway "
    "and begin down a long tunnel...\n\n";
    cout << "In the dungeon you have a few options-\n-'Travel quickly' which brings you closer to the end but"
    "makes you more likely to encounter\nenemies and stumble into traps but less likely to find treasure.\n"
    "-'Travel slowly' will cause you to cover half the distance but you will find more treasure\nand be more on guard so you'll "
    "come across fewer hostile encounters\n-'Rest' will use up supplies same as traveling does to recover health of your party "
    "but\nyou are still at risk of being attacked by enemies.\n-'Heal' lets you use potions on injured party members\n"
    "-'Explore' lets you search the surrounding area for a high chance of treasure with a low\nchance of hostiles (still "
    "uses supplies)\n\n";
    ifstream mlstnFile;
    mlstnFile.open("milestones.txt");
    int mls = 0; //milestones counter
    while(Party1.getDistance() < 40) //loop of game break as soon as end is broken
    {
        if(Party1.getDistance() == 20 || Party1.getDistance() == 30 || Party1.getDistance() == 38){ //Milestones (can be missed on purpose)
            Party1.addToDistance(1);
            mls++;
            string line;
            getline(mlstnFile, line);
            cout << "You have found the landmark of " << line << endl;
            mileEvent(line, Party1);
        }
        cout << "Distance: " << Party1.getDistance() << endl; //FLAG
        
        int type; //what actually happens due to the choice
        int encType; //1-4 type of hostile encounter for encounter.cpp
        int choice = gameMenu(); //GAMEMENU ***
        
        //TYPE: 1:Encounter, 2:Nothing, 3:Treasure, 4:Shop, 5:newMember
        
        if(choice == 1) //TRAVEL QUICKLY
        {
            type = DungeonRNG(Party1,1); //Get the type of encounter based on varying rng values
            if(type == 1){
                encType = rand() % 4 + 1;
                Encounter Enc1(encType); //get the number of enemies, type, and treasure kind
                int Enum = Enc1.getEnemies();
                string Etype = Enc1.getType();
                int Etreas = Enc1.getTreasure();
                Party1.Fight(Enum, Etype, Etreas); //fight function in party.cpp
            }
            else if(type == 2){
                cout << "You progress without trouble.\n";
            }
            else if(type == 3){
                int tre = rand() % 2 + 1;
                if(tre == 1){
                    cout << "You found 5 gold and 6 supplies in an abandoned structure\n";
                    Party1.addToMyGold(5);
                    Party1.setMySupplies(6);
                }
                else if(tre == 2){
                    cout << "You found 1 potion and 4 supplies on the scene of a past fight\n";
                    Party1.setMyPotions(1);
                    Party1.setMySupplies(4);
                }
            }
            else if(type == 4){
                cout << "You come across a small shack that seems to be a shop of sorts\n";
                int shplvl = rand() % 3 + 1;
                Shop shp(shplvl, (Party1.getMyGold()));
                Party1.setMyGold(shp.getCurrGold()); //Set Party's gold to currGold from Shop.h
                Party1.setMyPotions(shp.getBoughtP());
                Party1.setMySupplies(shp.getBoughtS());
            }
            else if(type == 5){
                int pclass = rand() % 4 + 1; //determine which class
                string cls = ""; //for flavor text and so you know which class you get
                if(pclass == 1) cls = "Paladin";
                else if(pclass == 2) cls = "Hero";
                else if(pclass == 3) cls = "Ranger";
                else if(pclass == 4) cls = "Mage";
                cout << "Your party comes across a badly injured adventurer slumped over surrounded by a puddle of\n"
                "blood. Do you use 2 potions to heal him or leave him to his fate? \nHeal (Y) ----- Move on (N)  ";
                string x;
                getline(cin, x);
                while(x != "Y" && x!= "y" && x!= "N" && x!= "n"){
                    cout << "Please enter a valid input:  ";
                    getline(cin, x);
                }
                if(x == "Y" || x == "y"){
                    if(Party1.getMyPotions() < 2){
                        cout << "You don't have enough potions to heal the fallen adventurer. You must move on\n";
                    }
                    else{
                        Party1.setMyPotions(-2);
                        cout << "You heal the traveler and see that they are a " << cls << ". They are so greatful "
                        "that they decide to join forces and get out together.\n";
                        newMember(pclass, Party1);
                    }
                }
            }
            Party1.addToDistance(2); //add to distance counter
            Party1.setMySupplies(-1*(Party1.getNumMembers())); //take away from supplies for each member
        }
            
        if(choice == 2) //TRAVEL SLOWLY
        {
            type = DungeonRNG(Party1,2);  
            if(type == 1){ //
                encType = rand() % 4 + 1;
                Encounter Enc2(encType); 
                int Enum = Enc2.getEnemies();
                string Etype = Enc2.getType();
                int Etreas = Enc2.getTreasure();
                Party1.Fight(Enum, Etype, Etreas);
            }
            else if(type == 2){ 
                cout << "You progress without trouble.\n";
            }
            else if(type == 3){
                int tre = rand() % 2 + 1;
                if(tre == 1){
                    cout << "You found 5 gold and 6 supplies in an abandoned structure\n";
                    Party1.addToMyGold(5);
                    Party1.setMySupplies(6);
                }
                else if(tre == 2){
                    cout << "You found 1 potion and 4 supplies on the scene of a past fight\n";
                    Party1.setMyPotions(1);
                    Party1.setMySupplies(4);
                }
            }
            else if(type == 4){
                cout << "You come across a small shack that seems to be a shop of sorts\n";
                int shplvl = rand() % 3 + 1;
                Shop shp(shplvl, (Party1.getMyGold()));
                Party1.setMyGold(shp.getCurrGold()); //Set Party's gold to currGold from Shop.h
                Party1.setMyPotions(shp.getBoughtP());
                Party1.setMySupplies(shp.getBoughtS());
            }
            else if(type == 5){
                int pclass = rand() % 4 + 1; //determine which class
                string cls = ""; //for flavor text and so you know which class you get
                if(pclass == 1) cls = "Paladin";
                else if(pclass == 2) cls = "Hero";
                else if(pclass == 3) cls = "Ranger";
                else if(pclass == 4) cls = "Mage";
                cout << "Your party comes across a badly injured adventurer slumped over surrounded by a puddle of\n"
                "blood. Do you use 2 potions to heal him or leave him to his fate? \nHeal (Y) ----- Move on (N)  ";
                string x;
                getline(cin, x);
                while(x != "Y" && x!= "y" && x!= "N" && x!= "n"){
                    cout << "Please enter a valid input:  ";
                    getline(cin, x);
                }
                if(x == "Y" || x == "y"){
                    if(Party1.getMyPotions() < 2){
                        cout << "You don't have enough potions to heal the fallen adventurer. You must move on\n";
                    }
                    else{
                        Party1.setMyPotions(-2);
                        cout << "You heal the traveler and see that they are a " << cls << ". They are so greatful "
                        "that they decide to join forces and get out together.\n";
                        newMember(pclass, Party1);
                    }
                }
            }
            Party1.addToDistance(1);
            Party1.setMySupplies(-1*(Party1.getNumMembers()));
        }
            
        if(choice == 3) //REST
        { 
            type = DungeonRNG(Party1,3);//Party1.rest()
            cout << "Type: " << type << endl;
            if(type == 1){
                encType = rand() % 4 + 1;
                Encounter Enc3(encType);
                int Enum = Enc3.getEnemies();
                string Etype = Enc3.getType();
                int Etreas = Enc3.getTreasure();
                if(Etype != "Skeletons" || Etype != "Bandits"){ //no trap/obstacle
                    int ran = rand() % 2 + 1;
                    if(ran == 1) Etype = "Skeletons";
                    else if(ran == 2) Etype = "Bandits";
                }
                Party1.Fight(Enum, Etype, Etreas);
            }
            else if(type == 2){
                cout << "You spend some time and supplies resting to recover health\n";
                Party1.Rest();
            }
            Party1.setMySupplies(-1*(Party1.getNumMembers()));
        }
                
        if(choice == 4) //HEAL
        {
            Heal(Party1);
        }
                
        if(choice == 5) //EXPLORE
        { 
            type = DungeonRNG(Party1,4);  
            if(type == 1){ //ENCOUNTER
                encType = rand() % 4 + 1;
                Encounter Enc3(encType);
                int Enum = Enc3.getEnemies();
                string Etype = Enc3.getType();
                int Etreas = Enc3.getTreasure();
                Party1.Fight(Enum, Etype, Etreas);
            }
            else if(type == 2){
                cout << "Your search turns up nothing.\n";
            }
            else if(type == 3){
                int tre = rand() % 2 + 1;
                if(tre == 1){
                    cout << "You found 10 gold and 10 supplies hidden in an abandoned structure\n";
                    Party1.addToMyGold(10);
                    Party1.setMySupplies(10);
                }
                else if(tre == 2){
                    cout << "You found 2 potions and 8 supplies hidden in a secret stash.\n";
                    Party1.setMyPotions(2);
                    Party1.setMySupplies(8);
                }
            }
            else if(type == 4){
                cout << "You come across a small shack that seems to be a shop of sorts\n";
                int shplvl = rand() % 3 + 1;
                Shop shp(shplvl, (Party1.getMyGold()));
                Party1.setMyGold(shp.getCurrGold()); //Set Party's gold to currGold from Shop.h
                Party1.setMyPotions(shp.getBoughtP());
                Party1.setMySupplies(shp.getBoughtS());
            }
            else if(type == 5){
                int pclass = rand() % 4 + 1; //determine which class
                string cls = ""; //for flavor text and so you know which class you get
                if(pclass == 1) cls = "Paladin";
                else if(pclass == 2) cls = "Hero";
                else if(pclass == 3) cls = "Ranger";
                else if(pclass == 4) cls = "Mage";
                cout << "Your party comes across a badly injured adventurer slumped over surrounded by a puddle of\n"
                "blood. Do you use 2 potions to heal him or leave him to his fate? \nHeal (Y) ----- Move on (N)  ";
                string x;
                getline(cin, x);
                while(x != "Y" && x!= "y" && x!= "N" && x!= "n"){
                    cout << "Please enter a valid input:  ";
                    getline(cin, x);
                }
                if(x == "Y" || x == "y"){
                    if(Party1.getMyPotions() < 2){
                        cout << "You don't have enough potions to heal the fallen adventurer. You must move on\n";
                    }
                    else{
                        Party1.setMyPotions(-2);
                        cout << "You heal the traveler and see that they are a " << cls << ". They are so grateful "
                        "that they decide to join forces and get out together.\n";
                        newMember(pclass, Party1);
                    }
                }
            }
            Party1.setMySupplies(-1*(Party1.getNumMembers()));
        }
                
        if(choice == 6) //DISPLAY PARTY
        { 
            Party1.displayParty(); //show members and their health/attack/lvl
        }
           
        if(choice == 7)
        {
            Party1.displayInventory(); //show gold/potions/supplies
        }
             
        if(choice == 8)
        {
            return; //QUIT
        }
        
        if(Party1.getMySupplies() <= 0 && choice != 6 && choice != 7 && choice != 4){ //starvation damage except with display and heal
            cout << "Your party is out of food and takes 1 damage from starvation!\n\n";
            Party1.Damage(1);
        }
        Party1.checkDeath(); //check health of members and delete/kill of if health is 0
        if(Party1.getNumMembers() == 0){
            cout << "GAME OVER. Your whole party has perished and your adventure is over.\n\n";
            return;
        }
    }
    if(Party1.getDistance() >= 40){ //Extra safeguard for win condition
        cout << "CONGRATULATIONS! You have cleared the dungeon and made it out with " << Party1.getMyGold() << " gold!\n";
        Party1.displayParty();
        cout << endl;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MAIN
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    Party Party1; //initialize party class object (aka over-arching class)
    mileFile(); //milestones
    beginMessage(); //Intro text
    introShop(Party1); //Get first two characters and buy first supplies and potions
    Dungeon(Party1);
    
    //game();
    return 0;
}