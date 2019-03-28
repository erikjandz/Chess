#ifndef CHESS_LINK_HPP
#define CHESS_LINK_HPP

using namespace std;

vector<vector<int>> movePawn(vector<vector<string>> board, vector<int> coord1, char p);
vector<vector<int>> moveKnight(vector<vector<string>> board, vector<int> coord1, char p);
vector<vector<int>> moveBischop(vector<vector<string>> board, vector<int> coord1, char p);
vector<vector<int>> moveRook(vector<vector<string>> board, vector<int> coord1, char p);
vector<vector<int>> moveKing(vector<vector<string>> board, vector<int> coord1, char p);
bool move(vector<vector<string>> & board, string piece, string place, char p);
bool check(vector<vector<string>> board, char p);
bool checkmate(vector<vector<string>> board, char p);

#endif //CHESS_LINK_HPP
