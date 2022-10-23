class LRUCache {
private:
    int capacity;  // capacity of list
    std::list<std::pair<int, int>> items;  // a list of (key, value) pairs
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;  // Map items to iterators (pointers) to list nodes

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        // if key is not found in hash map, return -1
        if (cache.find(key) == cache.end()) return -1;
        // move the (key, value) pair to the beginning of the list
        items.splice(items.begin(), items, cache[key]);
        return cache[key]->second;
    }

    void put(int key, int value) {
        // the key is not in the hash table
        if (cache.find(key) == cache.end()) {
            // if the cache is full then delete the least recently
            // used item, which is at the end of the list
            if (items.size() == capacity) {
                cache.erase(items.back().first);
                items.pop_back();
            }
            items.push_front(std::make_pair(key, value));
            cache[key] = items.begin();
        } else {
            // update the value associated with the key
            cache[key]->second = value;
            // move the (key, value) pair to the beginning of the list
            items.splice(items.begin(), items, cache[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
