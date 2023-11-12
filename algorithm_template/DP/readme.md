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

#### DP题目分类方式
- 坐标动态规划
- 序列动态规划
- 双序列动态规划
- 划分动态规划
- 区间动态规划
- 背包动态规划
- 位操作型动态规划: 使用值作状态

#### 固定套路
- DP能适用的问题:能将大问题拆成几个小问题，且满足无后效性、最优子结构性质
- 无后效性: 过去不依赖将来，将来不影响过去
- 转移方程f[i],f[i][j]
- 打印结果pi[i] -> trace back


### 序列型

#### DP套路(I): 第I类基本型(“时间序列”型)
- 定义dp[i][j]:表示第i-th轮的第j种状态 (j=1,2,...,K)
千方百计将dp[i][j]与前一轮的状态dp[i-1][j]产生关系(j=1,2,...,K)
最终的结果是dp[last][j]中的某种aggregation (sum, max, min ...)

  - 套路: 某些题目给你一次“行使某种策略的权力”。联想到买卖股票系列的题，
  我们常会设计的两个状态就是“行使了权力”和“没有行使权力”分别对应的价值。

##### problems
[LC 198. House Robber](https://leetcode.com/problems/house-robber/)
[LC 213. House Robber II](https://leetcode.com/problems/house-robber-ii/)
[LC 123. Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)
[LC 309. Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)
[LC 376. Wiggle Subsequence](https://leetcode.com/problems/wiggle-subsequence/)
[LC 276. Paint Fence](https://leetcode.com/problems/paint-fence/)
[LC 487. Max Consecutive Ones II](https://leetcode.com/problems/max-consecutive-ones-ii/)
[LC 1186. Maximum Subarray Sum with One Deletion](https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/)
[LC 1800. Maximum Ascending Subarray Sum](https://leetcode.com/problems/maximum-ascending-subarray-sum/)
[LC 53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)
[LC 485. Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/)
[LC 903. Valid Permutations for DI Sequence](https://leetcode.com/problems/valid-permutations-for-di-sequence/)
[LC 1289. Minimum Falling Path Sum II](https://leetcode.com/problems/minimum-falling-path-sum-ii/)


#### DP套路(II): 第II类基本型(“时间序列”加强版)

- 定义dp[i]:表示第i-th轮的状态，一般这个状态要求 和元素i直接有关。
  千方百计将dp[i]与之前的状态dp[i’]产生关系 (i=1,2,...,i-1) (比如sum, max, min)
  dp[i]肯定不能与大于 i的轮次有任何关系，否 则违反了DP 的无后效性。

- dp[i]: 可能的2种表述
  - dp[i]: the result from index 0 to i (first ith results)
  - dp[i]: the result from index i to the end

##### problems
[LC 300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)
[LC 354. Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes/)
[LC 139. Word Break](https://leetcode.com/problems/word-break/)
[LC 368. Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset/)
[LC 1105. Filling Bookcase Shelves](https://leetcode.com/problems/filling-bookcase-shelves/)
[LC 983. Minimum Cost For Tickets](https://leetcode.com/problems/minimum-cost-for-tickets/)
Maximal Product When Cutting Rope
Jump Game
Jump Game VI (dp, priority_queue, deque)
Largest Subset of Points with Positive Slope
Largest Sum of Submatrix 2D - Prefix Sum


#### DP套路(III): 双序列型

- 套路
  - dp[i][j]与dp[i-1][j], dp[i-1][j-1], dp[i][j-1]建立联系
  - dp[i][j]表示s1[0...i], s2[0...j]的关系
  - 最终的结果是dp[m][n]
  - 如何重构出DP计算的最优方案:根据状态转移的正过程“回溯”逆推

##### problems
[LC 1143: Longest Common Subsequences](https://leetcode.com/problems/longest-common-subsequence/)
[LC 1092: Shortest Common Supersequences](https://leetcode.com/problems/shortest-common-supersequence/)
[LC 72: Edit Distance](https://leetcode.com/problems/edit-distance/)
[LC 97: Interleaving String](https://leetcode.com/problems/interleaving-string/)
[LC 115. Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)
[LC 727. Minimum Window Subsequence](https://leetcode.com/problems/minimum-window-subsequence/)
[LC 583. Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings/)
[LC 712. Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/)
[LC 1035. Uncrossed Lines](https://leetcode.com/problems/uncrossed-lines/)
[LC 1216. Valid Palindrome III](https://leetcode.com/problems/valid-palindrome-iii/)
[LC 1312. Minimum Insertion Steps to Make a String Palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)


### 区间型DP

####  DP套路(IV):第I类区间型DP

- 给出一个序列，明确要求分割成K个连续区间，要你计算这些区间的某个最优性质
- 套路
  - 状态定义:dp[i][k]表示针对s[1:i]分成k个区间，此时能够得到的最优解
  - 搜寻最后一个区间的起始位置j，将dp[i][k]分割成dp[j-1][k-1]和s[j:i]两部分。k拆分城k-1区间和1个区间
  - 最终的结果是dp[N][K]
  - ```
  for (int i=1; i<=n; i++)
    for (int k=1; k<=min(i,K); k++)
      for (int j=i; j>=k; j--)
        dp[i][k] = dp[j-1][k-1] + s[i:j];
  ```

##### problems
[LC 1278. Palindrome Partitioning III](https://leetcode.com/problems/palindrome-partitioning-iii/)
[LC 813. Largest Sum of Averages](https://leetcode.com/problems/largest-sum-of-averages/)
[LC 410. Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/)
[LC 1335. Minimum Difficulty of a Job Schedule](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/)


####  DP套路(V):第II类区间型DP(中心开花)

- 只给出一个序列S(数组/字符串)，求一个针对这个序列的最优解
- 套路
  - 定义dp[i][j]:表示针对s[i:j]的子问题的求解
  - 大区间的dp[i][j]往小区间的dp[i’][j’]转移
    - dp[i][j] = max/min(dp[i][k] +/- dp[k][j] + ?) for all possible k
    - 第一层循环是区间大小;第二层循环是起始点
  - 最终的结果是dp[1][N]
  - template: start from length 1
  ```
  for (int len=1; len<=N; len++)
    for (int i=1; i+len-1<=N; i++)
      int j = i+len-1;
      for (int k=i; k<=j; k++)
        dp[i][j] = max(dp[i][k] + dp[k+1][j]) // calculation
  ```
  - 博弈类型dp (两头凑) - 左右两侧向中间合并结果

##### problems
[LC 516. Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/)
[***LC 312. Burst Balloons](https://leetcode.com/problems/burst-balloons/)
[LC 375. Guess Number Higher or Lower II](https://leetcode.com/problems/guess-number-higher-or-lower-ii/)
[LC 1246. Palindrome Removal](https://leetcode.com/problems/palindrome-removal/)
[***LC 1000. Minimum Cost to Merge Stones]()
[LC 877. Stone Game](https://leetcode.com/problems/stone-game/)
[LC 546.Remove Boxes](https://leetcode.com/problems/remove-boxes/)


### DP套路(VI): 背包入门

- 题型抽象:给出N件物品，每个物品可用可不用(或者有若干个不同的用法)。
- 要求以某个有上限C的代价来实现最大收益。(有时候反过来，要求以某个有下限的收益来实现 最小代价)
- 套路
- 定义dp[i][c]:表示考虑只从前i件物品的子集里选择、代价为c的最大收益
- 千方百计将dp[i][c]往dp[i-1][c’]转移:即考虑如何使用物品i，对代价/收益的影响
  - 第一层循环是物品编号i
  - 第二层循环是遍历“代价”的所有可能值


#### 标准01背包
- 给一系列物品(价值为v，重量为w)，每个物品只能用一次。背包总容量上限是C。问最大能装多少价值的东西
- ```
  for (int i=1; i<=N; i++)
    for (int c=1; c<=C; c++) {
      dp[i][c] = max(dp[i-1][c], dp[i-1][c-wi] + vi );
  }
  ```

##### problems
[LC 494. Target Sum](https://leetcode.com/problems/target-sum/)
[LC 1049. Last Stone Weight II](https://leetcode.com/problems/last-stone-weight-ii/)
[LC 474.Ones and Zeroes](https://leetcode.com/problems/ones-and-zeroes/)
[LC 879. Profitable Schemes](https://leetcode.com/problems/profitable-schemes/)
[LC 956. Tallest Billboard](https://leetcode.com/problems/tallest-billboard/)
[LC 518.Coin Change 2](https://leetcode.com/problems/coin-change-ii/)


### 状态压缩

- 复杂的“状态”，DP经常会用到“状态压缩”
- “状态”代表一个01向量(不超过32位)
- [1,0,1,1,0,0,1] => b1011001 => 89
- 当前状态set -> 未来状态new_set
- ```
for (int i=1; i<=N; i++)
  for (int set=0; set<=(1<<m)-1; set++) {
    dp[i][set] = min(dp[i][set], dp[i-1][set]);
    int new_set = unionset (set, skills[i]);
    dp[i][new_set ] = min(dp[i][new_set], dp[i-1][set]+1);
  }

Ans = min{dp[N][set]}
for set = 0,1,...,(1<<m)-1 and set cover target_set```

##### problems
[LC 691. Stickers to Spell Word](https://leetcode.com/problems/stickers-to-spell-word/)
[LC 1125. Smallest Sufficient Team](https://leetcode.com/problems/smallest-sufficient-team/)
[LC 1349. Maximum Students Taking Exam](https://leetcode.com/problems/maximum-students-taking-exam/)
[LC 943. Find the Shortest Superstring](https://leetcode.com/problems/find-the-shortest-superstring/)


### 弃坑型

##### problems
[LC 887. Super Egg Drop](https://leetcode.com/problems/super-egg-drop/)
[LC 920. Number of Music Playlists](https://leetcode.com/problems/number-of-music-playlists/)





