# `（困难）` [LCP 54.s5kipK 夺回据点](https://leetcode-cn.com/problems/s5kipK/)

### 题目描述
<p>欢迎各位勇者来到力扣城，本次试炼主题为「夺回据点」。</p>
<p>魔物了占领若干据点，这些据点被若干条道路相连接，<code>roads[i] = [x, y]</code> 表示编号 <code>x</code>、<code>y</code> 的两个据点通过一条道路连接。</p>
<p>现在勇者要将按照以下原则将这些据点逐一夺回：</p>
<ul>
<li>
<p>在开始的时候，勇者可以花费资源先夺回一些据点，初始夺回第 <code>j</code> 个据点所需消耗的资源数量为 <code>cost[j]</code></p>
</li>
<li>
<p>接下来，勇者在不消耗资源情况下，每次可以夺回<strong>一个</strong>和「已夺回据点」相连接的魔物据点，并对其进行夺回</p>
</li>
</ul>
<blockquote>
<p>注：为了防止魔物暴动，勇者在每一次夺回据点后（包括花费资源夺回据点后），需要保证剩余的所有魔物据点之间是相连通的（不经过「已夺回据点」）。</p>
</blockquote>
<p>请返回勇者夺回所有据点需要消耗的最少资源数量。</p>
<p><strong>注意：</strong></p>
<ul>
<li>输入保证初始所有据点都是连通的，且不存在重边和自环</li>
</ul>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<br>
<code>cost = [1,2,3,4,5,6]</code><br>
<code>roads = [[0,1],[0,2],[1,3],[2,3],[1,2],[2,4],[2,5]]</code></p>
<p>输出：<code>6</code></p>
<p>解释：<br>
勇者消耗资源 <code>6</code> 夺回据点 <code>0</code> 和 <code>4</code>，魔物据点 <code>1、2、3、5</code> 相连通；<br>
第一次夺回据点 <code>1</code>，魔物据点 <code>2、3、5</code> 相连通；<br>
第二次夺回据点 <code>3</code>，魔物据点 <code>2、5</code> 相连通；<br>
第三次夺回据点 <code>2</code>，剩余魔物据点 <code>5</code>；<br>
第四次夺回据点 <code>5</code>，无剩余魔物据点；<br>
因此最少需要消耗资源为 <code>6</code>，可占领所有据点。<br>
<img src="https://pic.leetcode-cn.com/1648706944-KJstUN-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; " height="170px"></p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<br>
<code>cost = [3,2,1,4]</code><br>
<code>roads = [[0,2],[2,3],[3,1]]</code></p>
<p>输出：<code>2</code></p>
<p>解释：<br>
勇者消耗资源 <code>2</code> 夺回据点 <code>1</code>，魔物据点 <code>0、2、3</code> 相连通；<br>
第一次夺回据点 <code>3</code>，魔物据点 <code>2、0</code> 相连通；<br>
第二次夺回据点 <code>2</code>，剩余魔物据点 <code>0</code>；<br>
第三次夺回据点 <code>0</code>，无剩余魔物据点；<br>
因此最少需要消耗资源为 <code>2</code>，可占领所有据点。<br>
<img src="https://pic.leetcode-cn.com/1648707186-LJRwzU-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; " height="60px"></p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>1 &lt;= roads.length, cost.length &lt;= 10^5</code></li>
<li><code>0 &lt;= roads[i][0], roads[i][1] &lt; cost.length</code></li>
<li><code>1 &lt;= cost[i] &lt;= 10^9</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    long long minimumCost(vector<int>& cost, vector<vector<int>>& roads) {

    }
};
```




