# `（困难）` [LCP 43.Y1VbOX 十字路口的交通](https://leetcode-cn.com/problems/Y1VbOX/)

[contest](https://leetcode-cn.com/contest/season/2021-fall/problems/Y1VbOX/)

### 题目描述
<div class="css-330z23" style="padding: 0px; margin: 13px 0px;"><p>前往「力扣挑战赛」场馆的道路上，有一个拥堵的十字路口，该十字路口由两条双向两车道的路交叉构成。由于信号灯故障，交警需要手动指挥拥堵车辆。假定路口没有新的来车且一辆车从一个车道驶入另一个车道所需的时间恰好为一秒钟，长度为 4 的一维字符串数组 <code>directions</code> 中按照 <strong>东、南、西、北</strong> 顺序记录了四个方向从最靠近路口到最远离路口的车辆计划开往的方向。其中：</p>
<ul>
<li><code>"E"</code> 表示向东行驶；</li>
<li><code>"S"</code> 表示向南行驶；</li>
<li><code>"W"</code> 表示向西行驶；</li>
<li><code>"N"</code> 表示向北行驶。</li>
</ul>
<p>交警每秒钟只能指挥各个车道距离路口最近的一辆车，且每次指挥需要满足如下规则：</p>
<ul>
<li>同一秒钟内，一个方向的车道只允许驶出一辆车；</li>
<li>同一秒钟内，一个方向的车道只允许驶入一辆车；</li>
<li>同一秒钟内，车辆的行驶路线不可相交。</li>
</ul>
<p>请返回最少需要几秒钟，该十字路口等候的车辆才能全部走完。</p>
<p>各个车道驶出的车辆可能的行驶路线如图所示：</p>
<p align="center"><img src="https://pic.leetcode-cn.com/1630393755-gyPeMM-%E5%9B%BE%E7%89%87.png" alt="图片.png" height="350px" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; "></p>
<p><strong>注意：</strong></p>
<ul>
<li>测试数据保证不会出现掉头行驶指令，即某一方向的行驶车辆计划开往的方向不会是当前车辆所在的车道的方向;</li>
<li>表示堵塞车辆行驶方向的字符串仅用大写字母 <code>"E"</code>，<code>"N"</code>，<code>"W"</code>，<code>"S"</code> 表示。</li>
</ul>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>directions = ["W","N","ES","W"]</code></p>
<p>输出：<code>2</code></p>
<p>解释：<br>
第 1 秒：东西方向排在最前的车先行，剩余车辆状态 <code>["","N","S","W"]</code>；<br>
第 2 秒：南、西、北方向的车行驶，路口无等待车辆；<br>
因此最少需要 2 秒，返回 2。</p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>directions = ["NS","WE","SE","EW"]</code></p>
<p>输出：<code>3</code></p>
<p>解释：<br>
第 1 秒：四个方向排在最前的车均可驶出；<br>
第 2 秒：东南方向的车驶出，剩余车辆状态 <code>["","","E","W"]</code>；<br>
第 3 秒：西北方向的车驶出。</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>directions.length = 4</code></li>
<li><code>0 &lt;= directions[i].length &lt;= 20</code></li>
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
    int trafficCommand(vector<string>& directions) {

    }
};
```




