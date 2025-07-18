#include <iostream>
#include <string>
#include <type_traits>
#include <complex>
#include <algorithm>

///@brief template class which describes a structure simmilar to std::vector
template<typename T>
class better_vector{
    T* array;
    size_t s; 

public:
    ///@brief default constructor
    better_vector():array(nullptr), s(0){}

    ///@brief copy constructor
    better_vector(const better_vector& other) : array(nullptr), s(other.s) {
        array = new T[s];
        for (size_t i = 0; i < s; ++i)
            array[i] = other.array[i];
    }

    ///@brief operator = overloading
    better_vector& operator=(const better_vector& other) {
        if (this != &other) {
            delete[] array;
            s = other.s;
            array = new T[s];
            for (size_t i = 0; i < s; ++i)
                array[i] = other.array[i];
        }
        return *this;
    }

    ///@brief function push_back which allocates a new place for a new element which will be placed in tnhe end of a vector
    ///@param new_element
    void push_back(const T& new_element){
        T* new_array = new T[s+1];
        for(size_t i=0; i<s; i++){
            new_array[i] = array[i];
        }
        new_array[s] = new_element;
        s++;
        delete[] array;
        array = new_array;
    }

    ///@brief function which clears all the data inside of a vector
    void clear(){
        delete[] array;
        array = nullptr;
        s = 0;
    }

    ///@brief function which looks for a size of a vector
    ///@return size
    size_t size() const{
        return s;
    }

    ///@brief function which helps to understanf if the vector is empty
    ///@return true if the vector is empty 
    bool empty() const{
        return s == 0;
    }
    
    ///@brief operator[] overloading
    T& operator[](int i){
        return array[i];
    }

    ///@brief operator[] const overloading
    const T& operator[](int i) const{
        return array[i];
    }

    ///@brief function which deletes the last elemment of a vector
    void pop_back(){
        if(s != 0){
            T* new_array = new T[s-1];
            for(size_t i=0; i<s-1; i++){
                new_array[i] = array[i];
            }
            s--;
            delete[] array;
            array = new_array;
        }
    }

    ///@brief operator + overloading
    better_vector<T> operator+(const better_vector<T>& v2) const {
        if (s != v2.s) {
            throw std::invalid_argument("Vectors must have same size for addition");
        }
        better_vector<T> new_one;
        for(size_t i=0; i<s; i++){
            new_one.push_back(array[i] + v2.array[i]);
        }
        return new_one;
    }

    ///@brief operator - overloading
    better_vector<T> operator-(const better_vector<T>& v2) const {
        if (s != v2.s) {
            throw std::invalid_argument("Vectors must have same size for subtraction");
        }
        better_vector<T> new_one;
        for(size_t i=0; i<s; i++){
            new_one.push_back(array[i] - v2.array[i]);
        }
        return new_one;
    }

    ///@brief operator* overloading
    template<typename U = T>
    typename std::enable_if<std::is_arithmetic<U>::value, better_vector<T>>::type
    operator*(U value) const {
        better_vector<T> new_one;
        for(size_t i=0; i<s; i++){
            new_one.push_back(array[i] * value);
        }
        return new_one;
    }
    
    ///@brief function which allocates new memory for a vector and changes its size
    void reserve(size_t new_capacity){
        if (s > new_capacity) return;
        T* new_array = new T[new_capacity];
        for(size_t i=0; i<s; i++){
            new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;
    }
    
    ///@brief function returns the first element
    T& front(){
        return array[0];
    }

    const T& front() const {
        return array[0];
    }

    ///@brief function returns the last element
    T& back(){
        return array[s-1];
    }

    const T& back() const {
        return array[s-1];
    }

    ///@brief changes the last element of an array
    template<typename... Args>
    void emplace_back(Args&&... args){
        T* new_array = new T[s+1];
        for(size_t i=0; i<s; i++){
            new_array[i] = array[i];
        }
        new_array[s] = T(std::forward<Args>(args)...);
        s++;
        delete[] array;
        array = new_array;
    }

    ///@brief destructor
    ~better_vector(){
        delete[] array;
    }
};