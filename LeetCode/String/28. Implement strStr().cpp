/* use stblib */
class Solution {
public:
    int strStr(string haystack, string needle) { return haystack.find(needle); }
};

/* Sliding window */
class Solution {
public:
    int strStr(string haystack, string needle) {
        // head ptr points to the beginning of haystack, and the tail ptr  points to the end of needle.
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

/* KMP */
/* time complexity: O(m+n) */
/* space complexity: O(n) */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        
        int next[needle.size()];
        get_next(next, needle);
        
        for (int i = 0, j = 0; i < haystack.size(); ++i) {
            while (j > 0 and haystack[i] != needle[j])
                j = next[j - 1];
            if (haystack[i] == needle[j])
                ++j;
            if (j == needle.size())
                return i - needle.size() + 1;
        }
        
        return -1;
    }
private:
    void get_next(int* next, const string& s) {
        next[0] = 0;
        for (int i = 1, j = 0; i < s.size(); ++i) {
            while (j > 0 and s[i] != s[j])
                j = next[j - 1];
            if (s[i] == s[j])
                ++j;
            next[i] = j;
        }
    }
};
