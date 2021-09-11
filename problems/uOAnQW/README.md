# `（简单）` [LCP 40.uOAnQW 心算挑战](https://leetcode-cn.com/problems/uOAnQW/)

[contest](https://leetcode-cn.com/contest/season/2021-fall/problems/uOAnQW/)

### 题目描述
<div class="css-330z23" style="padding: 0px; margin: 13px 0px;"><p>「力扣挑战赛」心算项目的挑战比赛中，要求选手从 <code>N</code> 张卡牌中选出 <code>cnt</code> 张卡牌，若这 <code>cnt</code> 张卡牌数字总和为偶数，则选手成绩「有效」且得分为 <code>cnt</code> 张卡牌数字总和。<br>
给定数组 <code>cards</code> 和 <code>cnt</code>，其中 <code>cards[i]</code> 表示第 <code>i</code> 张卡牌上的数字。 请帮参赛选手计算最大的有效得分。若不存在获取有效得分的卡牌方案，则返回 0。</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>cards = [1,2,8,9], cnt = 3</code></p>
<p>输出：<code>18</code></p>
<p>解释：选择数字为 1、8、9 的这三张卡牌，此时可获得最大的有效得分 1+8+9=18。</p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>cards = [3,3,1], cnt = 1</code></p>
<p>输出：<code>0</code></p>
<p>解释：不存在获取有效得分的卡牌方案。</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>1 &lt;= cnt &lt;= cards.length &lt;= 10^5</code></li>
<li><code>1 &lt;= cards[i] &lt;= 1000</code></li>
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
    int maxmiumScore(vector<int>& cards, int cnt) {
        vector<int> a;
        vector<int> b;

        for (auto n : cards) {
            if (n % 2 == 0) {
                a.push_back(n);
            }
            else {
                b.push_back(n);
            }
        }
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());

        int ans = 0;
        int i = 0;
        int j = 0;
        
        if (cnt % 2 == 1) {
            if (a.size() == 0) return 0;
            ans += a[i++];
            cnt--;
        }

        while (cnt > 0) {
            if (i + 1 < a.size() && j + 1 < b.size()) {
                int aa = a[i] + a[i + 1];
                int bb = b[j] + b[j + 1];
                ans += max(aa, bb);
                i += (aa > bb) ? 2 : 0;
                j += (aa > bb) ? 0 : 2;
            }
            else if (i + 1 < a.size()) {
                ans += a[i] + a[i + 1];
                i += 2;
            }
            else if (j + 1 < b.size()) {
                ans += b[j] + b[j + 1];
                j += 2;
            }
            else {
                return 0;
            }
            cnt -= 2;
        }

        return ans;
    }
};
```




