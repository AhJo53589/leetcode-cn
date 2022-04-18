# `（简单）` [LCP 50.WHnhjV 宝石补给](https://leetcode-cn.com/problems/WHnhjV/)

### 题目描述
<p>欢迎各位勇者来到力扣新手村，在开始试炼之前，请各位勇者先进行「宝石补给」。</p>
<p>每位勇者初始都拥有一些能量宝石， <code>gem[i]</code> 表示第 <code>i</code> 位勇者的宝石数量。现在这些勇者们进行了一系列的赠送，<code>operations[j] = [x, y]</code> 表示在第 <code>j</code> 次的赠送中 第 <code>x</code> 位勇者将自己一半的宝石（需向下取整）赠送给第 <code>y</code> 位勇者。</p>
<p>在完成所有的赠送后，请找到拥有<strong>最多</strong>宝石的勇者和拥有<strong>最少</strong>宝石的勇者，并返回他们二者的宝石数量<strong>之差</strong>。</p>
<p><strong>注意：</strong></p>
<ul>
<li>赠送将按顺序逐步进行。</li>
</ul>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>gem = [3,1,2], operations = [[0,2],[2,1],[2,0]]</code></p>
<p>输出：<code>2</code></p>
<p>解释：<br>
第 1 次操作，勇者 <code>0</code> 将一半的宝石赠送给勇者 <code>2</code>， <code>gem = [2,1,3]</code><br>
第 2 次操作，勇者 <code>2</code> 将一半的宝石赠送给勇者 <code>1</code>， <code>gem = [2,2,2]</code><br>
第 3 次操作，勇者 <code>2</code> 将一半的宝石赠送给勇者 <code>0</code>， <code>gem = [3,2,1]</code><br>
返回 3 - 1 = 2</p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>gem = [100,0,50,100], operations = [[0,2],[0,1],[3,0],[3,0]]</code></p>
<p>输出：<code>75</code></p>
<p>解释：<br>
第 1 次操作，勇者 <code>0</code> 将一半的宝石赠送给勇者 <code>2</code>， <code>gem = [50,0,100,100]</code><br>
第 2 次操作，勇者 <code>0</code> 将一半的宝石赠送给勇者 <code>1</code>， <code>gem = [25,25,100,100]</code><br>
第 3 次操作，勇者 <code>3</code> 将一半的宝石赠送给勇者 <code>0</code>， <code>gem = [75,25,100,50]</code><br>
第 4 次操作，勇者 <code>3</code> 将一半的宝石赠送给勇者 <code>0</code>， <code>gem = [100,25,100,25]</code><br>
返回 100 - 25 = 75</p>
</blockquote>
<p><strong>示例 3：</strong></p>
<blockquote>
<p>输入：<code>gem = [0,0,0,0], operations = [[1,2],[3,1],[1,2]]</code></p>
<p>输出：<code>0</code></p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>2 &lt;= gem.length &lt;= 10^3</code></li>
<li><code>0 &lt;= gem[i] &lt;= 10^3</code></li>
<li><code>0 &lt;= operations.length &lt;= 10^4</code></li>
<li><code>operations[i].length == 2</code></li>
<li><code>0 &lt;= operations[i][0], operations[i][1] &lt; gem.length</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for (auto& op : operations) {
            int x = gem[op[0]] / 2;
            gem[op[0]] -= x;
            gem[op[1]] += x;
        }
        int _max = *max_element(gem.begin(), gem.end());
        int _min = *min_element(gem.begin(), gem.end());
        return _max - _min;
    }
};
```




