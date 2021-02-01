/* 给定一个有序数组，
 * 通过二分搜索查找一个数，
 * 如果存在，则返回其索引，
 * 否则返回-1。
 * [left, right] 闭区间是
 * 每次进行搜索的区间。
 */
int binarySearch(int[] nums, int target) {
    int left = 0;
    int right = nums.length - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
    }
    return -1;
}
