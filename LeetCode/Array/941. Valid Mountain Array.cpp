/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int pos = 0;
        // go while there's a hill up, untill we reach peak:
        while (pos < arr.size() - 1 and arr[pos] < arr[pos + 1])
            ++pos;
        
        // peak can not be the first or last:
        if (pos == 0 or pos == arr.size() - 1)
            return false;
        
        // walk downhill:
        while (pos < arr.size() - 1 and arr[pos] > arr[pos + 1])
            ++pos;
        
        return pos == arr.size() - 1;
    }
};
