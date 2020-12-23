# `（简单）` [1598.crawler-log-folder 文件夹操作日志搜集器](https://leetcode-cn.com/problems/crawler-log-folder/)

[contest](https://leetcode-cn.com/contest/weekly-contest-208/problems/crawler-log-folder/)

### 题目描述
<p>每当用户执行变更文件夹操作时，LeetCode 文件系统都会保存一条日志记录。</p>

<p>下面给出对变更操作的说明：</p>

<ul>
	<li><code>"../"</code> ：移动到当前文件夹的父文件夹。如果已经在主文件夹下，则 <strong>继续停留在当前文件夹</strong> 。</li>
	<li><code>"./"</code> ：继续停留在当前文件夹<strong>。</strong></li>
	<li><code>"x/"</code> ：移动到名为 <code>x</code> 的子文件夹中。题目数据 <strong>保证总是存在文件夹 <code>x</code></strong> 。</li>
</ul>

<p>给你一个字符串列表 <code>logs</code> ，其中 <code>logs[i]</code> 是用户在 <code>i<sup>th</sup></code> 步执行的操作。</p>

<p>文件系统启动时位于主文件夹，然后执行 <code>logs</code> 中的操作。</p>

<p>执行完所有变更文件夹操作后，请你找出 <strong>返回主文件夹所需的最小步数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="height: 151px; width: 775px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/09/26/sample_11_1957.png" alt=""></p>

<pre><strong>输入：</strong>logs = ["d1/","d2/","../","d21/","./"]
<strong>输出：</strong>2
<strong>解释：</strong>执行 "../" 操作变更文件夹 2 次，即可回到主文件夹
</pre>

<p><strong>示例 2：</strong></p>

<p><img style="height: 270px; width: 600px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/09/26/sample_22_1957.png" alt=""></p>

<pre><strong>输入：</strong>logs = ["d1/","d2/","./","d3/","../","d31/"]
<strong>输出：</strong>3
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>logs = ["d1/","../","../","../"]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= logs.length &lt;= 10<sup>3</sup></code></li>
	<li><code>2 &lt;= logs[i].length &lt;= 10</code></li>
	<li><code>logs[i]</code> 包含小写英文字母，数字，<code>'.'</code> 和 <code>'/'</code></li>
	<li><code>logs[i]</code> 符合语句中描述的格式</li>
	<li>文件夹名称由小写英文字母和数字组成</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (auto s : logs) {
            if (s == "./") continue;
            ans += (s == "../") ? -1 : 1;
            ans = max(ans, 0);
        }
        return ans;
    }
};
```




