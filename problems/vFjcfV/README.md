# `（困难）` [LCP 42.vFjcfV 玩具套圈](https://leetcode-cn.com/problems/vFjcfV/)

[contest](https://leetcode-cn.com/contest/season/2021-fall/problems/vFjcfV/)

### 题目描述
<div class="css-330z23" style="padding: 0px; margin: 13px 0px;"><p>「力扣挑战赛」场地外，小力组织了一个套玩具的游戏。所有的玩具摆在平地上，<code>toys[i]</code> 以 <code>[xi,yi,ri]</code> 的形式记录了第 <code>i</code> 个玩具的坐标 <code>(xi,yi)</code> 和半径 <code>ri</code>。小扣试玩了一下，他扔了若干个半径均为 <code>r</code> 的圈，<code>circles[j]</code> 记录了第 <code>j</code> 个圈的坐标 <code>(xj,yj)</code>。套圈的规则如下：</p>
<ul>
<li>若一个玩具被某个圈完整覆盖了（即玩具的任意部分均在圈内或者圈上），则该玩具被套中。</li>
<li>若一个玩具被多个圈同时套中，最终仅计算为套中一个玩具</li>
</ul>
<p>请帮助小扣计算，他成功套中了多少玩具。</p>
<p><strong>注意：</strong></p>
<ul>
<li>输入数据保证任意两个玩具的圆心不会重合，但玩具之间可能存在重叠。</li>
</ul>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>toys = [[3,3,1],[3,2,1]], circles = [[4,3]], r = 2</code></p>
<p>输出：<code>1</code></p>
<p>解释： 如图所示，仅套中一个玩具<br>
<img src="https://pic.leetcode-cn.com/1629194140-ydKiGF-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; "></p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>toys = [[1,3,2],[4,3,1],[7,1,2]], circles = [[1,0],[3,3]], r = 4</code></p>
<p>输出：<code>2</code></p>
<p>解释： 如图所示，套中两个玩具<br>
<img src="https://pic.leetcode-cn.com/1629194157-RiOAuy-image.png" alt="image.png" width="400px" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; "></p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>1 &lt;= toys.length &lt;= 10^4</code></li>
<li><code>0 &lt;= toys[i][0], toys[i][1] &lt;= 10^9</code></li>
<li><code>1 &lt;= circles.length &lt;= 10^4</code></li>
<li><code>0 &lt;= circles[i][0], circles[i][1] &lt;= 10^9</code></li>
<li><code>1 &lt;= toys[i][2], r &lt;= 10</code></li>
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
    int circleGame(vector<vector<int>>& toys, vector<vector<int>>& circles, int r) {

    }
};
```




