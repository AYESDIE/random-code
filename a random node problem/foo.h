//
// Created by ayush on 04-10-2018.
//

#ifndef RESEARCH101_FOO_H
#define RESEARCH101_FOO_H

#include "coordinate.h"
#include "line.h"


class foo {
    std::vector<coordinate> foo_coordinate;
    std::vector<line> foo_line;

    void init();

public:
    foo();
    foo(const std::vector<coordinate> &foo_coordinate);
    virtual ~foo();

    int evaluate(coordinate x);
    void show();

};


#endif //RESEARCH101_FOO_H
