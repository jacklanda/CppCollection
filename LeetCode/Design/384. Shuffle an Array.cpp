class Solution {
public:
    Solution(vector<int>& nums) : origin(nums), copy(nums) {}
    
    vector<int> reset() {
        return origin;
    }
    
    vector<int> shuffle() {
        // std::random_shuffle(copy.begin(), copy.end()); // trick: use stl function
        for (int i = 0; i < copy.size(); ++i) {
            int pos = std::rand() % copy.size();
            std::swap(copy[i], copy[pos]);
        }
        return copy;
    }
private:
    std::vector<int>& origin;  // make a reference
    std::vector<int> copy;  // make a copy
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
