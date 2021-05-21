# `（中等）` [77.combinations 组合](https://leetcode-cn.com/problems/combinations/)

### 题目描述
<p>给定两个整数 <em>n</em> 和 <em>k</em>，返回 1 ... <em>n </em>中所有可能的 <em>k</em> 个数的组合。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong>&nbsp;n = 4, k = 2
<strong>输出:</strong>
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/combinations/solution/combinations-by-ikaruga-hfz4/)

### 答题
``` C++
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp(k);
        for (int x = 0; x < (1 << n); x++) {
            if (hammingWeight(x) != k) continue;
            int idx = 0;
            for (int i = 0; i < n && idx != temp.size(); i++) {
                if (x & (1 << i)) {
                    temp[idx++] = i + 1;
                }
            }
            ans.push_back({ temp.begin(), temp.begin() + k });
        }
        return ans;
    }

    int hammingWeight(uint32_t n) {
        int sum = 0;
        while (n != 0) {
            n &= (n - 1);
            sum++;
        }
        return sum;
    }
};
```




