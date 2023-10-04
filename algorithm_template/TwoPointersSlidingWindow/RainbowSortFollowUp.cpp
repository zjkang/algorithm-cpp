// Rainbow Sort 
// Follow up
// https://www.lintcode.com/problem/sort-colors-ii/description
// Given an array of n objects with k different colors (numbered from 1 to k), 
// sort them so that objects of the same color are adjacent, with the colors 
// in the order 1, 2, ... k.
// Example1
// Input: 
// [3,2,2,1,4] 
// 4
// Output: 
// [1,2,2,3,4]
// Example2
// Input: 
// [2,1,1,2,2] 
// 2
// Output: 
// [1,1,2,2,2]
// Challenge
// A rather straight forward solution is a two-pass algorithm using counting sort. 
// That will cost O(k) extra memory. Can you do it without using extra memory?
vector<int> sortColors(vector<int>& colors, int k) {
    if (k == 1) return colors;

}

void quickSort(vector<int>& colors, int start, int end, int colorFrom, int colorTo) {
    if (start >= end || colorFrom == colorTo) {
        return;
    }
    int mid = (colorFrom + colorTo) / 2;
    int left = start, right = end;
    while (left <= right) {
        // note: cannot use mid-1 since[1,2] always prefer to select 1, mid-1
        // will select [1,2] on right side.
        while (left <= right && colors[left] <= mid) {
            left++;
        }
        while (left <= right && colors[right] > mid) {
            right--;
        }
        if (left <= right) {
            swap(colors[left], colors[right]);
            left++;
            right--;
        }
    }
    quickSort(colors, start, right, colorFrom, mid);
    quickSort(colors, left, end, mid + 1, colorTo);
}





































