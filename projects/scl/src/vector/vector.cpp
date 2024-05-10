#include "vector.hpp"
#include <iostream>

namespace ABelyaeva {

    template <typename T>
    Vector<T>::Vector() noexcept : arr(new T[capacity]) {}

    template <typename T>
    Vector<T>::~Vector() noexcept {
        delete[] arr;
    }

    template <typename T>
    void Vector<T>::push_back(const T& value) noexcept {
        if (siz == capacity) {
            capacity *= 2;
            T* newArr = new T[capacity];
            for (std::size_t i = 0; i < siz; i++) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        arr[siz++] = value;
    }

    template <typename T>
    bool Vector<T>::has_item(const T& value) const noexcept {
        for (std::size_t i = 0; i < siz; i++) {
            if (arr[i] == value) {
                return true;
            }
        }
        return false;
    }

    template <typename T>
    bool Vector<T>::insert(const int position, const T& value) {
        if (position < 0 || position > static_cast<int>(siz)) {
            return false;
        }
        if (siz == capacity) {
            capacity *= 2;
            T* newArr = new T[capacity];
            for (std::size_t i = 0; i < siz; i++) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        for (int i = static_cast<int>(siz); i > position; i--) {
            arr[i] = arr[i - 1];
        }
        arr[position] = value;
        siz++;
        return true;
    }

    template <typename T>
    void Vector<T>::print() const noexcept {
        for (std::size_t i = 0; i < siz; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    template <typename T>
    bool Vector<T>::remove_first(const T& value) noexcept {
        for (std::size_t i = 0; i < siz; i++) {
            if (arr[i] == value) {
                for (std::size_t j = i + 1; j < siz; j++) {
                    arr[j - 1] = arr[j];
                }
                siz--;
                return true;
            }
        }
        return false;
    }

    template <typename T>
    int Vector<T>::size() const noexcept {
        return siz;
    }

}
