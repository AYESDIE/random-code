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

/*!
 * this function traverses through the entire area starting from (0,0) taking given "step" in between the length
 *
 * if step = 100 and l = 1,
 *      increment in each iteration = 0.01
 *
 * @param boo - object of class foo to perform operations
 * @param l - length of side
 */
void fspt(foo boo,int l){

    long long int step,amp;
    long long int ac=0,wa=0;
    coordinate p(0,0);
    std::cout<<"\nStarting coordinate:"<<p;
    std::cout<<"\n>> Step Size : ";
    std::cin>>step;
    long long int length = step*l;
    amp = l;
    /*!
     *      Caution: the following 2 enclosed loop are to prevent any floating point error that were being caused when using
     *      i and j as double rather than long long int
     */
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

/*!
 * this function checks for all random values
 * @param boo - object of class foo to perform operations
 * @param l - length of side
 */
void arv(foo boo, int l){
    long long int t,ac=0,wa=0;
    std::default_random_engine generator;
    std::cout<<"\n Number of iterations : ";
    std::cin>>t;
    std::uniform_real_distribution<double> distribution(0,l);
    for (int i = 0; i < t; ++i) {
        /*!
         * generating 2 random values between 0 and l
         */
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

/*!
 * this function traverses through the entire area starting from (r1,r2) taking given "step" in between the length
 *
 *      0 <= r1,r2 <= ( l / step )
 *
 * these r1 and r2 are added as noise to normal coordinates as in fspt()
 *
 * @param boo - object of class foo to perform operations
 * @param l - length of side
 */
void rspt(foo boo, int l){
    double noise1,noise2;
    long long int step,amp=l;
    long long int ac=0,wa=0;

    std::cout<<"\n>> step size : ";
    std::cin>>step;
    noise1 = (double)l/step;

    /*!
     * generating "r1" and "r2" noises
     */
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0,noise1);
    noise2 = distribution(generator);
    noise1 = distribution(generator);

    coordinate p(noise1,noise2);
    std::cout<<"\nStarting coordinate"<<p;
    long long int length = step*l;
    /*!
     *      Caution: the following 2 enclosed loop are to prevent any floating point error that were being caused when using
     *      i and j as double rather than long long int
     */
    for (long long int i = 0; i <= length ; i+=amp) {
        for (long long int j = 0; j <= length ; j+=amp) {
            double a,b;
            a = ((double)i / step)+noise1;
            b = ((double)j / step)+noise2;
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

/*!
 * manual checking of points
 * @param boo - object of class foo to perform operations
 */
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
    int n,c,l=4;
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
    std::cout<<"\n 1) All random values\n 2) Fixed starting point and traversal\n 3) Random starting point with noise and traversal \n 4) Manual Checking\n >> ";
    std::cin>>c;
    switch (c){
        case 1:
            arv(boo,l);
            break;
        case 2:
            fspt(boo,l);
            break;
        case 3:
            rspt(boo,l);
            break;
        case 4:
            mc(boo);
            break;
        default:
            std::cout<<"\n>>  Consider Rechecking";
    }
    return 0;
}