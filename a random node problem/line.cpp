/*!
 * Definition for line.h
 */

#include "line.h"

line::line() {}

line::~line() {

}

bool line::operator==(const line &rhs) const {
    return line_m == rhs.line_m &&
           line_n == rhs.line_n &&
           line_c == rhs.line_c;
}

bool line::operator!=(const line &rhs) const {
    return !(rhs == *this);
}

std::vector<double> line::getline() {
    /*!
     * returns the m, n and c data members as a vector
     */
    std::vector<double> temp({line_m,line_n,line_c});
    return temp;
}

line::line(coordinate c1, coordinate c2) {
    /*!
     * fills the parameters m, n and c for "my - nx + c = 0" to satisfy the "coordinate" c1 and c2
     */
    std::vector<double> a = c1.getcoordinate();
    std::vector<double> b = c2.getcoordinate();
    double x1 = a[0];
    double y1 = a[1];
    double x2 = b[0];
    double y2 = b[1];
    line_m = x2 - x1;
    line_n = y2 - y1;
    line_c = (line_n * x1) - (line_m * y1);
    /*!
     * minimize the value of m, n and c without changing the "line"
     */
    minimize();
}

bool line::check(coordinate c) {
    std::vector<double> a = c.getcoordinate();
    double x = a[0];
    double y = a[1];
    /*!
     * returns true if "coordinate" c lies on the "line"
     */
    return ((line_m*y)-(line_n*x)+line_c)==0;
}

void line::minimize() {
    /*!
     * minimize the value of m, n and c without changing the "line"
     */
    if(line_m!=0){
        line_n = line_n / line_m;
        line_c = line_c / line_m;
        line_m = 1;
    }
    else{
        line_c = line_c / line_n;
        line_n = 1;
    }
}

std::ostream &operator<<(std::ostream &os, const line &line1) {
    os << "line_m: " << line1.line_m << " line_n: " << line1.line_n << " line_c: " << line1.line_c;
    return os;
}
