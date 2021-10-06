/* 插入时间复杂度: O(1) */
/* 删除时间复杂度: O(1) */
/* 随机访问时间复杂度: O(1) */
/* 空间复杂度: O(n) */

class RandomizedCollection {
public:
    std::unordered_map<int, unordered_set<int>> m;
    std::vector<int> vec;

    /** Initialize your data structure here. */
    RandomizedCollection() {}

    /** Inserts a value to the collection. Returns true if the collection did
     * not already contain the specified element. */
    bool insert(int val) {
        vec.push_back(val);
        m[val].emplace(vec.size() - 1);
        return m[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection
     * contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) {
            return false;
        }
        int n = *(m[val].begin());
        vec[n] = vec.back();
        m[val].erase(n);
        m[vec[n]].erase(vec.size() - 1);
        if (n < vec.size() - 1) {
            m[vec[n]].emplace(n);
        }
        if (m[val].size() == 0) {
            m.erase(val);
        }
        vec.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() { return vec[std::rand() % vec.size()]; }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
