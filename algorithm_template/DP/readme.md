### DP 题目特点
1. 计数:
   多少种方式走到下角
   多少种方法选出k个数使得和是sum
2. 求最大最小值
    从左上角到右下角的最大数字和
    最长上升子序列长度
3. 求存在性
    取石子游戏，先手是否必胜
    能不能选出k个数使得和是sum

####  DP题目分类方式
- 坐标动态规划
- 序列动态规划
- 划分动态规划
- 区间动态规划
- 背包动态规划
- 双序列动态规划
- 位操作型动态规划: 使用值作状态

###### 固定套路
- 转移方程f[i],f[i][j]
- 打印结果pi[i] -> trace back


DP能适用的问题:能将大问题拆成几个小问题，且满足无后效性、最优子结构性质
无后效性: 过去不依赖将来，将来不影响过去


#### 序列型
- 定义dp[i][j]:表示第i-th轮的第j种状态 (j=1,2,...,K)
千方百计将dp[i][j]与前一轮的状态dp[i-1][j]产生关系(j=1,2,...,K)
最终的结果是dp[last][j]中的某种aggregation (sum, max, min ...)

  - 套路1: 某些题目给你一次“行使某种策略的权力”。联想到买卖股票系列的题，我们常会设计 的两个状态就是“行使了权力”和“没有行使权力”
分别对应的价值。

- 定义dp[i]:表示第i-th轮的状态，一般这个状态要求 和元素i直接有关。千方百计将dp[i]与之前的状态dp[i’]产生关系 (i=1,2,...,i-1) (比如sum, max, min) dp[i]肯定不能与大于 i的轮次有任何关系，否 则违反了DP 的无后效性。

- dp[i]: 可能的2种表述
  - dp[i]: the result from index 0 to i (first ith results)
  - dp[i]: the result from index i to the end

- 双序列型
  - dp[i][j]与dp[i-1][j], dp[i-1][j-1], dp[i][j-1]建立联系
  - dp[i][j]表示s1[0...i], s2[0...j]的关系


##### problems
longest ascending Subarray
largest subarray sum
longest consecutive 1s
longest consecutive 1 for 10 matrix
word break
Maximal Product When Cutting Rope
Jump Game
Jump Game VI (dp, priority_queue, deque)

longest increasing subsequence
largest subset of points with positive slope
russian doll envelopes

lc 198 house robber
lc 123 Best Time to Buy and Sell Stock III
lc 309 Best Time to Buy and Sell Stock with Cooldown
lc 376 Wiggle Subsequence
lc 276 Paint Fence
lc 1289 Minimum Falling Path Sum II
lc 487 Max Consecutive Ones II
lc 1186 Maximum Subarray Sum with One Deletion
lc 903 Valid Permutations for DI Sequence

lc 300 Longest Increasing Subsequence
lc 368 Largest Divisible Subset
lc 1105 Filling Bookcase Shelves
lc 983 Minimum Cost For Tickets

2D dp[i][j]
edit Distance
Largest Sum of Submatrix 2D - Prefix Sum


#### 区间型(中心开花)

- dp[i][j] = max/min(dp[i][k] +/- dp[k][j] + ?) for all possible k
- template: start from length 1
  ```
  for l in range(l, n+1):
    for i in range(n):
      l = i + l - 1
      for k in range(i, l+1):
        dp[i][j] = max(dp[i][k] + dp[k][j]) # calculation
  ```
- 博弈类型dp (两头凑) - 左右两侧向中间合并结果

##### problems
Cut Wood
[Stone Game]()
Can I Win I
Can I Win II






