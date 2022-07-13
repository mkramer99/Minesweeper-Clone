#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include "Board.h"
using namespace std;
using namespace sf;


int main() {
    Board game;
    int width = (game.columns * 32);
    int height = ((game.rows * 32) + 100);
    RenderWindow window(sf::VideoMode(width, height), "Minesweeper");
    //window.setKeyRepeatEnabled(false);

    while (window.isOpen()) {
        Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();


            window.clear();
            game.Update(window, event);
            window.display();
        }
    }
    return 0;
}
