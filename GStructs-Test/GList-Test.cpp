#include "gtest/gtest.h"
#include "GList.h"



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