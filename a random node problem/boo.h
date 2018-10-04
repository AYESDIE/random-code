//
// Created by ayush on 30-09-2018.
//

#ifndef RESEARCH101_BOO_H
#define RESEARCH101_BOO_H

#include "foo.h"

class boo {
    double boo_steps;
    double boo_length;
    double boo_node;
    double boo_edge;
    double boo_total;
    double boo_AC;
    double boo_PC;
    double boo_WA;
    vector<vector<double>> boo_locations;

    void boo_equate();

public:
    boo(double boo_steps, double boo_length, double boo_node);

    virtual ~boo();

    void evaluate();
    void result();


};


#endif //RESEARCH101_BOO_H
