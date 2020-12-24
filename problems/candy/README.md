# `（困难）` [135.candy 分发糖果](https://leetcode-cn.com/problems/candy/)

### 题目描述
<p>老师想给孩子们分发糖果，有 <em>N</em>&nbsp;个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。</p>

<p>你需要按照以下要求，帮助老师给这些孩子分发糖果：</p>

<ul>
	<li>每个孩子至少分配到 1 个糖果。</li>
	<li>相邻的孩子中，评分高的孩子必须获得更多的糖果。</li>
</ul>

<p>那么这样下来，老师至少需要准备多少颗糖果呢？</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> [1,0,2]
<strong>输出:</strong> 5
<strong>解释:</strong> 你可以分别给这三个孩子分发 2、1、2 颗糖果。
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> [1,2,2]
<strong>输出:</strong> 4
<strong>解释:</strong> 你可以分别给这三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/candy/solution/candy-by-ikaruga-trij/)

### 答题
``` C++
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> ans(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            ans[i] = (ratings[i] > ratings[i - 1]) ? max(ans[i], ans[i - 1] + 1) : ans[i];
        }
        for (int i = ratings.size() - 2; i >= 0; i--) {
            ans[i] = (ratings[i] > ratings[i + 1]) ? max(ans[i], ans[i + 1] + 1) : ans[i];
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
};
```




