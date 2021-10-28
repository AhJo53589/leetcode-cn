# `（困难）` [LCP 48.fsa7oZ 无限棋局](https://leetcode-cn.com/problems/fsa7oZ/)

[contest](https://leetcode-cn.com/contest/season/2021-fall/problems/fsa7oZ/)

### 题目描述
<p>小力正在通过残局练习来备战「力扣挑战赛」中的「五子棋」项目，他想请你能帮他预测当前残局的输赢情况。棋盘中的棋子分布信息记录于二维数组 <code>pieces</code> 中，其中 <code>pieces[i] = [x,y,color]</code> 表示第 <code>i</code> 枚棋子的横坐标为 <code>x</code>，纵坐标为 <code>y</code>，棋子颜色为 <code>color</code>(<code>0</code> 表示黑棋，<code>1</code> 表示白棋)。假如黑棋先行，并且黑棋和白棋都按最优策略落子，请你求出当前棋局在三步（按 <strong>黑、白、黑</strong> 的落子顺序）之内的输赢情况（三步之内先构成同行、列或对角线连续同颜色的至少 5 颗即为获胜）：</p>
<ul>
<li>黑棋胜, 请返回 <code>"Black"</code></li>
<li>白棋胜, 请返回 <code>"White"</code></li>
<li>仍无胜者, 请返回 <code>"None"</code></li>
</ul>
<p><strong>注意：</strong></p>
<ul>
<li>和传统的五子棋项目不同，「力扣挑战赛」中的「五子棋」项目 <strong>不存在边界限制</strong>，即可在 <strong>任意位置</strong> 落子；</li>
<li>黑棋和白棋均按 3 步内的输赢情况进行最优策略的选择</li>
<li>测试数据保证所给棋局目前无胜者；</li>
<li>测试数据保证不会存在坐标一样的棋子。</li>
</ul>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<br>
<code>pieces = [[0,0,1],[1,1,1],[2,2,0]]</code></p>
<p>输出：<code>"None"</code></p>
<p>解释：无论黑、白棋以何种方式落子，三步以内都不会产生胜者。</p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<br>
<code>pieces = [[1,2,1],[1,4,1],[1,5,1],[2,1,0],[2,3,0],[2,4,0],[3,2,1],[3,4,0],[4,2,1],[5,2,1]]</code></p>
<p>输出：<code>"Black"</code></p>
<p>解释：三步之内黑棋必胜，以下是一种可能的落子情况：<br>
<img src="https://pic.leetcode-cn.com/1629800639-KabOfY-902b87df29998b1c181146c8fdb3a4b6.gif" alt="902b87df29998b1c181146c8fdb3a4b6.gif" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; " width="300px"></p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>0 &lt;= pieces.length &lt;= 1000</code></li>
<li><code>pieces[i].length = 3</code></li>
<li><code>-10^9 &lt;= pieces[i][0], pieces[i][1] &lt;=10^9</code></li>
<li><code>0 &lt;= pieces[i][2] &lt;=1</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    string gobang(vector<vector<int>>& pieces) {

    }
};
```




