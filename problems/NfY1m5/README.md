# `（困难）` [LCP 59.NfY1m5 搭桥过河](https://leetcode-cn.com/problems/NfY1m5/)

### 题目描述
<p>欢迎各位勇者来到力扣城，本次试炼主题为「搭桥过河」。</p>
<p>勇者面前有一段长度为 <code>num</code> 的河流，河流可以划分为若干河道。每条河道上恰有一块浮木，<code>wood[i]</code> 记录了第 <code>i</code> 条河道上的浮木初始的覆盖范围。</p>
<ul>
<li>当且仅当浮木与相邻河道的浮木覆盖范围有重叠时，勇者才可以在两条浮木间移动</li>
<li>勇者 <strong>仅能在岸上</strong> 通过花费一点「自然之力」，使任意一条浮木沿着河流移动一个单位距离</li>
</ul>
<p>请问勇者跨越这条河流，最少需要花费多少「自然之力」。</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入： <code>num = 10, wood = [[1,2],[4,7],[8,9]]</code><br>
输出： <code>3</code><br>
解释：如下图所示，<br>
将 [1,2] 浮木移动至 [3,4]，花费 2「自然之力」，<br>
将 [8,9] 浮木移动至 [7,8]，花费 1「自然之力」，<br>
此时勇者可以顺着 [3,4]-&gt;[4,7]-&gt;[7,8] 跨越河流，<br>
因此，勇者最少需要花费 3 点「自然之力」跨越这条河流<br>
<img src="https://pic.leetcode-cn.com/1648196478-ophADL-wood%20(2).gif" alt="wood (2).gif" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; " width="650px"></p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入： <code>num = 10, wood = [[1,5],[1,1],[10,10],[6,7],[7,8]]</code><br>
输出： <code>10</code><br>
解释：<br>
将 [1,5] 浮木移动至 [2,6]，花费 1「自然之力」，<br>
将 [1,1] 浮木移动至 [6,6]，花费 5「自然之力」，<br>
将 [10,10] 浮木移动至 [6,6]，花费 4「自然之力」，<br>
此时勇者可以顺着 [2,6]-&gt;[6,6]-&gt;[6,6]-&gt;[6,7]-&gt;[7,8] 跨越河流，<br>
因此，勇者最少需要花费 10 点「自然之力」跨越这条河流</p>
</blockquote>
<p><strong>示例 3：</strong></p>
<blockquote>
<p>输入： <code>num = 5, wood = [[1,2],[2,4]]</code><br>
输出： <code>0</code><br>
解释：勇者不需要移动浮木，仍可以跨越这条河流</p>
</blockquote>
<p><strong>提示:</strong></p>
<ul>
<li><code>1 &lt;= num &lt;= 10^9</code></li>
<li><code>1 &lt;= wood.length &lt;= 10^5</code></li>
<li><code>wood[i].length == 2</code></li>
<li><code>1 &lt;= wood[i][0] &lt;= wood[i][1] &lt;= num</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    long long buildBridge(int num, vector<vector<int>>& wood) {

    }
};
```




