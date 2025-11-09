#include <bits/stdc++.h>
using namespace std;

template <typename T>
class MyVector
{
public:
    T *data;
    size_t size;
    size_t capacity;

    // Constructor with initial capacity
    MyVector() : size(0), capacity(4)
    {
        data = new T[capacity];
    }

    // Destructor
    ~MyVector()
    {
        delete[] data;
    }

    // Copy Constructor
    MyVector(const MyVector &other) : size(other.size), capacity(other.capacity)
    {
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }

    // Assignment Operator
    MyVector &operator=(const MyVector &other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for (size_t i = 0; i < size; ++i)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Resize the vector
    void resize(size_t new_size)
    {
        if (new_size > capacity)
        {
            T *new_data = new T[new_size];
            for (size_t i = 0; i < size; ++i)
            {
                new_data[i] = data[i];
            }

            delete[] data;
            data = new_data;
            capacity = new_size;
        }
    }

    // Push an element to the back of the vector
    void push_back(const T &value)
    {
        if (size == capacity)
        {
            resize(capacity * 2);
        }
        data[size] = value; // Assign value at the current size
        size++;             // Increment size after assigning the value
    }

    // Remove last element
    void pop_back()
    {
        if (size > 0)
        {
            size--;
        }
    }

    // Access element at given index
    T &at(size_t index)
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
};

int main()
{
    // Example usage
    MyVector<int> myVec;

    myVec.push_back(1);
    myVec.push_back(2);
    myVec.push_back(3);
    myVec.pop_back();
    myVec.push_back(4);

    cout << "Element at index 2: " << myVec.at(2) << endl;
    cout << "Vector size: " << myVec.size << endl;
    cout << "Vector capacity: " << myVec.capacity << endl;

    return 0;
}
