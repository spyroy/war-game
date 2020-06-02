#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Soldier{
	protected:
	    int Maximum_Health;
	    int HP;
	    int DP;
	    int Player;
	
	public:
		pair<int,int> Location;
		string instance;

        Soldier(){
            this->Player = 1;
        }

	    Soldier(int player){
            this->Player = player;
        }

	    virtual void abillity(vector<vector<Soldier *>> &b, std::pair<int,int> dest,int player){}

	    Soldier* Take_Hit(int damage,vector<vector<Soldier *>> &b,std::pair<int,int> dest){
		    this->HP -= damage;
		    if(HP <= 0){
                b[dest.first][dest.second] =  nullptr;
				//return nullptr;
            }
		    if(HP > Maximum_Health){
			    HP = Maximum_Health;
		    }   
		    return this;
	    }
		/*Getters and Setters*/
	    int getPlayer(){return Player;}
	    int getHP(){return HP;}
		int getDP(){return DP;}
		int getMaximum_Health(){return Maximum_Health;}
		string getInstance(){return instance;}
		pair<int,int> getLocation(){return Location;}
		void setLocation(pair<int,int> l ){Location = l;}
		void setHP(int d){HP = d;}
};