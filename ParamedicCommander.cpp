#include <iostream>
#include <string>
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include "Board.hpp"

using namespace std;

void ParamedicCommander::abillity(vector<vector<Soldier *>> &b, std::pair<int,int> dest,int player){
    if(b[dest.first+1][dest.second]->getPlayer() == player){
        b[dest.first+1][dest.second]->Take_Hit(-50,b,{dest.first+1,dest.second});
    }
    if(b[dest.first][dest.second+1]->getPlayer() == player){
        b[dest.first][dest.second+1]->Take_Hit(-50,b,{dest.first,dest.second+1});
    }
    if(b[dest.first+1][dest.second+1]->getPlayer() == player){
        b[dest.first+1][dest.second+1]->Take_Hit(-50,b,{dest.first+1,dest.second+1});
    }
    if(b[dest.first-1][dest.second]->getPlayer() == player){
        b[dest.first-1][dest.second]->Take_Hit(-50,b,{dest.first-1,dest.second});
    }
    if(b[dest.first][dest.second-1]->getPlayer() == player){
        b[dest.first][dest.second-1]->Take_Hit(-50,b,{dest.first,dest.second-1});
    }
    if(b[dest.first-1][dest.second-1]->getPlayer() == player){
        b[dest.first-1][dest.second-1]->Take_Hit(-50,b,{dest.first-1,dest.second-1});
    }
    if(b[dest.first-1][dest.second+1]->getPlayer() == player){
        b[dest.first-1][dest.second+1]->Take_Hit(-50,b,{dest.first-1,dest.second+1});
    }
    if(b[dest.first+1][dest.second-1]->getPlayer() == player){
        b[dest.first+1][dest.second-1]->Take_Hit(-50,b,{dest.first+1,dest.second-1});
    }

    for(int i =0;i<b.size();i++){
	    for(int j=0;j<b.at(0).size();j++){   
            if(b[i][j] != nullptr && b[i][j]->getInstance() == "ParamedicCommander" && b[i][j]->getPlayer() == player){
                b[i][j]->abillity(b,pair<int,int>{i,j},player);
            }
        }
    }
}