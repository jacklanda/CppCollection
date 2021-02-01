/* 递归式二分搜索 */
int BinarySearch(int arr[], int left, int right, int target) {
    int mid = (left + right) / 2;

    if (left > right) return -1;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return BinarySearch(arr, mid + 1, right, target);
    else if (arr[mid] > target)
        return BinarySearch(arr, left, right - 1, target);

    return -1;
}
