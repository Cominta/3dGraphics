#ifndef MAIN_STATE_H
#define MAIN_STATE_H

#include "state.h"
#include "3dEngine.h"

class MainState : public State
{
    public:
        MainState(sf::RenderWindow* window);
        ~MainState();

        void update();
        void render();
};

#endif