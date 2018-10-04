//
// Created by ayush on 01-10-2018.
//

#ifndef RESEARCH101_COORDINATES_H
#define RESEARCH101_COORDINATES_H

#include <vector>
#include <ostream>


class coordinates {
    double coordinates_x;
    double coordinates_y;


public:
    coordinates(double coordinates_x, double coordinates_y);

    coordinates();
    virtual ~coordinates();
    std::vector<double> getcoordinates();
    bool operator==(const coordinates &rhs) const;
    bool operator!=(const coordinates &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const coordinates &coordinates1);
};


#endif //RESEARCH101_COORDINATES_H
