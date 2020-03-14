#include <gtest/gtest.h>
#include "GString.h"



TEST(GString, ToConstChar_ReturnsConstructedValue_When_Constructed)
{
	const char* expected = "Hello";
	G::String str(expected);
	ASSERT_STREQ(expected, str.toConstChar());
}

TEST(GString, GetCount_ReturnsLengthWNull_When_StringExists)
{
	int expected = 6;
	G::String str("Hello");
	ASSERT_EQ(expected, str.getCount());
}

TEST(GString, SquareBracketOperator_ReturnsChar_When_NdxGiven)
{
	char expected = 'e';
	G::String str("Hello");
	ASSERT_EQ(expected, str[1]);
}