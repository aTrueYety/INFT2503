#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <functional>

class ChessBoard {
public:
  enum class Color { WHITE, BLACK };

  class Piece {
  public:
    Piece(Color color);
    virtual ~Piece();

    Color color;
    std::string color_string() const;
    std::string short_color_string() const;

    virtual std::string short_type() const = 0;
    virtual std::string type() const = 0;
    virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
  };

  class King : public Piece {
  public:
    King(Color color);
    std::string type() const override;
    std::string short_type() const override;
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override;
  };

  class Knight : public Piece {
  public:
    Knight(Color color);
    std::string type() const override;
    std::string short_type() const override;
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override;
  };

  ChessBoard();

  std::vector<std::vector<std::unique_ptr<Piece>>> squares;
  std::function<void(const std::string& from, const std::string& to)> after_piece_move;
  
  bool move_piece(const std::string &from, const std::string &to);
};
