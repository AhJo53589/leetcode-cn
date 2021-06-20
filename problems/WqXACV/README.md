# `（简单）` [1000080.WqXACV 完成一半题目](https://leetcode-cn.com/problems/WqXACV/)

[contest](https://leetcode-cn.com/contest/lc-vscode/problems/WqXACV/)

### 题目描述
<div class="question-content default-content"><p>有 <code>N</code> 位扣友参加了微软与力扣举办了「以扣会友」线下活动。主办方提供了 <code>2*N</code> 道题目，整型数组 <code>questions</code> 中每个数字对应了每道题目所涉及的知识点类型。<br>
若每位扣友选择不同的一题，请返回被选的 <code>N</code> 道题目至少包含多少种知识点类型。</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>questions = [2,1,6,2]</code></p>
<p>输出：<code>1</code></p>
<p>解释：有 2 位扣友在 4 道题目中选择 2 题。<br>
可选择完成知识点类型为 2 的题目时，此时仅一种知识点类型<br>
因此至少包含 1 种知识点类型。</p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>questions = [1,5,1,3,4,5,2,5,3,3,8,6]</code></p>
<p>输出：<code>2</code></p>
<p>解释：有 6 位扣友在 12 道题目中选择题目，需要选择 6 题。<br>
选择完成知识点类型为 3、5 的题目，因此至少包含 2 种知识点类型。</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>questions.length == 2*n</code></li>
<li><code>2 &lt;= questions.length &lt;= 10^5</code></li>
<li><code>1 &lt;= questions[i] &lt;= 1000</code></li>
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
    int halfQuestions(vector<int>& questions) {
        unordered_map<int, int> cnt;
        for (auto q : questions) {
            cnt[q]++;
        }

        vector<int> xx;
        for (auto [n, c] : cnt) {
            xx.push_back(c);
        }
        sort(xx.rbegin(), xx.rend());

        int n = questions.size() / 2;
        for (int i = 0; i < xx.size(); i++) {
            n -= xx[i];
            if (n <= 0) return i + 1;
        }
        return -1;
    }
};
```




