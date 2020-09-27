# `（中等）` [5524.maximum-profit-of-operating-a-centennial-wheel 经营摩天轮的最大利润](https://leetcode-cn.com/problems/maximum-profit-of-operating-a-centennial-wheel/)

[contest](https://leetcode-cn.com/contest/weekly-contest-208/problems/maximum-profit-of-operating-a-centennial-wheel/)

### 题目描述
<p>你正在经营一座摩天轮，该摩天轮共有 <strong>4 个座舱</strong> ，每个座舱<strong> 最多可以容纳 4 位游客</strong> 。你可以 <strong>逆时针</strong>&nbsp;轮转座舱，但每次轮转都需要支付一定的运行成本 <code>runningCost</code> 。摩天轮每次轮转都恰好转动 1 / 4 周。</p>

<p>给你一个长度为 <code>n</code> 的数组 <code>customers</code> ， <code>customers[i]</code> 是在第 <code>i</code> 次轮转（下标从 0 开始）之前到达的新游客的数量。这也意味着你必须在新游客到来前轮转 <code>i</code> 次。每位游客在登上离地面最近的座舱前都会支付登舱成本 <code>boardingCost</code> ，一旦该座舱再次抵达地面，他们就会离开座舱结束游玩。</p>

<p>你可以随时停下摩天轮，即便是 <strong>在服务所有游客之前</strong> 。如果你决定停止运营摩天轮，为了保证所有游客安全着陆，<strong>将免费进行</strong><strong>所有后续轮转</strong>&nbsp;。注意，如果有超过 4 位游客在等摩天轮，那么只有 4 位游客可以登上摩天轮，其余的需要等待 <strong>下一次轮转</strong> 。</p>

<p>返回最大化利润所需执行的 <strong>最小轮转次数</strong> 。 如果不存在利润为正的方案，则返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="height: 291px; width: 906px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/09/26/wheeldiagram12.png" alt=""></p>

<pre><strong>输入：</strong>customers = [8,3], boardingCost = 5, runningCost = 6
<strong>输出：</strong>3
<strong>解释：</strong>座舱上标注的数字是该座舱的当前游客数。
1. 8 位游客抵达，4 位登舱，4 位等待下一舱，摩天轮轮转。当前利润为 4 * $5 - 1 * $6 = $14 。
2. 3 位游客抵达，4 位在等待的游客登舱，其他 3 位等待，摩天轮轮转。当前利润为 8 * $5 - 2 * $6 = $28 。
3. 最后 3 位游客登舱，摩天轮轮转。当前利润为 11 * $5 - 3 * $6 = $37 。
轮转 3 次得到最大利润，最大利润为 $37 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>customers = [10,9,6], boardingCost = 6, runningCost = 4
<strong>输出：</strong>7
<strong>解释：</strong>
1. 10 位游客抵达，4 位登舱，6 位等待下一舱，摩天轮轮转。当前利润为 4 * $6 - 1 * $4 = $20 。
2. 9 位游客抵达，4 位登舱，11 位等待（2 位是先前就在等待的，9 位新加入等待的），摩天轮轮转。当前利润为 8 * $6 - 2 * $4 = $40 。
3. 最后 6 位游客抵达，4 位登舱，13 位等待，摩天轮轮转。当前利润为 12 * $6 - 3 * $4 = $60 。
4. 4 位登舱，9 位等待，摩天轮轮转。当前利润为 * $6 - 4 * $4 = $80 。
5. 4 位登舱，5 位等待，摩天轮轮转。当前利润为 20 * $6 - 5 * $4 = $100 。
6. 4 位登舱，1 位等待，摩天轮轮转。当前利润为 24 * $6 - 6 * $4 = $120 。
7. 1 位登舱，摩天轮轮转。当前利润为 25 * $6 - 7 * $4 = $122 。
轮转 7 次得到最大利润，最大利润为$122 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>customers = [3,4,0,5,1], boardingCost = 1, runningCost = 92
<strong>输出：</strong>-1
<strong>解释：</strong>
1. 3 位游客抵达，3 位登舱，0 位等待，摩天轮轮转。当前利润为 3 * $1 - 1 * $92 = -$89 。
2. 4 位游客抵达，4 位登舱，0 位等待，摩天轮轮转。当前利润为 is 7 * $1 - 2 * $92 = -$177 。
3. 0 位游客抵达，0 位登舱，0 位等待，摩天轮轮转。当前利润为 7 * $1 - 3 * $92 = -$269 。
4. 5 位游客抵达，4 位登舱，1 位等待，摩天轮轮转。当前利润为 12 * $1 - 4 * $92 = -$356 。
5. 1 位游客抵达，2 位登舱，0 位等待，摩天轮轮转。当前利润为 13 * $1 - 5 * $92 = -$447 。
利润永不为正，所以返回 -1 。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>customers = [10,10,6,4,7], boardingCost = 3, runningCost = 8
<strong>输出：</strong>9
<strong>解释：</strong>
1. 10 位游客抵达，4 位登舱，6 位等待，摩天轮轮转。当前利润为 4 * $3 - 1 * $8 = $4 。
2. 10 位游客抵达，4 位登舱，12 位等待，摩天轮轮转。当前利润为 8 * $3 - 2 * $8 = $8 。
3. 6 位游客抵达，4 位登舱，14 位等待，摩天轮轮转。当前利润为 12 * $3 - 3 * $8 = $12 。
4. 4 位游客抵达，4 位登舱，14 位等待，摩天轮轮转。当前利润为 16 * $3 - 4 * $8 = $16 。
5. 7 位游客抵达，4 位登舱，17 位等待，摩天轮轮转。当前利润为 20 * $3 - 5 * $8 = $20 。
6. 4 位登舱，13 位等待，摩天轮轮转。当前利润为 24 * $3 - 6 * $8 = $24 。
7. 4 位登舱，9 位等待，摩天轮轮转。当前利润为 28 * $3 - 7 * $8 = $28 。
8. 4 位登舱，5 位等待，摩天轮轮转。当前利润为 32 * $3 - 8 * $8 = $32 。
9. 4 位登舱，1 位等待，摩天轮轮转。当前利润为 36 * $3 - 9 * $8 = $36 。
​​​​​​​10. 1 位登舱，0 位等待，摩天轮轮转。当前利润为 37 * $3 - 10 * $8 = $31 。
轮转 9 次得到最大利润，最大利润为 $36 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == customers.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= customers[i] &lt;= 50</code></li>
	<li><code>1 &lt;= boardingCost, runningCost &lt;= 100</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/maximum-profit-of-operating-a-centennial-wheel/solution/maximum-profit-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int profit = 0;
        int maxProfit = 0;
        int ans = -1;
        int waitCnt = 0;
        
        int turn = 0;
        while (waitCnt != 0 || turn < customers.size()) {
            // cout << "--[turn]-- " << turn << endl;
            waitCnt += (turn < customers.size()) ? customers[turn] : 0;
            // cout << "waitCnt = " << waitCnt << endl;
            int upCnt = min(waitCnt, 4);
            // cout << "upCnt = " << upCnt << endl;
            waitCnt -= upCnt;
            // cout << "waitCnt = " << waitCnt << endl;
            profit += upCnt * boardingCost - runningCost;
            // cout << "profit = " << profit << endl;
            if (profit > maxProfit) {
                maxProfit = profit;
                ans = turn + 1;
                // cout << "ans = " << ans << endl;
            }
            turn++;
        }
        
        return ans;
    }
};
```




