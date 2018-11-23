#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

//e
int main()
{
    sf::VideoMode vm = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(vm, "SFML works!");

    enum gamestates {
        MENU,
        GAME
    };

    gamestates current = MENU;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
               switch(current) {
                   case MENU:
                    if((event.mouseButton.x >= vm.width/42 && event.mouseButton.x <= vm.width/42 + ((vm.width/7)/1.5)) && (event.mouseButton.y >= vm.height/18 && event.mouseButton.y <= vm.height/18 + vm.height/16)) {
                        current = GAME;
                    }
                    break;
                    default:
                    std::cout << "Oh, fiddlesticks. What now?";
                    break;
               }
            }
        }

        window.clear();
        switch(current) {
            case MENU: 
            {
                //drawMenu(vm, window);
                sf::RectangleShape button_area;
                button_area.setSize(sf::Vector2f(vm.width/7, vm.height));
                sf::Color color(169, 169, 169);
                button_area.setFillColor(color);
                button_area.setPosition(0, 0);
                window.draw(button_area);
                sf::RectangleShape visual_area;
                visual_area.setSize(sf::Vector2f(vm.width-(vm.width/7), vm.height));
                sf::Color color2(85, 85, 85);
                visual_area.setFillColor(color2);
                visual_area.setPosition(vm.width/7, 0);
                window.draw(visual_area);
                sf::RectangleShape buttonbg1;
                buttonbg1.setSize(sf::Vector2f((vm.width/7)/1.5, vm.height/25));
                sf::Color color3(65, 65, 65);
                buttonbg1.setFillColor(color3);
                buttonbg1.setPosition(vm.width/42, vm.height/18);
                window.draw(buttonbg1);
                sf::Font font;
                font.loadFromFile("Roboto-Regular.ttf");
                sf::Text buttontext1;
                buttontext1.setFont(font);
                buttontext1.setString("New Game");
                buttontext1.setCharacterSize(24);
                buttontext1.setFillColor(sf::Color::White);
                buttontext1.setPosition(vm.width/25, vm.height/16);
                window.draw(buttontext1);
            }
            break;
            case GAME:
            {
             sf::RectangleShape topangle;
             topangle.setSize(sf::Vector2f(vm.width, vm.height/35));
             topangle.setPosition(0,0);
             sf::Color color(169, 169, 169);
             topangle.setFillColor(color);
             window.draw(topangle);
             sf::RectangleShape ramangle;
             ramangle.setSize(sf::Vector2f(vm.width/7, vm.height-(vm.height/35)));
             ramangle.setPosition(0, vm.height/35);
             sf::Color color2(100, 100, 100);
             ramangle.setFillColor(color2);
             window.draw(ramangle);
             sf::RectangleShape contentangle;
             contentangle.setSize(sf::Vector2f(4*(vm.width/7), vm.height-(vm.height/35)));
             contentangle.setPosition(vm.width/7, vm.height/35);
             sf::Color color3(45, 45, 45);
             contentangle.setFillColor(color3);
             window.draw(contentangle); 
             sf::RectangleShape netangle;
             netangle.setSize(sf::Vector2f(2*(vm.width/7),(vm.height-(vm.height/35))/2));
             netangle.setPosition(sf::Vector2f(5*(vm.width)/7, vm.height/35));
             sf::Color color4(234, 234, 234);
             netangle.setFillColor(color4);
             window.draw(netangle);
             sf::RectangleShape termangle;
             termangle.setSize(sf::Vector2f(2*(vm.width/7),(vm.height-(vm.height/35))/2));
             termangle.setPosition(sf::Vector2f(5*(vm.width)/7, (vm.height-(vm.height/35))/2));
             sf::Color color5(200, 200, 200);
             termangle.setFillColor(color5);
             window.draw(termangle);
             sf::Font font;
             font.loadFromFile("Roboto-Regular.ttf");
             sf::Text termtext;
             termtext.setFont(font);
             termtext.setString("Test test test test test test");
             termtext.setCharacterSize(20);
             termtext.setFillColor(sf::Color::Black);
             termtext.setPosition(sf::Vector2f((5*(vm.width)/7)+(vm.width/117), (vm.height-(vm.height/35))/2));
             window.draw(termtext);
            }
            break;
        }
        window.display();
    }

    return 0;
}