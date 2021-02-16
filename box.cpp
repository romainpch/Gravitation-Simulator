#include "box.hpp"

#include <iostream>


//////////////
// 0 /// 1 ///
// 3 /// 2 ///    ^
//////////////    |
// 4 /// 5 ///    |
// 7 /// 6 ///
//////////////

using namespace std ;

box::~box(){
    //cout<<"supression box"<<endl ;
    if(sisterBox_ != NULL) delete sisterBox_ ;
    if(daughterBox_ != NULL) delete daughterBox_ ;
}


void box::affiche(ostream & os) const {
    // This function displays every boxes that *this contains
    // If a box contains a particle, it will display its position in the box
    for(int i=0;i<level_;i++){
        os<<"|  " ;
    }        
    os<<"box("<<mass_<<") : "<<center_ ;
    if(star_ != nullptr){
        os<< " * -> "<< star_->pos_<<endl ;
    }
    else{os<<endl ;}
    if(daughterBox_!=nullptr){daughterBox_->affiche() ;}
    if(sisterBox_ != nullptr){sisterBox_->affiche() ;}
}

void box::split(){
    //Splits the box into 8 sub-boxes and make daughterBox_ points to the first sub box
    int l(this->level_) ;
    double L(this->getsize()) ;
    if(daughterBox_ != nullptr){
        cout<<"This box can't be split !"<<endl ; 
    }
    else{
        vect center(this->center_) ;
        vect vectnull(0,0,0) ;
        double doublenull(0) ;
        vect shift7(-L/4, -L/4, -L/4) ;
        vect shift6(L/4, -L/4, -L/4) ;
        vect shift5(L/4, L/4, -L/4) ;
        vect shift4(-L/4, L/4, -L/4) ;
        vect shift3(-L/4, -L/4, L/4) ;
        vect shift2(L/4, -L/4, L/4) ;
        vect shift1(L/4, L/4, L/4) ;
        vect shift0(-L/4, L/4, L/4) ;

        box* s7 = new box(l+1, center+shift7) ;
        box* s6 = new box(l+1, center+shift6, vectnull, doublenull, nullptr, s7) ;
        box* s5 = new box(l+1, center+shift5, vectnull, doublenull, nullptr, s6) ;
        box* s4 = new box(l+1, center+shift4, vectnull, doublenull, nullptr, s5) ;
        box* s3 = new box(l+1, center+shift3, vectnull, doublenull, nullptr, s4) ;
        box* s2 = new box(l+1, center+shift2, vectnull, doublenull, nullptr, s3) ;
        box* s1 = new box(l+1, center+shift1, vectnull, doublenull, nullptr, s2) ;
        box* d0 = new box(l+1, center+shift0, vectnull, doublenull, nullptr, s1) ;

        this->daughterBox_ = d0 ;
    }
}

void box::delete_recurs(){
    if(sisterBox_ != nullptr){
        sisterBox_->delete_recurs() ;
        if(daughterBox_ != nullptr){
            daughterBox_->delete_recurs() ;
        }
        else{
            delete this ;
        }
    }
}

double box::getsize(){
    return 1/(pow(2,level_)) ;
}

box * box::whichbox(particle * P){
    vect center(center_) ;
    vect pos(P->pos_) ;
    if(pos.z_ > center.z_){
        if(pos.x_ < center.x_){
            if(pos.y_ < center.y_){
                return this->daughterBox_->sisterBox_->sisterBox_->sisterBox_ ;
            }
            else{
                return this->daughterBox_ ;
            }
        }
        else{
            if(pos.y_ < center.y_){
                return this->daughterBox_->sisterBox_->sisterBox_ ;
            }
            else{
                return this->daughterBox_->sisterBox_ ;
            }
        }
    }
    else{
        if(pos.x_ < center.x_){
            if(pos.y_ < center.y_){
                return this->daughterBox_->sisterBox_->sisterBox_->sisterBox_->sisterBox_->sisterBox_->sisterBox_->sisterBox_  ;
            }
            else{
                return this->daughterBox_->sisterBox_->sisterBox_->sisterBox_->sisterBox_->sisterBox_ ;
            }
        }
        else{
            if(pos.y_ < center.y_){
                return this->daughterBox_->sisterBox_->sisterBox_->sisterBox_->sisterBox_->sisterBox_->sisterBox_ ;
            }
            else{
                return this->daughterBox_->sisterBox_->sisterBox_->sisterBox_->sisterBox_->sisterBox_ ;
            }
        }
    }
}

void box::add_particle(particle* P) {
    if(daughterBox_==nullptr){
        if(star_ == nullptr){
            star_ = P ;
            mass_ += P->mass_ ;
            return;
        }
        else{
            particle * Q = this->star_ ;
            this->star_ = nullptr ;
            this->split() ;
            this->add_particle(Q) ;
            mass_ -= Q->mass_ ;
            this->add_particle(P) ;
            return ;
        }
    }
    else{
        mass_ += P->mass_ ;
        this->whichbox(P)->add_particle(P) ;
        return ;
    }
}

void box::remove_particle(particle* P){
    mass_ -= P->mass_ ;
    if(star_ == P){
        star_ = nullptr ;
    }
    else{
        this->whichbox(P)->remove_particle(P) ;
    }
}