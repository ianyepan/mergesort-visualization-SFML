#include "algo.hpp"
#include "Bar.hpp"
#include "utils.hpp"
#include "constants.hpp"

#include <cstdlib>
#include <functional>
#include <thread>

auto main() -> int {
  sf::RenderWindow window(sf::VideoMode(constants::windowWidth, constants::windowHeight),
                          "Mergesort visualization in C++ (SFML & OpenGL)",
                          sf::Style::Close);
  auto desktopMode = sf::VideoMode::getDesktopMode();
  window.setPosition({(int)desktopMode.width / 2 - (int)window.getSize().x / 2,
                      (int)desktopMode.height / 2 - (int)window.getSize().y / 2});

  global::barWidth = (float)window.getSize().x / constants::numCount;
  auto [bars, numbers] = utils::barsNumbersSetup(window);

  // Concurrency
  std::thread thread(algo::mergeSort, std::ref(numbers), 0, constants::numCount - 1);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    utils::updateBars(bars, numbers);
    utils::renderBars(bars, window);
  }

  thread.join();

  return EXIT_SUCCESS;
}
