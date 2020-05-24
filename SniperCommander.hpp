#include <iostream>
#include <string>
#include "Soldier.hpp"

using namespace std;

class SniperCommander : public Soldier{
	
	public:
        SniperCommander(int player){
            Soldier::Player = player;
            Soldier::Maximum_Health = 120;
            Soldier::HP = 120;
            Soldier::DP = 100;
        }
        virtual void Take_Hit(){}
};