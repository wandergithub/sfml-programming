#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

class App {
    int w_width, w_height;

    void loadConfig(const std::string& filename)
    {
        std::fstream config_file(filename);
        std::string type;

        while (config_file >> type)
        {
            if (type == std::string("Window"))
            {
                config_file >> w_width >> w_height;
            }
            else if ("")
            {
                continue;
            }
            else
            {
                continue;
            }
            
        }
        
    }

public:

    // Game initizlization
    App()
    {
        loadConfig("config.txt");
        sf::Window window(sf::VideoMode(w_width, w_height), "Project 1");
        
        // std::cout << w_width << " " << w_height << "\n";
    }
};



int main (int argc, char * argv[])
{
    App game;
    return 0;
}