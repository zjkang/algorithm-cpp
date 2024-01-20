### 单调栈模板


- 第一个更大的数，找到左侧或者右侧离它最近的一个比它大或者小的数字
- 表达式求值

```cpp
int ret = 0;
stack<int> stack;
while (i < N + 1) {
    while (!stack.empty() && heights[stack.top()] > val) {
        int idx = stack.top(); stack.pop();
        // calculate & update ret
        ...
    }
    stack.push(i);
    // update and move to next index
    i++;
}
```