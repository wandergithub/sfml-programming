/*
Experimentation file.
*/
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>


void loadFromFile(const std::string& filename)
{
    std::ifstream fin(filename);
    std::string first, last;
    int id;
    float avg;

    while (fin >> first)
    {
        fin >> last >> id >> avg;

        std::cout << first << " " << last << " " << id << " " << avg << "\n";
    }
}


int main(int argc, char * argv[])
{
    loadFromFile("config.txt");

    return 0;
}