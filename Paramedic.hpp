#pragma once
#include <iostream>
#include <string>
#include "Soldier.hpp"

using namespace std;

class Paramedic : public Soldier{
	
	public:
        Paramedic(){
            Soldier::Player = 1;
            Soldier::Maximum_Health = 100;
            Soldier::HP = 100;
            Soldier::DP = 10;
            Soldier::instance = "Paramedic";
        }

        Paramedic(int player){
            Soldier::Player = player;
            Soldier::Maximum_Health = 100;
            Soldier::HP = 100;
            Soldier::DP = 0;
            Soldier::instance = "Paramedic";
        }
        
        virtual void abillity(){}
};