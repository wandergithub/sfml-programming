#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Circle : public sf::CircleShape {

public:
    float sx, sy, radio;
    sf::Text &text;

    Circle(float radio, sf::Text &refText) 
        : sf::CircleShape(radio), text(refText) {
        this->radio = radio;
    }
};

class Rectangle : public sf::RectangleShape {
public:
    float sx, sy;
    sf::Text &text;

    sf::Vector2f dimentions;
    Rectangle(sf::Vector2f vector, sf::Text &refText) 
        : sf::RectangleShape(vector), text(refText) {
        dimentions = vector;
    }
};

class App {
    int w_width, w_height;
    sf::Font font;
    std::vector<Circle> circles;
    std::vector<Rectangle> rectangles;
    int fontSize, fr, fg, fb;
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
                config_file >> fontPath >> fontSize >> fr >> fg >> fb;
                loadFont(fontPath);
            }
            else if (type == std::string("Circle"))
            {
                sf::Text text;
                text.setFont(font);

                std::string name;
                float x, y, sx, sy, radio;
                int r, g, b;
                config_file >> name >> x >> y >> sx >> sy >> r >> g >> b >> radio;

                text.setString(name);
                text.setCharacterSize(fontSize);
                text.setFillColor(sf::Color(fr, fg, fb));
                text.setPosition(x, y);
                
                Circle circle(radio, text);
                circle.setFillColor(sf::Color(r, g, b));
                circle.sx = sx;
                circle.sy = sy;
                circle.setPosition(x, y);
                circles.push_back(circle);
            }
            else if (type == std::string("Rectangle"))
            {
                sf::Text text;
                text.setFont(font);

                std::string name;
                float x, y, sx, sy, w, h;
                int r, g, b;
                config_file >> name >> x >> y >> sx >> sy >> r >> g >> b >> w >> h;

                text.setString(name);
                text.setCharacterSize(fontSize);
                text.setFillColor(sf::Color(fr, fg, fb));
                text.setPosition(x, y);
                Rectangle rectangle(sf::Vector2f(w, h), text);

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

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            };
            
            window.clear(sf::Color::Black);

            // Handling circles
            for (Circle& circle : circles) {
                if (circle.getPosition().x <= 0 || (circle.getPosition().x  + (circle.radio * 2)) >= w_width)
                {
                    circle.sx *= (-1);
                }

                if (circle.getPosition().y <= 0 || (circle.getPosition().y + (circle.radio * 2)) >= w_height)
                {
                    circle.sy *= (-1);
                }

                circle.setPosition(circle.getPosition().x + circle.sx, circle.getPosition().y + circle.sy);
                window.draw(circle);
            }
            // Handling rectangles
            for (Rectangle& rectangle : rectangles) {
                if (rectangle.getPosition().x <= 0 || (rectangle.getPosition().x + rectangle.dimentions.x) >= w_width)
                {
                    rectangle.sx *= -1;
                }
                if (rectangle.getPosition().y <= 0 || (rectangle.getPosition().y + rectangle.dimentions.y) >= w_height)
                {
                    rectangle.sy *= -1;
                }
                
                rectangle.move(rectangle.sx, rectangle.sy);
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