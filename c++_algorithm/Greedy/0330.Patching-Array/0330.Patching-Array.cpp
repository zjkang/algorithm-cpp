// https://leetcode.com/problems/patching-array/
// 330. Patching Array

// 参考了其他人的解释也就是如果
// sum[1,...i] >= j: 也就是可以cover j，总的sum可以进一步扩展

// 思路：
// 这是一道贪心算法的题目，自己开始也没有想到最优解法。这里将参考的网上解法说明如下：
// 我们从左往右遍历数组，并且维护一个到当前为止最大可以到达的值。如果当前数组的值比这个最大值大，
// 就说明我们无法合成这个值，需要补贴一个数，然后加上补贴的这个数更新为新的最大可能到达的值。
// 以题目中的测试用例 2（nums = [1, 5, 10], n = 20）为例来说明具体过程：
// 1）初始状态：能够 cover 的是小于 1 的数，因此第一个遇到 1，正好可以 cover 下一个数，不需要补贴，
// 这样我们可以更新最大可以 cover 的值为 1*2 = 2 以内的数（不包含 2）。
// 2）第二个数是 5，而我们现在能够 cover 的是小于 1 的数，因此需要补贴一个 2，此时更新 cover 的值为 2*2 = 4，
// 即我们可以 cover4 以内的数（不包含 4）；然后我们发现依然不能到达 5，所以需要在补贴一个 4，之后可以到达的数就是 8 之内的数了（不包含 8）；再看数组 5，因为 5 已经在可以 cover 的范围之内了，而多了 5 好之后，可以 cover 的最大值就变成了 8 + 5 = 13 之内的数了（不包含 13）；此时可以再遍历下一个数了。
// 3）下一个数组值为 10，依然在我们可以 cover 的范围之内，因此不需要补贴，
// 但是 cover 的值却可以更新到 13 + 10 = 23 > 20，因此就可以返回了。


class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long cover = 1;         // now we can make the sums smaller than cover
        int result = 0;         // the return value
        int index = 0;          // the current index
        while(cover <= n) {
            if(index >= nums.size() || nums[index] > cover) {   // we need to patch one number now
                ++result;
                cover = cover * 2;
            }
            else {                                              // we only need to update cover
                cover += nums[index];
                ++index;
            }
        }
        return result;
    }
};