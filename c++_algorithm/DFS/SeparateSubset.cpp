// https://leetcode.com/problems/partition-equal-subset-sum/

// Separate subset

// Native DFS (timeout error)
// Python
def dfs(self, nums, index, cur_sum, total_sum):
    if index == len(nums):
        if cur_sum == total_sum - cur_sum: return True
        return False
    if self.dfs(nums, index + 1, cur_sum + nums[index], total_sum):
        return True
    if self.dfs(nums, index + 1, cur_sum, total_sum):
        return True
    return False


// Consider dp (backpack)
// constrain: all elements are positive integers within a specific range
// Python (4274ms)
def canPartition(self, nums: List[int]) -> bool:
    # dp[i][j]: able to use the first i elements to sum up to j
    # dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]
    total_sum = sum(nums)
    if total_sum % 2 != 0: return False
    half_sum = total_sum // 2
    m = len(nums)
    dp = [[False] * (total_sum + 1) for _ in range(m + 1)]
    dp[0][0] = True
    for i in range(1, m + 1):
        for j in range(1, total_sum + 1):
            dp[i][j] = dp[i-1][j]
            if not dp[i][j] and j - nums[i-1] >= 0:
                dp[i][j] = dp[i-1][j-nums[i-1]]
            if dp[i][half_sum]: return True
    return False


// 1-d dp
// [1,5, 10, 5]
// init: {0}
// process: {0,1} -> {0,1,5,6} -> {0,1,5,6,10,11,15,16} -> {...}
// Python (902ms)
def canPartition(self, nums: List[int]) -> bool:
    # dp[i][j]: able to use the first i elements to sum up to j
    # dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]
    total_sum = sum(nums)
    if total_sum % 2 != 0: return False
    half_sum = total_sum // 2
    dp = [False] * (total_sum + 1)
    dp[0] = True
    for num in nums:
        for i in range(total_sum, -1, -1):
            if dp[i] and i + num <= total_sum: dp[i + num] = True
            if dp[half_sum]: return True
    return False


// note:
// it can be solved to obtain all combinations of sum for each subset, positive numbers?
// if the numbers are in specific range.
