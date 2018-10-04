//
// Created by ayush on 01-10-2018.
//

#include "lines.h"

lines::~lines() {

}

lines::lines(coordinates c1, coordinates c2) {
    std::vector<double> coor1 = c1.getcoordinates();
    std::vector<double> coor2 = c2.getcoordinates();
    double x2 = coor2[0];
    double y2 = coor2[1];
    double x1 = coor1[0];
    double y1 = coor1[1];

    lines_m = x2-x1;
    lines_n = y2-y1;
    lines_c = (lines_n*x1)-(lines_m*y1);
    minimize();
}

void lines::minimize() {
    if(lines_m==0){
        if((lines_n!=0)and(lines_c!=0)){
            double df = (lines_c<lines_n)? lines_c:lines_n;
            lines_c/=df;
            lines_n/=df;
        }
        else if(lines_n==0){
            lines_c=1;
        }
        else{
            lines_n=1;
        }
    }
    else if(lines_n==0){
        if((lines_m!=0)and(lines_c!=0)){
            double df = (lines_c<lines_m)? lines_c:lines_m;
            lines_c/=df;
            lines_m/=df;
        }
        else if(lines_m==0){
            lines_c=1;
        }
        else{
            lines_m=1;
        }
    }
    else if(lines_c==0){
        if((lines_n!=0)and(lines_m!=0)){
            double df = (lines_m<lines_n)? lines_m:lines_n;
            lines_m/=df;
            lines_n/=df;
        }
        else if(lines_n==0){
            lines_m=1;
        }
        else{
            lines_n=1;
        }
    }
}

bool lines::operator==(const lines &rhs) const {
    return lines_m == rhs.lines_m &&
           lines_n == rhs.lines_n &&
           lines_c == rhs.lines_c;
}

bool lines::operator!=(const lines &rhs) const {
    return !(rhs == *this);
}

std::vector<double> lines::getline() {
    std::vector<double> temp;
    temp.push_back(lines_m);
    temp.push_back(lines_n);
    temp.push_back(lines_c);
    return temp;
}
