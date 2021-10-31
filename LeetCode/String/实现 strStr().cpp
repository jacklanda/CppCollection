/* 调用库函数find */
class Solution {
public:
    int strStr(string haystack, string needle) { return haystack.find(needle); }
};

/* 滑动窗口 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        // 定义头指针指向haystack字符串头，尾指针指向needle字符串尾
        int hsize = haystack.size(), nsize = needle.size();
        int head = 0, tail = nsize - 1;
        while (tail < hsize) {
            if (haystack.substr(head, nsize) == needle) return head;
            ++head;
            ++tail;
        }
        return -1;
    }
};
