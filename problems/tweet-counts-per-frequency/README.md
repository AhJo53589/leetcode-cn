# `（中等）` [5334.tweet-counts-per-frequency 推文计数](https://leetcode-cn.com/problems/tweet-counts-per-frequency/)

[contest](https://leetcode-cn.com/contest/weekly-contest-175/problems/tweet-counts-per-frequency/)

### 题目描述
<p>请你实现一个能够支持以下两种方法的推文计数类&nbsp;<code>TweetCounts</code>：</p>

<p>1.<code> recordTweet(string tweetName, int time)</code></p>

<ul>
	<li>记录推文发布情况：用户&nbsp;<code>tweetName</code>&nbsp;在&nbsp;<code>time</code>（以 <strong>秒</strong>&nbsp;为单位）时刻发布了一条推文。</li>
</ul>

<p>2.<code> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime)</code></p>

<ul>
	<li>返回从开始时间&nbsp;<code>startTime</code>（以 <strong>秒</strong> 为单位）到结束时间&nbsp;<code>endTime</code>（以 <strong>秒</strong> 为单位）内，每 <strong>分&nbsp;</strong><em><strong>minute</strong>，</em><strong>时&nbsp;<em>hour </em></strong>或者 <strong>日<em>&nbsp;day&nbsp;</em></strong>（取决于&nbsp;<code>freq</code>）内指定用户&nbsp;<code>tweetName</code>&nbsp;发布的推文总数。</li>
	<li><code>freq</code>&nbsp;的值始终为 <strong>分&nbsp;</strong><em><strong>minute</strong>，</em><strong>时</strong><em><strong> hour</strong>&nbsp;</em>或者<em>&nbsp;</em><strong>日</strong><em><strong> day</strong>&nbsp;</em>之一，表示获取指定用户&nbsp;<code>tweetName</code>&nbsp;发布推文次数的时间间隔。</li>
	<li>第一个时间间隔始终从 <code>startTime</code> 开始，因此时间间隔为&nbsp;<code>[startTime, startTime + delta*1&gt;, &nbsp;[startTime + delta*1, startTime + delta*2&gt;, [startTime + delta*2, startTime + delta*3&gt;, ... , [startTime + delta*i,&nbsp;<strong>min</strong>(startTime + delta*(i+1), endTime + 1)&gt;</code>，其中 <code>i</code> 和 <code>delta</code>（取决于 <code>freq</code>）都是非负整数。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>
["TweetCounts","recordTweet","recordTweet","recordTweet","getTweetCountsPerFrequency","getTweetCountsPerFrequency","recordTweet","getTweetCountsPerFrequency"]
[[],["tweet3",0],["tweet3",60],["tweet3",10],["minute","tweet3",0,59],["minute","tweet3",0,60],["tweet3",120],["hour","tweet3",0,210]]

<strong>输出：</strong>
[null,null,null,null,[2],[2,1],null,[4]]

<strong>解释：</strong>
TweetCounts tweetCounts = new TweetCounts();
tweetCounts.recordTweet("tweet3", 0);
tweetCounts.recordTweet("tweet3", 60);
tweetCounts.recordTweet("tweet3", 10);                             //&nbsp;"tweet3"&nbsp;发布推文的时间分别是&nbsp;0,&nbsp;10&nbsp;和&nbsp;60 。
tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 59); //&nbsp;返回&nbsp;[2]。统计频率是每分钟（60 秒），因此只有一个有效时间间隔 [0,60&gt;&nbsp;-&nbsp;&gt;&nbsp;2&nbsp;条推文。
tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 60); //&nbsp;返回&nbsp;[2,1]。统计频率是每分钟（60 秒），因此有两个有效时间间隔&nbsp;<strong>1)</strong>&nbsp;[0,60&gt;&nbsp;-&nbsp;&gt;&nbsp;2&nbsp;条推文，和&nbsp;<strong>2)</strong>&nbsp;[60,61&gt;&nbsp;-&nbsp;&gt;&nbsp;1&nbsp;条推文。 
tweetCounts.recordTweet("tweet3", 120);                            // "tweet3"&nbsp;发布推文的时间分别是 0, 10, 60 和 120 。
tweetCounts.getTweetCountsPerFrequency("hour", "tweet3", 0, 210);  //&nbsp;返回&nbsp;[4]。统计频率是每小时（3600 秒），因此只有一个有效时间间隔 [0,211&gt;&nbsp;-&nbsp;&gt;&nbsp;4&nbsp;条推文。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>同时考虑&nbsp;<code>recordTweet</code>&nbsp;和&nbsp;<code>getTweetCountsPerFrequency</code>，最多有 <code>10000</code> 次操作。</li>
	<li><code>0 &lt;= time, startTime, endTime &lt;=&nbsp;10^9</code></li>
	<li><code>0 &lt;= endTime - startTime &lt;= 10^4</code></li>
</ul>

            

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/tweet-counts-per-frequency/solution/5334-by-ikaruga/)

### 答题
``` C++
class TweetCounts {
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) 
	{
		record[tweetName][time]++;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime)
	{
		vector<int> ans;

		int f = 1;
		f *= (freq == "minute") ? 60 : 1;
		f *= (freq == "hour") ? 60 * 60 : 1;
		f *= (freq == "day") ? 60 * 60 * 24 : 1;

		int t = startTime;
		while (t <= endTime)
		{
			auto bg = record[tweetName].lower_bound(t);
			auto ed = record[tweetName].upper_bound(min(t + f - 1, endTime));
			int cnt = 0;
			for (auto it = bg; it != ed; it++)
			{
				cnt += it->second;
			}
			ans.push_back(cnt);
			t += f;
		}

		return ans;
    }

private:
	unordered_map<string, map<int, int>> record;
};
```




