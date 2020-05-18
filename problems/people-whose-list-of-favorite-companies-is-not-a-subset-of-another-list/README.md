# `（中等）` [1452.people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list 收藏清单](https://leetcode-cn.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/)

[contest](https://leetcode-cn.com/contest/weekly-contest-189/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/)

### 题目描述
<p>给你一个数组 <code>favoriteCompanies</code> ，其中 <code>favoriteCompanies[i]</code> 是第 <code>i</code> 名用户收藏的公司清单（<strong>下标从 0 开始</strong>）。</p>

<p>请找出不是其他任何人收藏的公司清单的子集的收藏清单，并返回该清单下标<em>。</em>下标需要按升序排列<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>favoriteCompanies = [["leetcode","google","facebook"],["google","microsoft"],["google","facebook"],["google"],["amazon"]]
<strong>输出：</strong>[0,1,4] 
<strong>解释：</strong>
favoriteCompanies[2]=["google","facebook"] 是 favoriteCompanies[0]=["leetcode","google","facebook"] 的子集。
favoriteCompanies[3]=["google"] 是 favoriteCompanies[0]=["leetcode","google","facebook"] 和 favoriteCompanies[1]=["google","microsoft"] 的子集。
其余的收藏清单均不是其他任何人收藏的公司清单的子集，因此，答案为 [0,1,4] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>favoriteCompanies = [["leetcode","google","facebook"],["leetcode","amazon"],["facebook","google"]]
<strong>输出：</strong>[0,1] 
<strong>解释：</strong>favoriteCompanies[2]=["facebook","google"] 是 favoriteCompanies[0]=["leetcode","google","facebook"] 的子集，因此，答案为 [0,1] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>favoriteCompanies = [["leetcode"],["google"],["facebook"],["amazon"]]
<strong>输出：</strong>[0,1,2,3]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <=&nbsp;favoriteCompanies.length <= 100</code></li>
	<li><code>1 <=&nbsp;favoriteCompanies[i].length <= 500</code></li>
	<li><code>1 <=&nbsp;favoriteCompanies[i][j].length <= 20</code></li>
	<li><code>favoriteCompanies[i]</code> 中的所有字符串 <strong>各不相同</strong> 。</li>
	<li>用户收藏的公司清单也 <strong>各不相同</strong> ，也就是说，即便我们按字母顺序排序每个清单， <code>favoriteCompanies[i] != favoriteCompanies[j] </code>仍然成立。</li>
	<li>所有字符串仅包含小写英文字母。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/solution/favorite-companies-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        for (auto& f : favoriteCompanies) {
            sort(f.begin(), f.end());
        }

        map<int, vector<int>> mapSizeIndex;
        for (int i = 0; i < favoriteCompanies.size(); i++) {
            mapSizeIndex[favoriteCompanies[i].size()].push_back(i);
        }

        vector<int> ans;
        for (auto it = mapSizeIndex.rbegin(); it != mapSizeIndex.rend(); it++) {
            for (auto& p : it->second) {
                if (it != mapSizeIndex.rbegin() && checkIncludes(favoriteCompanies, ans, p)) continue;
                ans.push_back(p);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }

    bool checkIncludes(vector<vector<string>>& fc, vector<int>& ans, int p) {
        for (auto i : ans) {
            if (includes(fc[i].begin(), fc[i].end(), fc[p].begin(), fc[p].end())) return true;
        }
        return false;
    }    
};
```




