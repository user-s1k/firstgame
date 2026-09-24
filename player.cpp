#include <SFML/Graphics.hpp>
#include <iostream>
#include "func.h"

sf::Vector2f playerXy;
//sf::Angle playerRotation = sf::degrees(300.f);
extern sf::Texture playerTexture;

void playerLogic() {

    sf::Vector2i mousePos = sf::Mouse::getPosition(window); // ищем позицию курсора
    sf::Vector2f mousePosF = sf::Vector2f(mousePos); // перевод в флоат
    sf::Vector2f distan = mousePosF - player.getPosition(); // расстояние между мышью и центром игрока

    sf::Angle angle = sf::radians(std::atan2(distan.y, distan.x)); // угол поворота

    player.setRotation(angle); // приминяем к игроку

    float time = timer.restart().asSeconds();  


    

    

	

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
    
    //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
    //    scale += time * 1.f;
    //}

    //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl)) {
    //    scale -= time * 1.f;
    //    if (scale <= 0.05f) { 
    //        scale = 0.05f;
    //    }
    //}
    


    // конец обработки движения


    // защита от убегания за пустоту(кривая косая)

    // Вычисляем текущие половинки размеров игрока на экране
    float halfW = (playerTexture.getSize().x * scale) / 2.f;
    float halfH = (playerTexture.getSize().y * scale) / 2.f;

    // полетел за левый появился за правым
    if (playerXy.x + halfW < 0.f) {
        playerXy.x = (float)windowW + halfW;
    }

    // улетез за правый появился за левым
    if (playerXy.x - halfW > (float)windowW) {
        playerXy.x = -halfW;
    }

    // улетел за верхний край появился за нижним 
    if (playerXy.y + halfH < 0.f) {
        playerXy.y = (float)windowH + halfH;
    }

    // улетел за нижний край появиться за верхнем
    if (playerXy.y - halfH > (float)windowH) {
        playerXy.y = -halfH;
    }
  


}