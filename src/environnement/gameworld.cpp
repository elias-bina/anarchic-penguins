#include <iostream>

#include "environnement/gameworld.h"

GameWorld::GameWorld() {}

GameWorld::~GameWorld(){};

std::optional<Player *> GameWorld::get_free_player(NewPlayerChoice player_choice, uint32_t from_player_index) {
  if (player_choice == NewPlayerChoice::RANDOM_PLAYER) {
    // TODO : Real rand
    from_player_index = 0;
  } else if (from_player_index >= _player_list.size()) {
    return std::nullopt;
  }

  if (player_choice == NewPlayerChoice::NEXT_PLAYER) {
    std::vector<Player>::iterator free_player_iterator;

    std::vector<Player>::iterator search_start_it = _player_list.begin();
    std::advance(search_start_it, from_player_index);

    // Cycle through players in increasing order starting from "from_player_index"

    free_player_iterator =
        std::find_if(search_start_it, _player_list.end(), [](Player p) { return !p.has_controller(); });

    // At the end of the list, cycle from the start to the chosen index

    if (free_player_iterator == _player_list.end()) {
      free_player_iterator =
          std::find_if(_player_list.begin(), search_start_it, [](Player p) { return !p.has_controller(); });
      if (free_player_iterator == search_start_it) {
        return std::nullopt;
      }
    }
    return &(*free_player_iterator);
  } else if (player_choice == NewPlayerChoice::PREVIOUS_PLAYER) {
    std::vector<Player>::reverse_iterator free_player_iterator;


    // Cycle through players in decreasing order starting from "from_player_index"

    std::vector<Player>::reverse_iterator search_start_it = _player_list.rbegin();
    std::advance(search_start_it, (_player_list.size() - 1) - from_player_index);

    free_player_iterator =
        std::find_if(search_start_it, _player_list.rend(), [](Player p) { return !p.has_controller(); });

    if (free_player_iterator == _player_list.rend()) {
      free_player_iterator =
          std::find_if(_player_list.rbegin(), search_start_it, [](Player p) { return !p.has_controller(); });
      if (free_player_iterator == search_start_it) {
        return std::nullopt;
      }
    }
    return &(*free_player_iterator);
  }
  return std::nullopt;
}

void GameWorld::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  for (size_t i = 0; i < _player_list.size(); i++) {
    _player_list[i].draw(target, states);
  }
}

void GameWorld::Update(std::chrono::nanoseconds duration) {
  // TODO: Check if there is a player with unbinded controller

  _player_list_mutex.lock();
  for (size_t i = 0; i < _player_list.size(); i++) {
    _player_list[i].Update(duration);
  }
  _player_list_mutex.unlock();
}
