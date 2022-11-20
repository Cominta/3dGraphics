#include "mainState.h"

MainState::MainState(sf::RenderWindow* window)
    : State(window)
{

}

MainState::~MainState()
{
    delete this->window;
}

void MainState::update()
{
    
}

void MainState::render()
{

}