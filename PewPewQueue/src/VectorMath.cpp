#include "VectorMath.h"

//Project vec2 onto vec1
sf::Vector3f VectorMath::project(sf::Vector3f vec1, sf::Vector3f vec2){
    //float magA = magnitude(vec1);
    //float magB = magnitude(vec2);
    //float dotAB = dotProduct(vec1, vec2);

    //float prod1 = dotAB/(magA * magB * magB);

    float prod2 = dotProduct(vec1, vec2) / dotProduct(vec1, vec2);

    return vec2*prod2;
}

sf::Vector3f VectorMath::reject(sf::Vector3f vec1, sf::Vector3f vec2){
    return vec1 - project(vec1, vec2);
}

float VectorMath::cosTheta(sf::Vector3f vec1, sf::Vector3f vec2){
    return ( dotProduct(vec1,vec2) / (magnitude(vec1)*magnitude(vec2)) );
}

//get depth from end of camPos, in direction of camDir, to point spriteCoords
float VectorMath::getDepth(sf::Vector3f camPos, sf::Vector3f camNorm, sf::Vector3f spriteCoords){
    sf::Vector3f camToPoint = (spriteCoords-camPos);
    sf::Vector3f depthVec = project(camNorm, camToPoint);
    std::cout<<camToPoint.x << " " << camToPoint.y << " " << camToPoint.z << " " << magnitude(depthVec) << "\n";
    return magnitude(depthVec);
}

void VectorMath::sortDepths(float depths[], sf::Vector3f coords[]){

}

float VectorMath::dotProduct(sf::Vector3f vec1, sf::Vector3f vec2){
    return (vec1.x*vec2.x+vec1.y*vec2.y+vec1.z*vec2.z);
}

float VectorMath::magnitude(sf::Vector3f vec1){
    return sqrtf(pow(vec1.x,2) + pow(vec1.y,2) + pow(vec1.z,2));
}

VectorMath::VectorMath()
{
    //ctor
}

VectorMath::~VectorMath()
{
    //dtor
}
