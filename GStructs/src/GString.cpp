#include "GString.h"
#include <stdint.h>
#include <assert.h>

using namespace G;

int String::getMaximumAllowableSize() { return INT32_MAX; }

String::String(const char* s)
{
	size_w_null = getCStringSize(s);
	data = new char[size_w_null];
	copyCStrings(s, data);
}

String::String(const String& other)
{
	*this = other;
}

String::String(String&& other)
{
	*this = other;
}

String::~String()
{
	delete[] data;
}

String& String::operator=(const String& other)
{
	return *this;
}

String& String::operator=(String&& other) noexcept
{
	return *this;
}

const char& String::operator[](int ndx)
{
	return data[ndx];
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
		*destination++ = *source++;
	*destination = 0;
}

