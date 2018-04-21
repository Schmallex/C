//
// Created by Alex on 16.04.2018.
//

#pragma once

#include <array>
#include <ostream>

template<typename T,int N >
class Vec {

public:
    Vec<T, N>::Vec(std::array<T, N> const &v) : data_(v) {}

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

    Vec operator+( Vec &rhs) {
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
        temp = temp *-1;
        return temp;
    }

    int  size() const{
        return data_.size();
    }

    template<typename T,int N>
    friend  std::ostream& operator<<(std::ostream& os, const Vec rhs);

    template<typename T,int N>
    friend float dot(const Vec lhs, const Vec rhs) ;


private:
     std::array<T,N> data_;
};

template<typename T,int N>
std::ostream& operator<<(std::ostream& os, const Vec<T,N> rhs){
    os<< "("<<rhs[0];
    for (int i = 1; i < rhs.size(); i++){
        os<< ","<< rhs[i]  ;
    }
    os<<")";
    return os;

}

template<typename T,int N>
float dot(const Vec <T,N>lhs, const Vec<T,N> rhs) {
    int product =0;
    int ans =0;
    for (int i = 0; i < rhs.size(); i++){
        product =lhs[i] * rhs[i];
        ans += product;
        product=0;
    }
    return ans;
}

