// Merge Sort: 谁小移谁
vector<int> mergeSort(vector<int>& A, int start, int end, vector<int>& temp) {
    if (start >= end) return;
    int mid = (start + end) / 2;
    mergeSort(A, start, mid, temp);
    mergeSort(A, mid + 1, end, temp);
    // merge result
    int i = start, j = mid + 1, k = start;
    while (i <= mid && j <= end) {
        if (A[i] <= A[j]) {
            temp[k] = A[i++];
        } else {
            temp[k] = A[j++];
        }
        k++;
    }
    while (i <= mid) {
        temp[k] = A[i++];
        k++;
    }
    while (j <= end) {
        temp[k] = A[j++];
        k++;
    }
    // copy back to original array
    while (start <= end) {
        A[start] = temp[start];
        start++;
    }
}
