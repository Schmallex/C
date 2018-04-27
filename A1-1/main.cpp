#include <iostream>
#include "vec3f.h"
#include "test11.cpp"

int main() {
    using namespace my;

    Vec3f a(1,1,3);
    Vec3f b(1,1,3);
    test_Vec3f();

    float x =dot(a,b);
    //test_Vec3f();
    std::cout << (a[1] == b[2]) << std::endl;
    return 0;
}