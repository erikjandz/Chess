#ifndef CHESS_LINK_HPP
#define CHESS_LINK_HPP

using namespace std;

bool movePawn(vector<vector<string>> board, vector<int> coord1, vector<int> coord2, char p);
bool moveKnight(vector<vector<string>> board, vector<int> coord1, vector<int> coord2, char p);
bool moveBischop(vector<vector<string>> board, vector<int> coord1, vector<int> coord2, char p);
bool moveRook(vector<vector<string>> board, vector<int> coord1, vector<int> coord2, char p);
bool moveKing(vector<vector<string>> board, vector<int> coord1, vector<int> coord2, char p);
void move(vector<vector<string>> & board, string piece, string place, char p);
bool check(vector<vector<string>> board, char p);
bool checkmate(vector<vector<string>> board, char p);

#endif //CHESS_LINK_HPP
