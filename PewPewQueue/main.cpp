#include <iostream>
#include <SFML/Graphics.hpp>
#include <VectorMath.h>

int width=800;
int height=600;
int numParticles = 200;

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
    sf::Vector3f camPos(400.0f,0.0f,100.0f);
    sf::Vector3f camNorm(-1,0,0);
    sf::Vector3f upVector(0,0,1);
    VectorMath vectormath;

    for(int i=0; i< numParticles; i++){

        //coords[i] = sf::Vector3f(0,0,0);
        std::pair<float,sf::Vector3f> somePair(0.0f, sf::Vector3f(0,0,0));
        coordsAndDepth.push_back(somePair);

        //setup random static particles
        coordsAndDepth.at(i).second.x = rand()%300 - 1;
        coordsAndDepth.at(i).second.y = rand()%300 - 1;
        coordsAndDepth.at(i).second.z = rand()%300 - 1;
    }

    srand(time(NULL));

    //sf::Vector2<int> mousepos;

    //sf::CircleShape c(10.f);
    sf::RectangleShape c(sf::Vector2f(20.f, 20.f));
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


            //sf::Vector2f mouseFloat(mousepos);
            //sf::Vector2f toMouse = mouseFloat - coords[i];
            //coords[i] += (toMouse / 100.0f);

            coordsAndDepth.at(i).first = vectormath.getDepth(camPos,camNorm,coordsAndDepth.at(i).second);

        }

        //sort by depth (don't forget to move coords' data accordingly
        std::sort(coordsAndDepth.begin(),coordsAndDepth.end(),pairCompare);


        for(int i = numParticles-1; i >= 0; i--){
            //Scale for perspective (disable for true orthographic
                //float scaleFactor = 160000 *(1/pow(coordsAndDepth.at(i).first,2));
                //c.setScale(scaleFactor, scaleFactor);

            //Find perspective information
            sf::Vector3f camToPoint = (coordsAndDepth.at(i).second-camPos);
            sf::Vector3f camU = vectormath.crossProduct(camNorm, upVector); //U is right-facing
            sf::Vector3f camV = vectormath.crossProduct(camU, camNorm); //V is down-facing, like screen coords

            float xScreenCoord = float(width)/2.0f + vectormath.magnitude(vectormath.project(camToPoint, camU))/2;
            float yScreenCoord = float(height)/2.0f + vectormath.magnitude(vectormath.project(camToPoint, camV))/2;

            c.setPosition(sf::Vector2f(xScreenCoord, yScreenCoord));


        //Old z-projection code
            //c.setPosition(sf::Vector2f(coordsAndDepth.at(i).second.x+width/2.0f, coordsAndDepth.at(i).second.y+height/2.0f));
            //Real projection goes here:
            //Vector2f screenCoords =

            window.draw(c);
        }

        camPos += vectormath.crossProduct(camNorm, upVector);
        camNorm = vectormath.unitOf(-camPos);
        window.display();
    }

    return 0;
}


