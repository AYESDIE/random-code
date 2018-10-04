//
// Created by ayush on 02-10-2018.
//

#ifndef RESEARCH101_COORDINATE_H
#define RESEARCH101_COORDINATE_H

#include <vector>
#include <ostream>

class coordinate {
    double coordinate_x;
    double coordinate_y;

public:
    coordinate();
    coordinate(double coordinate_x, double coordinate_y);
    virtual ~coordinate();

    std::vector<double> getcoordinate();

    bool operator==(const coordinate &rhs) const;
    bool operator!=(const coordinate &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const coordinate &coordinate1);
};


#endif //RESEARCH101_COORDINATE_H
