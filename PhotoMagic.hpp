// "Copyright [2023] <Brandon Nguyen>"
#include <iostream>
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.hpp"

namespace PhotoMagic {
// Transforms image using FibLFSR
void transform(sf::Image& image, FibLFSR* fib);
// Display an encrypted copy of the picture, using the LFSR to do the encryption
}
