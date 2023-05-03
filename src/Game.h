#ifndef Game_H
#define Game_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Coin.h"
#include "Enemy.h"
#include "GameObject.h"
#include "Player.h"
#include "Tile.h"

class Game
{

 public:
  // Functions
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt, sf::Event event);
  void render();
  void keyPressed(sf::Event event, float dt);
  void keyReleased(sf::Event event);
  bool collision(sf::Sprite sprite1 , sf::Sprite sprite2);
  void restart();

  // Game states
  enum GameState { Running, GameOver };
  GameState gameState;

  // Game Objects
  Player player;
  sf::Texture player_texture;
  sf::IntRect player_texture_rectangle;

  Tile tile[50];
  sf::Texture tile_texture;
  int no_of_tiles = 50;

  Tile platform_tile[25];
  sf::Texture platform_tile_texture;
  int no_of_platform_tiles = 25;

  Enemy moving_enemy;
  sf::Texture moving_tile_texture;

  Coin coin[15];
  sf::Texture coin_texture;
  int no_of_coins = 15;

  Enemy enemy;
  sf::Texture enemy_texture;

 private:
  sf::RenderWindow& window;

  // Menu information
  sf::View view;
  sf::Font font;
  sf::Sprite menu_background;
  sf::Texture menu_bakcground_texture;
  sf::Text title_text;
  bool play_selected = true;
  bool in_menu;
  sf::Text play;
  sf::Text quit;
  sf::Text quit_any;
  sf::Text instructions;
  sf::Text player_instructions;
  sf::Text menu_instructions;
  sf::Text coin_instructions;

  // Game screen information
  sf::View view1;
  sf::View view2;
  sf::Sprite game_background;
  sf::Texture game_background_texture;
  int score = 0;
  sf::Text score_text;
  int number_of_lives = 0;
  sf::Text lives_text;
  sf::Sprite start_flag;
  sf::Texture start_flag_texture;
  bool onground = false;

  // Game over screen information
  sf::Text game_over_text;

  // Audio in game
  sf::Music game_music;
  sf::SoundBuffer death_sound_buffer;
  sf::Sound death_sound;
  sf::SoundBuffer coin_sound_buffer;
  sf::Sound coin_sound;

  sf::Clock animation_clock;

};

#endif // PLATFORMER_GAME_H
