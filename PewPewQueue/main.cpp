#include <iostream>
#include <SFML/Graphics.hpp>
#include <VectorMath.h>

int width=800;
int height=600;
int numParticles = 50;

bool pairCompare(const std::pair<float, sf::Vector3f>& firstElem, const std::pair<float, sf::Vector3f>& secondElem) {
  return firstElem.first < secondElem.first;

}

int main()
{
    sf::RenderWindow window(sf::VideoMode(width,height), "No pants pooping.");
    window.setFramerateLimit(60);
    //sf::Vector3f coords[numParticles];
    //float depths[numParticles];
    std::vector<std::pair<float,sf::Vector3f> > coordsAndDepth;
    sf::Vector3f camPos(0.0f,0.0f,400.0f);
    sf::Vector3f camNorm(0,0,-1);
    VectorMath vectormath;

    for(int i=0; i< numParticles; i++){

        //coords[i] = sf::Vector3f(0,0,0);
        std::pair<float,sf::Vector3f> somePair(0.0f, sf::Vector3f(0,0,0));
        coordsAndDepth.push_back(somePair);
    }

    srand(time(NULL));

    //sf::Vector2<int> mousepos;

    sf::CircleShape c(10.f);
    c.setOrigin(10.0f,10.0f);
    c.setFillColor(sf::Color::Green);
    c.setOutlineColor(sf::Color::Black);
    c.setOutlineThickness(1);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //mousepos = sf::Mouse::getPosition(window);

        window.clear();

        //move each particle, then find depth and save it to the depth array
        for(int i=0; i< numParticles; i++){
            coordsAndDepth.at(i).second.x += rand()%3 - 1;
            coordsAndDepth.at(i).second.y += rand()%3 - 1;
            coordsAndDepth.at(i).second.z += rand()%3 - 1;

            //sf::Vector2f mouseFloat(mousepos);
            //sf::Vector2f toMouse = mouseFloat - coords[i];

            //coords[i] += (toMouse / 100.0f);

            coordsAndDepth.at(i).first = vectormath.getDepth(camPos,camNorm,coordsAndDepth[i].second);

        }

        //sort by depth (don't forget to move coords' data accordingly
        std::sort(coordsAndDepth.begin(),coordsAndDepth.end(),pairCompare);


        for(int i = numParticles-1; i >= 0; i--){
            float scaleFactor = 160000 *(1/pow(coordsAndDepth.at(i).first,2));
            c.setScale(scaleFactor, scaleFactor);
            std::cout<< "\n" << scaleFactor;


            c.setPosition(sf::Vector2f(coordsAndDepth.at(i).second.x+width/2.0f, coordsAndDepth.at(i).second.y+height/2.0f));
            //Real projection goes here:
            //Vector2f screenCoords =

            window.draw(c);
        }

        window.display();
    }

    return 0;
}


