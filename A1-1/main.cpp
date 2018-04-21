#include <iostream>
#include "Vec3f.h"
#include "../A1-2/Vec.h"


int main() {
    Vec<float,3> f({1,2,3});
    Vec<float,4> f1({1,2,3,4});
    Vec<float,4> f2({1,2,3,4});
    Vec<float,3> f3({1,2,3});

    bool b = f==f3;
    bool nb = f!=f3;
    f3=f3+f;
    f1 = f1 * 5;
    float mult = f1[0];

    std::cout <<"+  "<< f3 << std::endl;
    std::cout <<"-  "<< -f3 << std::endl;
    std::cout <<"*  "<< mult << std::endl;
    std::cout <<"==  "<< b << std::endl;
    std::cout <<"!=  "<< nb << std::endl;

    return 0;
}