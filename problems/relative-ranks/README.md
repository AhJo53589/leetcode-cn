# `（简单）` [506.relative-ranks 相对名次](https://leetcode-cn.com/problems/relative-ranks/)

### 题目描述
<p>给你一个长度为 <code>n</code> 的整数数组 <code>score</code> ，其中 <code>score[i]</code> 是第 <code>i</code> 位运动员在比赛中的得分。所有得分都 <strong>互不相同</strong> 。</p>

<p>运动员将根据得分 <strong>决定名次</strong> ，其中名次第 <code>1</code> 的运动员得分最高，名次第 <code>2</code> 的运动员得分第 <code>2</code> 高，依此类推。运动员的名次决定了他们的获奖情况：</p>

<ul>
	<li>名次第 <code>1</code> 的运动员获金牌 <code>"Gold Medal"</code> 。</li>
	<li>名次第 <code>2</code> 的运动员获银牌 <code>"Silver Medal"</code> 。</li>
	<li>名次第 <code>3</code> 的运动员获铜牌 <code>"Bronze Medal"</code> 。</li>
	<li>从名次第 <code>4</code> 到第 <code>n</code> 的运动员，只能获得他们的名次编号（即，名次第 <code>x</code> 的运动员获得编号 <code>"x"</code>）。</li>
</ul>

<p>使用长度为 <code>n</code> 的数组 <code>answer</code> 返回获奖，其中 <code>answer[i]</code> 是第 <code>i</code> 位运动员的获奖情况。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>score = [5,4,3,2,1]
<strong>输出：</strong>["Gold Medal","Silver Medal","Bronze Medal","4","5"]
<strong>解释：</strong>名次为 [1<sup>st</sup>, 2<sup>nd</sup>, 3<sup>rd</sup>, 4<sup>th</sup>, 5<sup>th</sup>] 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>score = [10,3,8,9,4]
<strong>输出：</strong>["Gold Medal","5","Bronze Medal","Silver Medal","4"]
<strong>解释：</strong>名次为 [1<sup>st</sup>, 5<sup>th</sup>, 3<sup>rd</sup>, 2<sup>nd</sup>, 4<sup>th</sup>] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == score.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= score[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>score</code> 中的所有值 <strong>互不相同</strong></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> name = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        
        vector<pair<int, int>> ranking;
        for (int i = 0; i < score.size(); i++) {
            ranking.push_back({score[i], i});
        }
        sort(ranking.rbegin(), ranking.rend());

        vector<string> ans(score.size());
        for (int rk = 0; rk < ranking.size(); rk++) {
            ans[ranking[rk].second] = (rk < 3) ? name[rk] : to_string(rk + 1);
        }
        return ans;
    }
};
```




