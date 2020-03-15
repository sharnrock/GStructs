#include "GString.h"
#include <stdint.h>
#include <assert.h>

using namespace G;

int String::getMaximumAllowableSize() { return INT32_MAX; }

String::String(const char* s)
	: data(nullptr)
	, size_w_null(0)
{
	initializeDataFromCString(s);
}

String::String()
	: data(nullptr)
	, size_w_null(0)
{
}

String::String(const String& other)
	: data(nullptr)
{
	*this = other;
}

String::String(String&& other) noexcept
	: data(nullptr)
{
	*this = other;
}

String::~String()
{
	delete[] data;
}

String& String::operator=(const char* rvalue)
{
	removePreviousString();
	initializeDataFromCString(rvalue);
	return *this;
}

String& String::operator=(const String& other)
{
	removePreviousString();
	initializeDataFromCString(other.toConstChar());
	return *this;
}

String& String::operator=(String&& other) noexcept
{
	removePreviousString();
	data = other.data;
	size_w_null = other.size_w_null;
	other.data = nullptr;
	other.size_w_null = 0;
	return *this;
}

const char& String::operator[](int ndx) const
{
	return data[ndx];
}

bool String::operator==(const String& rvalue)
{
	if (this->getCount() != rvalue.getCount())
	{
		return false;
	}

	for (int i = 0; i < this->getCount(); i++)
	{
		if (this->data[i] != rvalue.data[i])
			return false;
	}

	return true;
}

bool String::operator!=(const String& rvalue)
{
	return !(*this == rvalue);
}

bool String::isNull() const
{
	return !data;
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

void String::initializeDataFromCString(const char* s)
{
	assert(!data);
	size_w_null = getCStringSize(s);
	if (size_w_null)
	{
		data = new char[size_w_null];
		copyCStrings(s, data);
	}
}

void String::removePreviousString()
{
	if (data)
	{
		delete[] data;
		data = nullptr;
	}
}