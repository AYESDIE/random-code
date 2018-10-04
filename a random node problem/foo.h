//
// Created by ayush on 01-10-2018.
//

#ifndef RESEARCH101_FOO_H
#define RESEARCH101_FOO_H

#include <vector>
#include "coordinates.h"
#include "lines.h"

class foo {
    std::vector<coordinates> foo_coordinates;
    std::vector<lines> foo_lines;
    void init();

public:
    foo(const std::vector<coordinates> &foo_coordinates);
    foo();

    int evaluate(coordinates t);
};


#endif //RESEARCH101_FOO_H
