//
// Created by sasch on 20.04.2018.
//

#include "Vec3f.h"
using namespace std;
#include <array>

namespace my {

    Vec3f::Vec3f(float x, float y, float z) {
        v_[0] = x;
        v_[1] = y;
        v_[2] = z;
    }

    float &Vec3f::operator[](const int index) {
        return v_[index];
    }

    const float &Vec3f::operator[](const int index) const {
        return v_[index];
    }

    Vec3f &Vec3f::operator+=(const Vec3f rhs) {
        v_[0] += rhs[0];
        v_[1] += rhs[1];
        v_[2] += rhs[2];
        return *this;
    }


    Vec3f Vec3f::operator+(const Vec3f &rhs) const{
        Vec3f temp(*this);
        temp += rhs;
        return temp;
    }


    bool Vec3f:: operator ==( Vec3f rhs) const {
        if (v_[0] == rhs[0] && v_[1] == rhs[1] && v_[2] == rhs[2]) {
            return true;
        } else {
            return false;
        }
    }

    bool Vec3f::operator!=(const Vec3f rhs) const {
        if (v_[0] != rhs[0] || v_[1] != rhs[1] || v_[2] != rhs[2]) {
            return true;
        } else {
            return false;
        }
    }

    Vec3f Vec3f::operator-() const {
        return Vec3f(-v_[0], -v_[1], -v_[2]);
    }


    std::ostream &operator<<(std::ostream &os, const Vec3f rhs) {
        os << "(" << rhs[0] << "," << rhs[1] << "," << rhs[2] << ")";
        return os;
    }

    float dot(const Vec3f lhs, const Vec3f rhs) {
        return lhs[0] * rhs[0] + lhs[1] * rhs[1] + lhs[2] * rhs[2];
    }
}
