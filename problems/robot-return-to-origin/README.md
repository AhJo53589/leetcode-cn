# `（简单）` [657.robot-return-to-origin 机器人能否返回原点](https://leetcode-cn.com/problems/robot-return-to-origin/)

### 题目描述
<p>在二维平面上，有一个机器人从原点 (0, 0) 开始。给出它的移动顺序，判断这个机器人在完成移动后是否在<strong>&nbsp;(0, 0) 处结束</strong>。</p>

<p>移动顺序由字符串表示。字符 move[i] 表示其第 i 次移动。机器人的有效动作有&nbsp;<code>R</code>（右），<code>L</code>（左），<code>U</code>（上）和 <code>D</code>（下）。如果机器人在完成所有动作后返回原点，则返回 true。否则，返回 false。</p>

<p><strong>注意：</strong>机器人“面朝”的方向无关紧要。 “R” 将始终使机器人向右移动一次，“L” 将始终向左移动等。此外，假设每次移动机器人的移动幅度相同。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> "UD"
<strong>输出:</strong> true
<strong>解释：</strong>机器人向上移动一次，然后向下移动一次。所有动作都具有相同的幅度，因此它最终回到它开始的原点。因此，我们返回 true。</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> "LL"
<strong>输出:</strong> false
<strong>解释：</strong>机器人向左移动两次。它最终位于原点的左侧，距原点有两次 “移动” 的距离。我们返回 false，因为它在移动结束时没有返回原点。</pre>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> cnt(4, 0);
        unordered_map<char, int> u;
        u['U'] = 0;
        u['D'] = 1;
        u['L'] = 2;
        u['R'] = 3;
        for (auto c : moves) {
            cnt[u[c]]++;
        }
        return cnt[0] == cnt[1] && cnt[2] == cnt[3];
    }
};
```




