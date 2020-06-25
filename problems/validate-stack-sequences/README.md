# `（中等）` [946.validate-stack-sequences 验证栈序列](https://leetcode-cn.com/problems/validate-stack-sequences/)

### 题目描述
<p>给定&nbsp;<code>pushed</code>&nbsp;和&nbsp;<code>popped</code>&nbsp;两个序列，每个序列中的 <strong>值都不重复</strong>，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 <code>true</code>；否则，返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
<strong>输出：</strong>true
<strong>解释：</strong>我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
<strong>输出：</strong>false
<strong>解释：</strong>1 不能在 2 之前弹出。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>0 <= pushed.length == popped.length <= 1000</code></li>
	<li><code>0 <= pushed[i], popped[i] < 1000</code></li>
	<li><code>pushed</code>&nbsp;是&nbsp;<code>popped</code>&nbsp;的排列。</li>
</ol>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		if (popped.size() > pushed.size()) return false;

		stack<int> st;
		int i = 0; 
		int j = 0;
		while (i < pushed.size() && j < popped.size()) {
			while (pushed[i] != popped[j]) {
				st.push(pushed[i]);
				i++;
				if (i == pushed.size()) return false;
			}
			if (pushed[i] == popped[j]) {
				i++;
				j++;
				if (j == popped.size()) return true;
				while (!st.empty() && popped[j] == st.top()) {
					j++;
					st.pop();
				}
			}
		}
		return j == popped.size();
    }
};
```




