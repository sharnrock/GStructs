#ifndef _GLIST_H_
#define _GLIST_H_

namespace G
{
	template<typename T>
	class List
	{
	public:
		List();
		List(int capacity);
		~List();

		int getCount() { return index; }
		int getCapacity() { return capacity; }
		void append(const T& element);

		T& operator[](int ndx)
		{
			return data[ndx];
		}

		const T& operator[](int ndx) const
		{
			return data[ndx];
		}

	private:
		void fixCapacity();

		int capacity;
		T* data;
		int index;
	};

	template<typename T>
	List<T>::List() :
		capacity(0),
		data(nullptr),
		index(0)
	{
	}

	template<typename T>
	List<T>::List(int capacity) :
		capacity(capacity),
		data(new T[capacity]),
		index(0)
	{
	}

	template<typename T>
	List<T>::~List()
	{
		if (data)
			delete[] data;
	}

	template<typename T>
	void List<T>::append(const T& element)
	{
		fixCapacity();
		data[index] = element;
		++index;
	}

	template<typename T>
	void List<T>::fixCapacity()
	{
		if (index + 1 >= capacity)
		{
			// double capacity
			int old_capacity = capacity;
			capacity = (capacity) ? capacity << 1 : 1;
			T* new_data = new T[capacity];

			// Move data to new array
			assert(index < capacity);
			for (int i = 0; i < index; i++)
				new_data[i] = data[i];

			// Clean up
			if (data)
				delete[] data;

			data = new_data;
		}
	}
}

#endif

