#include <vector>
#include <string>
#include "Link.hpp"

using namespace std;

bool check(vector<vector<string>> board, char p){
    char o;
    if (p == 'W'){
        o = 'B';
    }else if (p == 'B') {
        o = 'W';
    }
    vector<int> king;

    for(int i = 1; i < 9; i++){
        for(int j = 1; j < 9; j++) {
            if(board[i][j][0] == p && board[i][j][1] == 'K') {
                king = {i, j};
                break;
            }
        }
    }
    vector<vector<int>> moves;
    vector<vector<int>> moves2;
    for(int i = 1; i < 9; i++){
        for(int j = 1; j < 9; j++) {
            if(board[i][j][0] != p && board[i][j] != "   "){
                if(board[i][j][1] == 'P'){
                    moves = movePawn(board, {i, j}, o);
                }else if(board[i][j][1] == 'N') {
                    moves = moveKnight(board, {i, j}, o);
                }else if(board[i][j][1] == 'B'){
                    moves = moveBischop(board, {i, j}, o);
                }else if(board[i][j][1] == 'R') {
                    moves = moveRook(board, {i, j}, o);
                }else if(board[i][j][1] == 'Q') {
                    moves = moveRook(board, {i, j}, o);
                    moves2 = moveBischop(board, {i, j}, o);
                    for (size_t k = 0; k < moves2.size(); k++) {
                        moves.push_back(moves2[i]);
                    }
                }else if(board[i][j][1] == 'K') {
                    moves = moveKing(board, {i, j}, o);
                }
            }
            for (size_t l = 0; l < moves.size(); l++) {
                if (moves[l] == king) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool checkmate(vector<vector<string>> board, char p){
    if(not check(board, p)){
        return false;
    }
    char o;
    if (p == 'W'){
        o = 'B';
    }else if (p == 'B') {
        o = 'W';
    }
    vector<int> king;
    string King;

    for(int i = 1; i < 9; i++){
        for(int j = 1; j < 9; j++) {
            if(board[i][j][0] == p && board[i][j][1] == 'K') {
                king = {i, j};
                King = board[i][j];
                break;
            }
        }
    }
    vector<vector<string>> board2 = board;
    vector<vector<int>> moves = moveKing(board, king, p);
    int count = 0;
    for(size_t i = 0; i < moves.size(); i++){
        board2[moves[i][0]][moves[i][1]] = King;
        board2[king[0]][king[1]] = "   ";
        if(check(board2, p)){
            count++;
        }
        board2 = board;
    }
    return count == moves.size();


}
