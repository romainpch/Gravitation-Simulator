#ifndef vect_HPP
#define vect_HPP

#include <iostream>
#include <stdlib.h>

using namespace std ;

class vect{
public :
    double x_ ;
    double y_ ;
    double z_ ;
    vect(double x = 0, double y = 0, double z = 0): x_(x), y_(y), z_(z){}
    ~vect(){} ;

    void affiche(ostream & = cout) const;

    bool operator==(const vect &P) const {return x_==P.x_ && y_==P.y_ && z_==P.z_;}
    bool operator!=(const vect &P) const {return !(P==(*this)) ;}
    
    void operator+=(const vect &) ;
    void operator-=(const vect &) ;
    void operator*=(double) ;
    void operator/=(double) ;

    friend ostream & operator<<(ostream &os, const vect &P){P.affiche();return os;}
} ;

vect operator+(const vect &,const vect &) ;
vect operator-(const vect &,const vect &) ;
vect operator*(double,const vect &) ;
vect operator*(const vect &,double) ;
vect operator/(const vect &,double) ;
double dot(const vect &, const vect &) ;
vect cross(const vect &, const vect &) ;


#endif