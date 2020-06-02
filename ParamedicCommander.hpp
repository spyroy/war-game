#pragma once
#include <iostream>
#include <string>
#include "Soldier.hpp"
#include "Paramedic.hpp"

using namespace std;

class ParamedicCommander : public Paramedic{
	
	public:
        ParamedicCommander(int player){
            Soldier::Player = player;
            Soldier::Maximum_Health = 200;
            Soldier::HP = 200;
            Soldier::DP = 0;
            Soldier::instance = "ParamedicCommander";
        }
        
        virtual void abillity(vector<vector<Soldier *>> &b, std::pair<int,int> dest,int player);
};