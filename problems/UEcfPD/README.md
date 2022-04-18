# `（简单）` [LCP 51.UEcfPD 烹饪料理](https://leetcode-cn.com/problems/UEcfPD/)

### 题目描述
<p>欢迎各位勇者来到力扣城，城内设有烹饪锅供勇者制作料理，为自己恢复状态。</p>
<p>勇者背包内共有编号为 <code>0 ~ 4</code> 的五种食材，其中 <code>materials[j]</code> 表示第 <code>j</code> 种食材的数量。通过这些食材可以制作若干料理，<code>cookbooks[i][j]</code> 表示制作第 <code>i</code> 种料理需要第 <code>j</code> 种食材的数量，而 <code>attribute[i] = [x,y]</code> 表示第 <code>i</code> 道料理的美味度 <code>x</code> 和饱腹感 <code>y</code>。</p>
<p>在饱腹感不小于 <code>limit</code> 的情况下，请返回勇者可获得的最大美味度。如果无法满足饱腹感要求，则返回 <code>-1</code>。</p>
<p><strong>注意：</strong></p>
<ul>
<li>每种料理只能制作一次。</li>
</ul>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>materials = [3,2,4,1,2]</code><br>
<code>cookbooks = [[1,1,0,1,2],[2,1,4,0,0],[3,2,4,1,0]]</code><br>
<code>attribute = [[3,2],[2,4],[7,6]]</code><br>
<code>limit = 5</code></p>
<p>输出：<code>7</code></p>
<p>解释：<br>
食材数量可以满足以下两种方案：<br>
方案一：制作料理 0 和料理 1，可获得饱腹感 2+4、美味度 3+2<br>
方案二：仅制作料理 2， 可饱腹感为 6、美味度为 7<br>
因此在满足饱腹感的要求下，可获得最高美味度 7</p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>materials = [10,10,10,10,10]</code><br>
<code>cookbooks = [[1,1,1,1,1],[3,3,3,3,3],[10,10,10,10,10]]</code><br>
<code>attribute = [[5,5],[6,6],[10,10]]</code><br>
<code>limit = 1</code></p>
<p>输出：<code>11</code></p>
<p>解释：通过制作料理 0 和 1，可满足饱腹感，并获得最高美味度 11</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>materials.length == 5</code></li>
<li><code>1 &lt;= cookbooks.length == attribute.length &lt;= 8</code></li>
<li><code>cookbooks[i].length == 5</code></li>
<li><code>attribute[i].length == 2</code></li>
<li><code>0 &lt;= materials[i], cookbooks[i][j], attribute[i][j] &lt;= 20</code></li>
<li><code>1 &lt;= limit &lt;= 100</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int perfectMenu(vector<int>& materials, vector<vector<int>>& cookbooks, vector<vector<int>>& attribute, int limit) {
        int ans = -1;

        for (int i = 0; i < (1 << cookbooks.size()); i++) {
            vector<int> temp = materials;
            vector<int> att = { 0, 0 };

            for (int j = 0; j < cookbooks.size(); j++) {
                if ((i & (1 << j)) == 0) continue;
                if (!CheckEnough(temp, cookbooks[j])) continue;
                Cook(temp, cookbooks[j], att, attribute[j]);
            }

            if (att[1] >= limit) {
                ans = max(ans, att[0]);
            }
        }

        return ans;
    }

    bool CheckEnough(vector<int>& materials, vector<int>& book) {
        for (int i = 0; i < book.size(); i++) {
            if (book[i] > materials[i]) return false;
        }
        return true;
    }

    void Cook(vector<int>& materials, vector<int>& book, vector<int>& att, vector<int>& attribute) {
        for (int i = 0; i < book.size(); i++) {
            materials[i] -= book[i];
        }
        att[0] += attribute[0];
        att[1] += attribute[1];
    }
};
```




