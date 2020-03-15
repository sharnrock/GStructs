#include <gtest/gtest.h>
#include "GMap.h"


TEST(GMap, SquareBracketOperator_StoreAndRetrieve_When_NewElement)
{
	int expected = 42;
	G::Map<int, int> map;
	map[2] = expected;
	ASSERT_EQ(expected, map[2]);
}