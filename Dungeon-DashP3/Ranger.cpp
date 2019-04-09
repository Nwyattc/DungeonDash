#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include "Ranger.h"
using namespace std;

Ranger::Ranger(){
    health = 6;
    currHealth = 6;
    attack = 3;
    level = 1;
    name = "Ranger";
    //talent
}
Ranger::Ranger(int h, int a, int l, string n){ //add in 
    health = h;
    attack = a;
    level = l;
    name = n;
    //
}


void Ranger::RsetHealth(int h){
    health = h;
}
int Ranger::RgetHealth(){
    return health;
}
void Ranger::RsetCurrHealth(int num){
    if((currHealth + num) > health){
        currHealth = health;
    }
    else {
        currHealth = currHealth + num;
    }
}
int Ranger::RgetCurrHealth(){
    return currHealth;
}


void Ranger::RsetAttack(int a){
    attack = a;
}
int Ranger::RgetAttack(){
    return attack;
}


void Ranger::RsetLevel(int l){
    level = l;
}
int Ranger::RgetLevel(){
    return level;
}


void Ranger::RsetName(string n){
    name = n;
}
string Ranger::RgetName(){
    return name;
}

//method associated with talent