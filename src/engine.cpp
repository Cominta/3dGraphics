#include "engine.h"

Engine::Engine()
{
    this->delta = 0.0f;

    this->window = new sf::RenderWindow(sf::VideoMode(1100, 800), "3dGraphics");
    this->states.push(new MainState(this->window));
}

Engine::~Engine()
{
    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

void Engine::start()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
        this->deltaClock.restart();
    }
}

void Engine::update()
{
    this->updateSFML();
    this->updateDelta();

    if (!this->states.empty())
    {
        this->states.top()->update();
    }

    this->mousePress = false;
}

void Engine::updateSFML()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
        {
            this->window->close();
        }

        else if (this->sfEvent.mouseButton.button == sf::Mouse::Button::Left && this->sfEvent.type == sf::Event::MouseButtonReleased)
        {
            this->mousePress = true;
        }
    }
}

void Engine::updateDelta()
{
    this->delta = this->deltaClock.getElapsedTime().asSeconds();
}

void Engine::render()
{
    this->window->clear();

    if (!this->states.empty())
    {
        this->states.top()->render();
    }

    this->window->display();
}