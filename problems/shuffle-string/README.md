# `（简单）` [1528.shuffle-string 重新排列字符串](https://leetcode-cn.com/problems/shuffle-string/)

[contest](https://leetcode-cn.com/contest/weekly-contest-199/problems/shuffle-string/)

### 题目描述
<p>给你一个字符串 <code>s</code> 和一个 <strong>长度相同</strong> 的整数数组 <code>indices</code> 。</p>

<p>请你重新排列字符串 <code>s</code> ，其中第 <code>i</code> 个字符需要移动到 <code>indices[i]</code> 指示的位置。</p>

<p>返回重新排列后的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/07/26/q1.jpg" style="height: 243px; width: 321px;"></p>

<pre><strong>输入：</strong>s = "codeleet", <code>indices</code> = [4,5,6,7,0,2,1,3]
<strong>输出：</strong>"leetcode"
<strong>解释：</strong>如图所示，"codeleet" 重新排列后变为 "leetcode" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abc", <code>indices</code> = [0,1,2]
<strong>输出：</strong>"abc"
<strong>解释：</strong>重新排列后，每个字符都还留在原来的位置上。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "aiohn", <code>indices</code> = [3,1,4,2,0]
<strong>输出：</strong>"nihao"
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = "aaiougrt", <code>indices</code> = [4,0,2,6,7,3,1,5]
<strong>输出：</strong>"arigatou"
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>s = "art", <code>indices</code> = [1,0,2]
<strong>输出：</strong>"rat"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>s.length == indices.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>s</code> 仅包含小写英文字母。</li>
	<li><code>0 &lt;= indices[i] &lt;&nbsp;n</code></li>
	<li><code>indices</code> 的所有的值都是唯一的（也就是说，<code>indices</code> 是整数 <code>0</code> 到 <code>n - 1</code> 形成的一组排列）。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
    string restoreString(string s, vector<int>& indices) {
        string ans(s.size(), '0');
        for (int i = 0; i < indices.size(); i++) {
            ans[indices[i]] = s[i];
        }
        return ans;
    }
```




