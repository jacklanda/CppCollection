/* 不可取的暴力法 */
class MyHashSet {
public:
    int *vec;
    /** Initialize your data structure here. */
    MyHashSet() { vec = new int[2000000]; }

    void add(int key) { vec[key] = 1; }
    void remove(int key) { vec[key] = 0; }
    /** Returns true if this set contains the specified element */
    bool contains(int key) { return vec[key] == 1 ? true : false; }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

/* 开链法：
 * 将发生哈希碰撞的元素用
 * 链表串起来挂在数组中 */
class MyHashSet {
private:
    std::vector<std::list<int>> data;
    static const int base = 769;
    static int hash(int key) { return key % base; }

public:
    /** Initialize your data structure here. */
    MyHashSet() : data(base) {}

    void add(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if ((*it) == key) return;
        }
        data[h].push_back(key);
    }

    void remove(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if ((*it) == key) {
                data[h].erase(it);
                return;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if ((*it) == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
