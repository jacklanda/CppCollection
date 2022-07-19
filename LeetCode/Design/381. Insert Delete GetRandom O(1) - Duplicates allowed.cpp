/* time complexity: O(1) */
/* space complexity: O(n) */

class RandomizedCollection {
public:
    RandomizedCollection() {}
    
    bool insert(int val) {
        bool is_present = val2vec.count(val) != 0;
        val2vec[val].emplace_back(vec.size());
        vec.emplace_back(std::make_pair(val, val2vec[val].size() - 1));
        return !is_present;
    }
    
    bool remove(int val) {
        if (val2vec.count(val)) {
            auto& last = vec.back();
            val2vec[last.first][last.second] = val2vec[val].back();
            vec[val2vec[val].back()] = last;
            val2vec[val].pop_back();
            if (val2vec[val].empty())
                val2vec.erase(val);
            vec.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return vec[std::rand() % vec.size()].first;
    }
private:
    std::unordered_map<int, std::vector<int>> val2vec;
    std::vector<std::pair<int, int>> vec;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
