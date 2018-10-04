//
// Created by ayush on 01-10-2018.
//

#include "boo.h"
#include "foo.h"
#include "coordinates.h"
#include <cmath>


boo::boo(int boo_node, int boo_step) : boo_step(boo_step), boo_node(boo_node) {
    boo_AC=0;
    boo_WA=0;
    boo_PC=0;
    boo_length=std::pow(2,boo_node);
    coordinates c = coordinates(0,0);
    boo_coordinates.push_back(c);
    c = coordinates(0,boo_length);
    boo_coordinates.push_back(c);
    c = coordinates(boo_length,0);
    boo_coordinates.push_back(c);
    c = coordinates(boo_length,boo_length);
    boo_coordinates.push_back(c);

    double ps = (boo_length-4)/4;
    for (int i = 4; i < ps; i+=4) {
        c = coordinates(i,0);
        boo_coordinates.push_back(c);
        c = coordinates(0,i);
        boo_coordinates.push_back(c);
        c = coordinates(i,boo_length);
        boo_coordinates.push_back(c);
        c = coordinates(boo_length,i);
        boo_coordinates.push_back(c);
    }
    boo_foo = foo(boo_coordinates);

    double lel = boo_length*boo_step;
    for (int j = 0; j <= lel ; j+=boo_length) {
        for (int i = 0; i <= lel ; i+=boo_length) {
            double x = (double)j/boo_step;
            double y = (double)i/boo_step;

            coordinates t(x,y);
            if(boo_foo.evaluate(t)==0){
                boo_WA++;
            }
            else if(boo_foo.evaluate(t)==1){
                boo_PC++;
            }
            else if(boo_foo.evaluate(t)==2){
                boo_AC++;
            }

        }
    }
}

std::ostream &operator<<(std::ostream &os, const boo &boo1) {
    os << "\n>> AC: " << boo1.boo_AC << "\n>> PC: " << boo1.boo_PC << "\n>> WA: " << boo1.boo_WA ;
    return os;
}
