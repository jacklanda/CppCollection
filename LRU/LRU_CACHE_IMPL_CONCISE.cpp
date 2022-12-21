/* LRU 数据结构及其基本操作的cpp实现：
 * 简而言之，LRU == DoublyLinkedlist + HashMap */

/* 基于STL-list 以及
 * STL-unordered_map
 * 实现的LRU缓存淘汰算法 */

#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>

using namespace std;

class LRUCache {
   private:
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;

   public:
    void LRU(int cap_) { cap = cap_; }
    int get(int k) {
        auto it = m.find(k);
        if (it == m.end()) return -1;
        l.splice(l.begin(), l, it->second);
        return it->second->second;
    }
    void put(int k, int v) {
        auto it = m.find(k);
        if (it != m.end()) l.erase(it->second);
        l.push_front(make_pair(k, v));
        m[k] = l.begin();
        if (m.size() > cap) {
            int k = l.rbegin()->first;
            l.pop_back();
            m.erase(k);
        }
    }
};

int main() {
    LRUCache *lru_cache = new LRUCache;
    int result = lru_cache->get(44);
    cout << result << endl;
    lru_cache->put(44, 99999);
    result = lru_cache->get(44);
    cout << result << endl;

    return 0;
}
