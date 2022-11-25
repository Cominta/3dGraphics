#ifndef MAIN_STATE_H
#define MAIN_STATE_H

#include "state.h"

class MainState : public State
{
    private: 
        sf::Shader shader;
        
        sf::RectangleShape* sprite;

    public:
        MainState(sf::RenderWindow* window);
        ~MainState();

        void update();
        void render();
};

#endif