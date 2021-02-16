#ifndef box_HPP
#define box_HPP

#include <iostream>
#include <stdlib.h>
#include "vect.hpp"
#include "particle.hpp"

class box{
public :
    int level_ ;
    vect center_ ;
    vect massCenter_ ;
    double mass_ ;
    particle * star_ ;
    box * sisterBox_ ;
    box * daughterBox_ ;


    box(int level = 0, vect center = vect(0,0,0), vect massCenter = vect(0,0,0), double mass = 0, particle * star = nullptr, box * sisterBox = nullptr, box * daughterBox = nullptr) : level_(level), center_(center), massCenter_(massCenter),mass_(mass), star_(star), sisterBox_(sisterBox), daughterBox_(daughterBox) {};
    ~box() ;

    double getsize() ;

    void split() ;
    void delete_recurs() ;
    box * whichbox(particle * P) ;

    void add_particle(particle *P) ;
    void remove_particle(particle *P) ;
    
    void affiche(ostream & = cout) const;
    friend ostream & operator<<(ostream &os, const box &B){B.affiche();return os;}
} ;

#endif