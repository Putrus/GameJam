#include <SFML/Graphics.hpp>

int main()
{
   sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
   sf::CircleShape shape(100.f);
   shape.setFillColor(sf::Color::Green);
   sf::Sprite sprite;
   sf::Texture texture;
   //texture.loadFromFile(filename);
   sprite.setTexture(texture);
   while (window.isOpen())
   {
      sf::Event event;
      while (window.pollEvent(event))
      {
         if (event.type == sf::Event::Closed)
            window.close();
      }

      window.clear();
      window.draw(sprite);
      window.draw(shape);
      window.display();
   }

   return 0;
}