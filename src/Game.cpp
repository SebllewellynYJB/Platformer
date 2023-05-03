#include <iostream>

#include "Game.h"

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
// This is where all the details about text and objects are set. e.g. texture, position, scale and colour
// For text. Loads the font then it can be set for text on screen
// For Sprites. Loads the texture from the file then sets the sprite to the texture
// For Game Objects uses a similar process but does it all at once
// For audio. Loads the file for sound effect. Opens the file for music
{
  //Menu information
  in_menu = true;

  // Menu background
  if (!menu_bakcground_texture.loadFromFile("Data/Images/img.png"))
  {
    std::cout << "background did not load\n";
  }
  menu_background.setTexture(menu_bakcground_texture);
  menu_background.setScale(2.4,2.5);

  //Font information
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }

  // Menu text information
  title_text.setString("Platform Game");
  title_text.setFont(font);
  title_text.setCharacterSize(70);
  title_text.setFillColor(sf::Color::White);
  title_text.setPosition(275,0);

  play.setString("Play");
  play.setFont(font);
  play.setCharacterSize(40);
  play.setFillColor(sf::Color::Black);
  play.setPosition(360,200);

  quit.setString("Quit");
  quit.setFont(font);
  quit.setCharacterSize(40);
  quit.setFillColor(sf::Color::Black);
  quit.setPosition(560,200);

  instructions.setString("How to play");
  instructions.setFont(font);
  instructions.setCharacterSize(40);
  instructions.setFillColor(sf::Color(0,0,0));
  instructions.setPosition(10,275);

  menu_instructions.setString("Use left and right arrows to navigate menu, press enter to move on");
  menu_instructions.setFont(font);
  menu_instructions.setCharacterSize(20);
  menu_instructions.setFillColor(sf::Color::White);
  menu_instructions.setPosition(10,350);

  player_instructions.setString("Player- Left to move left, Right to move right, Space to jump");
  player_instructions.setFont(font);
  player_instructions.setCharacterSize(20);
  player_instructions.setFillColor(sf::Color::White);
  player_instructions.setPosition(10,400);

  coin_instructions.setString("Collect coins to gain score");
  coin_instructions.setFont(font);
  coin_instructions.setCharacterSize(20);
  coin_instructions.setFillColor(sf::Color::White);
  coin_instructions.setPosition(10,450);

  quit_any.setString("Press Q to quit at any time");
  quit_any.setFont(font);
  quit_any.setCharacterSize(20);
  quit_any.setFillColor(sf::Color::Red);
  quit_any.setPosition(10,500);

  score_text.setFont(font);
  score_text.setCharacterSize(50);
  score_text.setFillColor(sf::Color(255,0,0));
  score_text.setPosition(1000,10);

  lives_text.setFont(font);
  lives_text.setCharacterSize(50);
  lives_text.setFillColor(sf::Color(255,0,0));
  lives_text.setPosition(10,10);

  game_over_text.setFont(font);
  game_over_text.setString("Game over");
  game_over_text.setCharacterSize(20);
  game_over_text.setPosition(500,400);
  // Game screen information
  if (!game_background_texture.loadFromFile("Data/Images/kenney_physicspack/PNG/Backgrounds/colored_desert.png"))
  {
    std::cout << "background did not load\n";
  }
  game_background.setTexture(game_background_texture);
  game_background.setScale(1.25,0.75);

  if (!start_flag_texture.loadFromFile("Data/Images/kenney_physicspack/PNG/Other/flagYellow.png"))
  {
    std::cout << "background did not load\n";
  }
  start_flag.setTexture(start_flag_texture);
  start_flag.setScale(0.5,0.5);
  start_flag.setPosition(10,635);

  // Player details. Sets the speed and direction for the player that is used in update
  player.initialiseSprite(player_texture , "Data/Images/kenney_tooncharacters1/Male person/Poses/character_malePerson_attack0.png");
  player.getSprite()->setPosition(10,550);
  player.getSprite()->setScale(1,1);
  player.setSpeed(250);
  player.setPlayerDirection(Vector2{0,0});
  //player.getSprite()->setTextureRect(player_texture_rectangle);
  //player_texture_rectangle = sf::IntRect (0,player_texture.getSize().y/5*4,
                                         //player_texture.getSize().x/9,
                                         //player_texture.getSize().y/5);

  // Enemy info
  enemy.initialiseSprite(enemy_texture , "Data/Images/kenney_pixelplatformer/Characters/character_0006.png");
  enemy.getSprite()->setPosition(700,665);
  enemy.getSprite()->setScale(1.5,1.5);

  moving_enemy.initialiseSprite(moving_tile_texture , "Data/Images/kenney_physicspack/PNG/Aliens/alienPink_square.png");
  moving_enemy.getSprite()->setPosition(400,500);
  moving_enemy.getSprite()->setScale(0.5,0.5);
  moving_enemy.setSpeed(200);
  moving_enemy.setDirection(Vector2{1,1});

  // Arrays for the game. Structure was taken from worksheet 3- Breakout
  // Creates an array that will apply all settings to each individual texture
  for (int i = 0; i < no_of_tiles; i++)
  {
    tile[i].initialiseSprite(tile_texture , "Data/Images/kenney_pixelplatformer/Tiles/tile_0000.png");
    tile[i].getSprite()->setScale(15,2);
    tile[i].getSprite()->setPosition(0 + 400 * i, 675);
  }

  // Creates an array that will apply all settings to each individual texture
  for (int i = 0; i < no_of_platform_tiles; i++)
  {
    platform_tile[i].initialiseSprite(platform_tile_texture ,"Data/Images/kenney_pixelplatformer/Tiles/tile_0002.png");
    platform_tile[i].getSprite()->setScale(2,2);
    platform_tile[i].getSprite()->setPosition(600 + 20 * i,500);
  }
  platform_tile[24].setIsVisible(false);
  platform_tile[25].setIsVisible(false);

  // Creates an array. All variables will apply to each individual texture
  for (int i = 0; i < no_of_coins; i++)
  {
    coin[i].initialiseSprite(coin_texture,"Data/Images/kenney_physicspack/PNG/Other/coinGold.png");
    coin[i].getSprite()->setPosition(700+500*i,580);
    coin[i].getSprite()->setScale(0.5,0.5);
  }

  // Audio in the game. This includes the music and the sound effect for the player death and coin collection
  if(!game_music.openFromFile("Data/577391__szegvari__desert-fly-orchestra-atmo (1).wav"))
  {
    std::cout << "Music did not load\n";
  }
  game_music.play();
  game_music.setVolume(10.0f);

  if (death_sound_buffer.loadFromFile("Data/555412__tonsil5__zombie-death-1.wav"))
  {
    std::cout << "sound did not load\n";
  }
  death_sound.setBuffer(death_sound_buffer);
  death_sound.setVolume(200);

  if (coin_sound_buffer.loadFromFile("Data/341695__projectsu012__coins-1.wav"))
  {
    std::cout << "sound did not load\n";
  }
  coin_sound.setBuffer(coin_sound_buffer);
  coin_sound.setVolume(200);

  // Different camera views - Includes menu and split screen for game screen
  view.setCenter(window.getSize().x/2, window.getSize().y/2);
  view.setSize(window.getSize().x/1, window.getSize().y/1);

  view1.setCenter(window.getSize().x/2, window.getSize().y/2);
  view1.setSize(window.getSize().x/1, window.getSize().y/1);
  game_background_texture.setRepeated(true);
  game_background.setTextureRect(sf::IntRect(0,0,game_background.getGlobalBounds().width*2, game_background.getGlobalBounds().height*2));

  view2.setCenter(window.getSize().x/2, window.getSize().y/2);
  view2.setSize(window.getSize().x/1, window.getSize().y/1);
  view1.setViewport(sf::FloatRect(0.0f,0.0f,1.0f,0.5f));
  view2.setViewport(sf::FloatRect(0.0f, 0.5f,1.0f,0.5f));

  return true;
}

void Game::update(float dt, sf::Event event)
// This will update different aspects of the game every frame. e.g. collision and movement
{
  collision(*player.getSprite(),*moving_enemy.getSprite());
  // Moves camera 2 right in the x-axis
  view2.move(1.0f,0.0f);
  for (int i = 0; i < no_of_tiles; i++)
  {
    if (collision(*player.getSprite(),*tile[i].getSprite()))
    {
      player.player_direction.y= 0;
    }
  }

  for (int i = 0; i < no_of_platform_tiles; i++)
  {
    if (collision(*player.getSprite(),*platform_tile[i].getSprite()))
    {
      player.player_direction.y= 0;
    }
  }

  //Updates collision between player and coin
  for (int i = 0; i < no_of_coins; i++)
  {
    if (collision(*player.getSprite(),*coin[i].getSprite()))
    {
      coin[i].setIsvisible(true);
    }
  }

  // Resets players location when they leave the screen at the y-axis
  // Takes off one of the players lives
  // Plays a death sound effect - Displays dead in the console
  // Resets view 1 to default settings
  for (int i = 0; i < no_of_tiles; i++)
  {
    if (player.getSprite()->getPosition().y > tile[i].getSprite()->getPosition().y)
    {
      player.getSprite()->setPosition(10,545);
      player.player_direction.y = 0;
      number_of_lives--;
      death_sound.play();
      std::cout << "Dead\n";
      view1.setCenter(window.getSize().x/2, window.getSize().y/2);
      view1.setSize(window.getSize().x/1, window.getSize().y/1);
      game_background_texture.setRepeated(true);
      game_background.setTextureRect(sf::IntRect(0,0,game_background.getGlobalBounds().width*2, game_background.getGlobalBounds().height*2));
    }
  }

  // checks to see if the players lives is less than - 3. if true, then the window will close
  if (number_of_lives < -3)
  {
    std::cout << "Game Over\n";
    gameState = GameOver;
    window.draw(game_over_text);
    window.close();
  }

  switch (gameState)
  {
      // update game objects
    case Running:
      break;
      // display game over message
      // wait for user to restart game
    case GameOver:
      break;
  }

  restart();

  // Updates collision and movement for tile
  moving_enemy.move(window, dt);

  // Updates player movement
  player.move(window,dt,event);

  //Animation code
  //if (animation_clock.getElapsedTime().asSeconds() > 0.1)
  {
     //player_texture_rectangle.left += player_texture.getSize().x/9;
     //if ( player_texture_rectangle.left >= player_texture.getSize().x/9 * 7)
    {
      //player_texture_rectangle.left = 0;
    }
     //player.getSprite()->setTextureRect(player_texture_rectangle);
     //animation_clock.restart();
  }
}

void Game::render()
// This will render all the text and objects to the screen that was created in the init function
{
  // Renders menu
  if (in_menu)
  // Text and textures that are rendered to the menu
  {
    window.setView(view);
    window.draw(menu_background);
    window.draw(title_text);
    window.draw(play);
    window.draw(quit);
    window.draw(menu_instructions);
    window.draw(instructions);
    window.draw(player_instructions);
    window.draw(coin_instructions);
    window.draw(quit_any);
  }
  else
  // Game objects and Background rendered for view 1
  {
    window.setView(view1);
    window.draw(game_background);
    window.draw(start_flag);
    window.draw(*player.getSprite());
    window.draw(*enemy.getSprite());
    window.draw(*moving_enemy.getSprite());
    window.draw(score_text);
    score_text.setString(std::to_string(score));
    window.draw(lives_text);
    lives_text.setString(std::to_string(number_of_lives-0));
    for (int i = 0; i < no_of_tiles; i++)
    {
      if (tile[i].isVisible())
      {
        window.draw(*tile[i].getSprite());
      }
    }
    for (int i = 0; i < no_of_platform_tiles; i++)
    {
      if (platform_tile[i].isVisible())
      {
        window.draw(*platform_tile[i].getSprite());
      }
    }
    for (int i = 0; i < no_of_coins; i++)
    {
      if (coin[i].isIsvisible())
      {
        window.draw(*coin[i].getSprite());
      }
    }

    // Same items rendered in view 2
    window.setView(view2);
    window.draw(game_background);
    window.draw(start_flag);
    window.draw(score_text);
    score_text.setString(std::to_string(score));
    window.draw(*player.getSprite());
    window.draw(*enemy.getSprite());
    window.draw(*moving_enemy.getSprite());
    window.draw(lives_text);
    lives_text.setString(std::to_string(number_of_lives-0));
    for (int i = 0; i < no_of_tiles; i++)
    {
      if (tile[i].isVisible())
      {
        window.draw(*tile[i].getSprite());
      }
    }
    for (int i = 0; i < no_of_platform_tiles; i++)
    {
      if (platform_tile[i].isVisible())
      {
        window.draw(*platform_tile[i].getSprite());
      }
    }
    for (int i = 0; i < no_of_coins; i++)
    {
      if (coin[i].isIsvisible())
      {
        window.draw(*coin[i].getSprite());
      }
    }
  }
}

void Game::keyPressed(sf::Event event, float dt)
// When the key is pressed. An event will happen
{
  // menu keys for play and quit
  if ((event.key.code == sf::Keyboard::Left) ||
      (event.key.code == sf::Keyboard::Right))
  {
    play_selected = !play_selected;
    if (play_selected)
    {
      play.setString("> Play <");
      quit.setString("Quit");
    }
    else
    {
      play.setString("Play");
      quit.setString("> Quit <");
    }
  }
  // Menu keys for loading next screen
  else if (event.key.code == sf::Keyboard::Enter)
  {
    if (play_selected)
    {
      in_menu = false;
    }
    else
    {
      window.close();
    }
  }
  // Keys to close menu
  if (event.key.code == sf::Keyboard::Q)
  {
    window.close();
  }
  //Key events that move player - includes movement across the x-axis using A and D keys and jumping using space bar
  if (event.key.code == sf::Keyboard::A)
  {
    player.player_direction.x = -1;
    view1.move(-5.0f ,0);
    // Flips player texture when key is pressed, so it will face the direction the player is moving
    player.getSprite()->setTextureRect(sf::IntRect(player.getSprite()->getLocalBounds().width, 0, -player.getSprite()->getLocalBounds().width, player.getSprite()->getLocalBounds().height));
  }
  else if (event.key.code == sf::Keyboard::D)
  {
    player.player_direction.x = 1;
    view1.move(5.0f,0);
    // Flips player texture when key is pressed, so it will face the direction the player is moving
    player.getSprite()->setTextureRect(sf::IntRect(0, 0, player.getSprite()->getLocalBounds().width, player.getSprite()->getLocalBounds().height));
  }
  if(event.key.code == sf::Keyboard::Space)
  {
    player.player_direction.y = -1;
  }
}

void Game::keyReleased(sf::Event event)
// When the key is released. The event will stop happening
{
}

bool Game::collision(sf::Sprite sprite1 , sf::Sprite sprite2)
// Handles the collision of different sprites and game objects in the game
{
  // Collision between player and coins
  for (int i = 0; i < no_of_coins; i++)
  {
    if (player.getSprite()->getGlobalBounds().intersects(coin[i].getSprite()->getGlobalBounds()))
    {
      std::cout << "Coin collected\n";
      coin[i].setIsvisible(false);
      score=+1;
      coin_sound.play();
      return true;
    }
  }

  // Collision between player and tiles
  for (int i = 0; i < no_of_tiles; i++)
  {
    if (player.getSprite()->getGlobalBounds().intersects(tile[i].getSprite()->getGlobalBounds()))
    {
      //std::cout << "Collision\n";
      onground = true;
      return true;
    }
  }

  // Collision between player and tiles
  for (int i = 0; i < no_of_platform_tiles; i++)
  {
    if (player.getSprite()->getGlobalBounds().intersects(platform_tile[i].getSprite()->getGlobalBounds()))
    {
      //std::cout << "Collision\n";
      player.player_direction.y = 0;
      return true;
    }
  }

  // Collision between the player and the moving enemy
  if (player.getSprite()->getGlobalBounds().intersects(moving_enemy.getSprite()->getGlobalBounds()))
  {
    std::cout << "Dead\n";
    player.player_direction.x = 0;
    player.player_direction.y = 0;
    return true;
  }
  return false;
}

void Game::restart()
{
  // reset game objects
  gameState = Running;
}