#include <iostream>
#include "line.h"
#include "coordinate.h"
#include "foo.h"
#include <random>

std::vector<coordinate> makecoordinate(int edgenode,int length=4){
    std::vector<coordinate> temp;
    coordinate x;
    x = coordinate(0,0);
    temp.push_back(x);
    x = coordinate(0,length);
    temp.push_back(x);
    x = coordinate(length,0);
    temp.push_back(x);
    x = coordinate(length,length);
    temp.push_back(x);

    for (int i = 1; i <= edgenode; ++i) {
        double mf = (double)length/(edgenode+1);
        x = coordinate(0,i*mf);
        temp.push_back(x);
        x = coordinate(i*mf,0);
        temp.push_back(x);
        x = coordinate(length,i*mf);
        temp.push_back(x);
        x = coordinate(i*mf,length);
        temp.push_back(x);
    }
    return temp;
}

int main(){
    coordinate c1(0,0),c2(4,4),c3(0,4),c4(4,0),c5(0,2),c6(2,0),c7(4,2),c8(2,4);
    std::vector<coordinate> c = makecoordinate(20);
    foo boo(c);

    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0,4);
    for (int i = 0; i < 100000; ++i) {
        double roll1 = distribution(generator);
        double roll2 = distribution(generator);
        coordinate cx(roll1,roll2);
        if(boo.evaluate(cx)==2){
            std::cout<<cx;
            std::cout<<" >>"<<boo.evaluate(cx)<<"\n";
        }
    }

//    for (int i = 0; i <= 400; i++) {
//        for (int j = 0; j <= 400; ++j) {
//            double x = (double)i/100;
//            double y = (double)j/100;
//            coordinate cx(x,y);
//            if(boo.evaluate(cx)==2){
//                std::cout<<cx;
//                std::cout<<" >>"<<boo.evaluate(cx)<<"\n";
//            }
//        }
//
//    }

}