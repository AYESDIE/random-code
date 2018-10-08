
#ifndef RESEARCH101_FOO_H
#define RESEARCH101_FOO_H

#include "coordinate.h"
#include "line.h"

/*!
 * The uppermost layer that holds all the coordinates and lines
 */

class foo {
    std::vector<coordinate> foo_coordinate;
    std::vector<line> foo_line;

    /*!
     * function makes all possible lines that can be made using the given "coordinate"
     * without repeating and "line"
     */
    void init();

public:
    foo();
    /*!
     * parameterized constructor
     * @param foo_coordinate - a vector of all the "coordinate"
     */
    foo(const std::vector<coordinate> &foo_coordinate);
    virtual ~foo();

    /*!
     *
     * @param x - "coordinate" for the query
     * @return - returns 0 if no link broken
     *           returns 1 if only one link is broken
     *           else returns 2
     */
    int evaluate(coordinate x);

    /*!
     * Shows all the equations
     */
    void show();

};


#endif //RESEARCH101_FOO_H
