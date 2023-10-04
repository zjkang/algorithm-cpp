// Rainbow Sort w/ k Color: 挡板做法
// Example 1:
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
void sortColors(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    int i = 0;
    while (i <= right) {
        if (nums[i] == 0) {
            swap(nums[left++], nums[i]);
            i++;
        } else if (nums[i] == 2) {
            swap(nums[right--], nums[i]);
        } else {
            i++;
        }
    }
}
