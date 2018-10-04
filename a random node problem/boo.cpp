//
// Created by ayush on 30-09-2018.
//

#include "boo.h"
#include "foo.h"
#include <cmath>
#include <iostream>

using namespace std;

boo::boo(double boo_steps, double boo_length, double boo_node) : boo_steps(boo_steps), boo_length(boo_length),
                                                        boo_node(boo_node) {
    boo_AC = 0;
    boo_WA = 0;
    boo_PC = 0;
    boo_total = boo_steps*boo_steps;
    boo_edge = ( std::pow(2,boo_node) - 4 ) / 4;
    boo_equate();
}

boo::~boo() {

}

void boo::boo_equate() {
    boo_locations.push_back({0,0});
    boo_locations.push_back({0,boo_length});
    boo_locations.push_back({boo_length,0});
    boo_locations.push_back({boo_length,boo_length});

    for (double i = 1; i < boo_edge+1; ++i) {
        double fec = (boo_length*i)/(boo_edge+1);
        boo_locations.push_back({0,0+fec});
        boo_locations.push_back({0+fec,0});
        boo_locations.push_back({boo_length+fec,0});
        boo_locations.push_back({0+fec,boo_length});
    }
}



void boo::evaluate() {
    foo phoo(boo_locations);
    double iter=0;
    cout<<"\n>> EVALUATING";
    double inc = boo_length/boo_steps;
    for (double i = 0; i <= boo_length*boo_steps ; i+=boo_length) {
        for (double j = 0; j <= boo_length*boo_steps ; j+=boo_length) {
            iter++;
            double res = phoo.evaluate((double)i/boo_steps,(double)j/boo_steps);
            if(res==2){
                boo_AC++;
            }
            else if(res==1){
                boo_PC++;
            }
            else{
                boo_WA++;
            }
        }
    }
}

void boo::result() {
    cout<<"\n>> Nodes: "<<std::pow(2,boo_node);
    cout<<"\n>> Length: "<<boo_length;
    cout<<"\n>> Steps: "<<boo_steps;
    cout<<"\n>> AC: "<<boo_AC;
    cout<<"\n>> PC: "<<boo_PC;
    cout<<"\n>> WA: "<<boo_WA;
    cout<<"\n==================================\n";
}
