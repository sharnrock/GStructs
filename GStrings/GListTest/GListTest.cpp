#include <gtest/gtest.h>

#include "GList.h"


namespace GetCapacity
{
	TEST(GListTest, GetCapacity_ReturnCapacity_When_Constructor)
	{
		G::List<int> list(5);
		ASSERT_EQ(5, list.getCapacity());
	}
}

namespace Append
{
	TEST(GListTest, Append_AddNew_When_Empty)
	{
		G::List<int> list;
		list.append(0);
		ASSERT_EQ(1, list.getCount());
	}

	TEST(GListTest, Append_DoubleCapacity_When_AppendPastCapacity)
	{
		G::List<int> list;
		list.append(1);
		list.append(1);
		ASSERT_EQ(2, list.getCapacity());
	}
}

namespace OperatorSquareBrackets
{
	TEST(GListTest, OperatorSquareBrackets_ReturnValue_When_NdxExists)
	{
		G::List<int> list;
		int expected = 0;
		list.append(expected);
		int actual = list[0];
		ASSERT_EQ(expected, actual);
	}

	TEST(GListTest, OperatorSquareBrackets_AlterValue_When_WriteToIndex)
	{
		G::List<int> list;
		int expected = 1;
		list.append(0);
		list[0] = 1;
		int actual = list[0];
		ASSERT_EQ(expected, actual);
	}
}