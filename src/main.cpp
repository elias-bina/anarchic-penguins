#include <cstdlib>
#include <ctime>
#include <iostream>

#include "constants.h"
#include "environnement/gameworld.h"
#include "game.h"

int main(int argc, char const *argv[]) {
  sf::RenderWindow window(sf::VideoMode(window_size_x, window_size_y), "Anarchic penguins è-é");
  window.setFramerateLimit(144);

  Game game(window);
  window.setActive(false);
  game.run();

  return 0;
}
