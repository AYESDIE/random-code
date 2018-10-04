#include <iostream>
#include "boo.h"
#include <cmath>

using namespace std;

int main() {
    for (double i = 2; i < 10; ++i) {
        boo phoo(10,std::pow(2,i),i);
        phoo.evaluate();
        phoo.result();
    }
    return 0;
}
