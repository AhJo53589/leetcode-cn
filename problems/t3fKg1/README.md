# `（困难）` [LCP_32.t3fKg1 批量处理任务](https://leetcode-cn.com/problems/t3fKg1/)

[contest](https://leetcode-cn.com/contest/season/2021-spring/problems/t3fKg1/)

### 题目描述
<div class="css-1708ckn" style="padding: 0px; margin: 13px 0px;"><p>某实验室计算机待处理任务以 <code>[start,end,period]</code> 格式记于二维数组 <code>tasks</code>，表示完成该任务的时间范围为起始时间 <code>start</code> 至结束时间 <code>end</code> 之间，需要计算机投入 <code>period</code> 的时长，注意：</p>
<ol>
<li><code>period</code> 可为不连续时间</li>
<li>首尾时间均包含在内</li>
</ol>
<p>处于开机状态的计算机可同时处理任意多个任务，请返回电脑最少开机多久，可处理完所有任务。</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>tasks = [[1,3,2],[2,5,3],[5,6,2]]</code></p>
<p>输出：<code>4</code></p>
<p>解释：<br>
tasks[0] 选择时间点 2、3；<br>
tasks[1] 选择时间点 2、3、5；<br>
tasks[2] 选择时间点 5、6；<br>
因此计算机仅需在时间点 2、3、5、6 四个时刻保持开机即可完成任务。</p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>tasks = [[2,3,1],[5,5,1],[5,6,2]]</code></p>
<p>输出：<code>3</code></p>
<p>解释：<br>
tasks[0] 选择时间点 2 或 3；<br>
tasks[1] 选择时间点 5；<br>
tasks[2] 选择时间点 5、6；<br>
因此计算机仅需在时间点 2、5、6 或 3、5、6 三个时刻保持开机即可完成任务。</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>2 &lt;= tasks.length &lt;= 10^5</code></li>
<li><code>tasks[i].length == 3</code></li>
<li><code>0 &lt;= tasks[i][0] &lt;= tasks[i][1] &lt;= 10^9</code></li>
<li><code>1 &lt;= tasks[i][2] &lt;= tasks[i][1]-tasks[i][0] + 1</code></li>
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
    int processTasks(vector<vector<int>>& tasks) {

    }
};
```




