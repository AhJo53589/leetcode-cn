# `（中等）` [1390.four-divisors 四因数](https://leetcode-cn.com/problems/four-divisors/)

[contest](https://leetcode-cn.com/contest/weekly-contest-181/problems/four-divisors/)

### 题目描述
<p>给你一个整数数组 <code>nums</code>，请你返回该数组中恰有四个因数的这些整数的各因数之和。</p>
<p>如果数组中不存在满足题意的整数，则返回 <code>0</code> 。</p>
<p>&nbsp;</p>
<p><strong>示例：</strong></p>
<pre><strong>输入：</strong>nums = [21,4,7]
<strong>输出：</strong>32
<strong>解释：</strong>
21 有 4 个因数：1, 3, 7, 21
4 有 3 个因数：1, 2, 4
7 有 2 个因数：1, 7
答案仅为 21 的所有因数的和。
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 10^4</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^5</code></li>
</ul>

​            

---
### 思路
```

```



### 答题
``` C++
bool flag = false;
unordered_map<int, unordered_set<int>> eleDict;
void init() {
    for (int i = 1; i <= 100000; i++) {
        for (int j = i; j <= 100000; j += i) {
            eleDict[j].insert(i);
        }
    }
}
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        if (flag == false) {
            init();
            flag = true;
        }
        int sum = 0;
        for (auto it = nums.cbegin(); it != nums.cend(); ++it) {
            const unordered_set<int>& eles = eleDict[*it];
            if (eles.size() == 4) {
                for (auto pit = eles.cbegin(); pit != eles.cend(); pit++) {
                    sum += *pit;
                }
            }
        }
        return sum;
    }
};
```




