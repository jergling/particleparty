#ifndef VECTORMATH_H
#define VECTORMATH_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

class VectorMath
{
    public:
        VectorMath();
        sf::Vector3f project(sf::Vector3f vec1, sf::Vector3f vec2);
        sf::Vector3f reject(sf::Vector3f vec1, sf::Vector3f vec2);
        float cosTheta(sf::Vector3f vec1, sf::Vector3f vec2);
        float getDepth(sf::Vector3f camPos, sf::Vector3f camDir, sf::Vector3f spriteCoords);
        void sortDepths(float depths[], sf::Vector3f coords[]);
        float magnitude(sf::Vector3f vec1);
        float dotProduct(sf::Vector3f vec1, sf::Vector3f vec2);
        virtual ~VectorMath();
    protected:
    private:
};

#endif // VECTORMATH_H
