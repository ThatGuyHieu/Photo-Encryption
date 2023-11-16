// "Copyright [2023] <Brandon Nguyen>"
#pragma once
#include <iostream>
#include <string>
#include <bitset>

class FibLFSR {
 public:
    // Constructor to create LFSR with the given initial seed
    explicit FibLFSR(std::string seed);

    // Simulate one step and return the new bit as 0 or 1
    int step();

    // Simulate k steps and return a k-bit integer
    int generate(int k);

    friend std::ostream& operator<<(std::ostream& cout, const FibLFSR& lfsr);

 private:
    // Any fields that you need
    std::bitset<16>bit_list;
};

std::ostream& operator<<(std::ostream& cout, const FibLFSR& lfsr);
