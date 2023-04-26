
#include "environnement/gameworld.h"

GameWorld::GameWorld(std::shared_ptr<Player> player) : _player{player} {}
GameWorld::GameWorld() { _player = std::shared_ptr<Player>(new Player()); }

GameWorld::~GameWorld(){};

void GameWorld::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  _player->draw(target, states);
}

void GameWorld::Update(std::chrono::nanoseconds duration) {
  _player->Update(duration);
}
