#include "Board.hpp"
#include <iostream>


Soldier*& WarGame::Board:: operator[](std::pair<int,int> location){
    // if(board.at(location.first).at(location.second) != nullptr)
    //     throw runtime_error ("spot is occupied by another soldier");
	return board.at(location.first).at(location.second);
}
Soldier* WarGame::Board:: operator[](std::pair<int,int> location) const{
    // if(board.at(location.first).at(location.second) != nullptr)
    //     throw runtime_error ("spot is occupied by another soldier");

	return board.at(location.first).at(location.second);
}
void WarGame::Board:: move(uint player_number, std::pair<int,int> source, MoveDIR direction){
    if((*this)[source]==nullptr)
        throw runtime_error ("no soldier in specified spot");
	if((*this)[source]->getPlayer()!=player_number)
        throw runtime_error ("wrong player number");
	int Xaxis=0;
	int Yaxis=0;
    switch (direction)
    {
        case Up:
            Yaxis=1;
            break;
        case Down:
            Yaxis=-1;
            break;
        case Left:
            Xaxis=-1;
            break;
        case Right:
            Xaxis=1;
            break;    
        default:
            break;
    }
	std::pair<int,int> dest(source.first+Yaxis,source.second+Xaxis);
	if(dest.first<0||dest.first>=board.size())
        throw runtime_error ("no such spot in the board");
	if(dest.second<0||dest.second>=board.at(0).size())
        throw runtime_error ("no such spot in the board");
	if((*this)[dest]!=nullptr)
        throw runtime_error ("spot is occupied by another soldier");
    board[dest.first][dest.second] = board[source.first][source.second];
    board[source.first][source.second] = nullptr;    
}
bool WarGame::Board:: has_soldiers(uint player_number) const{
	for(int i =0;i<board.size();i++){
		for(int j=0;j<board.at(0).size();j++){
			if(board[i][j]!=nullptr && board[i][j]->getPlayer()==player_number)
                return true;
			}
		}
	return false;
}