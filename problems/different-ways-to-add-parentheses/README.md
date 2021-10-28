# `（中等）` [241.different-ways-to-add-parentheses 为运算表达式设计优先级](https://leetcode-cn.com/problems/different-ways-to-add-parentheses/)

### 题目描述
<p>给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 <code>+</code>,&nbsp;<code>-</code>&nbsp;以及&nbsp;<code>*</code>&nbsp;。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> <code>"2-1-1"</code>
<strong>输出:</strong> <code>[0, 2]</code>
<strong>解释: </strong>
((2-1)-1) = 0 
(2-(1-1)) = 2</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入: </strong><code>"2*3-4*5"</code>
<strong>输出:</strong> <code>[-34, -14, -10, -10, 10]</code>
<strong>解释: 
</strong>(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10</pre>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        for (int i = 0; i < expression.size(); i++) {
            auto c = expression[i];
            if (c != '+' && c != '-' && c != '*') continue;

            vector<int> left = diffWaysToCompute(expression.substr(0, i));
            vector<int> right = diffWaysToCompute(expression.substr(i + 1));
            for (auto& l : left) {
                for (auto& r : right) {
                    if (c == '+') {
                        ans.push_back(l + r);
                    }
                    else if (c == '-') {
                        ans.push_back(l - r);
                    }
                    else {
                        ans.push_back(l * r);
                    }
                }
            }
        }

        if (ans.empty()) {
            ans.push_back(stoi(expression));
        }
        return ans;
    }
};
```




