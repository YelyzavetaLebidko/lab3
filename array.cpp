#include "array.h"
#include <iostream>

Array::Array(int initialSize, int step)
    : m_initialSize(initialSize), m_step(step), m_arr(nullptr), m_currIndex(0), m_size(0) {
    if (initialSize < 1) {
        std::cerr << "Error: Initial size of the array must be greater than zero." << std::endl;
        return;
    }
    m_arr = new int[initialSize];
    m_size = initialSize;
}

Array::~Array() {
    delete[] m_arr;
}

void Array::showElements() const {
    for (int i = 0; i < m_currIndex; i++) {
        std::cout << m_arr[i] << " ";
    }
    std::cout << std::endl;
}

void Array::expandArray(int size) {
    if (size <= m_size) {
        std::cerr << "Error: New size of the array must be greater than the current size." << std::endl;
        return;
    }
    int* newArr = new int[size];
    for (int i = 0; i < m_size; i++) {
        newArr[i] = m_arr[i];
    }
    delete[] m_arr;
    m_arr = newArr;
    m_size = size;
}

int Array::getSize() const {
    return m_size;
}

int Array::getElemSize() const {
    return m_currIndex;
}

void Array::setValue(int val) {
    if (m_currIndex >= m_size) {
        expandArray(m_size + m_step);
    }
    m_arr[m_currIndex++] = val;
}

void Array::setArray(int* pArr, int size) {
    if (pArr == nullptr || size < 1) {
        std::cerr << "Error: Invalid input array." << std::endl;
        return;
    }
    if (m_arr != nullptr) {
        delete[] m_arr;
    }
    m_arr = new int[size];
    for (int i = 0; i < size; i++) {
        m_arr[i] = pArr[i];
    }
    m_currIndex = size;
    m_size = size;
}