#include <iostream>
#include <vector>
#include <string>
#include "Link.hpp"

using namespace std;

void print(vector<vector<string>> board, char p){
    if(p == 'W'){
        for(int i = 0; i < 9; i++){
            for(int j  = 0; j < 9; j++){
                cout << board[8 - i][j] << '|';
            }
            cout << endl;
        }
    }else if(p == 'B'){
        for(int i = 0; i < 9; i++){
            cout << '|';
            for(int j  = 0; j < 9; j++){
                cout << board[i][8 - j] << '|';
            }
            cout << endl;
        }
    }

}

int main(){
    vector<vector<string>> board = {{" ", " A ", " B ", " C ", " D ", " E ", " F ", " G ", " H "},
                                    {"1", "WR1", "WN1", "WB1", "WQ1", "WK1", "WB2", "WN2", "WR2"},
                                    {"2", "WP1", "WP2", "WP3", "WP4", "WP5", "WP6", "WP7", "WP8"},
                                    {"3", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
                                    {"4", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
                                    {"5", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
                                    {"6", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
                                    {"7", "BP1", "BP2", "BP3", "BP4", "BP5", "BP6", "BP7", "BP8"},
                                    {"8", "BR1", "BN1", "BB1", "BQ1", "BK1", "BB2", "BN2", "BR2"}};
    string stuk;
    string plek;
    while (true) {
        print(board, 'W');
        cout << "Geef een stuk om te verplaatsen" << endl;
        cin >> stuk;
        cout << "Geef een veld" << endl;
        cin >> plek;
        move(board, stuk, plek, 'W');
        if(check(board, 'B')){
            cout << "Schaak" << endl;
        }
        if(checkmate(board, 'B')){
            cout << "Schaakmat";
            break;
        }
        print(board, 'B');
        cout << "Geef een stuk om te verplaatsen" << endl;
        cin >> stuk;
        cout << "Geef een veld" << endl;
        cin >> plek;
        move(board, stuk, plek, 'B');
        if(check(board, 'W')){
            cout << "Schaak" << endl;
        }
        if(checkmate(board, 'W')){
            cout << "Schaakmat";
            break;
    }
    }
}