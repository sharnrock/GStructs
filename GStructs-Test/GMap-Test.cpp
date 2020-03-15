#include <gtest/gtest.h>

#include "GList.h"
namespace G
{
	template<typename Key, typename Value>
	class Map
	{
	public:
		Map(int initial_capacity)
			: values(initial_capacity)
			, keys(initial_capacity)
			, count(0)
		{
		}

		Map()
			: count(0)
		{
		}

		Value& operator[](const Key& key)
		{
			int ndx = keys.getIndexOfElement(key);
			if (ndx < 0)
			{
				createNewPair(key, Value());
				return values[count-1];
			}
			return values[ndx];
		}

		void createNewPair(const Key& key, const Value& value)
		{
			keys.append(key);
			values.append(value);
			++count;
		}

		const G::List<Value>& getValues() { return values; }
		const G::List<Key>& getKeys() { return keys; }
		int getCount() { return count; }

	private:
		G::List<Value> values;
		G::List<Key> keys;
		int count;
	};
}

TEST(GMap, SquareBracketOperator_StoreAndRetrieve_When_NewElement)
{
	int expected = 42;
	G::Map<int, int> map;
	map[2] = expected;
	ASSERT_EQ(expected, map[2]);
}