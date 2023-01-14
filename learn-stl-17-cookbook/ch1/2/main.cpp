#include <string>
#include <iostream>
#include <map>
using namespace std;
int main(int argc, char ** argv)
{
    // example 1: if statement
    {

        std::map<char, int> character_map;
        character_map['a'] = 1;
        character_map['b'] = 2;
        character_map['c'] = 3;
        character_map['d'] = 4;
        character_map['e'] = 5;
        const char c('c');
        if (auto itr(character_map.find(c)); itr != character_map.end())
        {
            auto &[character, value] = *itr; // C++17 structured binding
            std::cout << "Found " << character << " with value " << value << '\n';
        }
        else
        {
            std::cout << "Could not find " << c << '\n';
        }
        // itr is not available here at all
        // std::cout<<*itr<<'\n'; // error: ‘itr’ was not declared in this scope
    }

    // example 2: switch statement
    switch (char c(getchar()); c)
    {
    case 'a':
        std::cout << "move left" << '\n';
        break;
    case 's':
        std::cout << "move back" << '\n';
        break;
    case 'w':
        std::cout << "move forward" << '\n';
        break;
    case 'd':
        std::cout << "move right" << '\n';
        break;
    case 'q':
        std::cout << "quit game" << '\n';
        break;
    case '0' ... '9':
        std::cout << "select tool " << c << '\n';
        break;
    default:
        std::cout << "invalid input: " << c << '\n';
    }

    return 0;
}