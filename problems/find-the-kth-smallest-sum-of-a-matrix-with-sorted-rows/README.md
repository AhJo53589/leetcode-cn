# `（困难）` [5403.find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows 有序矩阵中的第 k 个最小数组和](https://leetcode-cn.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/)

[contest](https://leetcode-cn.com/contest/weekly-contest-187/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/)

### 题目描述
<p>给你一个 <code>m&nbsp;* n</code> 的矩阵 <code>mat</code>，以及一个整数 <code>k</code> ，矩阵中的每一行都以非递减的顺序排列。</p>

<p>你可以从每一行中选出 1 个元素形成一个数组。返回所有可能数组中的第 k 个 <strong>最小</strong> 数组和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>mat = [[1,3,11],[2,4,6]], k = 5
<strong>输出：</strong>7
<strong>解释：</strong>从每一行中选出一个元素，前 k 个和最小的数组分别是：
[1,2], [1,4], [3,2], [3,4], [1,6]。其中第 5 个的和是 7 。  </pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>mat = [[1,3,11],[2,4,6]], k = 9
<strong>输出：</strong>17
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
<strong>输出：</strong>9
<strong>解释：</strong>从每一行中选出一个元素，前 k 个和最小的数组分别是：
[1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]。其中第 7 个的和是 9 。 
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>mat = [[1,1,10],[2,2,9]], k = 7
<strong>输出：</strong>12
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat.length[i]</code></li>
	<li><code>1 <= m, n <= 40</code></li>
	<li><code>1 <= k <= min(200, n ^&nbsp;m)</code></li>
	<li><code>1 <= mat[i][j] <= 5000</code></li>
	<li><code>mat[i]</code> 是一个非递减数组</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/solution/find-the-kth-smallest-sum-of-a-matrix-by-ikaruga/)

### 答题
``` C++
class Solution2 {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> ans(mat[0]);
        for (int i = 1; i < mat.size(); ++i) {
            multiset<int> st;
            for (int x : ans) {
                for (int y : mat[i]) {
                    st.insert(x + y);
                }
            }
            ans.assign(st.begin(), st.end());
            ans.resize(min(k, (int)ans.size()));
        }
        return ans.back();
    }
};
```


### 其它
``` C++
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int l = 0;
        int r = 0;
        for (int i = 0; i < mat.size(); i++) {
            l += mat[i].front();
            r += mat[i].back();
        }

        int base = l;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int cnt = 1;
            dfs(mat, k, mid, 0, base, cnt);
            if (cnt < k) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return r;
    }

    void dfs(vector<vector<int>>& mat, int k, int maxSum, int idx, int sum, int& cnt) {
        if (idx == mat.size()) return;
        if (sum > maxSum || cnt > k) return;

        dfs(mat, k, maxSum, idx + 1, sum, cnt);

        for (int j = 1; j < mat[idx].size(); j++) {
            int temp = sum + mat[idx][j] - mat[idx][0];
            if (temp > maxSum) break;
            cnt++;
            dfs(mat, k, maxSum, idx + 1, temp, cnt);
        }
    }
};
```


