//
// Created by ayush on 01-10-2018.
//

#include "foo.h"

foo::foo(const std::vector<coordinates> &foo_coordinates) : foo_coordinates(foo_coordinates) {
    init();
}

void foo::init() {
    for (int i = 0; i < foo_coordinates.size() ; ++i) {
        for (int j = i+1; j < foo_coordinates.size(); ++j) {
            int crit=0;
            lines temp(foo_coordinates[i],foo_coordinates[j]);
            for (int k = 0; k < foo_lines.size(); ++k) {
                if(foo_lines[k]==temp){
                    crit=1;
                    break;
                }
            }

            if(crit==0){
                foo_lines.push_back(temp);
            }
        }
    }
}

int foo::evaluate(coordinates t) {
    int type=0;
    std::vector<double> l = t.getcoordinates();
    double x = l[0];
    double y = l[1];
    for (int i = 0; i < foo_lines.size(); ++i) {
        std::vector<double> temp = foo_lines[i].getline();
        double m = temp[0];
        double n = temp[1];
        double c = temp[2];
        double res = (m*y)-(n*x)+c;
        if(res==0){
            type++;
        }
        if(type==2){
            break;
        }
    }
    return type;
}

foo::foo() {}
