#include "particle.hpp"

#include <iostream>

using namespace std ;

void particle::affiche(ostream & os) const {
    os<<"Position : "<<pos_.x_<<","<<pos_.y_<<","<<pos_.z_<<endl<<"Speed : "<<speed_.x_<<","<<speed_.y_<<","<<speed_.z_<<endl<<"Mass : "<<mass_ ; 
}