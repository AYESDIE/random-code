
#ifndef RESEARCH101_LINES_H
#define RESEARCH101_LINES_H


#include <vector>
#include <ostream>
#include "coordinate.h"

class line {
    /*!
     * instead of representing the line by the formula
     *          y = mx + c
     *
     * the line is represented by the formula
     *          my - nx + c = 0
     *
     *      where m = x2 - x1 ,
     *            n = y2 - y1 ,
     *      and   c = ( n * x1 ) - ( m * y1 )
     *
     *      and the slope is given as = n/m
     *
     */
    double line_m;
    double line_n;
    double line_c;
    /*!
     * function minimize the values of m, n and c without any change in the line
     */
    void minimize();

public:
    line();
    /*!
     * Parameterized constructor for line
     * @param c1 - coordinate of a point as an object of class coordinate
     * @param c2 - coordinate of another point as an object of class coordinate
     */
    line(coordinate c1,coordinate c2);
    virtual ~line();

    /*!
     * function returns the m, n and c parameters of the line
     * @return
     */
    std::vector<double> getline();

    /*!
     * checks whether the given coordinate lies on line
     * @param c - coordinate for the given query
     * @return - true if the coordinate lies on the line
     */
    bool check(coordinate c);

    /*!
     * equality operator
     */
    bool operator==(const line &rhs) const;
    bool operator!=(const line &rhs) const;

    /*!
     * ostream for line
     * @param os
     * @param line1
     * @return ostream for line
     */
    friend std::ostream &operator<<(std::ostream &os, const line &line1);

};


#endif //RESEARCH101_LINES_H
