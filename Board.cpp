#include "Board.hpp"
#include <iostream>


Soldier*& WarGame::Board:: operator[](std::pair<int,int> location){
	return board.at(location.first).at(location.second);
}
Soldier* WarGame::Board:: operator[](std::pair<int,int> location) const{
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
    cout << "player " << player_number << " moved from (" << source.first << ", " << source.second << ") " << "to (" << dest.first << " , " << dest.second << ")"<<endl<< endl;
    board[dest.first][dest.second] = board[source.first][source.second];
    board[source.first][source.second] = nullptr; 
    board[dest.first][dest.second]->setLocation(dest);
    board[dest.first][dest.second]->abillity(board,dest,player_number);
    for(int i = board.size()-1;i>=0;i--){
	 	for(int j=0;j<board.at(0).size();j++){
             pair<int,int> p = {i,j};
             if(board[i][j] != nullptr && board[i][j]->getPlayer() == 1){
                 cout << "1  ";
             }
             else if(board[i][j] != nullptr && board[i][j]->getPlayer() == 2){
                 cout << "2  ";
             }
             else
                 cout << "0  ";
             if(j == board.at(0).size()-1){
                 cout << endl;
             } 
         }
    }
    cout << endl;

}
bool WarGame::Board:: has_soldiers(uint player_number) const{
	for(int i =0;i<board.size();i++){
		for(int j=0;j<board[0].size();j++){
			if(board[i][j]!=nullptr && board[i][j]->getPlayer()==player_number)
                return true;
			}
		}
	return false;
}

int WarGame::Board::rows(){
    return board.size();
}

int WarGame::Board::columns(){
    return board[0].size();
}

double  WarGame::Board::distance(std::pair<int,int> source,std::pair<int,int> destination){
    return std::distance(board[source.first][source.second], board[destination.first][destination.second]);
}