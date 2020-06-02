#pragma once
#include <iostream>
#include <string>
#include "Soldier.hpp"

using namespace std;

class Sniper : public Soldier{
	
	public:
        Sniper(){
            Soldier::Player = 1;
            Soldier::Maximum_Health = 100;
            Soldier::HP = 100;
            Soldier::DP = 50;
            Soldier::instance = "Sniper";
        }

        Sniper(int player){
            Soldier::Player = player;
            Soldier::Maximum_Health = 100;
            Soldier::HP = 100;
            Soldier::DP = 50;
            Soldier::instance = "Sniper";
        }
        
        virtual void abillity(vector<vector<Soldier *>> &b, std::pair<int,int> dest,int player);
};