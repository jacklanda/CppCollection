/* 插入时间复杂度: O(1) */
/* 删除时间复杂度: O(1) */
/* 随机访问时间复杂度: O(1) */
/* 空间复杂度: O(n) */

class RandomizedSet {
public:
    RandomizedSet() {}

    bool insert(int val) {
        if (auto it = m.find(val); it != m.end()) return false;
        vec.emplace_back(val);
        m.emplace(val, vec.size() - 1);
        return true;
    }

    bool remove(int val) {
        if (auto it = m.find(val); it == m.end()) return false;
        vec[m[val]] = vec.back();
        m[vec.back()] = m[val];
        vec.pop_back();
        m.erase(val);
        return true;
    }

    int getRandom() { return vec[std::rand() % vec.size()]; }

private:
    std::unordered_map<int, int> m;
    std::vector<int> vec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
