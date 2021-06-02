# `（中等）` [1711.count-good-meals 大餐计数](https://leetcode-cn.com/problems/count-good-meals/)

[contest](https://leetcode-cn.com/contest/weekly-contest-222/problems/count-good-meals/)

### 题目描述
<div class="notranslate"><p><strong>大餐</strong> 是指 <strong>恰好包含两道不同餐品</strong> 的一餐，其美味程度之和等于 2 的幂。</p>

<p>你可以搭配 <strong>任意</strong> 两道餐品做一顿大餐。</p>

<p>给你一个整数数组 <code>deliciousness</code> ，其中 <code>deliciousness[i]</code> 是第 <code>i<sup>​​​​​​</sup>​​​​</code>​​​​ 道餐品的美味程度，返回你可以用数组中的餐品做出的不同 <strong>大餐</strong> 的数量。结果需要对 <code>10<sup>9</sup> + 7</code> 取余。</p>

<p>注意，只要餐品下标不同，就可以认为是不同的餐品，即便它们的美味程度相同。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>deliciousness = [1,3,5,7,9]
<strong>输出：</strong>4
<strong>解释：</strong>大餐的美味程度组合为 (1,3) 、(1,7) 、(3,5) 和 (7,9) 。
它们各自的美味程度之和分别为 4 、8 、8 和 16 ，都是 2 的幂。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>deliciousness = [1,1,1,3,3,3,7]
<strong>输出：</strong>15
<strong>解释：</strong>大餐的美味程度组合为 3 种 (1,1) ，9 种 (1,3) ，和 3 种 (1,7) 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= deliciousness.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= deliciousness[i] &lt;= 2<sup>20</sup></code></li>
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
    int countPairs(vector<int>& deliciousness) {
        const int mod = 1e9 + 7;
        int ans = 0;

        map<int, int> cnt;
        for (auto d : deliciousness) {
            cnt[d]++;
        }

        for (const auto& [k, v] : cnt) {
            for (int x = 1; x <= (1 << 21); x *= 2) {
                int nk = x - k;
                if (nk < k) continue;
                if (cnt.find(nk) == cnt.end()) continue;
                if (nk == k) {
                    ans += 1LL * v * (v - 1) / 2 % mod;
                }
                else {
                    ans += 1LL * cnt[nk] * cnt[k] % mod;
                }
                ans %= mod;
            }
        }

        return ans;
    }
};
```




