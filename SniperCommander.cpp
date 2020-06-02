#include <iostream>
#include <string>
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Board.hpp"

using namespace std;

void SniperCommander::abillity(vector<vector<Soldier *>> &b, std::pair<int,int> dest,int player){
    double max = -1;
    Soldier* s = nullptr;
    pair<int,int> location;
    for(int i =0;i<b.size();i++){
		for(int j=0;j<b.at(0).size();j++){
            pair <int,int> current = {i,j};
            if(current != dest && b[i][j]!= nullptr && b[i][j]->getPlayer() != player){
                if(b[i][j]->getHP() > max){
                    max = b[i][j]->getHP();
                    s = b[i][j];
                }
            }
        }
    }
    if(max != -1 )
        s->Take_Hit(b[dest.first][dest.second]->getDP(),b,location);

    for(int i =0;i<b.size();i++){
	    for(int j=0;j<b.at(0).size();j++){   
            if(b[i][j] != nullptr && b[i][j]->getInstance() == "Sniper" && b[i][j]->getPlayer() == player){
                b[i][j]->abillity(b,pair<int,int>{i,j},player);
            }
        }
    }
}