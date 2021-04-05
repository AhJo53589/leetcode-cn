# `（简单）` [LCP_28.4xy4Wx 采购方案](https://leetcode-cn.com/problems/4xy4Wx/)

[contest](https://leetcode-cn.com/contest/season/2021-spring/problems/4xy4Wx/)

### 题目描述
<div class="css-1708ckn" style="padding: 0px; margin: 13px 0px;"><p>小力将 N 个零件的报价存于数组 <code>nums</code>。小力预算为 <code>target</code>，假定小力仅购买两个零件，要求购买零件的花费不超过预算，请问他有多少种采购方案。</p>
<p>注意：答案需要以 <code>1e9 + 7 (1000000007)</code> 为底取模，如：计算初始结果为：<code>1000000008</code>，请返回 <code>1</code></p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>nums = [2,5,3,5], target = 6</code></p>
<p>输出：<code>1</code></p>
<p>解释：预算内仅能购买 nums[0] 与 nums[2]。</p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>nums = [2,2,1,9], target = 10</code></p>
<p>输出：<code>4</code></p>
<p>解释：符合预算的采购方案如下：<br>
nums[0] + nums[1] = 4<br>
nums[0] + nums[2] = 3<br>
nums[1] + nums[2] = 3<br>
nums[2] + nums[3] = 10</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>2 &lt;= nums.length &lt;= 10^5</code></li>
<li><code>1 &lt;= nums[i], target &lt;= 10^5</code></li>
</ul>
</div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int purchasePlans(vector<int>& nums, int target) {
        const long long mod = 1e9 + 7;
        long long ans = 0;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= target) break;

            auto it = upper_bound(nums.begin() + i + 1, nums.end(), target - nums[i]);
            ans += (it - nums.begin()) - i - 1;
            ans %= mod;
        }
        return ans;
    }
};
```




