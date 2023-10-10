// Q1 Heapify
// Given an integer array, heapify it into a min-heap array.
// For a heap array A, A[0] is the root of heap, and for each A[i], A[i * 2 + 1] is the left child of A[i] and A[i * 2 + 2] is the right child of A[i].

// Example
// Example 1
// Input : [3,2,1,4,5]
// Output : [1,2,3,4,5]
// Explanation : return any one of the legitimate heap arrays

// Challenge
// O(n) time complexity


// Heapify 的具体实现方法。时间复杂度为 O(n)O(n)，使用的是 siftdown
// 之所以是 O(n) 是因为从第 N/2 个位置开始往下 siftdown，那么就有大约 N/4 个数在 siftdown 中最多交换 1 次，N/8 个数最多交换 2 次，N/16 个数最多交换 3 次。
// 所以 O(N/4 * 1 + N/8 * 2 + N/16 * 3 + ... + 1 * LogN) = O(N)O(N/4∗1+N/8∗2+N/16∗3+...+1∗LogN)=O(N)
class Solution {
    void heapify(vector<int> A) {
        for (int i = A.size() / 2, i >= 0; i--) {
            siftdown(A, i);
        }
    }

    void siftdown(vector<int>& A, int index) {
        int N = A.size();
        while (index < N) {
            int left = index * 2 + 1;
            int right = index * 2 + 2;
            int minIndex = index;
            if (left < N && A[left] < A[minIndex]) {
                minIndex = left;
            }
            if (right < N && A[right] < A[minIndex]) {
                minIndex = right;
            }
            if (minIndex == index) {
                break;
            }
            swap(A[minIndex], A[index]);
            index = minIndex;
        }
    }
};