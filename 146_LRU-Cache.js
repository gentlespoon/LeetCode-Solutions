/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 );

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


// GentleSpoon me@gentlespoon.com
// Leetcode    Q146
// Start       2019-02-20 15:22:48
// Finish      2019-02-20 15:57:52

/*
Runtime: 252 ms, faster than 50.74% of JavaScript online submissions for LRU Cache.
Memory Usage: 59.2 MB, less than 36.90% of JavaScript online submissions for LRU Cache.
*/


var LRUCache = function(capacity) {
    this.cache = new Map();
    this.used = [];
    this.capacity = capacity;
};

/**
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    if (!this.cache.has(key)) {
        return -1
    }
    let index = this.used.indexOf(key);
    let removedKey = this.used[index];
    this.used.splice(index, 1);
    this.used.push(removedKey);
    return this.cache.get(key);
};

/**
 * @param {number} key
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    if (!this.cache.has(key)) {
        if (this.cache.size === this.capacity) {
            let removedKey = this.used.shift();
            this.cache.delete(removedKey);
        }
        this.used.push(key);
    } else {
        this.get(key);
    }
    this.cache.set(key, value);
};
