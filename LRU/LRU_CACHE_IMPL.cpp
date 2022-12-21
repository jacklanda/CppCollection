/* LRU 数据结构及其基本操作的cpp实现：
 * 简而言之，LRU == DoublyLinkedlist + HashMap */

#include <iostream>
#include <unordered_map>

using namespace std;

/* 基于自定义双链表和
 * STL-unordered_map
 * 实现的LRU缓存淘汰算法 */

/* 双向链表的节点结构 */
struct LRUCacheNode {
    int key;
    int value;
    LRUCacheNode *prev;
    LRUCacheNode *next;
    LRUCacheNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
};

class LRUCache {
   private:
    // 使用基于HashMap实现的无序字典
    unordered_map<int, LRUCacheNode *> dict;
    // 指向双链表的头节点
    LRUCacheNode *head;
    // 指向双链表的尾节点
    LRUCacheNode *tail;
    // Cache容量
    int capacity;
    // 计数
    int count;

   public:
    // LRUCache构造函数
    LRUCache(int capacity);
    // LRUCache析构函数
    ~LRUCache();
    // 查询接口
    int get(int key);
    // 插入接口：缓存未满时插入，已满时替换
    void set(int key, int value);

   private:
    // 删除尾节点（最久未使用）
    void removeLRUNode();
    // 分离当前节点
    void detachNode(LRUCacheNode *node);
    // 插入节点到头部
    void insertToFront(LRUCacheNode *node);
};

LRUCache::LRUCache(int capacity) {
    this->capacity = capacity;
    this->count = 0;
    head = new LRUCacheNode;
    tail = new LRUCacheNode;
    head->prev = NULL;
    head->next = tail;
    tail->prev = head;
    tail->next = NULL;
}

LRUCache::~LRUCache() {
    delete head;
    delete tail;
}

int LRUCache::get(int key) {
    //如果在哈希表中没找到键
    if (dict.find(key) == dict.end())
        return -1;
    else {
        LRUCacheNode *node = dict[key];
        //找到键->命中，将该节点做分离操作并移至头部
        detachNode(node);
        insertToFront(node);
        return node->value;
    }
}

void LRUCache::set(int key, int value) {
    //如果在哈希表中没找到键
    if (dict.find(key) == dict.end()) {
        LRUCacheNode *node = new LRUCacheNode;
        //如果Cache已满
        if (count == capacity) removeLRUNode();
        node->key = key;
        node->value = value;
        dict[key] = node;     //插入哈希表
        insertToFront(node);  //插入链表头部
        count++;
    } else {
        LRUCacheNode *node = dict[key];
        detachNode(node);
        node->value = value;
        insertToFront(node);
    }
}

void LRUCache::removeLRUNode() {
    LRUCacheNode *node = tail->prev;
    detachNode(node);
    dict.erase(node->key);
    count--;
}

void LRUCache::detachNode(LRUCacheNode *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void LRUCache::insertToFront(LRUCacheNode *node) {
    node->next = head->next;
    node->prev = head;
    head->next = node;
    node->next->prev = node;
}
