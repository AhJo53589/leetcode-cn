# `（简单）` [1000082.Ju9Xwi 下载插件](https://leetcode-cn.com/problems/Ju9Xwi/)

[contest](https://leetcode-cn.com/contest/lc-vscode/problems/Ju9Xwi/)

### 题目描述
<div class="question-content default-content"><p>小扣打算给自己的 <strong>VS code</strong> 安装使用插件，初始状态下带宽每分钟可以完成 <code>1</code> 个插件的下载。假定每分钟选择一下两种策略之一:</p>
<ul>
<li>使用当前带宽下载插件</li>
<li>将带宽加倍（下载插件数量随之加倍）</li>
</ul>
<p>请返回小扣完成下载 <code>n</code> 个插件最少需要多少分钟。</p>
<p>注意：实际的下载的插件数量可以超过 <code>n</code> 个</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>n = 2</code></p>
<p>输出：<code>2</code></p>
<p>解释：<br>
以下两个方案，都能实现 2 分钟内下载 2 个插件</p>
<ul>
<li>方案一：第一分钟带宽加倍，带宽可每分钟下载 2 个插件；第二分钟下载 2 个插件</li>
<li>方案二：第一分钟下载 1 个插件，第二分钟下载 1 个插件</li>
</ul>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>n = 4</code></p>
<p>输出：<code>3</code></p>
<p>解释：<br>
最少需要 3 分钟可完成 4 个插件的下载，以下是其中一种方案:<br>
第一分钟带宽加倍，带宽可每分钟下载 2 个插件;<br>
第二分钟下载 2 个插件;<br>
第三分钟下载 2 个插件。</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>1 &lt;= n &lt;= 10^5</code></li>
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
    int leastMinutes(int n) {
        int ans = INT_MAX;
        int x = 0;
        int t = 1;
        while (t <= n) {
            ans = min(ans, x + n / t + (n % t != 0));
            x++;
            t *= 2;
        }
        return ans;
    }
};
```




