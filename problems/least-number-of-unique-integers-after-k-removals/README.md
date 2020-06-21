# `（中等）` [1481.least-number-of-unique-integers-after-k-removals 不同整数的最少数目](https://leetcode-cn.com/problems/least-number-of-unique-integers-after-k-removals/)

[contest](https://leetcode-cn.com/contest/weekly-contest-193/problems/least-number-of-unique-integers-after-k-removals/)

### 题目描述
<p>给你一个整数数组 <code>arr</code> 和一个整数 <code>k</code> 。现需要从数组中恰好移除 <code>k</code> 个元素，请找出移除后数组中不同整数的最少数目。</p>

<ol>
</ol>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [5,5,4], k = 1
<strong>输出：</strong>1
<strong>解释：</strong>移除 1 个 4 ，数组中只剩下 5 一种整数。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [4,3,1,1,3,3,2], k = 3
<strong>输出：</strong>2
<strong>解释：</strong>先移除 4、2 ，然后再移除两个 1 中的任意 1 个或者三个 3 中的任意 1 个，最后剩下 1 和 3 两种整数。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= arr.length&nbsp;<= 10^5</code></li>
	<li><code>1 <= arr[i] <= 10^9</code></li>
	<li><code>0 <= k&nbsp;<= arr.length</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> cnt;
        for (auto n : arr) {
            cnt[n]++;
        }

        map<int, int> r_cnt;
        for (auto it = cnt.begin(); it != cnt.end(); it++) {
            r_cnt[it->second]++;
        }

        int ans = 0;
        for (auto it = r_cnt.begin(); it != r_cnt.end(); it++) {
            if (k != 0) {
                if (k < it->first) {
                    k = 0;
                }
                else {
                    int t = k / (it->first);
                    t = min(t, it->second);
                    it->second -= t;
                    k -= t * (it->first);
                }
            }
            if (it->second == 0) continue;

            ans += it->second;
        }
        return ans;
    }
};
```




