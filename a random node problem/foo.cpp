//
// Created by ayush on 29-09-2018.
//

#include "foo.h"
#include <iostream>
#include <cmath>
using namespace std;

foo::foo( const vector<vector<double>> &foo_location,double foo_approx_margin) : foo_location(foo_location), foo_approx_margin(foo_approx_margin) {
    foo_equate();
}

void foo::foo_equate(){
    for (double i = 0; i < foo_location.size(); ++i) {
        for (double j = i+1; j < foo_location.size(); ++j) {
            double foo_x1 = foo_location[i][0];
            double foo_x2 = foo_location[j][0];
            double foo_y1 = foo_location[i][1];
            double foo_y2 = foo_location[j][1];
            double foo_m = foo_x2-foo_x1;
            double foo_n = foo_y2-foo_y1;
            double foo_c = (foo_n*foo_x1)-(foo_m*foo_y1);
            vector<double> temp({foo_m,foo_n,foo_c});
            foo_equation.push_back(temp);
        }
    }
}

double foo::evaluate(double x, double y) {
    double type=0;
    double prox;
    for (double i = 0; i < foo_equation.size(); ++i) {
        double foo_m = foo_equation[i][0];
        double foo_n = foo_equation[i][1];
        double foo_c = foo_equation[i][2];
        prox = (foo_m*y)-(foo_n*x)+foo_c;
        prox = abs(prox);
        if(prox<=foo_approx_margin){
            type++;
        }

        if(type==2){
            break;
        }
    }


    if(type>=2){
        return 2;
    }
    else if(type==1){
        return 1;
    }
    else{
        return 0;
    }
}

void foo::showeq() {
    for (double i = 0; i < foo_equation.size() ; ++i) {
        double m = foo_equation[i][0];
        double n = foo_equation[i][1];
        double c = foo_equation[i][2];
        cout<<m<<" "<<-n<<" "<<c<<"\n";
    }

}
