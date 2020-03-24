# `（中等）` [1386.cinema-seat-allocation 安排电影院座位](https://leetcode-cn.com/problems/cinema-seat-allocation/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-22/problems/cinema-seat-allocation/)

### 题目描述
<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/03/21/cinema_seats_1.png" style="height: 149px; width: 400px;"></p>

<p>如上图所示，电影院的观影厅中有 <code>n</code>&nbsp;行座位，行编号从 1&nbsp;到 <code>n</code>&nbsp;，且每一行内总共有 10 个座位，列编号从 1 到 10 。</p>

<p>给你数组&nbsp;<code>reservedSeats</code>&nbsp;，包含所有已经被预约了的座位。比如说，<code>researvedSeats[i]=[3,8]</code>&nbsp;，它表示第&nbsp;<strong>3</strong>&nbsp;行第&nbsp;<strong>8</strong>&nbsp;个座位被预约了。</p>

<p>请你返回&nbsp;<strong>最多能安排多少个 4 人家庭</strong>&nbsp;。4 人家庭要占据&nbsp;<strong>同一行内连续&nbsp;</strong>的 4 个座位。隔着过道的座位（比方说 [3,3] 和 [3,4]）不是连续的座位，但是如果你可以将 4 人家庭拆成过道两边各坐 2 人，这样子是允许的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/03/21/cinema_seats_3.png" style="height: 96px; width: 400px;"></p>

<pre><strong>输入：</strong>n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
<strong>输出：</strong>4
<strong>解释：</strong>上图所示是最优的安排方案，总共可以安排 4 个家庭。蓝色的叉表示被预约的座位，橙色的连续座位表示一个 4 人家庭。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^9</code></li>
	<li><code>1 &lt;=&nbsp;reservedSeats.length &lt;= min(10*n, 10^4)</code></li>
	<li><code>reservedSeats[i].length == 2</code></li>
	<li><code>1&nbsp;&lt;=&nbsp;reservedSeats[i][0] &lt;= n</code></li>
	<li><code>1 &lt;=&nbsp;reservedSeats[i][1] &lt;= 10</code></li>
	<li>所有&nbsp;<code>reservedSeats[i]</code> 都是互不相同的。</li>
</ul>

            

---
### 思路
```
```
[发布的题解](https://leetcode-cn.com/problems/cinema-seat-allocation/solution/cinema-seat-allocation-by-ikaruga/)


### 答题
``` C++
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) 
    {
        int ans = 0;
        sort(reservedSeats.begin(), reservedSeats.end());
        int r = 0;
        for (int i = 0; i < n;)
        {
            int bitA = 0;
            int bitB = 0;
            int bitC = 0;
            while (r < reservedSeats.size() && reservedSeats[r][0] == i + 1)
            {
                int b = reservedSeats[r][1];
                r++;
                if (b >= 2 && b < 6)
                {
                    bitA |= (1 << (b - 2));
                }
                if (b >= 4 && b < 8)
                {
                    bitB |= (1 << (b - 4));
                }
                if (b >= 6 && b < 10)
                {
                    bitC |= (1 << (b - 6));
                }
            }
            int cntA = 2 - (bitA != 0) - (bitC != 0);
            int cntB = 1 - (bitB != 0);
            ans += max(cntA, cntB);

            if (r >= reservedSeats.size())
            {
                ans += (n - 1 - i) * 2;
                break;
            }

            int next = reservedSeats[r][0] - 1;
            ans += (next - i - 1) * 2;
            i = next;
        }
        return ans;
    }
};
```




