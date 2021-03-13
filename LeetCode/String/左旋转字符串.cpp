class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int len = s.size();
        s += s;
        return s.substr(n, len);
    }
};
