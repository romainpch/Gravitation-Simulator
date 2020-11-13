#include "vect.hpp"

#include <iostream>

using namespace std ;


void vect::affiche(ostream & os) const {
    os<<"("<<x_<<","<<y_<<","<<z_<<")" ; 
}

void vect::operator+=(const vect &P){
    x_+=P.x_ ;
    y_+=P.y_ ;
    z_+=P.z_ ;
    return ;
}

void vect::operator-=(const vect &P){
    x_-=P.x_ ;
    y_-=P.y_ ;
    z_-=P.z_ ;
    return ;
}

void vect::operator*=(double a){
    x_*=a ;
    y_*=a ;
    z_*=a ;
    return ;
}

void vect::operator/=(double a){
    if(a==0){
        cout<<"you can't divide by 0" ;
        exit(1) ;
    }
    x_/=a ;
    y_/=a ;
    z_/=a ;
    return ;
}

vect operator+(const vect &P,const vect &Q){
    vect R(P) ;
    R+=Q ;
    return R ;
}

vect operator-(const vect &P,const vect &Q){
    vect R(P) ;
    R-=Q ;
    return R ;
}

vect operator*(double a,const vect &P){
    vect R(P) ;
    R*=a ;
    return R ;
}

vect operator*(const vect &P,double a){
    vect R(P) ;
    R*=a ;
    return R ;
}

vect operator/(const vect &P,double a){
    vect R(P) ;
    R/=a ;
    return R ;
}

double dot(const vect &P, const vect &Q){
    double r(P.x_*Q.x_+P.y_*Q.y_+P.z_*Q.z_) ;
    return r ;
}

vect cross(const vect &P, const vect &Q){
    vect R(P.y_*Q.z_ - P.z_*Q.y_ , P.z_*Q.x_ - P.x_*Q.z_  , P.x_*Q.y_ - P.y_*Q.x_ ) ;
    return R ;
}