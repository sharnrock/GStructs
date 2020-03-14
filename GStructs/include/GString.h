#ifndef _GSTRING_H_
#define _GSTRING_H_

namespace G
{
	// Ascii or Latin1 manipulation.  Don't use for UTF-x
	class String
	{
	public:
		String(const char*);
		~String();

		const char& operator[](int ndx);

		int getMaximumAllowableSize();
		const char* toConstChar() { return data; }

		int getCount() { return size_w_null; }

	private:
		int getCStringSize(const char* source);
		void copyCStrings(const char* source, char* destination);

		char* data;
		int size_w_null;
	};
}

#endif // _GSTRING_H_