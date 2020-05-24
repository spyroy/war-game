#include <iostream>
#include <string>
#include "Soldier.hpp"

using namespace std;

class Sniper : public Soldier{
	
	public:
        Sniper(int player){
            Soldier::Player = player;
            Soldier::Maximum_Health = 100;
            Soldier::HP = 100;
            Soldier::DP = 50;
        }
        virtual void Take_Hit(){}
};