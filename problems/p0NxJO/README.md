# `（中等）` [LCP_30.p0NxJO 魔塔游戏](https://leetcode-cn.com/problems/p0NxJO/)

[contest](https://leetcode-cn.com/contest/season/2021-spring/problems/p0NxJO/)

### 题目描述
<div class="css-1708ckn" style="padding: 0px; margin: 13px 0px;"><p>小扣当前位于魔塔游戏第一层，共有 <code>N</code> 个房间，编号为 <code>0 ~ N-1</code>。每个房间的补血道具/怪物对于血量影响记于数组 <code>nums</code>，其中正数表示道具补血数值，即血量增加对应数值；负数表示怪物造成伤害值，即血量减少对应数值；<code>0</code> 表示房间对血量无影响。</p>
<p><strong>小扣初始血量为 1，且无上限</strong>。假定小扣原计划按房间编号升序访问所有房间补血/打怪，<strong>为保证血量始终为正值</strong>，小扣需对房间访问顺序进行调整，<strong>每次仅能将一个怪物房间（负数的房间）调整至访问顺序末尾</strong>。请返回小扣最少需要调整几次，才能顺利访问所有房间。若调整顺序也无法访问完全部房间，请返回 -1。</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>nums = [100,100,100,-250,-60,-140,-50,-50,100,150]</code></p>
<p>输出：<code>1</code></p>
<p>解释：初始血量为 1。至少需要将 nums[3] 调整至访问顺序末尾以满足要求。</p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>nums = [-200,-300,400,0]</code></p>
<p>输出：<code>-1</code></p>
<p>解释：调整访问顺序也无法完成全部房间的访问。</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>1 &lt;= nums.length &lt;= 10^5</code></li>
<li><code>-10^5 &lt;= nums[i] &lt;= 10^5</code></li>
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
    int magicTower(vector<int>& nums) {
        int ans = 0;
        long long sum = 1;
        long long last = 0;
        priority_queue<long long> pq;
        for (auto n : nums) {
            sum += n;
            if (n < 0) {
                pq.push(-n);
            }

            if (sum <= 0) {
                while (sum <= 0 && !pq.empty()) {
                    sum += pq.top();
                    last -= pq.top();
                    pq.pop();
                    ans++;
                }
            }
        }
        return sum + last > 0 ? ans : -1;
    }
};
```




