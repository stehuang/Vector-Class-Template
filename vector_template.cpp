//
//  vector_template.cpp
//  
//
//  Created by Stella Huang on 1/28/19.
//
//

#include <stdio.h>
#include <iostream>

namespace Pic10c{
    template <typename T, typename Allocator = std::allocator<T>>
    class vector{
        
    private:
        size_t size;
        size_t capacity;
        T* data;
        
        static const int INIT_CAP = 10;

        
        
    public:
        // 4 main functions
        vector();
        vector(const vector&);
        vector& operator=(const vector&);
        ~vector();
        
        // other functions
        bool empty() const;
        size_t size() const;
        size_t capacity() const;
        T front() const;
        T back() const;
        T at( size_t index ) const;
        void push_back(T new_value);
        void pop_back();
        void dump_data_to( std::ostream& out ) const;
        void dump_data() const;
        void push_back( double new_value );
        void pop_back();
    };

    
}

// 4 main functions modified to accept type T objects

template <typename T>
vector<T>::vector()
: data(nullptr), size(0), capacity(INIT_CAP) {
    
    data = new T[capacity];
}

template <typename T>
vector<T>::vector(const vector& source)
: data(nullptr), size(source.size), capacity(source.capacity) {
    
    data = new T[capacity];
    
    // Deep copy of internal array
    for ( int i = 0 ; i < the_size ; ++i ){
        data[i] = source.data[i];
    }
}

template <typename T>
vector<T>&::operator=(const vector& rhs) {
    if (this != &rhs) {     // Self-assignment?
        // Release old memory and request more
        delete[] data;
        data = new T[rhs.capacity];
        
        // Shallow copy non-pointers
        size = rhs.size;
        capacity = rhs.capacity;
        
        // Deep copy internal array
        for (int i = 0 ; i < the_size ; ++i)
            data[i] = rhs.data[i];
    }
    return *this;
}


template <typename T>
vector<T>::~vector(){
    delete[] data;
}



//////////////////// Other functions //////////////////////

bool vector::empty() const {
    return (size == 0);
}

size_t vector::size() const {
    return size;
}

size_t vector::capacity() const {
    return capacity;
}

template <typename T>
T vector::front() const {
    return *data;
}

template <typename T>
T vector::back() const {
    return *(the_data + the_size - 1);
}

template <typename A_Type>
T vector::at( size_t index ) const {
    if (index < size)
        return data[index];
    return data[0];
}













