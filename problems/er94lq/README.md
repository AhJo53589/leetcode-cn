# `（中等）` [LCP 23.er94lq 魔术排列](https://leetcode-cn.com/problems/er94lq/)

### 题目描述
<p>秋日市集上，魔术师邀请小扣与他互动。魔术师的道具为分别写有数字 <code>1~N</code> 的 <code>N</code> 张卡牌，然后请小扣思考一个 <code>N</code> 张卡牌的排列 <code>target</code>。</p>
<p>魔术师的目标是找到一个数字 k（k &gt;= 1），使得初始排列顺序为 <code>1~N</code> 的卡牌经过特殊的洗牌方式最终变成小扣所想的排列 <code>target</code>，特殊的洗牌方式为：</p>
<ul>
<li>第一步，魔术师将当前位于 <strong>偶数位置</strong> 的卡牌（下标自 1 开始），保持 <strong>当前排列顺序</strong> 放在位于 <strong>奇数位置</strong> 的卡牌之前。例如：将当前排列 [1,2,3,4,5] 位于偶数位置的 [2,4] 置于奇数位置的 [1,3,5] 前，排列变为 [2,4,1,3,5]；</li>
<li>第二步，若当前卡牌数量小于等于 <code>k</code>，则魔术师按排列顺序取走全部卡牌；若当前卡牌数量大于 <code>k</code>，则取走前 <code>k</code> 张卡牌，剩余卡牌继续重复这两个步骤，直至所有卡牌全部被取走；</li>
</ul>
<p>卡牌按照魔术师取走顺序构成的新排列为「魔术取数排列」，请返回是否存在这个数字 k 使得「魔术取数排列」恰好就是 <code>target</code>，从而让小扣感到大吃一惊。</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>target = [2,4,3,1,5]</code></p>
<p>输出：<code>true</code></p>
<p>解释：排列 target 长度为 5，初始排列为：1,2,3,4,5。我们选择 k = 2：<br>
第一次：将当前排列 [1,2,3,4,5] 位于偶数位置的 [2,4] 置于奇数位置的 [1,3,5] 前，排列变为 [2,4,1,3,5]。取走前 2 张卡牌 2,4，剩余 [1,3,5]；<br>
第二次：将当前排列 [1,3,5] 位于偶数位置的 [3] 置于奇数位置的 [1,5] 前，排列变为 [3,1,5]。取走前 2 张 3,1，剩余 [5]；<br>
第三次：当前排列为 [5]，全部取出。<br>
最后，数字按照取出顺序构成的「魔术取数排列」2,4,3,1,5 恰好为 target。</p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>target = [5,4,3,2,1]</code></p>
<p>输出：<code>false</code></p>
<p>解释：无法找到一个数字 k 可以使「魔术取数排列」恰好为 target。</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>1 &lt;= target.length = N &lt;= 5000</code></li>
<li>题目保证 <code>target</code> 是 <code>1~N</code> 的一个排列。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/er94lq/solution/er94lq-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    bool isMagic(vector<int>& target) {
        vector<int> cards;
        for (int i = 0; i < target.size(); i++) {
            cards.push_back(i + 1);
        }
        magicSort(cards, 0);

        int maxk = sameCnt(cards, target, 0);
        for (int i = maxk; i > 0; i--) {
            if (check(cards, target, i)) return true;
        }
        return false;
    }

    bool check(vector<int> cards, vector<int>& target, int k) {
        int start = k;
        while (start < (int)cards.size() - 1) {
            magicSort(cards, start);
            if (sameCnt(cards, target, start) < k) break;
            start += k;
        }
        return sameCnt(cards, target, 0) == target.size();
    }

    void magicSort(vector<int>& v, int start) {
        vector<int> temp;
        for (int i = 0; i < start; i++) {
            temp.push_back(v[i]);
        }
        for (int i = start + 1; i < v.size(); i += 2) {
            temp.push_back(v[i]);
        }
        for (int i = start; i < v.size(); i += 2) {
            temp.push_back(v[i]);
        }
        swap(temp, v);
    }

    int sameCnt(vector<int>& v, vector<int>& target, int start) {
        for (int i = start; i < target.size(); i++) {
            if (v[i] != target[i]) return i - start;
        }
        return target.size() - start;
    }
};
```




