#include <iostream>
#include "line.h"
#include "coordinate.h"
#include "foo.h"
#include <random>

/*!
 * makes coordinates equidistant to each other
 * @param edgenode
 * @param length
 * @return
 */
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
    std::vector<coordinate> c = makecoordinate(10);
    foo boo(c);

    int a=0,b=0,p=0,n;

    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0,4);
//    for (int i = 0; i < 100000; ++i) {
//        double roll1 = distribution(generator);
//        double roll2 = distribution(generator);
//        coordinate cx(roll1,roll2);
//        if(boo.evaluate(cx)==1){
//            std::cout<<cx;
//            std::cout<<" >>"<<boo.evaluate(cx)<<"\n";
//        }
//    }

//    int step = 100;
//    int length = 4;
//    for (int i = 0; i <= length*step; i++) {
//        for (int j = 0; j <= length*step; ++j) {
//            std::cout<<i<<" "<<j<<"\n";
//            double x = (double)i/step;
//            double y = (double)j/step;
//            coordinate cx(x,y);
//            n = boo.evaluate(cx);
//            if(n==2){
//                a++;
//            }
//            else if(n==1){
//                b++;
//            }
//            else{
//                p++;
//            }
//        }
//    }
//
//    std::cout<<a<<"\n"<<b<<"\n"<<p;

//    for (int i = 0; i < 10; ++i) {
//        double l,q;
//        std::cin>> l>>q;
//        coordinate cx(l,q);
//        n = boo.evaluate(cx);
//            if(n==2){
//                std::cout<<"AC";
//            }
//            else if(n==1){
//                std::cout<<"PC";
//            }
//            else{
//                std::cout<<"WA";
//            }
//    }

}