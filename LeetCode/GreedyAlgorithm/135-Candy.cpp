/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy_nums(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i - 1] < ratings[i]) candy_nums[i] = candy_nums[i - 1] + 1;
        }
        for (int i = ratings.size() - 1; i >= 1; --i) {
            if (ratings[i - 1] > ratings[i]) candy_nums[i - 1] = std::max(candy_nums[i - 1], candy_nums[i] + 1);
        }
        return std::accumulate(candy_nums.begin(), candy_nums.end(), 0);
    }
};
