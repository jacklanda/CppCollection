/* 调用库函数find */
class Solution {
public:
    int strStr(string haystack, string needle) { return haystack.find(needle); }
};

/* 调用库函数substr */
class Solution {
public:
    int strStr(string haystack, string needle) {
        int hsize = haystack.size(), nsize = needle.size(), cur = 0;
        if (!nsize)
            return 0;
        else if (!hsize && nsize)
            return -1;
        while (cur + nsize <= hsize) {
            if (haystack.substr(cur, nsize) == needle) return cur;
            ++cur;
        }
        return -1;
    }
};
