#include "box.hpp"

#include <iostream>

using namespace std ;

void box::affiche(ostream & os) const {
    if(level_ == 0){os<<"This is the frame Box !"<<endl ;}
    else{os<<"Just a simple box !"<<endl ;}
    os<<"Box here : "<<center_ ;
}

void box::updatemass(double m){
    return ;
}

void box::split(){
    return ;
}

box * box::whichbox(particle * P){
    return nullptr ;
}

void box::add_particle(particle* P) {
    if(daughterBox_==nullptr){
        if(star_ == nullptr){
            star_ = P ;
            this->updatemass(P->mass_) ;
            return;
        }
        else{
            particle * Q = this->star_ ;
            this->star_ = nullptr ;
            this->split() ;
            this->add_particle(Q) ;
            this->add_particle(P) ;
            return ;
        }
    }
    else{
        this->whichbox(P)->add_particle(P) ;
        return ;
    }
}