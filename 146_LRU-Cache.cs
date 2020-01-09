// github.com/gentlespoon
// 0146 - Medium - LRU Cache
// 2020-01-07T22:26:01-07:00
// 2020-01-07T22:53:14-07:00
// Runtime: 244 ms, faster than 99.15% of C# online submissions for LRU Cache.
// Memory Usage: 50.5 MB, less than 6.67% of C# online submissions for LRU Cache.

/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/


public class LRUCache
{
    private int _capacity;
    private LinkedList<int> _used;
    private Dictionary<int, (int, LinkedListNode<int>)> _cache;

    public LRUCache(int capacity)
    {
        _capacity = capacity;
        _used = new LinkedList<int>();
        _cache = new Dictionary<int, (int, LinkedListNode<int>)>();
    }

    public int Get(int key)
    {
        (int, LinkedListNode<int>) value;
        if(_cache.TryGetValue(key, out value))
        {
            _used.Remove(value.Item2);
            var newNode = _used.AddFirst(key);
            _cache[key] = (value.Item1, newNode);
            return value.Item1;
        }

        return -1;
    }

    public void Put(int key, int newValue)
    {
        (int, LinkedListNode<int>) value;
        LinkedListNode<int> newNode = null;
        if (_cache.TryGetValue(key, out value))
        {
            _used.Remove(value.Item2);
        }
        else if (_capacity == _used.Count)
        {
            var last = _used.Last;
            _used.Remove(last);
            _cache.Remove(last.Value);
        }

        newNode = _used.AddFirst(key);
        _cache[key] = (newValue, newNode);
    }

}
