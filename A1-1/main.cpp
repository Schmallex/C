#include <iostream>
#include <random>
#include <vector>

#include "../A1-2/Vec.h"

int main() {
    using namespace my;
    using vec3f = Vec<float,3>

    Vec<float,3> a ({1,2,3});
    Vec<float,3> b ({1,2,3});


    float x =dot(a,b);
    //test_Vec3f();

    std::cout << (a[1] == b[2]) << std::endl;

    //Aufgabe 3 Test
    //3.3 Random Numbers Generator
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 100.0);

    std::vector<Vec> Vecs ;
    for (int i=0; i<10; ++i){
        float d = dist(mt);
        float e = dist(mt);
        float f = dist(mt);
        Vecs[i]=Vec<float,3>  ({d,e,f});
    }
    //3.4 components + 1
    for(Vec v : Vecs){
        for(int i = 0;i<v.length();i++){
            v[i]=v[i]+1;
        }
    }
    //3.5 components + 1 with std:transform
    std::vector<Vec> Vecs_copy;
    int increase (int i){return i +1;}
    for(Vec v : Vecs){
        std::transform(v.[0],v[2],Vecs_copy,increase);
    }



    return 0;
}