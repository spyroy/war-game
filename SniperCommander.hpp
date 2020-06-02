#pragma once
#include <iostream>
#include <string>
#include "Soldier.hpp"
#include "Sniper.hpp"

using namespace std;

class SniperCommander : public Sniper{
	
	public:
        SniperCommander(int player){
            Soldier::Player = player;
            Soldier::Maximum_Health = 120;
            Soldier::HP = 120;
            Soldier::DP = 100;
            Soldier::instance = "SniperCommander";
        }
        
        virtual void abillity(vector<vector<Soldier *>> &b, std::pair<int,int> dest,int player);
};