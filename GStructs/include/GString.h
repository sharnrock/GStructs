#ifndef _GSTRING_H_
#define _GSTRING_H_

namespace G
{
	// Ascii or Latin1 manipulation (i.e Single Byte).  Don't use for UTF-x or multibyte encodings
	class String
	{
	public:
		/// The largest amount of chars this string can hold
		int getMaximumAllowableSize();

		String();
		String(const char*);
		String(const String& other);
		String(String&& other)  noexcept;
		~String();

		String& operator=(const char*);
		String& operator=(const String&);
		String& operator=(String&&) noexcept;
		const char& operator[](int ndx) const;

		bool operator==(const String& rvalue);
		bool operator!=(const String& rvalue);

		bool isNull() const;
		const char* toConstChar() const { return data; }
		int getCount() const { return size_w_null; }

	private:
		void removePreviousString();
		void initializeDataFromCString(const char* s);
		int getCStringSize(const char* source);
		void copyCStrings(const char* source, char* destination);

		char* data;
		int size_w_null;
	};
}

#endif // _GSTRING_H_