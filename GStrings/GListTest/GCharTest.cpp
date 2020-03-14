#include <gtest/gtest.h>

namespace G
{
	// Latin 1
	class String
	{
	public:
		String() : str(nullptr) {}
		String(const char* str);
		~String();

		int getSize() { return size; }
	private:
		int getStringSize(const char*);
		char* str;
		int size;
	};

//// CPP
	String::String(const char* str)
	{
		size = getStringSize(str);

		char* temp = new char[size];
		this->str = temp;
		while (*str)
			*temp++ = *str++;
		*temp = 0;
	}

	String::~String()
	{
		if (str)
			delete[] str;
	}

	int String::getStringSize(const char* c)
	{
		const char* start = c;
		while (*c++);
		assert((c - start) < INT32_MAX);
		return (int)(c - start);
	}
}

TEST(GCharTest, GetSize_ReturnsSize_When_Construct)
{
	G::String s("hello");
	ASSERT_EQ(6, s.getSize());
}