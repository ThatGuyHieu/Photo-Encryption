// "Copyright [2023] <Brandon Nguyen>"
#include <iostream>
#include <string>
#include "FibLFSR.hpp"

FibLFSR::FibLFSR(std::string seed) : bit_list(seed) {
    std::bitset<16>init(seed);
    bit_list = init;
}

int FibLFSR::step() {
    bool step_XOR = bit_list[15] ^ bit_list[13] ^ bit_list[12] ^ bit_list[10];
    bit_list = bit_list << 1;
    bit_list[0] = step_XOR;
    return step_XOR;
}

int FibLFSR::generate(int k) {
    int gene = 0;
    for (int i = 0; i < k; i++) {
        gene *= 2;
        gene += step();
    }
    return gene;
}

std::ostream& operator<<(std::ostream& cout, const FibLFSR& lfsr) {
    return cout << lfsr.bit_list;
}
