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
    for(int i = 1; i < 9; i++){
        for(int j = 1; j < 9; j++) {
            if(board[i][j][0] != p && board[i][j] != "   "){
                if(board[i][j][1] == 'P'){
                    if(movePawn(board, {i, j}, king, o)){
                        return true;
                    }
                }
                if(board[i][j][1] == 'N'){
                    if(moveKnight(board, {i, j}, king, o)) {
                        return true;
                    }
                }
                if(board[i][j][1] == 'B'){
                    if(moveBischop(board, {i, j}, king, o)){
                        return true;
                    }
                }
                if(board[i][j][1] == 'R'){
                    if(moveRook(board, {i, j}, king, o)) {
                        return true;
                    }
                }
                if(board[i][j][1] == 'Q'){
                    if(moveRook(board, {i, j}, king, o) || moveBischop(board, {i, j}, king, o)){
                        return true;
                    }
                }
                if(board[i][j][1] == 'K'){
                    if(moveKing(board, {i, j}, king, o)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

vector<vector<int>> kingMoves(vector<vector<string>> board, vector<int> coord1, char p) {
    char o;
    if (p == 'W') {
        o = 'B';
    } else if (p == 'B') {
        o = 'W';
    }
    vector<vector<int>> moves;

    if(coord1[0] > 1 && coord1[1] > 1 && board[coord1[0] - 1][coord1[1] - 1][0] != p){
        moves.push_back({coord1[0] - 1, coord1[1] - 1});
    }
    if(coord1[0] > 1 && coord1[1] < 8 && board[coord1[0] - 1][coord1[1] + 1][0] != p){
        moves.push_back({coord1[0] - 1, coord1[1] + 1});
    }
    if(coord1[0] > 1 && board[coord1[0] - 1][coord1[1]][0] != p){
        moves.push_back({coord1[0] - 1, coord1[1]});
    }
    if(coord1[0] < 8 && coord1[1] > 1 && board[coord1[0] + 1][coord1[1] - 1][0] != p){
        moves.push_back({coord1[0] + 1, coord1[1] - 1});
    }
    if(coord1[0] < 8 && coord1[1] < 8 && board[coord1[0] + 1][coord1[1] + 1][0] != p){
        moves.push_back({coord1[0] + 1, coord1[1] + 1});
    }
    if(coord1[0] < 8 && board[coord1[0] + 1][coord1[1]][0] != p){
        moves.push_back({coord1[0] + 1, coord1[1]});
    }
    if(coord1[1] > 1 && board[coord1[0]][coord1[1] - 1][0] != p){
        moves.push_back({coord1[0], coord1[1] - 1});
    }
    if(coord1[1] < 8 && board[coord1[0]][coord1[1] + 1][0] != p){
        moves.push_back({coord1[0], coord1[1] - 1});
    }

    return moves;
}

bool checkmate(vector<vector<string>> board, char p){
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
    vector<vector<int>> moves = kingMoves(board, king, p);
    for(size_t i = 0; i < moves.size(); i++){
        board2[moves[i][0]][moves[i][1]] = King;
        board2[king[0]][king[1]] = "   ";
        if(check(board2, p)){
            return true;
        }
        board2 = board;
    }
    return false;


}
