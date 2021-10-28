# `（困难）` [LCP 47.oPs9Bm 入场安检](https://leetcode-cn.com/problems/oPs9Bm/)

[contest](https://leetcode-cn.com/contest/season/2021-fall/problems/oPs9Bm/)

### 题目描述
<p>「力扣挑战赛」 的入场仪式马上就要开始了，由于安保工作的需要，设置了可容纳人数总和为 <code>M</code> 的 <code>N</code> 个安检室，<code>capacities[i]</code> 记录第 <code>i</code> 个安检室可容纳人数。安检室拥有两种类型：</p>
<ul>
<li>先进先出：在安检室中的所有观众中，最早进入安检室的观众最先离开</li>
<li>后进先出：在安检室中的所有观众中，最晚进入安检室的观众最先离开</li>
</ul>
<p align="center"><img src="https://pic.leetcode-cn.com/1628843202-cdFPSt-c24754f1a5ff56989340ba5004dc5eda.gif" alt="c24754f1a5ff56989340ba5004dc5eda.gif" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; "></p>
<p>恰好 <code>M+1</code> 位入场的观众（编号从 0 开始）需要排队<strong>依次</strong>入场安检， 入场安检的规则如下：</p>
<ul>
<li>观众需要先进入编号 <code>0</code> 的安检室</li>
<li>当观众将进入编号 <code>i</code> 的安检室时（<code>0 &lt;= i &lt; N</code>)，
<ul>
<li>若安检室未到达可容纳人数上限，该观众可直接进入；</li>
<li>若安检室已到达可容纳人数上限，在该观众进入安检室之前需根据当前安检室类型选择一位观众离开后才能进入；</li>
</ul>
</li>
<li>当观众离开编号 <code>i</code> 的安检室时 （<code>0 &lt;= i &lt; N-1</code>)，将进入编号 <code>i+1</code> 的安检室接受安检。</li>
</ul>
<p>若可以任意设定每个安检室的类型，请问有多少种设定安检室类型的方案可以使得编号 <code>k</code> 的观众第一个通过最后一个安检室入场。</p>
<p><strong>注意：</strong></p>
<ul>
<li>观众不可主动离开安检室，只有当安检室容纳人数达到上限，且又有新观众需要进入时，才可根据安检室的类型选择一位观众离开；</li>
<li>由于方案数可能过大，请将答案对 <code>1000000007</code> 取模后返回。</li>
</ul>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>capacities = [2,2,3], k = 2</code></p>
<p>输出：<code>2</code><br>
解释：<br>
存在两种设定的 <code>2</code> 种方案：</p>
<ul>
<li>方案 1：将编号为 <code>0</code> 、<code>1</code> 的实验室设置为 <strong>后进先出</strong> 的类型，编号为 <code>2</code> 的实验室设置为 <strong>先进先出</strong> 的类型；</li>
<li>方案 2：将编号为 <code>0</code> 、<code>1</code> 的实验室设置为 <strong>先进先出</strong> 的类型，编号为 <code>2</code> 的实验室设置为 <strong>后进先出</strong> 的类型。</li>
</ul>
<p>以下是方案 1 的示意图：<br>
<img src="https://pic.leetcode-cn.com/1628841618-bFKsnt-c60e38199a225ad62f13b954872edf9b.gif" alt="c60e38199a225ad62f13b954872edf9b.gif" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; "></p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>capacities = [3,3], k = 3</code></p>
<p>输出：<code>0</code></p>
</blockquote>
<p><strong>示例 3：</strong></p>
<blockquote>
<p>输入：<code>capacities = [4,3,2,2], k = 6</code></p>
<p>输出：<code>2</code></p>
</blockquote>
<p><strong>提示:</strong></p>
<ul>
<li><code>1 &lt;= capacities.length &lt;= 200</code></li>
<li><code>1 &lt;= capacities[i] &lt;= 200</code></li>
<li><code>0 &lt;= k &lt;= sum(capacities)</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int securityCheck(vector<int>& capacities, int k) {

    }
};
```




