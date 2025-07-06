/** game.h
 *
 * Game entry point.
 * 
 */

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <SDL.h>
#include "randomnumber.h"
#include "medialayer.h"
#include "gameobject.h"
#include "component.h"

class Game{

public:


    Game():
        _media_layer(nullptr)
    {};

    ~Game(){};

    // Initializes Game
    bool initialize();

    // Initializes Game with media layer
    bool initialize(MediaLayer* media_layer);

    // Initializes Game with media layer and window dimension
    bool initialize(MediaLayer* media_layer, int window_width, int window_height);

    // Runs game loop
    void run_loop();

    // Shuts down game
    void shutdown();

    int rand(int min, int max);

    Vector2d get_bounds(){ return Vector2d(_window_width, _window_height); };

    std::vector<GameObject*> game_objects(){ return _game_objects; }

private:

    RandomNumber _rand;

    bool _is_running;
    int _window_width{720};
    int _window_height{480};
    MediaLayer* _media_layer;
    std::vector<GameObject*> _game_objects;

    // Create Ship
    void create_ship();

    // create asteroids
    void create_asteroids();

    // Retrieves and handles keyboard input from media layer
    void process_input();

    // Update game objects
    void update_game();

    // Renders updated game objects
    void generate_output();

    // Converts keyboard input to game action
    Component::Game_Action_Code map_action(Medialayer_Key_Code key);

};
#endif