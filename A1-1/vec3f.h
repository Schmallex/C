//
// Created by sasch on 20.04.2018.
//

#pragma once

#include <array>
#include <ostream>

namespace my {

    class Vec3f {

    public:
        Vec3f(float x = 0, float y = 0, float z = 0);

        Vec3f &operator+=(const my::Vec3f rhs);

 
        Vec3f operator+(const my::Vec3f &rhs)const;

        Vec3f operator-()const;

        bool operator ==(my::Vec3f rhs)const;

        bool operator!=(my::Vec3f rhs)const;

        float &operator[](const int index);

        const float &operator[](const int index) const;

        static constexpr int dimension = 3;

        using value_type=float;

    private:
        float v_[3];
    };

    std::ostream &operator<<(std::ostream &os, const my::Vec3f rhs);

    float dot(const my::Vec3f lhs, const my::Vec3f rhs);
}
 //A1_1_VEC3F_H
