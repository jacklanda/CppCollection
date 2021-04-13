class LRUCache {
private:
    int _m_capacity;
    list<pair<int, int>> _m_list;
    unordered_map<int, list<pair<int, int>>::iterator> _m_hash_map;

public:
    LRUCache(int capacity) : _m_capacity(capacity) {}

    int get(int key) {
        // 若查找未果，则返回-1
        if (_m_hash_map.find(key) == _m_hash_map.end())
            return -1;
        else {
            int value = _m_hash_map[key]->second;
            /* 以下三行分别是：1. 删除key对应的
             * 在链表中的原节点；2. 在链表头部插入
             * 刚被删除的<key, value>节点；3. 建立
             * 哈希表对key链表节点的映射 */
            _m_list.erase(_m_hash_map[key]);
            _m_list.push_front(make_pair(key, value));
            _m_hash_map[key] = _m_list.begin();
            return value;
        }
    }

    void put(int key, int value) {
        if (_m_hash_map.find() != _m_hash_map.end())
            _m_list.erase(_m_hash_map[key]);
        else if (_m_list.size() >= _m_capacity) {
            _m_hash_map.erase(_m_list.back().first);
            _m_list.pop_back();
        }
        _m_list.push_front(make_pair(key, value));
        _m_hash_map[key] = _m_list.begin();
    }
}
