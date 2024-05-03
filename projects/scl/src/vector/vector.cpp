#include <iostream>
#include <stdexcept>

namespace ABelyaeva {
	template <typename T>
	Vector<T>::Vector() noexcept : arr(new T[capacity]), capacity(10), size(0) {}

	template <typename T>
	Vector<T>::~Vector() noexcept {
		delete[] arr;
	}

	template <typename T>
	void Vector<T>::push_back(const T& value) noexcept {
		if (size == capacity) {
			capacity *= 2;
			T* newArr = new T[capacity];
			for (std::size_t i = 0; i < size; ++i) {
				newArr[i] = arr[i];
			}
			delete[] arr;
			arr = newArr;
		}
		arr[size++] = value;
	}

	template <typename T>
	bool Vector<T>::has_item(const T& value) const noexcept {
		for (std::size_t i = 0; i < size; ++i) {
			if (arr[i] == value) {
				return true;
			}
		}
		return false;
	}

	template <typename T>
	bool Vector<T>::insert(const int position, const T& value) {
		if (position < 0 || position > static_cast<int>(size)) {
			return false;
		}
		if (size == capacity) {
			capacity *= 2;
			T* newArr = new T[capacity];
			for (std::size_t i = 0; i < size; ++i) {
				newArr[i] = arr[i];
			}
			delete[] arr;
			arr = newArr;
		}
		for (std::size_t i = size; i > position; --i) {
			arr[i] = arr[i - 1];
		}
		arr[position] = value;
		++size;
		return true;
	}

	template <typename T>
	void Vector<T>::print() const noexcept {
		for (std::size_t i = 0; i < size; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}

	template <typename T>
	bool Vector<T>::remove_first(const T& value) noexcept {
		for (std::size_t i = 0; i < size; ++i) {
			if (arr[i] == value) {
				for (std::size_t j = i + 1; j < size; ++j) {
					arr[j - 1] = arr[j];
				}
				--size;
				return true;
			}
		}
		return false;
	}

	template <typename T>
	std::size_t Vector<T>::size() const noexcept {
		return size;
	}
}

