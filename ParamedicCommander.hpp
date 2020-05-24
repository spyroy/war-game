#include <iostream>
#include <string>
#include "Soldier.hpp"

using namespace std;

class ParamedicCommander : public Soldier{
	
	public:
        ParamedicCommander(int player){
            Soldier::Player = player;
            Soldier::Maximum_Health = 100;
            Soldier::HP = 100;
            Soldier::DP = 0;
        }
        virtual void Take_Hit(){}
};