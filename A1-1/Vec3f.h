//
// Created by Alex on 16.04.2018.
//

#pragma once

#include <array>
#include <ostream>
namespace my {
class Vec3{

public:
    Vec3(float x =0,float y=0,float z =0);

    Vec3& operator+=(const my::Vec3 rhs);
    Vec3 operator+(const my::Vec3& rhs);

    Vec3 operator-();
    bool operator==( my::Vec3 rhs);
    bool operator!=( my::Vec3 rhs);


    static constexpr int dimension = 3;
    float& operator[] (const int index);
    const float& operator[] (const int index)const;

private:
     float v_[3];
};

std::ostream& operator<<(std::ostream& os, const my::Vec3 rhs);
float dot(const my::Vec3 lhs,const my::Vec3 rhs);

}