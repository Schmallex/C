//
// Created by Alex on 16.04.2018.
//

#include "Vec3f.h"
using namespace std;
#include <array>

namespace my {
    Vec3::Vec3(float x, float y, float z) {
        v_[0] = x;
        v_[1] = y;
        v_[2] = z;
    }

    float &Vec3::operator[](const int index) {
        return v_[index];
    }

    const float &Vec3::operator[](const int index) const {
        return v_[index];
    }

    Vec3 &Vec3::operator+=(const Vec3 rhs) {
        v_[0] += rhs[0];
        v_[1] += rhs[1];
        v_[2] += rhs[2];
        return *this;
    }

    Vec3 Vec3::operator+(const Vec3 &rhs) {
        Vec3 temp(*this);
        temp += rhs;
        return temp;
    }


    bool Vec3::operator==(const Vec3 rhs) {
        if (v_[0] == rhs[0] && v_[1] == rhs[1] && v_[2] == rhs[2]) {
            return true;
        } else {
            return false;
        }
    }

    bool Vec3::operator!=(const Vec3 rhs) {
        if (v_[0] != rhs[0] || v_[1] != rhs[1] || v_[2] != rhs[2]) {
            return true;
        } else {
            return false;
        }
    }

    Vec3 Vec3::operator-() {
        return Vec3(-v_[0], -v_[1], -v_[2]);
    }


    std::ostream &operator<<(std::ostream &os, const Vec3 rhs) {
        os << "(" << rhs[0] << "," << rhs[1] << "," << rhs[2] << ")";
        return os;
    }

    float dot(const Vec3 lhs, const Vec3 rhs) {
        return lhs[0] * rhs[0] + lhs[1] * rhs[1] + lhs[2] * rhs[2];
    }
}