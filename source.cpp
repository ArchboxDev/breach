#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
    sf::VideoMode vm = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(vm, "SFML works!");

    enum gamestates {
        MENU,
        GAME
    };

    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        switch(current) {
            case MENU:
                window.draw(menu(vm));
            break;
            case GAME:
            break;
        }
        window.display();
    }

    return 0;
}

public std::vector<sf:RectangleShape> menu(sf::VideoMode vm) {
    std::vector<sf::RectangleShape> stuffToDraw;
    stuffToDraw[0].setSize(sf::Vector2f(vm.width/7, vm.height));
    sf::Color color(169, 169, 169);
    stuffToDraw[0].setFillColor(color);
    stuffToDraw[0].setPosition(0, 0);
    sf::RectangleShape rrectangle;
    stuffToDraw[1].setSize(sf::Vector2f(vm.width-(vm.width/7), vm.height));
    sf::Color color(85, 85, 85);
    stuffToDraw[1].setFillColor(color);
    rstuffToDraw[1].setPosition(0, 0);
}