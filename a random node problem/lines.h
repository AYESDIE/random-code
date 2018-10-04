//
// Created by ayush on 01-10-2018.
//

#ifndef RESEARCH101_LINES_H
#define RESEARCH101_LINES_H

#include "coordinates.h"
#include <vector>
class lines {
    double lines_m;
    double lines_n;
    double lines_c;

    void minimize();

public:
    lines(coordinates x,coordinates y);
    virtual ~lines();

    std::vector<double> getline();

    bool operator==(const lines &rhs) const;
    bool operator!=(const lines &rhs) const;

};


#endif //RESEARCH101_LINES_H
