// Selection Sort
vector<int> selectSort(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        int minIndex = i;
        for (int j = i+1; j < nums.size(); j++) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }
        swap(nums[i], nums[minIndex]);
    }
    return nums;
}