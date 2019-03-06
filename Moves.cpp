#include <vector>
#include <string>
#include <iostream>
#include "Link.hpp"

using namespace std;

bool movePawn(vector<vector<string>> board, vector<int> coord1, const vector<int> coord2, char p){
    char o;
    if(p == 'W'){
        o = 'B';
    }else if(p == 'B'){
        o = 'W';
    }
    vector<vector<int>> moves;
    if(p == 'W') {
        if (coord1[0] == 2) {
            if (board[coord1[0] + 2][coord1[1]] == "   ") {
                moves.push_back({coord1[0] + 2, coord1[1]});
            }
        }
        if (board[coord1[0] + 1][coord1[1]] == "   ") {
            moves.push_back({coord1[0] + 1, coord1[1]});
        }
        if (coord1[1] == 1) {
            if (board[coord1[0] + 1][2][0] == o) {
                moves.push_back({coord1[0] + 1, 2});
            }
        } else if (coord1[1] == 8) {
            if (board[coord1[0] + 1][7][0] == o) {
                moves.push_back({coord1[0] + 1, 7});
            }
        } else {
            if (board[coord1[0] + 1][coord1[1] + 1][0] == o) {
                moves.push_back({coord1[0] + 1, coord1[1] + 1});
            }
            if (board[coord1[0] + 1][coord1[0] - 1][0] == o) {
                moves.push_back({coord1[0] + 1, coord1[1] - 1});
            }
        }
    }else if(p == 'B'){
        if (coord1[0] == 7){
            if (board[coord1[0] - 2][coord1[1]] == "   ") {
                moves.push_back({coord1[0] - 2, coord1[1]});
            }
        }
        if (board[coord1[0] - 1][coord1[1]] == "   ") {
            moves.push_back({coord1[0] - 1, coord1[1]});
        }
        if (coord1[1] == 1) {
            if (board[coord1[0] - 1][2][0] == o) {
                moves.push_back({coord1[0] - 1, 2});
            }
        } else if (coord1[1] == 8) {
            if (board[coord1[0] - 1][7][0] == o) {
                moves.push_back({coord1[0] - 1, 7});
            }
        } else {
            if (board[coord1[0] - 1][coord1[1] + 1][0] == o) {
                moves.push_back({coord1[0] - 1, coord1[1] + 1});
            }
            if (board[coord1[0] - 1][coord1[0] - 1][0] == o) {
                moves.push_back({coord1[0] - 1, coord1[1] - 1});
            }
        }
    }
    for(size_t i = 0; i < moves.size(); i++){
        if(coord2 == moves[i]){
            return true;
        }
    }
    return false;
}

bool moveKnight(vector<vector<string>> board, vector<int> coord1, const vector<int> coord2, char p) {
    vector<vector<int>> moves;
    if(coord1[0] <= 6 && coord1[1] <= 7 && board[coord1[0] + 2][coord1[1] + 1][0] != p){
        moves.push_back({coord1[0] + 2, coord1[1] + 1});
    }
    if(coord1[0] <= 7 && coord1[1] <= 6 && board[coord1[0] + 1][coord1[1] + 2][0] != p){
        moves.push_back({coord1[0] + 1, coord1[1] + 2});
    }
    if(coord1[0] <= 6 && coord1[1] >= 2 && board[coord1[0] + 2][coord1[1] - 1][0] != p){
        moves.push_back({coord1[0] + 2, coord1[1] - 1});
    }
    if(coord1[0] <= 7 && coord1[1] >= 3 && board[coord1[0] + 1][coord1[1] - 2][0] != p){
        moves.push_back({coord1[0] + 1, coord1[1] - 2});
    }
    if(coord1[0] >= 2 && coord1[1] >= 3 && board[coord1[0] - 1][coord1[1] - 2][0] != p){
        moves.push_back({coord1[0] - 1, coord1[1] - 2});
    }
    if(coord1[0] >= 3 && coord1[1] >= 2 && board[coord1[0] - 2][coord1[1] - 1][0] != p){
        moves.push_back({coord1[0] - 2, coord1[1] - 1});
    }
    if(coord1[0] >= 2 && coord1[1] <= 6 && board[coord1[0] - 1][coord1[1] + 2][0] != p){
        moves.push_back({coord1[0] - 1, coord1[1] + 2});
    }
    if(coord1[0] >= 3 && coord1[1] <= 7 && board[coord1[0] - 2][coord1[1] + 1][0] != p){
        moves.push_back({coord1[0] - 2, coord1[1] + 1});
    }
    for (size_t i = 0; i < moves.size(); i++) {
        if (coord2 == moves[i]) {
            return true;
        }
    }
    return false;
}

bool moveBischop(vector<vector<string>> board, vector<int> coord1, const vector<int> coord2, char p) {
    char o;
    if (p == 'W') {
        o = 'B';
    } else if (p == 'B') {
        o = 'W';
    }
    vector<vector<int>> moves;
    int x = coord1[1];
    int y = coord1[0];
    while(true){
        if(y == 8 || x == 8){
            break;
        }
        x++;
        y++;
        if (board[y][x][0] == p) {
            break;
        }
        if (board[y][x][0] == o) {
            moves.push_back({y, x});
            break;
        }else{
            moves.push_back({y, x});
        }
    }
    x = coord1[1];
    y = coord1[0];
    while(true){
        if(y == 1 || x == 8){
            break;
        }
        x++;
        y--;
        if (board[y][x][0] == p) {
            break;
        }
        if (board[y][x][0] == o) {
            moves.push_back({y, x});
            break;
        }else{
            moves.push_back({y, x});
        }
    }
    x = coord1[1];
    y = coord1[0];
    while (true){
        if(y == 8 || x == 1){
            break;
        }
        x--;
        y++;
        if (board[y][x][0] == p) {
            break;
        }
        if (board[y][x][0] == o) {
            moves.push_back({y, x});
            break;
        }else{
            moves.push_back({y, x});
        }
    }
    x = coord1[1];
    y = coord1[0];
    while(true){
        if(y == 1 || x == 1){
            break;
        }
        x--;
        y--;
        if (board[y][x][0] == p) {
            break;
        }
        if (board[y][x][0] == o) {
            moves.push_back({y, x});
            break;
        }else{
            moves.push_back({y, x});
        }
    }

    for (size_t i = 0; i < moves.size(); i++) {
        if (coord2 == moves[i]) {
            return true;
        }
    }
    return false;
}

bool moveRook(vector<vector<string>> board, vector<int> coord1, const vector<int> coord2, char p) {
    char o;
    if (p == 'W') {
        o = 'B';
    } else if (p == 'B') {
        o = 'W';
    }
    vector<vector<int>> moves;
    int x = coord1[1];
    while (true) {
        if(x == 8){
            break;
        }
        x++;
        if (board[coord1[0]][x][0] == p) {
            break;
        }
        if (board[coord1[0]][x][0] == o) {
            moves.push_back({coord1[0], x});
            break;
        }else{
            moves.push_back({coord1[0], x});
        }
    }
    x = coord1[1];
    while (true) {
        if(x == 1){
            break;
        }
        x--;
        if (board[coord1[0]][x][0] == p) {
            break;
        }
        if (board[coord1[0]][x][0] == o) {
            moves.push_back({coord1[0], x});
            break;
        }else{
            moves.push_back({coord1[0], x});
        }
    }
    int y = coord1[0];
    while (true) {
        if(y == 8){
            break;
        }
        y++;
        if (board[y][coord1[1]][0] == p) {
            break;
        }
        if (board[y][coord1[1]][0] == o) {
            moves.push_back({y, coord1[1]});
            break;
        }else{
            moves.push_back({y, coord1[1]});
        }
    }
    y = coord1[0];
    while (true) {
        if(y == 1){
            break;
        }
        y--;
        if (board[y][coord1[1]][0] == p) {
            break;
        }
        if (board[y][coord1[1]][0] == o) {
            moves.push_back({y, coord1[1]});
            break;
        }else{
            moves.push_back({y, coord1[1]});
        }
    }

    for (size_t i = 0; i < moves.size(); i++) {
        if (coord2 == moves[i]) {
            return true;
        }
    }
    return false;
}

bool moveKing(vector<vector<string>> board, vector<int> coord1, const vector<int> coord2, char p) {
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

    for (size_t i = 0; i < moves.size(); i++) {
        if (coord2 == moves[i]) {
            return true;
        }
    }
    return false;
}

void move(vector<vector<string>> & board, string piece, string place, char p) {
    vector<int> coord1;
    vector<int> coord2;
    if(piece[0] != p){
        cout << "foute zet" << endl;
        return;
    }
    for(int i = 1; i < 9; i++) {
        for(int j = 1; j < 9; j++) {
            if(board[i][j] == piece) {
                coord1 = {i, j};
                break;
            }
        }
    }
    coord2 = {place[1] - 48, int(place[0]) - 64};
    if(piece[1] == 'P') {
        if(movePawn(board, coord1, coord2, p)) {
            board[coord2[0]][coord2[1]] = piece;
            board[coord1[0]][coord1[1]] = "   ";
        }else{
            cout << "Foute zet" << endl;
            return;
        }
    }
    if(piece[1] == 'N') {
        if(moveKnight(board, coord1, coord2, p)) {
            board[coord2[0]][coord2[1]] = piece;
            board[coord1[0]][coord1[1]] = "   ";
        }else{
            cout << "Foute zet" << endl;
            return;
        }
    }
    if(piece[1] == 'B') {
        if (moveBischop(board, coord1, coord2, p)) {
            board[coord2[0]][coord2[1]] = piece;
            board[coord1[0]][coord1[1]] = "   ";
        }else{
            cout << "Foute zet" << endl;
            return;
        }
    }
    if(piece[1] == 'R') {
        if (moveRook(board, coord1, coord2, p)) {
            board[coord2[0]][coord2[1]] = piece;
            board[coord1[0]][coord1[1]] = "   ";
        }else{
            cout << "Foute zet" << endl;
            return;
        }
    }
    if(piece[1] == 'Q') {
        if (moveRook(board, coord1, coord2, p) || moveBischop(board, coord1, coord2, p)){
            board[coord2[0]][coord2[1]] = piece;
            board[coord1[0]][coord1[1]] = "   ";
        }else{
            cout << "Foute zet" << endl;
            return;
        }
    }
    if(piece[1] == 'K') {
        if (moveKing(board, coord1, coord2, p)){
            board[coord2[0]][coord2[1]] = piece;
            board[coord1[0]][coord1[1]] = "   ";
        }else{
            cout << "Foute zet" << endl;
            return;
        }
    }
}
