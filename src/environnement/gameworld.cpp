
#include "environnement/gameworld.h"

GameWorld::GameWorld(std::shared_ptr<Player> player) : _player{player} {}
GameWorld::GameWorld() { _player = std::shared_ptr<Player>(new Player()); }

GameWorld::~GameWorld(){};

void GameWorld::Display(sf::RenderWindow &window) { _player->Display(window); }

void GameWorld::Update(std::chrono::nanoseconds duration) {
  _player->Update(duration);
}
