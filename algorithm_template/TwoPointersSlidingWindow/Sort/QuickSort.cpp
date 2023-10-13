// Quick Sort
// 本质使用 挡板法        
// laioffer的模板: quick select
// pivot的元素先放在最右边
// while left <= right
//     left (exclude left) 的左边包括所有比pivot小的元素
//     right (exclude right)的右边包括所有大于等于pivot的元素
// swap left, pivot index的值，重制pivot index
// 挡板可以扩张到k个挡板,k+1个区域
void quickSort(vector<int>& nums, int start, int end) {
    if (start >= end) return;
    int left = start;
    int right = end - 1;
    int pivotIndex = end;
    while (left <= right) {
        if (nums[left] < nums[pivotIndex]) {
            left++;
        } else {
            swap(nums[left], nums[right]);
            right--;
        }
    }
    // ..., right, left, ...
    swap(nums[left], nums[pivotIndex]);
    quickSort(nums, start, right);
    quickSort(nums, left + 1, end);
}