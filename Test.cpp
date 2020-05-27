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

TEST_CASE("Check Paramdedic and sniper behavior")
{
    Board b(BOARD_SIZE,BOARD_SIZE);
    b[{2,2}] = new Paramedic(1);
    b[{3,3}] = new Paramedic(2);
    b[{1,1}] = new Sniper(1);
    b[{4,4}] = new Sniper(2);
    b[{3,1}] = new FootCommander(1);
    CHECK(b.has_soldiers(1) == true);//Player 1 has 3 soldiers
    CHECK(b.has_soldiers(2) == true);//Player 2 has 2 soldiers
    b.move(1, {1,1}, Board::MoveDIR::Up);//sniper (1) moves up and shots sniper (2)
    CHECK(b[{2,1}] != nullptr);
    CHECK(b[{4,4}]->getHP() == 50);
    b.move(2, {3,3}, Board::MoveDIR::Up);//Paramedic (2) moves up and heals sniper (2)
    CHECK(b[{4,3}] != nullptr);
    CHECK(b[{4,4}]->getHP() == 100);
    b.move(2, {4,4}, Board::MoveDIR::Down);//Sniper (2) moves down and shots Sniper (1) or FootCommander(1)
    CHECK(b[{3,4}] != nullptr);
    CHECK(((b[{3,1}]->getHP() == 100) || (b[{2,1}]->getHP() == 50)));
    b.move(1, {2,2}, Board::MoveDIR::Up);//Paramedic(1) moves up and heals FootCommander(1) and Sniper (1)
    CHECK(b[{4,3}] != nullptr);
    CHECK(b[{3,1}]->getHP() == 150);
    CHECK(b[{2,1}]->getHP() == 100);
    b.move(1, {2,1}, Board::MoveDIR::Left);//Sniper(1) moves left and shots sniper (2)
    CHECK(b[{2,0}] != nullptr);
    CHECK(b[{3,4}]->getHP() == 50);
    b.move(1, {2,0}, Board::MoveDIR::Down);//Sniper(1) moves down and kills sniper (2)
    CHECK(b[{1,0}] != nullptr);
    CHECK(b[{3,4}] == nullptr);
    CHECK_THROWS(b.move(1, {1,0}, Board::MoveDIR::Left));//out of board
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if((i == 1 && j == 0) || (i == 3 && j == 1) || (i == 3 && j == 2) || (i == 4 && j == 3)){
                CHECK(b[{i,j}] != nullptr);
            }
            else
            {
                CHECK(b[{i,j}] == nullptr);
            }
            
        }
    }
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
    CHECK(board[{1,0}] != nullptr);
    CHECK(board[{0,0}] == nullptr);
    CHECK(board[{2,0}]->getHP() == 90);
    CHECK(board.has_soldiers(2));//Should be true
    board.move(1,{1,0},Board::MoveDIR::Down);//Back to {0,0} and shoot
    CHECK(board[{1,0}] == nullptr);
    CHECK(board[{0,0}] != nullptr);
    CHECK(board[{2,0}]->getHP() == 80);
    CHECK(board.has_soldiers(2));//Should be true
    board.move(1,{0,0},Board::MoveDIR::Up);//Move to {1,0} and shoot (damage 10)
    CHECK(board[{1,0}] != nullptr);
    CHECK(board[{0,0}] == nullptr);
    CHECK(board[{2,0}]->getHP() == 70);
    CHECK(board.has_soldiers(2));//Should be true
    board.move(1,{1,0},Board::MoveDIR::Down);//Back to {0,0} and shoot
    CHECK(board[{1,0}] == nullptr);
    CHECK(board[{0,0}] != nullptr);
    CHECK(board[{2,0}]->getHP() == 60);
    CHECK(board.has_soldiers(2));//Should be true
    board.move(1,{0,0},Board::MoveDIR::Up);//Move to {1,0} and shoot (damage 10)
    CHECK(board[{1,0}] != nullptr);
    CHECK(board[{0,0}] == nullptr);
    CHECK(board[{2,0}]->getHP() == 50);
    CHECK(board.has_soldiers(2));//Should be true
    board.move(1,{1,0},Board::MoveDIR::Down);//Back to {0,0} and shoot
    CHECK(board[{1,0}] == nullptr);
    CHECK(board[{0,0}] != nullptr);
    CHECK(board[{2,0}]->getHP() == 40);
    CHECK(board.has_soldiers(2));//Should be true
    board.move(1,{0,0},Board::MoveDIR::Up);//Move to {1,0} and shoot (damage 10)
    CHECK(board[{1,0}] != nullptr);
    CHECK(board[{0,0}] == nullptr);
    CHECK(board[{2,0}]->getHP() == 30);
    CHECK(board.has_soldiers(2));//Should be true
    board.move(1,{1,0},Board::MoveDIR::Down);//Back to {0,0} and shoot
    CHECK(board[{1,0}] == nullptr);
    CHECK(board[{0,0}] != nullptr);
    CHECK(board[{2,0}]->getHP() == 20);
    CHECK(board.has_soldiers(2));//Should be true
    board.move(1,{7,0},Board::MoveDIR::Down);//Move to {6,0} and shoot (damage 10)
    CHECK(board[{7,0}] == nullptr);
    CHECK(board[{6,0}] != nullptr);
    CHECK(board[{2,0}]->getHP() == 10);
    CHECK(board.has_soldiers(2));//Should be true
    board.move(1,{7,0},Board::MoveDIR::Down);//Move to {5,0} and shoot (damage 10)
    CHECK(board[{6,0}] == nullptr);
    CHECK(board[{5,0}] != nullptr);
    CHECK(board[{2,0}] != nullptr);
    CHECK(!board.has_soldiers(2));//Should be false
}

TEST_CASE("FootCommander"){
    Board b(BOARD_SIZE,BOARD_SIZE);
    b[{0,0}] = new FootSoldier(1);
    b[{0,1}] = new FootSoldier(1);
    b[{0,2}] = new FootCommander(1);
    b[{0,3}] = new FootSoldier(1);
    b[{0,4}] = new FootSoldier(1);
    b[{4,2}] = new ParamedicCommander(2);
    b.move(1,{0,2},Board::MoveDIR::Up);//Commander moves up and all soldiers shoot (60 damage total)
    CHECK(b[{1,2}] != nullptr);
    CHECK(b[{0,2}] == nullptr);
    CHECK(b[{4,2}]->getHP() == 140);//200-60
    b.move(1,{0,0},Board::MoveDIR::Up);//soldier moves up (damage 10)
    CHECK(b[{1,0}] != nullptr);
    CHECK(b[{0,0}] == nullptr);
    CHECK(b[{4,2}]->getHP() == 130);
    b.move(1,{0,4},Board::MoveDIR::Up);//soldier moves up (damage 10)
    CHECK(b[{1,4}] != nullptr);
    CHECK(b[{0,4}] == nullptr);
    CHECK(b[{4,2}]->getHP() == 120);
    b.move(1,{1,2},Board::MoveDIR::Up);//Commander moves up and all soldiers shoot (60 damage total)
    CHECK(b[{1,2}] == nullptr);
    CHECK(b[{2,2}] != nullptr);
    CHECK(b[{4,2}]->getHP() == 60);//120-60
    b.move(1,{2,2},Board::MoveDIR::Up);//Commander moves up and all soldiers shoot (60 damage total) and kills soldier (2)
    CHECK(b[{2,2}] == nullptr);
    CHECK(b[{3,2}] != nullptr);
    CHECK(b[{4,2}] == nullptr);
}

TEST_CASE("SniperCommander"){
    Board b(BOARD_SIZE,BOARD_SIZE);
    b[{0,0}] = new Sniper(1);
    b[{0,1}] = new Sniper(1);
    b[{0,2}] = new SniperCommander(1);
    b[{0,3}] = new Sniper(1);
    b[{0,4}] = new Sniper(1);
    b[{4,2}] = new ParamedicCommander(2);
    b[{3,2}] = new ParamedicCommander(2);
    b.move(1,{0,2},Board::MoveDIR::Up);//Commander moves up and all soldiers shoot (300 damage total)
    CHECK(b[{1,2}] != nullptr);
    CHECK(b[{0,2}] == nullptr);
    CHECK(b[{4,2}] == nullptr);//200-300 (dead)
    b.move(1,{0,0},Board::MoveDIR::Up);//soldier moves up (damage 10)
    CHECK(b[{1,0}] != nullptr);
    CHECK(b[{0,0}] == nullptr);
    CHECK(b[{3,2}]->getHP() == 150);//200-50
    b.move(1,{1,2},Board::MoveDIR::Up);//Commander moves up and all soldiers shoot (60 damage total)
    CHECK(b[{1,2}] == nullptr);
    CHECK(b[{2,2}] != nullptr);
    CHECK(b[{3,2}] == nullptr);//150-300
}

TEST_CASE("ParamedicCommander"){
    Board b(BOARD_SIZE,BOARD_SIZE);
    b[{0,0}] = new Soldier(1);
    b[{0,1}] = new Paramedic(1);
    b[{0,2}] = new ParamedicCommander(1);
    b[{0,3}] = new Paramedic(1);
    b[{0,4}] = new Sniper(1);
    b[{4,2}] = new Sniper(2);
    b[{3,4}] = new SniperCommander(2);
    b.move(2,{4,2},Board::MoveDIR::Left);//soldier(2) moves and shots soldier(1)
    CHECK(b[{4,1}] != nullptr);
    CHECK(b[{4,2}] == nullptr);
    CHECK(((b[{0,0}]->getHP() == 50) || (b[{0,4}]->getHP() == 50)));
    b.move(2,{4,1},Board::MoveDIR::Right);//soldier(2) moves and shots paramedic(1)
    CHECK(b[{4,2}] != nullptr);
    CHECK(b[{4,1}] == nullptr);
    CHECK(((b[{0,1}]->getHP() == 50) || (b[{0,2}]->getHP() == 150) || (b[{0,3}]->getHP() == 50)));
    b.move(1,{0,2},Board::MoveDIR::Up);//commander moves and heals everyone
    CHECK(b[{1,2}] != nullptr);
    CHECK(b[{0,2}] == nullptr);
    CHECK(b[{0,0}]->getHP() == 100);
    CHECK(b[{0,1}]->getHP() == 100);
    CHECK(b[{1,2}]->getHP() == 200);
    CHECK(b[{0,3}]->getHP() == 100);
    CHECK(b[{0,4}]->getHP() == 100);
}

