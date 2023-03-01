#pragma once
#include <initializer_list>
#include <utility>
#include "iterator.h"

template<class Type, size_t array_size = 0>
class array {
public:
	array(std::initializer_list<Type> initList = {}) {
		m_size = array_size;
		m_array = new Type[m_size];

		if (initList.size() == 1) {
			for (size_t i = 0; i < m_size; i++) {
				m_array[i] = *initList.begin();
			}
		}
		else if (initList.size() != 0) {
			size_t i = 0;
			for (auto iterator = initList.begin(); iterator < initList.end(); iterator++) {
				m_array[i] = *iterator;
				i++;
			}
		}
	}

	size_t size() const {
		return m_size;
	}

	bool empty() {
		if (m_size == 0) {
			return true;
		}
		return false;
	}

	Type& operator[](size_t index) {
		return m_array[index];
	}

	void resize(size_t newSize) {
		Type* movedArray = new Type[newSize];
		size_t elementCount = std::min(m_size, newSize);
		for (int i = 0; i < elementCount; i++) {
			movedArray[i] = std::move(m_array[i]);
		}
		delete[] m_array;

		m_array = movedArray;
		m_size = newSize;
	}

	void push_back(Type newElement) {
		resize(m_size + 1);
		m_array[m_size - 1] = newElement;
	}

	void erase(iterator<Type> iterator) {
		for (; iterator != end(); iterator++) {
			*iterator = *(iterator + 1);
		}
		resize(m_size - 1);
	}

	iterator<Type> begin() {
		return iterator<Type>(m_array);
	}

	iterator<Type> end() {
		return iterator<Type>(m_array + m_size);
	}

	~array() {
		delete[] m_array;
	}
private:
	Type* m_array;
	size_t m_size;
};
