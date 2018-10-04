//
// Created by ayush on 02-10-2018.
//

#include <vector>
#include "coordinate.h"

coordinate::coordinate() {}

coordinate::coordinate(double coordinate_x, double coordinate_y) : coordinate_x(coordinate_x),
                                                                   coordinate_y(coordinate_y) {}

std::vector<double> coordinate::getcoordinate() {
    std::vector<double> temp({coordinate_x,coordinate_y});
    return temp;
}

bool coordinate::operator==(const coordinate &rhs) const {
    return coordinate_x == rhs.coordinate_x &&
           coordinate_y == rhs.coordinate_y;
}

bool coordinate::operator!=(const coordinate &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const coordinate &coordinate1) {
    os << "( " << coordinate1.coordinate_x << " , " << coordinate1.coordinate_y <<" )";
    return os;
}

coordinate::~coordinate() {

}
