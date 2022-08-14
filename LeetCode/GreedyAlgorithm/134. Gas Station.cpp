/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur_sum = 0, total_sum = 0, start_pos = 0;
        
        for (int i = 0; i < gas.size(); ++i) {
            cur_sum += gas[i] - cost[i];
            total_sum += gas[i] - cost[i];
            if (cur_sum < 0) {
                cur_sum = 0;
                start_pos = i + 1;
            }
        }
        
        return total_sum < 0 ? -1 : start_pos;
    }
};
