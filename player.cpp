#include <SFML/Graphics.hpp>
#include <iostream>
#include "func.h"


sf::Vector2f playerXy;

void playerLogic() {

    float time = timer.restart().asSeconds(); 

    // позиция и размер 

    

    

	

    // playerXy.[координата] = time * <float>
    

    // обработка движения
    // движение вниз
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        playerXy.y += time * 300.f;
    }

    // движение вверх
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        playerXy.y -= time * 300.f;
    }

    // движение вправо
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        playerXy.x += time * 300.f;
    }
    // движение влево
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        playerXy.x -= time * 300.f;
    }

    // какаета хуйня
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        scale += time * 1.f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl)) {
        scale -= time * 1.f;
        if (scale <= 0.05f) { 
            scale = 0.05f;
        }
    }
    


    // конец обработки движения


    // защита от убегания за пустоту(кривая косая)

    if (playerXy.x < -90.f) {
        playerXy.x = windowH + 210.f;
    }

    if (playerXy.y < -90.f) {
        playerXy.y = windowW - 210.f;
    }
     
    if (playerXy.x + bounds.size.x - 90.f > windowW) {
        playerXy.x = -90.f;
    }

    if (playerXy.y + bounds.size.y - 90.f > windowH) {
        playerXy.y = -90.f;
    }
  


}