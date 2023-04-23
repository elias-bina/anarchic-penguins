#include <cstdlib>
#include <ctime>
#include <iostream>

#include "environnement/gameworld.h"
#include "game.h"

int main(int argc, char const *argv[]) {

  sf::RenderWindow window(sf::VideoMode(1000, 700), "Anarchic penguins è-é");
  window.setFramerateLimit(60);

  Game game(window);
  game.run();

  std::shared_ptr<Player> player = std::shared_ptr<Player>(new Player());
  std::shared_ptr<GameWorld> world =
      std::shared_ptr<GameWorld>(new GameWorld(player));
  std::cout << "Hello mario, your player is at " << world->_player->_position._x
            << ";" << world->_player->_position._y << std::endl;
  std::srand(std::time(nullptr));
  for (uint32_t i = 0; i < 10; i++) {
    int choice = std::rand() % 4;
    switch (choice) {
    case 0:
      world->_player->move_x(1);
      break;
    case 1:
      world->_player->move_x(-1);
      break;
    case 2:
      world->_player->move_y(1);
      break;
    case 3:
      world->_player->move_y(-1);
      break;

    default:
      break;
    }

    std::cout << "Hello mario, your player is at "
              << world->_player->_position._x << ";"
              << world->_player->_position._y << std::endl;
  }

  return 0;
}
