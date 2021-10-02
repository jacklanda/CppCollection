class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        std::string s = std::to_string(n);
        int flag = s.size();  // 初始化为最后一位
        for (int i = s.size() - 1; i > 0; --i) {
            if (s[i - 1] > s[i]) {
                s[i - 1]--;
                // s[i] = '9';
                flag = i;  // 记录最后一次位置
            }
        }
        for (int i = flag; i < s.size(); ++i) {
            s[i] = '9';  // 从 flag 以后应当都是 '9'
        }
        return std::stoi(s);
    }
};
