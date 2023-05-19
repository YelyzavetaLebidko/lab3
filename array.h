#ifndef ARRAY_H
#define ARRAY_H

class Array {
public:
    Array(int initialSize = 10, int step = 5); // constructor
    ~Array(); // destructor
    void showElements() const;
    void expandArray(int size);
    int getSize() const;
    int getElemSize() const;
    void setValue(int val);
    void setArray(int* pArr, int size);

private:
    int m_initialSize; // initial size of the array
    int m_step; // step size for expanding the array
    int* m_arr; // pointer to the array
    int m_currIndex; // index of the current element
    int m_size; // current size of the array
};

#endif // ARRAY_H