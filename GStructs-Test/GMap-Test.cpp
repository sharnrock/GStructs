#include <gtest/gtest.h>

#include "GList.h"
namespace G
{
	template<typename Key, typename Value>
	class Map
	{
	public:
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

	private:
		G::List<Value> values;
		G::List<Key> keys;
		int count;
	};
}

TEST(GMap, test1)
{
	int expected = 42;
	G::Map<int, int> map;
	map[2] = expected;
	ASSERT_EQ(expected, map[2]);
}