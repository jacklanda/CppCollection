/* time complexity: O(1) */
/* space complexity: O(n) */

class RandomizedSet {
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (val2idx.count(val)) return false;
        val2idx[val] = vals.size();
        vals.emplace_back(val);
        return true;
    }
    
    bool remove(int val) {
        // trick: swap the last item and the to-be-removed item,
        // update last item's record in hashtable, finally pop back 
        // and erase to-be-removed item.
        if (!val2idx.count(val)) return false;
        int old_idx = val2idx[val];
        vals[old_idx] = vals.back();
        val2idx[vals[old_idx]] = old_idx;
        
        vals.pop_back();
        val2idx.erase(val);
        return true;
    }
    
    int getRandom() {
        return vals[std::rand() % vals.size()];
    }
private:
    std::unordered_map<int, int> val2idx;
    std::vector<int> vals;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
