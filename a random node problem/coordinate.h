
#ifndef RESEARCH101_COORDINATE_H
#define RESEARCH101_COORDINATE_H

#include <vector>
#include <ostream>

/*!
 * A class that holds the values of "coordinate"
 */
class coordinate {
    /*!
     * @param coordinate_x - Holds the value of x
     * @param coordinate_y - Holds the value of y
     */
    double coordinate_x;
    double coordinate_y;

public:
    coordinate();

    /*!
     * Parameterized constructor
     *
     * @param coordinate_x
     * @param coordinate_y
     */
    coordinate(double coordinate_x, double coordinate_y);
    virtual ~coordinate();

    /*!
     * Returns the "coordinate" in std::vector
     * @return std::vector<double>(coordinate_x,coordinate_y)
     */
    std::vector<double> getcoordinate();

    /*!
     * Equality Operator
     */
    bool operator==(const coordinate &rhs) const;
    bool operator!=(const coordinate &rhs) const;

    /*!
     * ostream for "coordinate"
     * @param os
     * @param coordinate1
     * @return ostream for "coordinate"
     */
    friend std::ostream &operator<<(std::ostream &os, const coordinate &coordinate1);
};


#endif //RESEARCH101_COORDINATE_H
