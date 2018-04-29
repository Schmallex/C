//
// Created by Alex on 16.04.2018.
//

#pragma once

#include <array>
#include <ostream>
#include <vector>

namespace my {

    template<typename T, int N>
    class Vec {

    public:
        explicit Vec(std::array<T, N> const &v) : data_(v) {}

        float operator[](const int index) {
            return data_[index];
        }

        const float operator[](const int index) const {
            return data_[index];
        }

        Vec operator+=(const Vec rhs) {
            for (int i = 0; i < data_.size(); i++) {
                data_[i] += rhs[i];
            }
            return *this;
        }

        Vec operator+(Vec &rhs) {
            Vec temp(*this);
            temp += rhs;
            return temp;
        }


        bool operator==(const Vec rhs) {
            for (int i = 0; i < data_.size(); i++) {
                if (data_[i] != rhs[i]) {
                    return false;
                }
            }
            return true;
        }

        bool operator!=(const Vec rhs) {
            for (int i = 0; i < data_.size(); i++) {
                if (data_[i] == rhs[i]) {
                    return false;
                }
            }
            return true;
        }

        Vec operator*(const int d) {
            for (int i = 0; i < data_.size(); i++) {
                data_[i] *= d;
            }
            return *this;
        }

        Vec operator-() {
            Vec temp(*this);
            temp = temp * -1;
            return temp;
        }

        int size() const {
            return data_.size();
        }

        template<typename Z, int M>
        friend std::ostream &operator<<(std::ostream &os, const Vec rhs);

        template<typename Z, int M>
        friend float dot(const Vec lhs, const Vec rhs);

        //Aufgabe 3

        float length() const {
            float l = 0;
            for (auto value : data_) {
                l += pow(value, 2);
            }
            return sqrt(l);
        }
        template<typename Z, int M>
        friend void lengthOfAll(std::vector<Vec> Vecs);


    private:
        std::array<T, N> data_;
    };

    template<typename Z, int M>
    std::ostream &operator<<(std::ostream &os, const Vec<Z,M> rhs) {
        os << "(" << rhs[0];
        for (int i = 1; i < rhs.size(); i++) {
            os << "," << rhs[i];
        }
        os << ")";
        return os;

    }

    template<typename Z, int M>
    float dot(const Vec<Z, M> lhs, const Vec<Z, M> rhs) {
        int product = 0;
        int ans = 0;
        for (int i = 0; i < rhs.size(); i++) {
            product = lhs[i] * rhs[i];
            ans += product;
            product = 0;
        }
        return ans;
    }


    void lengthOfAll(const  std::vector Vecs) {
        for (Vec v :Vecs) {
            std::cout << v << "Length : " << v.length();
        }
    }

}