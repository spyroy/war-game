#include <iostream>
#include <string>
#include "FootSoldier.hpp"
#include "Board.hpp"
#include <bits/stdc++.h>

using namespace std;

void FootSoldier::abillity(vector<vector<Soldier *>> &b, std::pair<int,int> dest,int player){
    double max = INT64_MAX;
    Soldier* s = nullptr;
    double dis ;
    pair<int,int> location;
    for(int i =0;i<b.size();i++){
		for(int j=0;j<b.at(0).size();j++){
            pair <int,int> current = {i,j};
            if(current != dest && b[i][j]!= nullptr && b[i][j]->getPlayer() != player){
                if(sqrt(pow((i-dest.first), 2) + pow((j-dest.second), 2)) < max){
                    max = sqrt(pow((i-dest.first), 2) + pow((j-dest.second), 2) * 1.0);
                    s = b[i][j];
                    location = {i,j};
                }
            }
        }
    }
    if(max != INT64_MAX && s != nullptr)
        s->Take_Hit(b[location.first][location.second]->getDP(),b,location);
}