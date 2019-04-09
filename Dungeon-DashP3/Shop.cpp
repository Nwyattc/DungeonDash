#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include "Shop.h"
using namespace std;

//Make sure boughtP, boughtS and currGold are passed back to party object
Shop::Shop(int lvl, int gold){
    currGold = gold; //implement gold
    potions = (lvl);
    supplies = (lvl * 5);
    boughtP = 0;
    boughtS = 0;
    
    string yn = ""; //for asking leave or not
    bool ask = true; //input for while loop
    
    cout << "The Shop Owner approaches you and smiles. 'Welcome to my shop! Feel free to browse my wares.'\n";
    while(ask == true) 
    {
        cout << "~~~~ Shop ~~~~\nPotions in stock: " << potions << " ----- (Cost 5)\n";
        cout << "Supplies in stock: " << supplies << " --- (Cost 1)\n";
        cout << "My gold: " << currGold << endl << endl;
        cout << "What would you like to do?\nBuy potions  (1)\nBuy supplies (2)\nLeave        (3)\n";
        string input;
        getline(cin, input);
        
        while(input != "1" && input != "2" && input != "3") //input validation
        {
            cout << "Please enter a valid input\n";
            getline(cin, input);
        }
        int x = stoi(input);
        
        switch (x)
        {
            case 1: buyPotion();
                    break;
            case 2: buySupplies();
                    break;
            case 3: cout << "Are you sure you have done all you want and are ready to proceed?\n(Y/N)  "; //catch accidental 3 presses
                    getline(cin, yn);
                    if(yn == "Y" || yn == "y"){ //only way to break while loop
                        ask = false;
                        break;
                    }
                    else if(yn == "N" || yn == "n") break;
            default: cout << "\nPlease enter a valid input\n";
        }
    }
    
}

int Shop::buyPotion(){ //buying and diplaying potions
    cout << "How many would you like to buy?  ";
    string x;
    getline(cin, x);
    while(x < 47 || x > 58){
        cout << "Please enter a valid input: ";
        getline(cin, x);
    }
    int num = stoi(x);
    if (num > potions || num < 0){ //input validation
        cout << "Sorry we don't have enough potions for that." << endl;
        return 0;
    }
    
    if(currGold >= (num * 5)) //if enough money
    {
        cout << "You hand the shopkeep " << (num * 5) << " gold and he gives you " << num << " potions.\n";
        potions -= num;
        currGold -= (num * 5);
        boughtP += num;
        cout << "'Thanks for the business!'" << endl;
        return num;
    }
    else if(currGold < (num * 5)) cout << "\nYou don't have enough gold for that!\n";
}

int Shop::showPotion(){
    return potions;
} 



int Shop::buySupplies(){ //buying and diplaying supplies
    cout << "How many would you like to buy?  ";
    string x;
    getline(cin, x);
    while(x < 47 || x > 58){
        cout << "Please enter a valid input: ";
        getline(cin, x);
    }
    int num = stoi(x);
    if (num > supplies || num < 0) //input validation
    { 
        cout << "Sorry we don't have enough supplies for that." << endl;
        return 0;
    }
    
    if(currGold >= (num * 1)) //if enough money
    {
        cout << "\nYou hand the shopkeep " << (num * 1) << " gold and he gives you " << num << " supplies.\n";
        supplies -= num;
        currGold -= (num * 1);
        boughtS += num;
        cout << "'Thanks for the business!'\n\n";
        return num;
    }
    else if(currGold < (num * 1)) cout << "\nYou don't have enough gold for that!\n\n";
}

int Shop::showSupplies(){
    return supplies;
}


//Getters for accessing the numbers outside the class
int Shop::getCurrGold(){ 
    return currGold;
}
int Shop::getBoughtP(){
    return boughtP;
}
int Shop::getBoughtS(){
    return boughtS;
}





/**
int Shop::buyUpgrades(int num, int ){
    //find a way to implement an array of different upgrades at different prices
}
int Shop::showUpgrades(){
    
}
*/
