#include "HotPotato.hpp"
#include "QueueOfStrings.hpp"

#include <istream>  
#include <vector>
#include <string>

// You may want to #include others that we have talked about


std::string playHotPotato(std::istream &in, const std::vector<unsigned> & numOfPasses)
{
    // Initialized Variables
    std::string line;
    std::string moveToBack;
    QueueOfStrings hotPotato;

    // Linked List is created.
    while ( getline(in, line) && numOfPasses.size() > 0) {
        if (!line.empty())
            hotPotato.enqueue(line);
    }

    // Run Hot Potato.
    for (size_t i{0}; i < numOfPasses.size(); i++) {
        if (hotPotato.size() == 1)
            break;

        size_t finalPos{numOfPasses[i] % hotPotato.size()};
        for (size_t j{0}; j < finalPos; j++) 
        {
            hotPotato.enqueue(hotPotato.front());
            hotPotato.dequeue();
        }
        hotPotato.dequeue();
        hotPotato = hotPotato;

        if (hotPotato.size() != 1 && i == numOfPasses.size() - 1)
            i = -1;
    }

    return hotPotato.front();
}
