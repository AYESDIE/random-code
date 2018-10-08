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

//void fspt(int n){
//    std::vector<coordinate> c = makecoordinate(n);
//    foo boo(c);
//    double x,y;
//    long long int step,ac=0,wa=0;
//    int length = 4;
//
//    std::cout<<">> x : ";
//    std::cin>>x;
//    std::cout<<">> y : ";
//    std::cin>>y;
//    std::cout<<">> step size : ";
//    std::cin>>step;
//
//    for (int i = 0; i <= length*step; i++) {
//        for (int j = 0; j <= length*step; ++j) {
//            double a = (double)i/step;
//            double b = (double)j/step;
//            coordinate cx(a,b);
//            n = boo.evaluate(cx);
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

void arv(int n){
    std::vector<coordinate> c = makecoordinate(n);
    long long int t,ac=0,wa=0;
    foo boo(c);
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

//void rspt(int n){
//    std::vector<coordinate> c = makecoordinate(n);
//    foo boo(c);
//    double x,y;
//    long long int step,ac=0,wa=0;
//    int length = 4;
//
//    std::default_random_engine generator;
//    std::uniform_real_distribution<double> distribution(0,1);
//    double roll1 = distribution(generator);
//    double roll2 = distribution(generator);
//
//    std::cout<<">> step size : ";
//    std::cin>>step;
//
//    for (int i = 0; i <= length*step; i++) {
//        for (int j = 0; j <= length*step; ++j) {
//            double a = (double)i/step;
//            double b = (double)j/step;
//            coordinate cx(a,b);
//            n = boo.evaluate(cx);
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
//
//}

void mc(int n){
    std::vector<coordinate> c = makecoordinate(n);
    foo boo(c);
    long long int t;
    std::cout<<"\n Number of iterations : ";
    std::cin>>t;
    for (int i = 0; i < 10; ++i) {
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
    int c;
    std::cout<<"\n================================================\n";
    std::cout<<" Enter nodes per side(minimum = 2): ";
    std::cin>>n;
    n=n-2;
    std::vector<coordinate> x = makecoordinate(n);
    foo boo(x);
//    for (int i = 0; i < x.size(); ++i) {
//        std::cout<<"\n>> "<<x[i];
//    }
    std::cout<<"\n 1) All random values\n 2) Fixed starting point and traversal\n 3) Random starting point and traversal \n 4) Manual Checking\n >> ";
    std::cin>>c;
    switch (c){
        case 1:
            arv(n);
            break;
        case 2:
            //fspt(n);
            break;
        case 3:
            //rspt(n);
            break;
        case 4:
            mc(n);
            break;
        default:
            std::cout<<"\n>>  Consider Rechecking";
    }

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