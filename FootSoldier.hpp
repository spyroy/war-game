#pragma once
#include <iostream>
#include <string>
#include "Soldier.hpp"

using namespace std;

class FootSoldier : public Soldier{
	
	public:
        FootSoldier(){
            Soldier::Player = 1;
            Soldier::Maximum_Health = 100;
            Soldier::HP = 100;
            Soldier::DP = 10;
            Soldier::instance = "FootSoldier";
        }
        
        FootSoldier(int player){
            Soldier::Player = player;
            Soldier::Maximum_Health = 100;
            Soldier::HP = 100;
            Soldier::DP = 10;
            Soldier::instance = "FootSoldier";
        }
        virtual void abillity(){
            
        }
};