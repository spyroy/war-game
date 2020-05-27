#pragma once
#include <iostream>
#include <string>

using namespace std;

class Soldier{
	protected:
	    int Maximum_Health;
	    int HP;
	    int DP;
	    int Player;
		pair<int,int> Location;
		string instance;
	
	public:
        Soldier(){
            this->Player = 1;
        }

	    Soldier(int player){
            this->Player = player;
        }

	    virtual void abillity(){}

	    Soldier* Take_Hit(int damage){
		    this->HP -= damage;
		    if(HP <= 0){
                return nullptr;
            }
		    if(HP > Maximum_Health){
			    HP = Maximum_Health;
			    return this;
		    }   
		    return this;
	    }
		/*Getters*/
	    int getPlayer(){return Player;}
	    int getHP(){return HP;}
		int getDP(){return DP;}
		int getMaximum_Health(){return Maximum_Health;}
		string getInstance(){return instance;}
		pair<int,int> getLocation(){return Location;}
};