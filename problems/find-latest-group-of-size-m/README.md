# `（中等）` [1562.find-latest-group-of-size-m 查找大小为 M 的最新分组](https://leetcode-cn.com/problems/find-latest-group-of-size-m/)

[contest](https://leetcode-cn.com/contest/weekly-contest-203/problems/find-latest-group-of-size-m/)

### 题目描述
<p>给你一个数组 <code>arr</code> ，该数组表示一个从 <code>1</code> 到 <code>n</code> 的数字排列。有一个长度为 <code>n</code> 的二进制字符串，该字符串上的所有位最初都设置为 <code>0</code> 。</p>
<p>在从 <code>1</code> 到 <code>n</code> 的每个步骤 <code>i</code> 中（假设二进制字符串和 <code>arr</code> 都是从 <code>1</code> 开始索引的情况下），二进制字符串上位于位置 <code>arr[i]</code> 的位将会设为 <code>1</code> 。</p>
<p>给你一个整数 <code>m</code> ，请你找出二进制字符串上存在长度为 <code>m</code> 的一组 <code>1</code> 的最后步骤。一组 <code>1</code> 是一个连续的、由 <code>1</code> 组成的子串，且左右两边不再有可以延伸的 <code>1</code> 。</p>
<p>返回存在长度 <strong>恰好</strong> 为 <code>m</code> 的 <strong>一组 <code>1</code>&nbsp;</strong> 的最后步骤。如果不存在这样的步骤，请返回 <code>-1</code> 。</p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<pre><strong>输入：</strong>arr = [3,5,1,2,4], m = 1
<strong>输出：</strong>4
<strong>解释：
</strong>步骤 1："00<strong>1</strong>00"，由 1 构成的组：["1"]
步骤 2："0010<strong>1</strong>"，由 1 构成的组：["1", "1"]
步骤 3："<strong>1</strong>0101"，由 1 构成的组：["1", "1", "1"]
步骤 4："1<strong>1</strong>101"，由 1 构成的组：["111", "1"]
步骤 5："111<strong>1</strong>1"，由 1 构成的组：["11111"]
存在长度为 1 的一组 1 的最后步骤是步骤 4 。</pre>

<p><strong>示例 2：</strong></p>
<pre><strong>输入：</strong>arr = [3,1,5,4,2], m = 2
<strong>输出：</strong>-1
<strong>解释：
</strong>步骤 1："00<strong>1</strong>00"，由 1 构成的组：["1"]
步骤 2："<strong>1</strong>0100"，由 1 构成的组：["1", "1"]
步骤 3："1010<strong>1</strong>"，由 1 构成的组：["1", "1", "1"]
步骤 4："101<strong>1</strong>1"，由 1 构成的组：["1", "111"]
步骤 5："1<strong>1</strong>111"，由 1 构成的组：["11111"]
不管是哪一步骤都无法形成长度为 2 的一组 1 。
</pre>

<p><strong>示例 3：</strong></p>
<pre><strong>输入：</strong>arr = [1], m = 1
<strong>输出：</strong>1
</pre>

<p><strong>示例 4：</strong></p>
<pre><strong>输入：</strong>arr = [2,1], m = 2
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li><code>n == arr.length</code></li>
	<li><code>1 <= n <= 10^5</code></li>
	<li><code>1 <= arr[i] <= n</code></li>
	<li><code>arr</code> 中的所有整数 <strong>互不相同</strong></li>
	<li><code>1 <= m&nbsp;<= arr.length</code></li>
</ul>

---
### 思路
```

```

[发布的题解](https://leetcode-cn.com/problems/find-latest-group-of-size-m/solution/find-latest-group-of-size-m-by-ikaruga/)

### 答题
``` C++
struct DSU {
    DSU(int n) : data(n, -1) {}

    bool unionSet(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;

        if (data[y] < data[x]) std::swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    bool same(int x, int y) { return root(x) == root(y); }

    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }

    int size(int x) { return -data[root(x)]; }

    std::vector<int> data;
};

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int ans = -1;
        DSU dsu(arr.size());
        vector<bool> vi(arr.size(), false);
        int lenM = 0;
        for (int j = 0; j < arr.size(); j++) {
            int i = arr[j] - 1;
            vi[i] = true;
            if (i != 0 && vi[i - 1]) {
                lenM -= (m == dsu.size(i - 1));
                dsu.unionSet(i - 1, i);
            }
            if (i != arr.size() - 1 && vi[i + 1]) {
                lenM -= (m == dsu.size(i + 1));
                dsu.unionSet(i + 1, i);
            }
            lenM += (m == dsu.size(i));
            ans = (lenM != 0) ? j + 1 : ans;
        }
        return ans;
    }
};
```




