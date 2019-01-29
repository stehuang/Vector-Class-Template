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

vector::vector()
: the_data(nullptr), size(0), capacity(INIT_CAP) {
    
    data = new T[capacity];
}

vector::vector(const vector& source)
: data(nullptr), size(source.size), capacity(source.capacity) {
    
    data = new T[capacity];
    
    // Deep copy of internal array
    for ( int i = 0 ; i < the_size ; ++i ){
        data[i] = source.data[i];
    }
}









