#include <iostream>
#include <string>
#include "Soldier.hpp"

using namespace std;

class FootSoldier : public Soldier{
	
	public:
        FootSoldier(int player){
            Soldier::Player = player;
            Soldier::Maximum_Health = 100;
            Soldier::HP = 100;
            Soldier::DP = 10;
        }
        virtual void Take_Hit(){}
};