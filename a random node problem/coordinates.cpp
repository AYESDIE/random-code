//
// Created by ayush on 01-10-2018.
//

#include "coordinates.h"

coordinates::coordinates(double coordinates_x, double coordinates_y) : coordinates_x(coordinates_x),
                                                                       coordinates_y(coordinates_y) {}

coordinates::coordinates() {}

coordinates::~coordinates() {

}

std::vector<double> coordinates::getcoordinates() {
    std::vector<double> temp;
    temp.push_back(coordinates_x);
    temp.push_back(coordinates_y);
    return temp;
}

bool coordinates::operator==(const coordinates &rhs) const {
    return coordinates_x == rhs.coordinates_x &&
           coordinates_y == rhs.coordinates_y;
}

bool coordinates::operator!=(const coordinates &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const coordinates &coordinates1) {
    os << "coordinates_x: " << coordinates1.coordinates_x << " coordinates_y: " << coordinates1.coordinates_y;
    return os;
}
