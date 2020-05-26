#include "doctest.h"
#include "Board.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include <iostream>
#include <string>
using namespace std;
using namespace WarGame;

#define BOARD_SIZE 5

TEST_CASE("Check Paramdedic behavior")
{
    Board b(BOARD_SIZE,BOARD_SIZE);
    b[{2,2}] = new Paramedic(1);
    b[{3,3}] = new Paramedic(2);
    b[{1,1}] = new Sniper(1);
    b[{4,4}] = new Sniper(2);
    b[{3,1}] = new FootCommander(1);
    CHECK(b.has_soldiers(1) == true);//Player 1 has 3 soldiers
    CHECK(b.has_soldiers(1) == true);//Player 2 has 2 soldiers
    int move = 0; //First move UP

}
TEST_CASE("Foot Soldiers behavior")
{
    Board board (8,1);
    CHECK(!board.has_soldiers(1));//For now there are no players at all, and for this case it will be false
    board[{0,0}]=new FootSoldier(1);
    CHECK(board.has_soldiers(1));//True
    board[{7,0}]=new FootSoldier(1);
    board[{2,0}]=new FootSoldier(2);
    CHECK(board.has_soldiers(2));
    board.move(1,{0,0},Board::MoveDIR::Up);//Move to {1,0} and shoot (damage 10)
    board.move(1,{1,0},Board::MoveDIR::Down);//Back to {0,0} and shoot
    board.move(1,{0,0},Board::MoveDIR::Up);//Move to {1,0} and shoot (damage 10)
    board.move(1,{1,0},Board::MoveDIR::Down);//Back to {0,0} and shoot
    board.move(1,{0,0},Board::MoveDIR::Up);//Move to {1,0} and shoot (damage 10)
    board.move(1,{1,0},Board::MoveDIR::Down);//Back to {0,0} and shoot
    board.move(1,{0,0},Board::MoveDIR::Up);//Move to {1,0} and shoot (damage 10)
    board.move(1,{1,0},Board::MoveDIR::Down);//Back to {0,0} and shoot
    CHECK(board.has_soldiers(2));//Should be true

}

