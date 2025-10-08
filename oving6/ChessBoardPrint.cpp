#include "ChessBoardPrint.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

ChessBoardPrint::ChessBoardPrint(ChessBoard& board) : board(board) {
  board.after_piece_move = [this](const std::string& from, const std::string& to) {
    print_move(from, to);
    print_board();
  };
}

void ChessBoardPrint::print_move(const std::string& from, const std::string& to) {
  auto& piece = board.squares[to[0] - 'a'][stoi(string() + to[1]) - 1];
  if (piece)
    cout << piece->type() << " moved from " << from << " to " << to << endl;
}

void ChessBoardPrint::print_board() {
  ostringstream oss;

  for (size_t col = 0; col < board.squares.size(); ++col)
    oss << "+---";
  oss << "+" << endl;

  for (int row = board.squares[0].size() - 1; row >= 0; --row) {
    oss << "|";
    for (size_t col = 0; col < board.squares.size(); ++col) {
      string cell = "";
      if (board.squares[col][row])
        cell = board.squares[col][row]->short_type();
      oss << setw(3) << cell << "|";
    }
    oss << endl;

    for (size_t col = 0; col < board.squares.size(); ++col)
      oss << "+---";
    oss << "+" << endl;
  }

  cout << oss.str();
}
