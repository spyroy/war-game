#include <iostream>
#include <string>
#include "Soldier.hpp"

using namespace std;

class FootCommander : public Soldier{
	
	public:
        FootCommander(int player){
            Soldier::Player = player;
            Soldier::Maximum_Health = 150;
            Soldier::HP = 150;
            Soldier::DP = 20;
        }
        virtual void Take_Hit(){}
};