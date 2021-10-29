/* C++ 里没有split，可使用 istringstream 替代之 */
class Solution {
public:
    string reverseWords(string s) {
        string res;
        istringstream in(s);
        string word;
        stack<string> stk;

        while (in >> word) stk.emplace(word);
        while (!stk.empty()) {
            res = res + stk.top() + ' ';
            stk.pop();
        }
        res.pop_back();

        return res;
    }
};
