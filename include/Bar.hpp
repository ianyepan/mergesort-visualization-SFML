#pragma once

#include <SFML/Graphics.hpp>

#include <memory>

class Bar {
 public:
  Bar(int n, float _dy);
  ~Bar() = default;

  auto getN() const -> int;
  void setN(int n);
  auto getRect() const -> sf::RectangleShape &;

 private:
  int w{2};
  int n;
  float dy;
  std::unique_ptr<sf::RectangleShape> rect;
};
