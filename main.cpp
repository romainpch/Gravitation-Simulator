#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "box.cpp"
#include "particle.cpp"
#include "vect.cpp"

using namespace std ;

int main(int argc, char const *argv[]){
    //Model Parameters
    int N_star = 1000 ;
    box Universe ; //Generation of a blank box 

    cout<<"Initialisation : generating "<<N_star<<"stars..."<<endl ; 
    for(int i=0; i<N_star; i++){
        particle* star = new particle(1) ;
    }

    vect posi(-0.5,0.5,0.5) ;
    vect speed(0,0,0) ;
    particle* Terre = new particle(posi,speed,1) ;
    particle* Lune = new particle(-0.1,0.5,0.5,0,0,0,1) ;
    Universe.add_particle(Terre) ;
    Universe.add_particle(Lune) ;
    cout<<Universe<<endl ;
    return 0;
}
