
#include "foo.h"
#include <iostream>

void foo::init() {
    /*!
     * iterates through all the "coordinate" with the complexity of n^2
     */
    for (int i = 0; i < foo_coordinate.size(); ++i) {
        for (int j = i+1; j < foo_coordinate.size(); ++j) {
            /*!
             * forms a "line" with the name temp
             */
            line temp(foo_coordinate[i],foo_coordinate[j]);

            /*!
             * checks if the line already exists
             */
            int crit=0;
            for (int k = 0; k < foo_line.size(); ++k) {
                if(temp==foo_line[i]){
                    crit=1;
                    break;
                }
            }

            /*!
             * push the line in the vector if it doesn't exist.
             */
            if(crit==0){
                foo_line.push_back(temp);
            }
        }
    }
}

foo::foo() {}

foo::foo(const std::vector<coordinate> &foo_coordinate) : foo_coordinate(foo_coordinate) {
    init();
}

foo::~foo() {

}

void foo::show() {
    for (int i = 0; i < foo_line.size(); ++i) {
        std::vector<double> temp = foo_line[i].getline();
        std::cout<< temp[0] <<" "<< -temp[1] <<" "<<temp[2]<<"\n";
    }

}

int foo::evaluate(coordinate s) {
    /*!
     * evaluating over all the lines using "check()" of "line"
     */
    int res=0;
    for (int i = 0; i < foo_line.size(); ++i) {
        if(foo_line[i].check(s)){
            res++;
        }
        if(res==2){
            break;
        }
    }
    return res;
}
