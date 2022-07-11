/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

/* time complexity: O(log(n)) */
/* space complexity: O(1) */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            int result = guess(mid);
            if (result == 0)
                return mid;
            else if (result == 1)
                left = mid + 1;
            else if (result == -1)
                right = mid - 1;
        }

        return -1;
    }
};
