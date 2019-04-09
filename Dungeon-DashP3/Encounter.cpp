#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include "Encounter.h"
using namespace std;

Encounter::Encounter(){
    enemies = 1;
    type = "Skeletons";
    treasure = 1;
}

Encounter::Encounter(int num){
    if(num == 1){
        type = "Skeletons";
        enemies = rand() % 3 + 1;
        treasure = rand() % 3 + 1;
        //cout << "There are(is) " << enemies << type << "attacking!\n";
    }
    else if(num == 2){
        type = "Bandits";
        enemies = rand() % 3 + 1;
        treasure = rand() % 3 + 1;
        //cout << "There are(is) " << enemies << type << "attacking!\n";
    }
    else if(num == 3){
        type = "Trap";
        enemies = rand() % 3 + 1;
        treasure = rand() % 3 + 1;
    }
    else if(num == 4){
        type = "Obstacle";
        enemies = rand() % 3 + 1;
        treasure = rand() % 3 + 1;
    }
}

int Encounter::getEnemies(){
    return enemies;
}

string Encounter::getType(){
    return type;
}

int Encounter::getTreasure(){
    return treasure;
}

//void Fight();
//more planned with the actual interaction between characters and enemies