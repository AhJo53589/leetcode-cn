# `（简单）` [LCP 39.0jQkd0 无人机方阵](https://leetcode-cn.com/problems/0jQkd0/)

[contest](https://leetcode-cn.com/contest/season/2021-fall/problems/0jQkd0/)

### 题目描述
<div class="css-330z23" style="padding: 0px; margin: 13px 0px;"><p>在 「力扣挑战赛」 开幕式的压轴节目 「无人机方阵」中，每一架无人机展示一种灯光颜色。 无人机方阵通过两种操作进行颜色图案变换：</p>
<ul>
<li>调整无人机的位置布局</li>
<li>切换无人机展示的灯光颜色</li>
</ul>
<p>给定两个大小均为 <code>N*M</code> 的二维数组 <code>source</code> 和 <code>target</code> 表示无人机方阵表演的两种颜色图案，由于无人机切换灯光颜色的耗能很大，请返回从 <code>source</code> 到 <code>target</code> 最少需要多少架无人机切换灯光颜色。</p>
<p><strong>注意：</strong> 调整无人机的位置布局时无人机的位置可以随意变动。</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>source = [[1,3],[5,4]], target = [[3,1],[6,5]]</code></p>
<p>输出：<code>1</code></p>
<p>解释：<br>
最佳方案为<br>
将 <code>[0,1]</code> 处的无人机移动至 <code>[0,0]</code> 处；<br>
将 <code>[0,0]</code> 处的无人机移动至 <code>[0,1]</code> 处；<br>
将 <code>[1,0]</code> 处的无人机移动至 <code>[1,1]</code> 处；<br>
将 <code>[1,1]</code> 处的无人机移动至 <code>[1,0]</code> 处，其灯光颜色切换为颜色编号为 <code>6</code> 的灯光；<br>
因此从<code>source</code> 到 <code>target</code> 所需要的最少灯光切换次数为 1。<br>
<img src="https://pic.leetcode-cn.com/1628823765-uCDaux-8819ccdd664e91c78cde3bba3c701986.gif" alt="8819ccdd664e91c78cde3bba3c701986.gif" height="300px" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; "></p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>source = [[1,2,3],[3,4,5]], target = [[1,3,5],[2,3,4]]</code></p>
<p>输出：<code>0</code><br>
解释：<br>
仅需调整无人机的位置布局，便可完成图案切换。因此不需要无人机切换颜色</p>
</blockquote>
<p><strong>提示：</strong><br>
<code>n == source.length == target.length</code><br>
<code>m == source[i].length == target[i].length</code><br>
<code>1 &lt;= n, m &lt;=100</code><br>
<code>1 &lt;= source[i][j], target[i][j] &lt;=10^4</code></p>
</div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int minimumSwitchingTimes(vector<vector<int>>& source, vector<vector<int>>& target) {
        unordered_map<int, int> sc;
        for (auto& v : source) {
            for (auto& n : v) {
                sc[n]++;
            }
        }

        unordered_map<int, int> tc;
        for (auto& v : target) {
            for (auto& n : v) {
                tc[n]++;
            }
        }

        int ans = 0;
        for (auto it = tc.begin(); it != tc.end(); it++) {
            ans += max(it->second - sc[it->first], 0);
        }
        return ans;
    }
};
```




