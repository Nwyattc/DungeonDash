#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include "Mage.h"
using namespace std;

Mage::Mage(){
    health = 4;
    currHealth = 4;
    attack = 4;
    level = 1;
    name = "Mage";
}
Mage::Mage(int h, int a, int l, string n){ //add in 
    health = h;
    attack = a;
    level = l;
    name = n;
    //
}


void Mage::MsetHealth(int h){
    health = h;
}
int Mage::MgetHealth(){
    return health;
}
void Mage::MsetCurrHealth(int num){
    if((currHealth + num) > health){
        currHealth = health;
    }
    else {
        currHealth = currHealth + num;
    }
}
int Mage::MgetCurrHealth(){
    return currHealth;
}


void Mage::MsetAttack(int a){
    attack = a;
}
int Mage::MgetAttack(){
    return attack;
}


void Mage::MsetLevel(int l){
    level = l;
}
int Mage::MgetLevel(){
    return level;
}


void Mage::MsetName(string n){
    name = n;
}
string Mage::MgetName(){
    return name;
}

//method associated with talent