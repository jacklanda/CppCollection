class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += (2*k)){
            if (i + k <= s.size()){
                reverse(s.begin() + i, s.begin() + i + k);
                continue;
            }
            reverse(s.begin() + i, s.begin() + s.size());
        }
        return s;
    }
};
