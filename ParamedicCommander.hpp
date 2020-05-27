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
            Soldier::Maximum_Health = 100;
            Soldier::HP = 100;
            Soldier::DP = 0;
            Soldier::instance = "ParamedicCommander";
        }
        
        virtual void abillity(){}
};