# `（困难）` [LCP_35.DFPeFJ 电动车游城市](https://leetcode-cn.com/problems/DFPeFJ/)

[contest](https://leetcode-cn.com/contest/season/2021-spring/problems/DFPeFJ/)

### 题目描述
<p>小明的电动车电量充满时可行驶距离为 <code>cnt</code>，每行驶 1 单位距离消耗 1 单位电量，且花费 1 单位时间。小明想选择电动车作为代步工具。地图上共有 N 个景点，景点编号为 0 ~ N-1。他将地图信息以 <code>[城市 A 编号,城市 B 编号,两城市间距离]</code> 格式整理在在二维数组 <code>paths</code>，表示城市 A、B 间存在双向通路。初始状态，电动车电量为 0。每个城市都设有充电桩，<code>charge[i]</code> 表示第 i 个城市每充 1 单位电量需要花费的单位时间。请返回小明最少需要花费多少单位时间从起点城市 <code>start</code> 抵达终点城市 <code>end</code>。</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>paths = [[1,3,3],[3,2,1],[2,1,3],[0,1,4],[3,0,5]], cnt = 6, start = 1, end = 0, charge = [2,10,4,1]</code></p>
<p>输出：<code>43</code></p>
<p>解释：最佳路线为：1-&gt;3-&gt;0。<br>
在城市 1 仅充 3 单位电至城市 3，然后在城市 3 充 5 单位电，行驶至城市 5。<br>
充电用时共 3*10 + 5*1= 35<br>
行驶用时 3 + 5 = 8，此时总用时最短 43。<br>
<img src="https://pic.leetcode-cn.com/1616125304-mzVxIV-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; "></p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>paths = [[0,4,2],[4,3,5],[3,0,5],[0,1,5],[3,2,4],[1,2,8]], cnt = 8, start = 0, end = 2, charge = [4,1,1,3,2]</code></p>
<p>输出：<code>38</code></p>
<p>解释：最佳路线为：0-&gt;4-&gt;3-&gt;2。<br>
城市 0 充电 2 单位，行驶至城市 4 充电 8 单位，行驶至城市 3 充电 1 单位，最终行驶至城市 2。<br>
充电用时 4*2+2*8+3*1 = 27<br>
行驶用时 2+5+4 = 11，总用时最短 38。</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>1 &lt;= paths.length &lt;= 200</code></li>
<li><code>paths[i].length == 3</code></li>
<li><code>2 &lt;= charge.length == n &lt;= 100</code></li>
<li><code>0 &lt;= path[i][0],path[i][1],start,end &lt; n</code></li>
<li><code>1 &lt;= cnt &lt;= 100</code></li>
<li><code>1 &lt;= path[i][2] &lt;= cnt</code></li>
<li><code>1 &lt;= charge[i] &lt;= 100</code></li>
<li>题目保证所有城市相互可以到达</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge) {

    }
};
```




