# `（中等）` [1366.rank-teams-by-votes 通过投票对团队排名](https://leetcode-cn.com/problems/rank-teams-by-votes/)

[contest](https://leetcode-cn.com/contest/weekly-contest-178/problems/rank-teams-by-votes/)

### 题目描述
<p>现在有一个特殊的排名系统，依据参赛团队在投票人心中的次序进行排名，每个投票者都需要按从高到低的顺序对参与排名的所有团队进行排位。</p>
<p>排名规则如下：</p>
<ul>
	<li>参赛团队的排名次序依照其所获「排位第一」的票的多少决定。如果存在多个团队并列的情况，将继续考虑其「排位第二」的票的数量。以此类推，直到不再存在并列的情况。</li>
	<li>如果在考虑完所有投票情况后仍然出现并列现象，则根据团队字母的字母顺序进行排名。</li>
</ul>

<p>给你一个字符串数组&nbsp;<code>votes</code> 代表全体投票者给出的排位情况，请你根据上述排名规则对所有参赛团队进行排名。</p>
<p>请你返回能表示按排名系统 <strong>排序后</strong> 的所有团队排名的字符串。</p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<pre><strong>输入：</strong>votes = ["ABC","ACB","ABC","ACB","ACB"]
<strong>输出：</strong>"ACB"
<strong>解释：</strong>A 队获得五票「排位第一」，没有其他队获得「排位第一」，所以 A 队排名第一。
B 队获得两票「排位第二」，三票「排位第三」。
C 队获得三票「排位第二」，两票「排位第三」。
由于 C 队「排位第二」的票数较多，所以 C 队排第二，B 队排第三。
</pre>

<p><strong>示例 2：</strong></p>
<pre><strong>输入：</strong>votes = ["WXYZ","XYZW"]
<strong>输出：</strong>"XWYZ"
<strong>解释：</strong>X 队在并列僵局打破后成为排名第一的团队。X 队和 W 队的「排位第一」票数一样，但是 X 队有一票「排位第二」，而 W 没有获得「排位第二」。 
</pre>

<p><strong>示例 3：</strong></p>
<pre><strong>输入：</strong>votes = ["ZMNAGUEDSJYLBOPHRQICWFXTVK"]
<strong>输出：</strong>"ZMNAGUEDSJYLBOPHRQICWFXTVK"
<strong>解释：</strong>只有一个投票者，所以排名完全按照他的意愿。
</pre>

<p><strong>示例 4：</strong></p>
<pre><strong>输入：</strong>votes = ["BCA","CAB","CBA","ABC","ACB","BAC"]
<strong>输出：</strong>"ABC"
<strong>解释：</strong> 
A 队获得两票「排位第一」，两票「排位第二」，两票「排位第三」。
B 队获得两票「排位第一」，两票「排位第二」，两票「排位第三」。
C 队获得两票「排位第一」，两票「排位第二」，两票「排位第三」。
完全并列，所以我们需要按照字母升序排名。
</pre>

<p><strong>示例 5：</strong></p>
<pre><strong>输入：</strong>votes = ["M","M","M","M"]
<strong>输出：</strong>"M"
<strong>解释：</strong>只有 M 队参赛，所以它排名第一。
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li><code>1 &lt;= votes.length &lt;= 1000</code></li>
	<li><code>1 &lt;= votes[i].length &lt;= 26</code></li>
	<li><code>votes[i].length ==&nbsp;votes[j].length</code> for&nbsp;<code>0 &lt;= i, j &lt; votes.length</code></li>
	<li><code>votes[i][j]</code>&nbsp;是英文 <strong>大写</strong> 字母</li>
	<li><code>votes[i]</code>&nbsp;中的所有字母都是唯一的</li>
	<li><code>votes[0]</code>&nbsp;中出现的所有字母 <strong>同样也</strong> 出现在&nbsp;<code>votes[j]</code>&nbsp;中，其中&nbsp;<code>1 &lt;= j &lt; votes.length</code></li>
</ul>

​            

---
### 思路
```
因为只有A-Z 26个队伍，那排名也就只有26个
完全可以弄一个 [27][27]的数组存放，每个队伍的排名数据

当然，还有额外条件，如果全部的名次都相同，会按照队伍的字符排序，
既然这样的话，我们就将每个队伍的最后一个空格，填上 26-(队伍名-'A')
如果是A队的话 就是 26
B队就是 25

sort里面的默认排序是less，我们需要使用greater
如果在排二维数组的时候，它的特性就是首先对比第二维数组中的第一个数的大小，如果相同就回去比第二个，第三个.....
```



### 答题
``` C++
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> dw(27, vector<int>(27, 0));
        string res;
        for (auto p : votes) {
            for (int i = 0; i < p.length(); i++) {
                //i是名次 p[i]是选择的队伍
                dw[p[i] - 'A'][i] ++;
                dw[p[i] - 'A'].back() = 26 - (p[i] - 'A');
            }
        }
        sort(dw.begin(), dw.end(), greater<vector<int>>());

        for (int i = 0; i < dw.size(); i++) {
            if (dw[i].back() != 0)
                res.push_back(26 - (dw[i].back() - 'A'));
        }
        return res;

    }
};
```




