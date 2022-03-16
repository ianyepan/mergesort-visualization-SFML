#include "Bar.hpp"

#include <memory>

Bar::Bar(int _n, float _dy) : n(_n), dy(_dy) {
  rect = std::make_unique<sf::RectangleShape>(sf::Vector2f(2, dy * n));
  rect->setOrigin(0, dy * n);
  rect->setFillColor(sf::Color(72, 178, 234));
  rect->setOutlineThickness(1.0f);
  rect->setOutlineColor(sf::Color::Black);
}

auto Bar::getN() const -> int {
  return n;
}

void Bar::setN(int _n) {
  n = _n;
  rect->setSize(sf::Vector2f(w, dy * n));
  rect->setOrigin(0, dy * n);
}

auto Bar::getRect() const -> sf::RectangleShape & {
  return *rect;
}
