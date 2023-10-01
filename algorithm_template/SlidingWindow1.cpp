// Sliding Window 1

// Reference:
// https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/hua-dong-chuang-kou-ji-qiao-jin-jie
// 固定终点写法: 如果定义window，收缩window的条件，移动窗口的时机是难点

// left/right, slow/fast 2 pointers

// https://github.com/zjkang/ds_algorithm/blob/main/python/array_string/Template_Sliding_Window.py
/* 滑动窗口算法框架 */
void slidingWindow(string s, string t)
{
    unordered_map<char, int> need, window;
    for (char c : t)
        need[c]++;
    int left = 0, right = 0;
    int valid = 0;
    while (right < s.size()) {
        // c 是将移入窗口的字符
        char c = s[right];

        // 进行窗口内数据的一系列更新
        ...
            /*** debug 输出的位置 ***/
            printf("window: [%d, %d)\n", left, right);
        /********************/
        // 判断左侧窗口是否要收缩
        while (window needs shrink) {
            // d 是将移出窗口的字符
            char d = s[left];
            // 左移窗口
            left++;
            // 进行窗口内数据的一系列更新
            ...
        }
        // 右移窗口
        right++;
    }
}


// 一个更紧凑更好理解的模板
// https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C++-Maximum-Sliding-Window-Cheatsheet-Template
int slow = 0, fast = 0;
int ans = 0;
while (slow < fast) {
    // ... 1. CODE: use A[fast] to update state which might make the window invalid
    while (invalid(slow ... fast)) { // when invalid, keep shrinking the left edge until it's valid again
        // CODE: update state using A[slow]
        slow++;
    }
    ans = max(ans, fast - slow + 1); // the window [slow, fast] is the maximum window we've found thus far
    fast++;
}
return ans;



// ---------------------------------------------------------------------------
// Q1 Max Consecutive Ones III
// https://leetcode.com/problems/max-consecutive-ones-iii/
// 对于每一个终点，计算以它为终点的1s最长有多长with k flips


// Q2 Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/


// Q3 Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/

// Other Sliding Windows
// https://leetcode.com/list/?selectedList=5qymxb97



// ---------------------------------------------------------------------------
// Sliding window with other data strucuture
// Q1 Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/
// Mono stack in desc


// Q2 Sliding Window Median
// https://leetcode.com/problems/sliding-window-median/
// Set or Map (Multi-Set)


// Q3 Max Water Trapped
// https://leetcode.com/problems/trapping-rain-water/
// // Two pointers with maintaining max left and right value




