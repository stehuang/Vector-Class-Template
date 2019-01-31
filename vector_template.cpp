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
    template <typename T>
    class vector{
        
    private:
        size_t the_size;
        size_t the_capacity;
        T* the_data;
        
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
        T at(size_t index) const;
        T& operator[]( size_t index );
        T operator[]( size_t index ) const;
        void dump_data_to( std::ostream& out ) const;
        void dump_data() const;
        void push_back(T new_value);
        void pop_back();
        
        // overloading operations
        // vector * double; the other way around is defined as a non-member func
        vector operator*(size_t numb) const;
        vector operator+(const vector& rhs) const;
        vector& operator+=(const vector& rhs);
        T operator*(const vector& rhs) const;
        bool operator>(const vector& rhs) const;
        bool operator<(const vector& rhs) const;
        bool operator>=(const vector& rhs) const;
        bool operator<=(const vector& rhs) const;
        bool operator==(const vector& rhs) const;
        bool operator!=(const vector& rhs) const;


        
        
    private:
        //Other members [private]
        void reserve( size_t new_capacity );
        
    };
    
    
    
    // 4 main functions modified to accept type T objects
    
    template <typename T>
    vector<T>::vector(): the_data(nullptr), the_size(0), the_capacity(INIT_CAP) {
        the_data = new T[the_capacity];
    }
    
    template <typename T>
    vector<T>::vector(const vector& source)
    : the_data(nullptr), the_size(source.the_size), the_capacity(source.the_capacity) {
        
        the_data = new T[the_capacity];
        
        // Deep copy of internal array
        for (int i = 0 ; i < the_size ; ++i ){
            the_data[i] = source.the_data[i];
        }
    }
    
    template <typename T>
    vector<T>& vector<T>::operator=(const vector& rhs){
        if (this != &rhs) {     // Self-assignment?
            // Release old memory and request more
            delete[] the_data;
            the_data = new T[rhs.the_capacity];
            
            // Shallow copy non-pointers
            the_size = rhs.the_size;
            the_capacity = rhs.the_capacity;
            
            // Deep copy internal array
            for (int i = 0 ; i < the_size ; ++i)
                the_data[i] = rhs.the_data[i];
        }
        return *this;
    }
    
    template <typename T>
    vector<T>::~vector(){
        delete[] the_data;
    }
    
    
    
    //////////////////// Other functions //////////////////////
    template <typename T>
    bool vector<T>::empty() const {
        return (the_size == 0);
    }
    
    template <typename T>
    size_t vector<T>::size() const {
        return the_size;
    }
    
    template <typename T>
    size_t vector<T>::capacity() const {
        return the_capacity;
    }
    
    template <typename T>
    T vector<T>::front() const {
        return *the_data;
    }
    
    template <typename T>
    T vector<T>::back() const {
        return *(the_data + the_size - 1);
    }
    
    template <typename T>
    T vector<T>::at(size_t index) const {
        if (index < the_size)
            return the_data[index];
        return the_data[0];
    }
    
    template <typename T>
    T& vector<T>::operator[]( size_t index ){
        return the_data[index];
    }
    
    template <typename T>
    T vector<T>::operator[]( size_t index ) const {
        return the_data[index];
    }
    
    template <typename T>
    void vector<T>::push_back(T new_value){
        if ( the_size == the_capacity )
            reserve( the_capacity + 1 );     // `the_data` is reassigned
        
        the_data[the_size++] = new_value;
    }
    
    template <typename T>
    void vector<T>::reserve( size_t new_capacity ){
        if ( new_capacity > the_capacity ) {
            if ( new_capacity <= 2 * the_capacity )
                new_capacity = 2 * the_capacity;
            
            T* old_location = the_data;
            
            the_data = new T[new_capacity];
            the_capacity = new_capacity;
            
            for ( size_t i = 0 ; i < the_size ; ++i )
                the_data[i] = old_location[i];
            
            delete old_location;
        }
    }
    
    template <typename T>
    vector<T> vector<T>::operator*(size_t numb) const{
        vector<T> result = *this;
        for(size_t i=0; i<the_size; i++){
            result.the_data[i] = result.the_data[i]*numb;
        }
        return result;
    }
    
    // end of namespace
}





/** ************************ OTHER FUNCTIONS ************************ **/
template <typename T>
std::ostream& operator<<( std::ostream& out, const Pic10c::vector<T>& v ){
    for ( size_t i = 0 ; i < v.size() ; ++i )
        out << v[i] << ' ';
    return out;
}

template <typename T>
void print_vector( const Pic10c::vector<T>& v ){
    if ( v.empty() )
        std::cout << "Vector is empty\n";
    else
        std::cout << "Vector (contents): " << v << '\n' ;
}

// numb * vector; non member function
template <typename T>
Pic10c::vector<T> operator*(size_t numb, const Pic10c::vector<T> rhs){
    return rhs * numb;
    // DO NOT RETURN BY REFERENCE; i.e. NO VECTOR<T>&
}














#endif








