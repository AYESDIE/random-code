#include <iostream>
#include "line.h"
#include "coordinate.h"
#include "foo.h"
#include <random>

/*!
 * makes "coordinate" equidistant to each other
 * @param edgenode
 * @param length
 * @return vector of "coordinate"
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

void fspt(foo boo,int l){
    long long int step,amp;
    long long int ac=0,wa=0;
    coordinate p(0,0);
    std::cout<<"\nStarting coordinate:"<<p;
    std::cout<<"\n>> Step Size : ";
    std::cin>>step;

    long long int length = step*l;
    amp = l;
    for (long long int i = 0; i <= length ; i+=amp) {
        for (long long int j = 0; j <= length ; j+=amp) {
            double a,b;
            a = (double)i / step;
            b = (double)j / step;
            coordinate cx(a,b);
            int n = boo.evaluate(cx);
            if(n==2){
                ac++;
            }
            else{
                wa++;
            }
        }
    }
    std::cout<<"\n>> AC : "<<ac<<"\n>> WA : "<<wa;
}

void arv(foo boo){
    long long int t,ac=0,wa=0;
    std::default_random_engine generator;
    std::cout<<"\n Number of iterations : ";
    std::cin>>t;
    std::uniform_real_distribution<double> distribution(0,4);
    for (int i = 0; i < t; ++i) {
        double roll1 = distribution(generator);
        double roll2 = distribution(generator);
        coordinate cx(roll1,roll2);
        if(boo.evaluate(cx)==2){
            ac++;
        }
        else{
            wa++;
        }
    }
    std::cout<<"\n>> AC : "<<ac<<"\n>> WA : "<<wa;
}

//void rspt(foo boo, int l){
//    long long int step,amp;
//    long long int ac=0,wa=0;
//    std::default_random_engine generator;
//    std::uniform_real_distribution<double> distribution(0,l);
//    double roll1 = distribution(generator);
//    roll1=0;
//    coordinate p(roll1,0);
//    std::cout<<"\nStarting coordinate:"<<p;
//    std::cout<<"\n>> step size : ";
//    std::cin>>step;
//
//    long long int length = step*l;
//    amp = l;
//    for (long long int i = 0; i <= length ; i+=amp) {
//        for (long long int j = 0; j <= length ; j+=amp) {
//            double a,b;
//            a = (double)i / step;
//            b = (double)j / step;
//            coordinate cx(a,b);
//            int n = boo.evaluate(cx);
//            if(n==2){
//                ac++;
//            }
//            else{
//                wa++;
//            }
//        }
//    }
//
//    std::cout<<"\n>> AC : "<<ac<<"\n>> WA : "<<wa;
//}

void mc(foo boo){
    long long int t;
    int n;
    std::cout<<"\n Number of iterations : ";
    std::cin>>t;
    for (int i = 0; i < t; ++i) {
        double l,q;
        std::cout<<"\n>> x: ";
        std::cin>>l;
        std::cout<<"\n>> y: ";
        std::cin>>q;
        coordinate cx(l,q);
        n = boo.evaluate(cx);
        if(n==2){
            std::cout<<"\n>> AC";
        }
        else{
            std::cout<<"\n>> WA";
        }
        std::cout<<"\n-----------------------------------------------\n";
    }
}

int main(){

    int a=0,b=0,p=0,n;
    int c,l=4;
    std::cout<<"\n================================================\n";
    std::cout<<" Enter nodes per side(minimum = 2): ";
    std::cin>>n;
    std::cout<<" Enter length of a side(default = 4): ";
    std::cin>>l;
    n=n-2;
    std::vector<coordinate> x = makecoordinate(n,l);
    foo boo(x);
    std::cout<<"\nAll the coordinates:\n";
    for (int i = 0; i < x.size(); ++i) {
        std::cout<<"\n>> "<<x[i];
    }
    std::cout<<"\n 1) All random values\n 2) Fixed starting point and traversal\n 3) Fixed starting point with noise and traversal \n 4) Manual Checking\n >> ";
    std::cin>>c;
    switch (c){
        case 1:
            arv(boo);
            break;
        case 2:
            fspt(boo,l);
            break;
        case 3:
            //rspt(boo,l);
            break;
        case 4:
            mc(boo);
            break;
        default:
            std::cout<<"\n>>  Consider Rechecking";
    }
    return 0;
}