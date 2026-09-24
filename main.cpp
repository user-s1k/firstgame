#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "func.h"

void playerLogic();

unsigned int windowW = 1920;
unsigned int windowH = 1080;
float spawnW = windowH;
float scale = 0.2f;

sf::RenderWindow window;
sf::FloatRect bounds;
sf::Texture playerTexture;
sf::Sprite player(playerTexture);

sf::Clock timer;

int main()
{
    std::cout << "Enter resulution: ";
    std::cin >> windowW;
    std::cin >> windowH;

    // spawnW = (float)windowH;

   

    if (!playerTexture.loadFromFile("Textures/player.png")) {
        std::cout << "Failed load player texture\n";
        return 0;
    }
    player.setTexture(playerTexture, true);

    

    
   
    playerXy = sf::Vector2f(0.f, (float)windowH - bounds.size.y);
    
    sf::FloatRect localBounds = player.getGlobalBounds();
    player.setOrigin(sf::Vector2f( localBounds.size.x /  2.f, localBounds.size.y /  2.f));

    bounds = player.getGlobalBounds();
    player.setScale({ scale, scale });

    // создаем окно 
    window.create(sf::VideoMode({ windowW, windowH }), "MyFirstGame");
        

    // главный игровой цикл
    while(window.isOpen())
    {
        
        // обработчик событий
        while(const auto event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>()) { // если крестик нажат - закрываем окно
                window.close();
            }
        } 

       
        

        playerLogic();

        player.setPosition({ playerXy });
        player.setScale({ scale, scale });
       
       
        window.clear();   // очищаем экран
        window.draw(player);
        window.display(); // выводим всё на экран  
        
        
    }

    return 0;
}
