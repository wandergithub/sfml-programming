#include <SFML/Graphics/Font.hpp>
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
            
        };
        
    };

    void loadFont()
    {
        sf::Font font;
        if (!font.loadFromFile("fonts/tech.ttf"))
        {
            std::cerr << "Could not load font\n";
            exit(-1);
        };
    };

public:

    App()
    {
        loadConfig("config.txt");
        loadFont();
        sf::Window window(sf::VideoMode(w_width, w_height), "Project 1");
        window.setFramerateLimit(60);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            };
            
        };
        // std::cout << w_width << " " << w_height << "\n";
    };
};



int main (int argc, char * argv[])
{
    App game;
    return 0;
}