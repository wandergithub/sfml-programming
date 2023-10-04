#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Circle : public sf::CircleShape {

public:
    float sx, sy;

    Circle(float radius) : sf::CircleShape(radius) {

    }
};

class Rectangle : public sf::RectangleShape {
public:
    float sx, sy;

    Rectangle(sf::Vector2f vector) : sf::RectangleShape(vector) {

    }
};

class App {
    int w_width, w_height;
    sf::Font font;
    std::vector<Circle> circles;
    std::vector<Rectangle> rectangles;

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
            else if (type == std::string("Font"))
            {   std::string fontPath;
                config_file >> fontPath;
                loadFont(fontPath);
            }
            else if (type == std::string("Circle"))
            {
                std::string name;
                float x, y, sx, sy, radio;
                int r, g, b;
                config_file >> name >> x >> y >> sx >> sy >> r >> g >> b >> radio;
                Circle circle(radio);
                circle.setFillColor(sf::Color(r, g, b));
                circle.sx = sx;
                circle.sy = sy;
                circle.setPosition(x, y);

                circles.push_back(circle);
            }
            else if (type == std::string("Rectangle"))
            {
                std::string name;
                float x, y, sx, sy, w, h;
                int r, g, b;
                config_file >> name >> x >> y >> sx >> sy >> r >> g >> b >> w >> h;
                Rectangle rectangle(sf::Vector2f(w, h));
                rectangle.setFillColor(sf::Color(r, g, b));
                rectangle.sx = sx;
                rectangle.sy = sy;
                rectangle.setPosition(x, y);

                rectangles.push_back(rectangle);
            }
            
        };
        
    };

    void loadFont(const std::string& fontPath)
    {
        if (!font.loadFromFile(fontPath))
        {
            std::cerr << "Could not load font\n";
            exit(-1);
        };
    };

public:

    App()
    {
        loadConfig("config.txt");
        sf::RenderWindow window(sf::VideoMode(w_width, w_height), "Project 1");
        window.setFramerateLimit(60);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            };
            
            window.clear(sf::Color::Black);

            // Printing circles
            for (sf::CircleShape circle : circles) {
                window.draw(circle);
            }
            // Printing rectangles
            for (sf::RectangleShape rectangle : rectangles) {
                window.draw(rectangle);
            }

            window.display();
        };
    };
};



int main (int argc, char * argv[])
{
    App game;
    return 0;
}