//
// Created by ayush on 29-09-2018.
//

#ifndef RESEARCH101_FOO_H
#define RESEARCH101_FOO_H

#include <vector>
using namespace std;

class foo {
    double foo_approx_margin;
    vector<vector<double>> foo_location;
    vector<vector<double>> foo_equation;

    void foo_equate();

public:

    foo( const vector<vector<double>> &foo_location,double foo_approx_margin=0);

    double evaluate(double x,double y);
    void showeq();


};


#endif //RESEARCH101_FOO_H
