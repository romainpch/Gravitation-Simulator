#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "box.cpp"
#include "particle.cpp"
#include "vect.cpp"

using namespace std ;

int main(int argc, char const *argv[]){
    particle S(1,2,3,10);
    cout<<S<<endl ;
    return 0;
}
