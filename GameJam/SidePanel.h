#include "Panel.h"
#include "Resources.h"

class SidePanel {
public:
   ~SidePanel();
   void draw(sf::RenderWindow& window);
   void initialize(TextureHolder& textures);
private:

public:

private:
   std::vector<Panel*> panels;
};

