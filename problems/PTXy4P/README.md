# `（简单）` [LCP 55.PTXy4P 采集果实](https://leetcode-cn.com/problems/PTXy4P/)

### 题目描述
<p>欢迎各位勇者来到力扣新手村，本次训练内容为「采集果实」。</p>
<p>在新手村中，各位勇者需要采集一些果实来制作药剂。<code>time[i]</code> 表示勇者每次采集 <code>1～limit</code> 颗第 <code>i</code> 种类型的果实需要的时间（即每次最多可以采集 <code>limit</code> 颗果实）。</p>
<p>当前勇者需要完成「采集若干批果实」的任务， <code>fruits[j] = [type, num]</code> 表示第 <code>j</code> 批需要采集 <code>num</code> 颗 <code>type</code> 类型的果实。采集规则如下：</p>
<ul>
<li>按 <code>fruits</code> 给定的顺序<strong>依次</strong>采集每一批次</li>
<li>采集完当前批次的果实才能开始采集下一批次</li>
<li>勇者完成当前批次的采集后将<strong>清空背包</strong>（即多余的果实将清空）</li>
</ul>
<p>请计算并返回勇者完成采集任务最少需要的时间。</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>time = [2,3,2], fruits = [[0,2],[1,4],[2,1]], limit = 3</code></p>
<p>输出：<code>10</code></p>
<p>解释：<br>
由于单次最多采集 3 颗<br>
第 0 批需要采集 2 颗第 0 类型果实，需要采集 1 次，耗时为 2*1=2<br>
第 1 批需要采集 4 颗第 1 类型果实，需要采集 2 次，耗时为 3*2=6<br>
第 2 批需要采集 1 颗第 2 类型果实，需要采集 1 次，耗时为 2*1=2<br>
返回总耗时 2+6+2=10</p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>time = [1], fruits = [[0,3],[0,5]], limit = 2</code></p>
<p>输出：<code>5</code></p>
<p>解释：<br>
由于单次最多采集 2 颗<br>
第 0 批需要采集 3 颗第 0 类型果实，需要采集 2 次，耗时为 1*2=2<br>
第 1 批需要采集 5 颗第 0 类型果实，需要采集 3 次，耗时为 1*3=3<br>
需按照顺序依次采集，返回 2+3=5</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>1 &lt;= time.length &lt;= 100</code></li>
<li><code>1 &lt;= time[i] &lt;= 100</code></li>
<li><code>1 &lt;= fruits.length &lt;= 10^3</code></li>
<li><code>0 &lt;= fruits[i][0] &lt; time.length</code></li>
<li><code>1 &lt;= fruits[i][1] &lt; 10^3</code></li>
<li><code>1 &lt;= limit &lt;= 100</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int getMinimumTime(vector<int>& time, vector<vector<int>>& fruits, int limit) {
        int ans = 0;
        for (auto& f : fruits) {
            int a = f[1] / limit + (f[1] % limit != 0);
            ans += a * time[f[0]];
        }
        return ans;
    }
};

```




