#include "Panel.h"
#include "Resources.h"

class SidePanel {
public:
   ~SidePanel();
   void draw(sf::RenderWindow& window);
   void initialize(TextureHolder& textures);
   bool check(int n);
   int checked();
private:

public:

private:
   std::vector<Panel*> panels;
   Panel* checkPanel;
};

