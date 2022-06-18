/* Brutal Force */

class Solution {
public:
    string getPermutation(int n, int k) {
        std::vector<int> nums;
        for (int i = 1; i <= n; ++i) nums.emplace_back(i);
        for (int i = k - 1; i > 0; --i) {
            std::next_permutation(nums.begin(), nums.end());
        }
        std::string res = "";
        for (const int& num : nums) res.push_back('0' + num);
        return res;
    }
};
