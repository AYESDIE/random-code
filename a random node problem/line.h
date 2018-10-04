//
// Created by ayush on 02-10-2018.
//

#ifndef RESEARCH101_LINES_H
#define RESEARCH101_LINES_H


#include <vector>
#include <ostream>
#include "coordinate.h"

class line {
    double line_m;
    double line_n;
    double line_c;

    void minimize();

public:
    line();
    line(coordinate c1,coordinate c2);
    virtual ~line();

    std::vector<double> getline();
    bool check(coordinate c);

    bool operator==(const line &rhs) const;
    bool operator!=(const line &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const line &line1);

};


#endif //RESEARCH101_LINES_H
