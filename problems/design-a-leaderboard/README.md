# `（中等）` [5097.design-a-leaderboard 力扣排行榜](https://leetcode-cn.com/problems/design-a-leaderboard/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-12/problems/design-a-leaderboard/)

### 题目描述
<p>新一轮的「力扣杯」编程大赛即将启动，为了动态显示参赛者的得分数据，需要设计一个排行榜 Leaderboard。</p>

<p>请你帮忙来设计这个&nbsp;<code>Leaderboard</code> 类，使得它有如下&nbsp;3 个函数：</p>

<ol>
	<li><code>addScore(playerId, score)</code>：

	<ul>
		<li>假如参赛者已经在排行榜上，就给他的当前得分增加&nbsp;<code>score</code>&nbsp;点分值并更新排行。</li>
		<li>假如该参赛者不在排行榜上，就把他添加到榜单上，并且将分数设置为&nbsp;<code>score</code>。</li>
	</ul>
	</li>
	<li><code>top(K)</code>：返回前&nbsp;<code>K</code>&nbsp;名参赛者的&nbsp;<strong>得分总和</strong>。</li>
	<li><code>reset(playerId)</code>：将指定参赛者的成绩清零。题目保证在调用此函数前，该参赛者已有成绩，并且在榜单上。</li>
</ol>

<p>请注意，在初始状态下，排行榜是空的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入： </strong>
["Leaderboard","addScore","addScore","addScore","addScore","addScore","top","reset","reset","addScore","top"]
[[],[1,73],[2,56],[3,39],[4,51],[5,4],[1],[1],[2],[2,51],[3]]
<strong>输出：</strong>
[null,null,null,null,null,null,73,null,null,null,141]

<strong>解释： </strong>
Leaderboard leaderboard = new Leaderboard ();
leaderboard.addScore(1,73);   // leaderboard = [[1,73]];
leaderboard.addScore(2,56);   // leaderboard = [[1,73],[2,56]];
leaderboard.addScore(3,39);   // leaderboard = [[1,73],[2,56],[3,39]];
leaderboard.addScore(4,51);   // leaderboard = [[1,73],[2,56],[3,39],[4,51]];
leaderboard.addScore(5,4);    // leaderboard = [[1,73],[2,56],[3,39],[4,51],[5,4]];
leaderboard.top(1);           // returns 73;
leaderboard.reset(1);         // leaderboard = [[2,56],[3,39],[4,51],[5,4]];
leaderboard.reset(2);         // leaderboard = [[3,39],[4,51],[5,4]];
leaderboard.addScore(2,51);   // leaderboard = [[2,51],[3,39],[4,51],[5,4]];
leaderboard.top(3);           // returns 141 = 51 + 51 + 39;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= playerId, K &lt;= 10000</code></li>
	<li>题目保证&nbsp;<code>K</code>&nbsp;小于或等于当前参赛者的数量</li>
	<li><code>1 &lt;= score&nbsp;&lt;= 100</code></li>
	<li>最多进行&nbsp;<code>1000</code>&nbsp;次函数调用</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
class Leaderboard 
{
public:
	Leaderboard()
	{

	}

	void addScore(int playerId, int score)
	{
		if (lb_id.count(playerId) == 0)
		{
			lb_score.push_back({ playerId, score });
			lb_id[playerId] = lb_score.size() - 1;
		}
		else
		{
			lb_score[lb_id[playerId]].second += score;
		}

		while (true)
		{
			size_t i = lb_id[playerId];
			if (i == 0) break;

			if (lb_score[i].second > lb_score[i - 1].second)
			{
				swap(lb_id[playerId], lb_id[lb_score[i - 1].first]);
				swap(lb_score[i], lb_score[i - 1]);
			}
			else
			{
				break;
			}
		}
	}

	int top(int K) 
	{
		int sum = 0;
		for (int i = 0; i < K; i++)
		{
			sum += lb_score[i].second;
		}
		return sum;
	}

	void reset(int playerId)
	{
		for (size_t i = lb_id[playerId] + 1; i < lb_score.size(); i++)
		{
			lb_id[lb_score[i].first]--;
		}
		auto del = lb_score.begin() + lb_id[playerId];
		lb_score.erase(del);
		lb_id.erase(playerId);
	}

private:
	vector<pair<int, int>> lb_score;
	unordered_map<int, size_t> lb_id;
};
```




