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
    //3.2
    void printVecs (std::vector Vecs)const{
        lengthOfAll(Vecs);
    }
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
    std::cout << "3.3 Random" << std::endl;
   printVecs(Vecs) ;

    //3.4 components + 1
    for(Vec v : Vecs){
        for(int i = 0;i<v.length();i++){
            v[i]=v[i]+1;
        }
    }
    std::cout << "3.4 components + 1" << std::endl;
    printVecs(Vecs) ;

    //3.5 components + 1 with std:transform
    auto Vecs_transform = Vecs;

    int increase (int i){return i +1;}

    for(Vec v : Vecs){
        std::transform(v.[0],v[2],Vecs_transform,increase);
    }
    std::cout << "3.5 components + 1 with std:transform" << std::endl;
    printVecs(Vecs_transform) ;


    //3.6 stable_partition
    auto Vecs_stable = Vecs;
    //std::vector<int>::iterator bound;
    std::stable_partition (Vecs_stable.begin(), Vecs_stable.end(), [](Vec v){return v.length()<90;});
    std::cout << "3.6 stable partition" << std::endl;
    printVecs(Vecs_stable) ;


    //3.7 sort
    auto Vecs_sort = Vecs;
    std::sort(Vecs_sort.begin(),Vecs_sort.end(),[](Vec x, Vec y){return x.length()<y.length();});
    std::cout << "3.7 sort" << std::endl;
    printVecs(Vecs_sort) ;


    //3.8 middle ELement
    auto mid = Vecs_sort.begin() + Vecs_sort.size() / 2 ;
    std::cout << "3.8 middle Element" << std::endl;
    std::cout << Vecs_sort[mid] << std::endl;


    //3.9 copy_if
    std::vector<Vec> Vec_copy_if (Vecs.size());

    auto it = std::copy_if (Vecs.begin(), Vecs.end(), Vec_copy_if.begin(), [](Vec v ){return (v.size()<80);} );
    Vec_copy_if.resize(std::distance(Vec_copy_if.begin(),it));
    std::cout << "3.9 copy_if" << std::endl;
    printVecs( Vec_copy_if);


    //3.10
    auto Vecs_remove_erase = Vecs;
    bool inRange(Vec v){
        auto size = v.size();
        return size > 90 && size < 120;
    }
    auto to_be_erased =std::remove_if(Vecs_remove_erase.begin(),Vecs_remove_erase.end(),inRange);
    Vecs_remove_erase.erase(to_be_erased);
    std::cout << "3.10" << std::endl;
    printVecs( Vecs_remove_erase);

    return 0;
}

