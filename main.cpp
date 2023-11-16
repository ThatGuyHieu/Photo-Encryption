// "Copyright [2023] <Brandon Nguyen>"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.hpp"
#include "PhotoMagic.hpp"

using PhotoMagic::transform;

int main(int argc, char* argv[]) {
    FibLFSR fib(argv[3]);

    sf::Image image;

    if (!image.loadFromFile(argv[1])) {
        return -1;
    }

    sf::Vector2u size = image.getSize();
    sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "input-file");

    sf::Texture texture;
    texture.loadFromImage(image);

    sf::Sprite sprite;
    sprite.setTexture(texture);

    transform(image, &fib);

    sf::RenderWindow window2(sf::VideoMode(size .x, size .y), "output-file");

    sf::Texture texture2;
    if (!texture2.loadFromImage(image)) {
        return -1;
    }

    sf::Sprite sprite2;
    sprite2.setTexture(texture2);

    while (window1.isOpen() && window2.isOpen()) {
        sf::Event event;
        while (window1.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window1.close();
        }

        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            window2.close();
        }

        window1.clear();
        window1.draw(sprite);
        window1.display();
        window2.clear();
        window2.draw(sprite2);
        window2.display();
    }
    if (!image.saveToFile(argv[2])) {
        return 1;
    }
    return 0;
}
