// Find k closest element to target for unsorted array
int quickSelect(vector<int>& nums, int target, int k) {
    return quickSelect(nums, 0, nums.size() - 1, target, k);
}

int quickSelect(vector<int>& nums, int start, int end, int target, int k) {
    if (start > end) return -1;
    int left = start, right = end - 1;
    int pivotIndex = end;
    // [start, left) (exclude left): all (elements-target) < (pivot - target)
    // (right, end] (exclude right): all (elements-target) >= (pivot - target)
    while (left <= right) {
        if (nums[left] - target < nums[pivotIndex] - target) {
            left++;
        } else {
            swap(nums[left], nums[right]);
            right--;
        }
        // ..., right, left, ...
        swap(nums[left], nums[pivotIndex]);
        pivotIndex = left;
        if (pivotIndex == k-1) {
            return nums[pivotIndex];
        }
        if (pivotIndex < k - 1) {
            return quickSelect(nums, pivotIndex + 1, end, target, k);
        } else {
            return quickSelect(nums, start, pivotIndex - 1, target, k);
        }
    }
}