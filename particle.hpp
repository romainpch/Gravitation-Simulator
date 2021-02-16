#ifndef particle_HPP
#define particle_HPP

#include <iostream>
#include <stdlib.h>
#include "vect.hpp"

class particle{
public :
    vect pos_ ;
    vect speed_ ;
    double mass_ ;

    particle(double x = 0, double y = 0, double z = 0, double vx = 0, double vy = 0, double vz = 0, double m=0): pos_(x,y,z), speed_(vx,vy,vz), mass_(m) {};
    particle(vect pos = vect(0,0,0), vect speed = vect(0,0,0), double m=0): pos_(pos), speed_(speed), mass_(m) {};
    ~particle(){} ;

    void generate_position()

    void affiche(ostream & = cout) const;
    friend ostream & operator<<(ostream &os, const particle &P){P.affiche();return os;}
} ;


#endif