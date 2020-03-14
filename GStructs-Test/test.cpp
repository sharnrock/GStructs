#include "gtest/gtest.h"

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

        int getCapacity() { return capacity;  }
        int getCount() { return next_insert; }

        void append(const T& t)
        {
            if (!hasEnoughCapacityToInsert())
                fixCapacity();
            data[next_insert++] = t;
        }

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

    private:
        T* data;
        int capacity;
        int next_insert;
    };
}

namespace Helper
{
    int getConstInt(const G::List<int>& testee, int ndx)
    {
        return testee[ndx];
    }
}

TEST(GList, Construct_CapacityIsEqual_After_Construct) 
{
    int expected = 12;
    G::List<int> l(expected);
    int actual = l.getCapacity();
    ASSERT_EQ(expected, actual);
}

TEST(GList, Append_CapacityDoubles_After_Append)
{
    G::List<int> l;
    ASSERT_EQ(0, l.getCapacity());
    l.append(1);
    ASSERT_EQ(1, l.getCapacity());
    l.append(1);
    ASSERT_EQ(2, l.getCapacity());
    l.append(1);
    ASSERT_EQ(4, l.getCapacity());
    l.append(1);
    ASSERT_EQ(4, l.getCapacity());
}

TEST(GList, Append_CountIncreases_After_Append)
{
    G::List<int> l;
    l.append(1);
    l.append(1);
    l.append(1);
    l.append(1);
    ASSERT_EQ(4, l.getCount());
}

TEST(GList, SquareBracketOperator_ReturnsValue_After_Append)
{
    int expected = 42;
    G::List<int> l;
    l.append(12);
    l.append(expected);
    int actual = l[1];
    ASSERT_EQ(expected, actual);
}

TEST(GList, SquareBracketOperator_UpdateValue_After_Append)
{
    int expected = 42;
    G::List<int> l;
    l.append(0);
    l[0] = expected;
    ASSERT_EQ(expected, l[0]);
}

TEST(GList, SquareBracketConstOperator_ReturnsValue_After_Append)
{
    int expected = 42;
    G::List<int> l;
    l.append(expected);
    int actual = Helper::getConstInt(l, 0);
    ASSERT_EQ(expected, actual);
}