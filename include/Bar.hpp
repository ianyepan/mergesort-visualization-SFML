#pragma once

#include <SFML/Graphics.hpp>

#include <memory>

class Bar {
 public:
  Bar(int n, float _dy);

  auto getRect() -> sf::RectangleShape &;
  auto getN() const -> int;
  void setN(int n);

 private:
  int w{2};
  int n;
  float dy;
  std::unique_ptr<sf::RectangleShape> rect;
};
