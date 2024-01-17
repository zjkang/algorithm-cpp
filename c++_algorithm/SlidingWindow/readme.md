### Sliding Window

滑动窗口可以分为固定大小和动态大小2中。动态滑动窗口模板一定有2种写法:固定起点或者固定终点。为了记忆，我采用了固定终点的写法

固定终点写法: 如果定义window，收缩window的条件，移动窗口的时机是难点


```cpp
/* 滑动窗口算法框架 */
void slidingWindow(string s, string t)
{
    unordered_map<char, int> need, window;
    for (char c : t)
        need[c]++;
    int fast = 0, slow = 0;
    int valid = 0;
    while (fast < s.size()) {
        // c 是将移入窗口的字符
        char c = s[fast];

        // 进行窗口内数据的一系列更新
        ...
        /*** debug 输出的位置 ***/
        printf("window: [%d, %d)\n", slow, fast);
        /********************/
        // 判断左侧窗口是否要收缩
        while (window needs shrink) {
            // d 是将移出窗口的字符
            char d = s[slow];
            // 左移窗口
            slow++;
            // 进行窗口内数据的一系列更新
            ...
        }
        // 右移窗口
        fast++;
    }
}
```

一个更紧凑更好理解的模板

```cpp
int slow = 0, fast = 0;
int ans = 0;
while (fast < n) {
    // ... 1. CODE: use A[fast] to update state which might make the window invalid
    while (invalid(slow ... fast)) { // when invalid, keep shrinking the left edge until it's valid again
        // CODE: update state using A[slow]
        slow++;
    }
    ans = max(ans, fast - slow + 1); // the window [slow, fast] is the maximum window we've found thus far
    fast++;
}
return ans;
```


Reference:
- https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/hua-dong-chuang-kou-ji-qiao-jin-jie
- https://leetcode.com/list/?selectedList=5qymxb97