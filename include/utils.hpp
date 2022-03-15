#pragma once

#include "Bar.hpp"
#include "constants.hpp"

#include <algorithm>
#include <memory>
#include <random>
#include <utility>
#include <vector>

namespace utils {

inline void shuffle(std::vector<int> &v) {
  std::random_device rd;
  auto randomEngine = std::default_random_engine{rd()};
  std::shuffle(v.begin(), v.end(), randomEngine);
}

inline void renderBars(const std::vector<std::unique_ptr<Bar>> &bars, sf::RenderWindow &window) {
  for (int i = 0; i < constants::numCount; ++i) {
    bars[i]->getRect().setPosition((global::barWidth * i) + 1, window.getSize().y);
  }
  window.clear(sf::Color::White);
  for (int i = 0; i < constants::numCount; ++i) {
    window.draw(sf::RectangleShape(bars[i]->getRect()));
  }
  window.display();
}

inline void updateBars(const std::vector<std::unique_ptr<Bar>> &bars, std::vector<int> &numbers) {
  for (int i = 0; i < constants::numCount; ++i) {
    bars[i]->setN(numbers[i]);
  }
}

inline auto barsNumbersSetup(sf::RenderWindow &window)
  -> std::pair<std::vector<std::unique_ptr<Bar>>, std::vector<int>> {
  std::vector<std::unique_ptr<Bar>> bars(constants::numCount);
  std::vector<int> numbers(constants::numCount);

  float dy = window.getSize().y / constants::numCount * constants::heightScale;

  for (int i = 0; i < constants::numCount; ++i) {
    bars[i] = std::make_unique<Bar>(i, dy);
    numbers[i] = i;
  }

  utils::shuffle(numbers);

  utils::updateBars(bars, numbers);

  utils::renderBars(bars, window);

  return {std::move(bars), std::move(numbers)};
}

}  // namespace utils
