#include <iostream>
#include "ChessBoard.hpp"
#include "ChessBoardPrint.hpp"
#include "EchoServer.hpp"

int main() {
  ChessBoard board;
  ChessBoardPrint print(board);

  // Sett opp brikker her, f.eks.:
  board.squares[4][0] = std::make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares[4][7] = std::make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);

  board.move_piece("e1", "e2");
  board.move_piece("e2", "e3");
  board.move_piece("e3", "e4");
  board.move_piece("e4", "e5");
  board.move_piece("e5", "e6");
  board.move_piece("e6", "e7");
  board.move_piece("e7", "e8");
  
  EchoServer echo_server;
  
  std::cout << "Starting echo server" << std::endl
            << "Connect in a terminal with: telnet localhost 8080. Type 'exit' to end connection." << std::endl;
  
  echo_server.start();
}
