// "Copyright [2023] <Brandon Nguyen>"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "PhotoMagic.hpp"
#include "FibLFSR.hpp"

namespace PhotoMagic {
    void transform(sf::Image& image, FibLFSR* fib) {
        sf::Color p;
        for (std::size_t x = 0; x < image.getSize().x; x++) {
            for (std::size_t y = 0; y < image.getSize().y; y++) {
                p = image.getPixel(x, y);
                p.r = p.r ^ fib -> generate(8);
                p.g = p.g ^ fib -> generate(8);
                p.b = p.b ^ fib -> generate(8);
                image.setPixel(x, y, p);
            }
        }
    }
}  // namespace PhotoMagic
