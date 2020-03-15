#include <gtest/gtest.h>
#include "GString.h"



TEST(GString, ToConstChar_ReturnsConstructedValue_When_Constructed)
{
	const char* expected = "Hello";
	G::String str(expected);
	ASSERT_STREQ(expected, str.toConstChar());
}

TEST(GString, Constructor_DoesNotBreak_When_NullString)
{
	G::String expected("\0");
	ASSERT_EQ(1, expected.getCount());
}

TEST(GString, Constructor_DoesNotBreak_When_NoString)
{
	G::String expected;
	ASSERT_EQ(0, expected.getCount());
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

TEST(GString, EqualsOperator_ReturnsFalse_When_StringsMismatch)
{
	G::String s1("Hello");
	G::String s2("GoodBye");
	ASSERT_FALSE(s1 == s2);
}

TEST(GString, EqualsOperator_ReturnsFalse_When_StringsMismatchSameSize)
{
	G::String s1("Hello");
	G::String s2("Hella");
	ASSERT_FALSE(s1 == s2);
}

TEST(GString, EqualsOperator_ReturnsTrue_When_StringsMatch)
{
	G::String s1("Hello");
	G::String s2("Hello");
	ASSERT_TRUE(s1 == s2);
}

TEST(GString, AssignmentOperator_AssignsNewString_When_GString)
{
	G::String expected("new_string");
	G::String str("initial");
	str = expected;
	ASSERT_STREQ(expected.toConstChar(), str.toConstChar());
}

TEST(GString, AssignmentOperator_AssignsNewString_When_ConstChar)
{
	const char* expected = "new_string";
	G::String str("initial");
	str = expected;
	ASSERT_STREQ(expected, str.toConstChar());
}

G::String invokeMoveOperator(G::String in)
{
	return in;
}

TEST(GString, MoveOperator_MovesPointer_To_LValueString)
{
	G::String expected("Hello");
	G::String actual("\0");
	actual = invokeMoveOperator(expected);
	ASSERT_STREQ(expected.toConstChar(), actual.toConstChar());
}

TEST(GString, CopyOperator_)
{
	G::String expected("Hello");
	G::String actual(expected);
	ASSERT_STREQ(expected.toConstChar(), actual.toConstChar());
}

TEST(GString, AssignmentOperator_CountsMatch_When_GStringInvoked)
{
	G::String expected("new_string");
	G::String str("abc");
	str = expected;
	ASSERT_EQ(expected.getCount(), str.getCount());
}

TEST(GString, AssignmentOperator_CountsMatch_When_CStringInvoked)
{
	G::String expected("new_string");
	G::String str("abc");
	str = expected.toConstChar();
	ASSERT_EQ(expected.getCount(), str.getCount());
}

TEST(GString, IsNull_ReturnsTrue_When_Null)
{
	G::String string;
	ASSERT_TRUE(string.isNull());
}

TEST(GString, IsNull_ReturnsFalse_When_NotNull)
{
	G::String string("stuff");
	ASSERT_FALSE(string.isNull());
}