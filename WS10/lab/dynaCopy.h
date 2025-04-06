// Author : Mahbod Darami  , Student ID : 117135244
//workshop 10
// i did all codes by mself
#ifndef SENECA_DYNACOPY_H
#define SENECA_DYNACOPY_H

#include <iostream>

namespace seneca {
    template <typename T>
    T* dynaCopy(const T* src, int size) {
        if (!src || size <= 0) return nullptr;

        T* dest = new T[size];
        for (int i = 0; i < size; ++i) {
            dest[i] = src[i];
        }
        return dest;
    }
    template <typename T>
    T* dynaCopy(T*& dest, const T* src, int size) {
        delete[] dest;
        dest = nullptr;

        if (!src || size <= 0) return nullptr;

        dest = new T[size];
        for (int i = 0; i < size; ++i) {
            dest[i] = src[i];
        }
        return dest;
    }
    template <typename T>
    void prnArray(const T* arr, int size) {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i];
            if (i < size - 1) std::cout << ", ";
        }
        std::cout << std::endl;
    }

}

#endif // SENECA_DYNACOPY_H
