class Solution {
public:
    string minNumber(vector<int>& nums) {
        std::vector<std::string> vec;
        vec.reserve(nums.size());
        /* 先将nums数组中的每个int元素转换为string. */
        for (int i = 0; i < nums.size(); ++i) {
            vec.emplace_back(std::to_string(nums[i]));
        }
        /* 对数组进行自定义排序(有时间最好手写快排) */
        std::sort(vec.begin(), vec.end(),
                  [](auto& x, auto& y) { return x + y < y + x; });
        /* 根据排好序的数组构建结果字符串 */
        std::string result;
        for (auto s : vec) result.append(s);
        return result;
    }
};
