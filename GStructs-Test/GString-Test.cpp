#include <gtest/gtest.h>
//#include "GString.h"

#include <stdint.h>
namespace G
{
	// Ascii or Latin1 manipulation.  Don't use for UTF-x
	class String
	{
	public:
		String(const char*);
		~String();

		int getMaximumAllowableSize() { return INT32_MAX; }

		const char* toConstChar()
		{
			return data;
		}

		int getCount() { return size_w_null; }

	private:
		int getCStringSize(const char* source);
		void copyCStrings(const char* source, char* destination);

		char* data;
		int size_w_null;
	};

	//// CPP
	String::String(const char* s)
	{
		size_w_null = getCStringSize(s);
		data = new char[size_w_null];
		copyCStrings(s, data);
	}
	
	String::~String()
	{
		delete[] data;
	}

	int String::getCStringSize(const char* source)
	{
		const char* start = source;
		while (*source++);
		assert(getMaximumAllowableSize() > (source - start));
		return (int)(source - start);
	}

	void String::copyCStrings(const char* source, char* destination)
	{
		while (*source)
		{
			*destination++ = *source++;
		}
		*destination = 0;
	}
}




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