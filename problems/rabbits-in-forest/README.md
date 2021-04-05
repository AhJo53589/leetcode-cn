# `（中等）` [781.rabbits-in-forest 森林中的兔子](https://leetcode-cn.com/problems/rabbits-in-forest/)

### 题目描述
<div class="notranslate"><p>森林中，每个兔子都有颜色。其中一些兔子（可能是全部）告诉你还有多少其他的兔子和自己有相同的颜色。我们将这些回答放在&nbsp;<code>answers</code>&nbsp;数组里。</p>

<p>返回森林中兔子的最少数量。</p>

<pre><strong>示例:</strong>
<strong>输入:</strong> answers = [1, 1, 2]
<strong>输出:</strong> 5
<strong>解释:</strong>
两只回答了 "1" 的兔子可能有相同的颜色，设为红色。
之后回答了 "2" 的兔子不会是红色，否则他们的回答会相互矛盾。
设回答了 "2" 的兔子为蓝色。
此外，森林中还应有另外 2 只蓝色兔子的回答没有包含在数组中。
因此森林中兔子的最少数量是 5: 3 只回答的和 2 只没有回答的。

<strong>输入:</strong> answers = [10, 10, 10]
<strong>输出:</strong> 11

<strong>输入:</strong> answers = []
<strong>输出:</strong> 0
</pre>

<p><strong>说明:</strong></p>

<ol>
	<li><code>answers</code>&nbsp;的长度最大为<code>1000</code>。</li>
	<li><code>answers[i]</code>&nbsp;是在&nbsp;<code>[0, 999]</code>&nbsp;范围内的整数。</li>
</ol>
</div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (auto n : answers) {
            ans += (n == 0);
            cnt[n]++;
        }
        cnt.erase(0);

        for (auto [k, v] : cnt) {
            ans += (v / (k + 1) + (v % (k + 1) != 0)) * (k + 1);
        }
        return ans;
    }
};
```




