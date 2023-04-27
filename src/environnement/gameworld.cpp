
#include "environnement/gameworld.h"

GameWorld::GameWorld() { _player_list.push_back(std::shared_ptr<Player>(new Player())); }

GameWorld::~GameWorld(){};

void GameWorld::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  for (size_t i = 0; i < _player_list.size(); i++) {
    _player_list[i]->draw(target, states);
  }
}

void GameWorld::Update(std::chrono::nanoseconds duration) {
  for (size_t i = 0; i < _player_list.size(); i++) {
    _player_list[i]->Update(duration);
  }
}
