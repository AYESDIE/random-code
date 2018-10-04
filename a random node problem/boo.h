//
// Created by ayush on 01-10-2018.
//

#ifndef RESEARCH101_BOO_H
#define RESEARCH101_BOO_H

#include "coordinates.h"
#include "foo.h"
#include <vector>
#include <ostream>


class boo {
    int boo_step;
    foo boo_foo;
    int boo_AC;
    int boo_WA;
    int boo_PC;
    double boo_length;
    std::vector<coordinates> boo_coordinates;
    int boo_node;

public:
    boo(int boo_node, int boo_step=100);

    friend std::ostream &operator<<(std::ostream &os, const boo &boo1);


};


#endif //RESEARCH101_BOO_H
