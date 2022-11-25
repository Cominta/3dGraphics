#include "mainState.h"

MainState::MainState(sf::RenderWindow* window)
    : State(window)
{
    this->shader.loadFromFile("shaderSolid.frag", sf::Shader::Fragment);

    this->sprite = new sf::RectangleShape(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
}

MainState::~MainState()
{
    
}

void MainState::update()
{
    this->updateMouse();
}

void MainState::render()
{   
    sf::Clock* clockSFML = new sf::Clock();
    shader.setUniform("u_resolution", sf::Glsl::Vec2{this->window->getSize()});

    this->window->draw((*this->sprite), &this->shader);
}