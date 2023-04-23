
#include "environnement/gameworld.h"

GameWorld::GameWorld(std::shared_ptr<Player> player) : _player{player} {}
GameWorld::GameWorld() { _player = std::shared_ptr<Player>(new Player()); }

GameWorld::~GameWorld() {}