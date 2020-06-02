#pragma once
#include <iostream>
#include <string>
#include "Soldier.hpp"
#include "Board.hpp"

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
        void abillity(vector<vector<Soldier *>> &b, std::pair<int,int> dest,int player);
};