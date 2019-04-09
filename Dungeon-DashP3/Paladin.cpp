#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include "Paladin.h"
using namespace std;

Paladin::Paladin(){
    health = 10;
    currHealth = 10;
    attack = 1;
    level = 1;
    name = "Paladin";
    //talent
}
Paladin::Paladin(int h, int a, int l, string n){ //add in 
    health = h;
    attack = a;
    level = l;
    name = n;
    //
}


void Paladin::PsetHealth(int h){
    health = h;
}
int Paladin::PgetHealth(){
    return health;
}
void Paladin::PsetCurrHealth(int num){
    if((currHealth + num) > health){
        currHealth = health;
    }
    else {
        currHealth = currHealth + num;
    }
}
int Paladin::PgetCurrHealth(){
    return currHealth;
}


void Paladin::PsetAttack(int a){
    attack = a;
}
int Paladin::PgetAttack(){
    return attack;
}


void Paladin::PsetLevel(int l){
    level = l;
}
int Paladin::PgetLevel(){
    return level;
}


void Paladin::PsetName(string n){
    name = n;
}
string Paladin::PgetName(){
    return name;
}

//method associated with talent