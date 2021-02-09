#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
// The class declaration must have doxygen comments � put these in
// Follow the style in modelfile.h

/**
	 * @class Vector
	 * @brief Dynamic array that stores data of user defined type
	 * @author Charlie Sewell
	 * @version 01
	 * @date 27/04/2020
*/
template <class T>
class Vector
{
    private:
	    int size; ///size of dynamic array
	    T *vec; ///dynamic array
        /**
        * @brief Performs a deep copy of the input pointer array
        * @param &vect - Array to be copied
        * @return bool - whether array has been copyied
        */
	    bool Copy(const Vector<T> &vect){
	        std:: cout << "copying";
	        if(vect.vec != NULL){
                T *newVec = new T[vect.GetLength()]{};
                for(int i=0; i <vect.GetLength();i++){
                    newVec[i] = vect.vec[i];
                }
                size = vect.GetLength();
                delete[] vec;
                vec = newVec;
	        }
	        else{
                return(false);
	        }

	    }

	public:
        Vector(){
            size = 20;
            vec = NULL;
            vec = new T[size]{};
        };
        Vector(const Vector<T> &vect){
            vec = NULL;
            Copy(vect);

        };
        virtual ~Vector(){
            delete[] vec;
        };
        /**
        * @brief Gets the length of the dynamic Array
        * @return size - Length of Array
        */
        int GetLength() const;
        /**
        * @brief Resizes the dynamic array
        * @param newSize - New Size for Array
        * @return void
        */
        void reSize(int newSize){
            if(newSize < size)
                return;
            T *newVec = new T[newSize]{};
            for(int i=0; i <size;i++){
                newVec[i] = vec[i];
            }
            size = newSize;
            delete[] vec;
            vec = newVec;

        };
        /**
        * @brief Replaces the current array with the input
        * @param &vect - input array
        * @return *this - this object
        */
        Vector<T>& operator = (const Vector<T> &vect){
            Copy(vect);
            return *this;
        };
        /**
        * @brief fetches data from dynamic array
        * @param ind - indice of where to fetch data from
        * @return vec[ind] - the data found at indice
        */
        T& operator[](int ind){
            if(ind >= size){
                reSize(ind*2);
            }
            if(ind < size && ind >= 0)
                return vec[ind];
        }
};
template <class T>
int Vector<T>::GetLength() const{
        return(size);
};

#endif //VECTOR_H
