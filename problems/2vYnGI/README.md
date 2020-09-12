# `（简单）` [LCP 18.2vYnGI 早餐组合](https://leetcode-cn.com/problems/2vYnGI/)

### 题目描述
<p>小扣在秋日市集选择了一家早餐摊位，一维整型数组 <code>staple</code> 中记录了每种主食的价格，一维整型数组 <code>drinks</code> 中记录了每种饮料的价格。小扣的计划选择一份主食和一款饮料，且花费不超过 <code>x</code> 元。请返回小扣共有多少种购买方案。</p>
<p>注意：答案需要以 <code>1e9 + 7 (1000000007)</code> 为底取模，如：计算初始结果为：<code>1000000008</code>，请返回 <code>1</code></p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>staple = [10,20,5], drinks = [5,5,2], x = 15</code></p>
<p>输出：<code>6</code></p>
<p>解释：小扣有 6 种购买方案，所选主食与所选饮料在数组中对应的下标分别是：<br>
第 1 种方案：staple[0] + drinks[0] = 10 + 5 = 15；<br>
第 2 种方案：staple[0] + drinks[1] = 10 + 5 = 15；<br>
第 3 种方案：staple[0] + drinks[2] = 10 + 2 = 12；<br>
第 4 种方案：staple[2] + drinks[0] = 5 + 5 = 10；<br>
第 5 种方案：staple[2] + drinks[1] = 5 + 5 = 10；<br>
第 6 种方案：staple[2] + drinks[2] = 5 + 2 = 7。</p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>staple = [2,1,1], drinks = [8,9,5,1], x = 9</code></p>
<p>输出：<code>8</code></p>
<p>解释：小扣有 8 种购买方案，所选主食与所选饮料在数组中对应的下标分别是：<br>
第 1 种方案：staple[0] + drinks[2] = 2 + 5 = 7；<br>
第 2 种方案：staple[0] + drinks[3] = 2 + 1 = 3；<br>
第 3 种方案：staple[1] + drinks[0] = 1 + 8 = 9；<br>
第 4 种方案：staple[1] + drinks[2] = 1 + 5 = 6；<br>
第 5 种方案：staple[1] + drinks[3] = 1 + 1 = 2；<br>
第 6 种方案：staple[2] + drinks[0] = 1 + 8 = 9；<br>
第 7 种方案：staple[2] + drinks[2] = 1 + 5 = 6；<br>
第 8 种方案：staple[2] + drinks[3] = 1 + 1 = 2；</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>1 &lt;= staple.length &lt;= 10^5</code></li>
<li><code>1 &lt;= drinks.length &lt;= 10^5</code></li>
<li><code>1 &lt;= staple[i],drinks[i] &lt;= 10^5</code></li>
<li><code>1 &lt;= x &lt;= 2*10^5</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/2vYnGI/solution/2vyngi-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        const int mod = 1e9 + 7;
        int ans = 0;
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        int j = drinks.size() - 1;
        for (int i = 0; i < staple.size(); i++) {
            while (j >= 0 && staple[i] + drinks[j] > x) j--;
            if (j == -1) break;
            ans += j + 1;
            ans %= mod;
        }
        return ans;
    }
};
```




