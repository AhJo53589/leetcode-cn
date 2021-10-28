# `（中等）` [LCP 46.05ZEDJ 志愿者调配](https://leetcode-cn.com/problems/05ZEDJ/)

[contest](https://leetcode-cn.com/contest/season/2021-fall/problems/05ZEDJ/)

### 题目描述
<p>「力扣挑战赛」有 <code>n</code> 个比赛场馆（场馆编号从 <code>0</code> 开始），场馆之间的通道分布情况记录于二维数组 <code>edges</code> 中，<code>edges[i]= [x, y]</code> 表示第 <code>i</code> 条通道连接场馆 <code>x</code> 和场馆 <code>y</code>(即两个场馆相邻)。初始每个场馆中都有一定人数的志愿者（不同场馆人数可能不同），后续 <code>m</code> 天每天均会根据赛事热度进行志愿者人数调配。调配方案分为如下三种：</p>
<ol>
<li>将编号为 <code>idx</code> 的场馆内的志愿者人数减半；</li>
<li>将编号为 <code>idx</code> 的场馆相邻的场馆的志愿者人数都加上编号为 <code>idx</code> 的场馆的志愿者人数；</li>
<li>将编号为 <code>idx</code> 的场馆相邻的场馆的志愿者人数都减去编号为 <code>idx</code> 的场馆的志愿者人数。</li>
</ol>
<p>所有的调配信息记录于数组 <code>plans</code> 中，<code>plans[i] = [num,idx]</code> 表示第 <code>i</code> 天对编号 <code>idx</code> 的场馆执行了第 <code>num</code> 种调配方案。<br>
在比赛结束后对调配方案进行复盘时，不慎将第 <code>0</code> 个场馆的<strong>最终</strong>志愿者人数丢失，只保留了<strong>初始</strong>所有场馆的志愿者总人数 <code>totalNum</code> ，以及记录了第 <code>1 ~ n-1</code> 个场馆的<strong>最终</strong>志愿者人数的一维数组 <code>finalCnt</code>。请你根据现有的信息求出初始每个场馆的志愿者人数，并按场馆编号顺序返回志愿者人数列表。</p>
<p><strong>注意：</strong></p>
<ul>
<li>测试数据保证当某场馆进行第一种调配时，该场馆的志愿者人数一定为偶数；</li>
<li>测试数据保证当某场馆进行第三种调配时，该场馆的相邻场馆志愿者人数不为负数；</li>
<li>测试数据保证比赛开始时每个场馆的志愿者人数都不超过 <code>10^9</code>；</li>
<li>测试数据保证给定的场馆间的道路分布情况中不会出现自环、重边的情况。</li>
</ul>
<p><strong>示例 1：</strong></p>
<blockquote>
<p><img src="https://pic.leetcode-cn.com/1630061228-gnZsOz-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; "><br>
输入：<br>
<code>finalCnt = [1,16], totalNum = 21, edges = [[0,1],[1,2]], plans = [[2,1],[1,0],[3,0]]</code></p>
<p>输出：<code>[5,7,9]</code></p>
<p>解释：<br>
<img src="https://pic.leetcode-cn.com/1630061300-WuVkeF-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; " height="200"></p>
</blockquote>
<p><strong>示例 2 ：</strong></p>
<blockquote>
<p>输入：<br>
<code>finalCnt = [4,13,4,3,8], totalNum = 54, edges = [[0,3],[1,3],[4,3],[2,3],[2,5]], plans = [[1,1],[3,3],[2,5],[1,0]]</code></p>
<p>输出：<code>[10,16,9,4,7,8]</code></p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>2 &lt;= n &lt;= 5*10^4</code></li>
<li><code>1 &lt;= edges.length &lt;= min((n * (n - 1)) / 2, 5*10^4)</code></li>
<li><code>0 &lt;= edges[i][0], edges[i][1] &lt; n</code></li>
<li><code>1 &lt;= plans.length &lt;= 10</code></li>
<li><code>1 &lt;= plans[i][0] &lt;=3</code></li>
<li><code>0 &lt;= plans[i][1] &lt; n</code></li>
<li><code>finalCnt.length = n-1</code></li>
<li><code>0 &lt;= finalCnt[i] &lt; 10^9</code></li>
<li><code>0 &lt;= totalNum &lt; 5*10^13</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/05ZEDJ/solution/05zedj-by-ikaruga-hid6/)

### 答题
``` C++
class Solution {
public:
    vector<int> volunteerDeployment(vector<int>& finalCnt, long long totalNum, vector<vector<int>>& edges, vector<vector<int>>& plans) {
        vector<vector<int>> paths(finalCnt.size() + 1);
        for (auto d : edges) {
            paths[d[0]].push_back(d[1]);
            paths[d[1]].push_back(d[0]);
        }

        vector<pair<int, long long>> t(paths.size());
        t[0] = { 1, 0 };
        for (int i = 0; i < finalCnt.size(); i++) {
            t[i + 1] = { 0, finalCnt[i] };
        }

        for (int i = (int)plans.size() - 1; ~i; i--) {
            int num = plans[i][0];
            int idx = plans[i][1];
            auto&[ca, cb] = t[idx];

            if (num == 1) {
                ca *= 2;
                cb *= 2;
            }
            else {
                int f = (num == 2) ? -1 : 1;
                for (auto n : paths[idx]) {
                    auto&[a, b] = t[n];
                    a += ca * f;
                    b += cb * f;
                }
            }
        }

        int sx = 0;
        for (auto&[a, b] : t) {
            sx += a;
            totalNum -= b;
        }
        int x = totalNum / sx;

        vector<int> ans(t.size());
        for (int i = 0; i < t.size(); i++) {
            auto[a, b] = t[i];
            ans[i] = a * x + b;
        }
        return ans;
    }
};
```




