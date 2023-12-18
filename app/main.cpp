#include <string>
#include <fstream>  
#include <iostream>
#include "QueueOfStrings.hpp"
#include "HotPotato.hpp"

int main()
{
    std::ifstream in{"hp_names_1.txt"};
    std::vector<unsigned> numOfPasses{};
    std::cout << playHotPotato(in, numOfPasses) << std::endl;
}

