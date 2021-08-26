# `（中等）` [5851.find-unique-binary-string 找出不同的二进制字符串](https://leetcode-cn.com/problems/find-unique-binary-string/)

[contest](https://leetcode-cn.com/contest/weekly-contest-255/problems/find-unique-binary-string/)

### 题目描述
<div class="notranslate"><p>给你一个字符串数组 <code>nums</code> ，该数组由 <code>n</code> 个 <strong>互不相同</strong> 的二进制字符串组成，且每个字符串长度都是 <code>n</code> 。请你找出并返回一个长度为&nbsp;<code>n</code>&nbsp;且&nbsp;<strong>没有出现</strong> 在 <code>nums</code> 中的二进制字符串<em>。</em>如果存在多种答案，只需返回 <strong>任意一个</strong> 即可。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = ["01","10"]
<strong>输出：</strong>"11"
<strong>解释：</strong>"11" 没有出现在 nums 中。"00" 也是正确答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = ["00","01"]
<strong>输出：</strong>"11"
<strong>解释：</strong>"11" 没有出现在 nums 中。"10" 也是正确答案。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = ["111","011","001"]
<strong>输出：</strong>"101"
<strong>解释：</strong>"101" 没有出现在 nums 中。"000"、"010"、"100"、"110" 也是正确答案。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 16</code></li>
	<li><code>nums[i].length == n</code></li>
	<li><code>nums[i] </code>为 <code>'0'</code> 或 <code>'1'</code></li>
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
    string findDifferentBinaryString(vector<string>& nums) {
        set<int> x;
        for (int i = 0; i < nums.size(); i++) {
            x.insert(str2int(nums[i]));
        }

        auto it = x.begin();
        int n = nums[0].size();
        for (int i = 0; i < (1 << n); i++, it++) {
            if (it == x.end()) return int2str(i, n);
            if (*it != i) return int2str(i, n);
        }
        return "";
    }

    int str2int(string s) {
        int x = 0;
        for (auto c : s) {
            x *= 2;
            x += (c - '0');
        }
        return x;
    }

    string int2str(int x, int n) {
        string s(n, '0');
        for (int i = n - 1; ~i; i--) {
            s[i] = (x % 2 == 1) ? '1' : '0';
            x /= 2;
        }
        return s;
    }
};
```




