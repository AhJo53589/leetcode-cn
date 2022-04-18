# `（困难）` [LCP 53.EJvmW4 守护太空城](https://leetcode-cn.com/problems/EJvmW4/)

### 题目描述
<p>各位勇者请注意，力扣太空城发布陨石雨红色预警。</p>
<p>太空城中的一些舱室将要受到陨石雨的冲击，这些舱室按照编号 <code>0 ~ N</code> 的顺序依次排列。为了阻挡陨石损毁舱室，太空城可以使用能量展开防护屏障，具体消耗如下：</p>
<ul>
<li>选择一个舱室开启屏障，能量消耗为 <code>2</code></li>
<li>选择相邻两个舱室开启联合屏障，能量消耗为 <code>3</code></li>
<li>对于已开启的<strong>一个</strong>屏障，<strong>多维持一时刻</strong>，能量消耗为 <code>1</code></li>
</ul>
<p>已知陨石雨的影响范围和到达时刻，<code>time[i]</code> 和 <code>position[i]</code> 分别表示该陨石的到达时刻和冲击位置。请返回太空舱能够守护所有舱室所需要的最少能量。</p>
<p><strong>注意：</strong></p>
<ul>
<li>同一时间，一个舱室不能被多个屏障覆盖</li>
<li>陨石雨仅在到达时刻对冲击位置处的舱室有影响</li>
</ul>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>time = [1,2,1], position = [6,3,3]</code></p>
<p>输出：<code>5</code></p>
<p>解释：<br>
时刻 1，分别开启编号 3、6 舱室的屏障，能量消耗 2*2 = 4<br>
时刻 2，维持编号 3 舱室的屏障，能量消耗 1<br>
因此，最少需要能量 5</p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>time = [1,1,1,2,2,3,5], position = [1,2,3,1,2,1,3]</code></p>
<p>输出：<code>9</code></p>
<p>解释：<br>
时刻 1，开启编号 1、2 舱室的联合屏障，能量消耗 3<br>
时刻 1，开启编号 3 舱室的屏障，能量消耗 2<br>
时刻 2，维持编号 1、2 舱室的联合屏障，能量消耗 1<br>
时刻 3，维持编号 1、2 舱室的联合屏障，能量消耗 1<br>
时刻 5，重新开启编号 3 舱室的联合屏障，能量消耗 2<br>
因此，最少需要能量 9</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>1 &lt;= time.length == position.length &lt;= 500</code></li>
<li><code>1 &lt;= time[i] &lt;= 5</code></li>
<li><code>0 &lt;= position[i] &lt;= 100</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int defendSpaceCity(vector<int>& time, vector<int>& position) {

    }
};
```




