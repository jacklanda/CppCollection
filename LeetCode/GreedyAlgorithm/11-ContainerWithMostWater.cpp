/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, area = 0, max_area = INT_MIN;
        while (left < right) {
            area = std::min(height[left], height[right]) * (right - left);
            max_area = std::max(max_area, area);
            if (height[left] < height[right])
                ++left;
            else
                --right;
        }
        return max_area;
    }
};
