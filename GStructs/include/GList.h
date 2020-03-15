#ifndef _GLIST_H_
#define _GLIST_H_

#include <assert.h>
namespace G
{
    /// Dynamic array; doubles in capacity when out of space
    template<typename T>
    class List
    {
    public:
        List(int starting_capacity)
            : data(new T[starting_capacity])
            , capacity(starting_capacity)
            , next_insert(0)
        {}

        List()
            : data(nullptr)
            , capacity(0)
            , next_insert(0)
        {}

        ~List()
        {
            if (data)
                delete[] data;
        }

        T& operator[](int ndx)
        {
            return data[ndx];
        }

        const T& operator[](int ndx) const
        {
            return data[ndx];
        }

        int getCapacity() { return capacity; }
        int getCount() { return next_insert; }
        const T* getData() const { return data; }

        void append(const T& t)
        {
            if (!hasEnoughCapacityToInsert())
                fixCapacity();
            data[next_insert++] = t;
        }

        /// Returns index or -1 if it doesn't exist
        int getIndexOfElement(const T& element)
        {
            for (int i = 0; i < getCount(); i++)
            {
                if (data[i] == element)
                    return i;
            }
            return -1;
        }

    private:
        void fixCapacity()
        {
            if (isStartingCapacity())
                initializeArray();
            else
                doubleCapacityAndCopyDataToNewArray();
        }

        void doubleCapacityAndCopyDataToNewArray()
        {
            capacity <<= 1; // double value /w shift
            T* newone = new T[capacity];
            assert(capacity > next_insert);
            for (int i = 0; i < next_insert; i++)
                newone[i] = data[i];

            delete[] data;
            data = newone;
        }

        void initializeArray()
        {
            capacity = 1;
            data = new T[capacity];
        }

        bool isStartingCapacity()
        {
            return !capacity;
        }

        bool hasEnoughCapacityToInsert()
        {
            return next_insert < capacity;
        }

    
        T* data;
        int capacity;
        int next_insert;
    };
}

#endif // _GLIST_H_
