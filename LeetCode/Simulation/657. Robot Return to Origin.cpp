/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char& c : moves) {
            if (c == 'L') ++x;
            else if (c == 'R') --x;
            else if (c == 'U') ++y;
            else if (c == 'D') --y;
        }
        return x == 0 and y == 0;
    }
};
