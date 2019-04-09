#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include "Hero.h"
using namespace std;

Hero::Hero(){
    health = 8;
    currHealth = 8;
    attack = 2;
    level = 1;
    name = "Hero";
    //talent
}
Hero::Hero(int h, int a, int l, string n){ //add in 
    health = h;
    attack = a;
    level = l;
    name = n;
    //
}


void Hero::HsetHealth(int h){ 
    health = h;
}
int Hero::HgetHealth(){
    return health;
}
void Hero::HsetCurrHealth(int num){
    if((currHealth + num) > health){
        currHealth = health;
    }
    else {
        currHealth = currHealth + num;
    }
}
int Hero::HgetCurrHealth(){
    return currHealth;
}


void Hero::HsetAttack(int a){
    attack = a;
}
int Hero::HgetAttack(){
    return attack;
}


void Hero::HsetLevel(int l){
    level = l;
}
int Hero::HgetLevel(){
    return level;
}


void Hero::HsetName(string n){
    name = n;
}
string Hero::HgetName(){
    return name;
}

//method associated with talent