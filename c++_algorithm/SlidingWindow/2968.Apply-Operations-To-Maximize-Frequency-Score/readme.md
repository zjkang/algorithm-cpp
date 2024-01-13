### 2968.Apply-Operations-to-Maximize-Frequency-Score

这道题群主给了2个解法。也给了滑窗问题的2种思路，固定滑窗和动态滑窗。群主利用了固定起点的做法，而我更偏好固定终点的做法。题目中也使用了固定终点的做法。

#### 解法1：二分+固定滑窗
为了通过有限的操作得到更多相等的元素，我们必然会将这些操作集中在原本已经接近的元素上。所以我们将nums排序之后，必然是选取其中的一段subarray，将其变成同一个数。显然，由中位数的性质，想将一个数组中的所有元素变成同一个元素，那么变成他们的中位数median能够使得改动之和最小。

我们可以二分搜索最大的subarray长度len。对于选定的len，我们在nums上走一遍固定长度的滑窗。对于每一个滑窗范围[i:j]，根据median性质，我们将其变为nums[(i+j)/2]是最高效的做法。令中位数的index是m，那么我们就可以知道区间[i:j]所需要的改动就是两部分之和 `sum[m:j]-nums[m]*(j-m+1) + nums[m]*(m-i+1)-sum[i:m]`. 其中区间和可以用前缀和数组来实现。

如果存在一个滑窗使得其需要的改动小于等于k，那么说明len是可行的。我们可以再尝试更大的滑窗，否则尝试更小的滑窗。

#### 解法2：动态滑窗
上述的思想也可以用动态滑窗来实现。固定左边界i之后，我们可以右移右边界j，直至区间[i:j]所需要的改动大于k。此时j-i就是一个可行的区间长度。然后再移动一格左边界i，找到下一个合适的j。

此题类似`1838.Frequency-of-the-Most-Frequent-Element`


### Reference
https://www.youtube.com/watch?v=zASCMQD0iKk
https://github.com/wisdompeak/LeetCode/tree/master/Math/2968.Apply-Operations-to-Maximize-Frequency-Score
