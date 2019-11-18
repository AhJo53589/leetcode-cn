# `（中等）` [752.open-the-lock 打开转盘锁](https://leetcode-cn.com/problems/open-the-lock/)

### 题目描述
<p>你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： <code>'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'</code> 。每个拨轮可以自由旋转：例如把 <code>'9'</code> 变为&nbsp; <code>'0'</code><font face="Helvetica Neue, Helvetica, Arial, sans-serif" color="#333333"><span style="background-color:#ffffff; font-size:14px">，</span></font><code>'0'</code> 变为 <code>'9'</code> 。每次旋转都只能旋转一个拨轮的一位数字。</p>

<p>锁的初始数字为 <code>'0000'</code> ，一个代表四个拨轮的数字的字符串。</p>

<p>列表 <code>deadends</code> 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。</p>

<p>字符串 <code>target</code> 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入：</strong>deadends = ["0201","0101","0102","1212","2002"], target = "0202"
<strong>输出：</strong>6
<strong>解释：</strong>
可能的移动序列为 "0000" -&gt; "1000" -&gt; "1100" -&gt; "1200" -&gt; "1201" -&gt; "1202" -&gt; "0202"。
注意 "0000" -&gt; "0001" -&gt; "0002" -&gt; "0102" -&gt; "0202" 这样的序列是不能解锁的，
因为当拨动到 "0102" 时这个锁就会被锁定。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> deadends = ["8888"], target = "0009"
<strong>输出：</strong>1
<strong>解释：</strong>
把最后一位反向旋转一次即可 "0000" -&gt; "0009"。
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
<strong>输出：</strong>-1
<strong>解释：
</strong>无法旋转到目标数字且不被锁定。
</pre>

<p><strong>示例 4:</strong></p>

<pre><strong>输入:</strong> deadends = ["0000"], target = "8888"
<strong>输出：</strong>-1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li>死亡列表 <code>deadends</code> 的长度范围为 <code>[1, 500]</code>。</li>
	<li>目标数字 <code>target</code> 不会在 <code>deadends</code> 之中。</li>
	<li>每个 <code>deadends</code> 和 <code>target</code> 中的字符串的数字会在 10,000 个可能的情况 <code>'0000'</code> 到 <code>'9999'</code> 中产生。</li>
</ol>




---
### 思路
``` 
因为是从队列的习题集里做到的题，很自然就想到用队列的特性来解决。  
大概解决思路很快就想到了。  
将当前数字的可以变换的所有（8种）情况全部判断加入队列。  
下一步的时候，再依次将刚加进去的情况的下一步情况再加入队列。  
其间通过黑名单方式排除deadends和已经计算过的情况。  
通过这种方式能够计算最早达到目标的步数。  

另外实现字符串“0000”变化的方法getNextMoveList()感觉也比较有意思。 
```


### 答题
``` C++
vector<string> getNextMoveList(string strCurrent)
{
	vector<string> vStr;
	for (int i = 0; i < 4; i++)
	{
		string strTemp = strCurrent;
		int iCurrent = strCurrent[i] - '0';

		strTemp[i] = ((iCurrent + 1) % 10) + '0';
		vStr.push_back(strTemp);
		strTemp[i] = ((iCurrent + 10 - 1) % 10) + '0';
		vStr.push_back(strTemp);
	}
	return vStr;
}

int openLock(vector<string>& deadends, string target)
{
	map<string, bool> mapDeadends;
	for (string s : deadends)
	{
		mapDeadends[s] = true;
	}

	string strInit("0000");
	string strEnd("----");
	if (mapDeadends[strInit]) return -1;

	queue<string> qLockNum;
	qLockNum.push(strInit);
	mapDeadends[strInit] = true;
	qLockNum.push(strEnd);

	int num = 1;
	while (!qLockNum.empty())
	{
		string strCurrent = qLockNum.front();
		qLockNum.pop();

		if (strCurrent == strEnd)
		{
			if (qLockNum.empty() || qLockNum.front() == strEnd) break;

			num++;
			qLockNum.push(strEnd);
			continue;
		}

		vector<string> strNextMoveList = getNextMoveList(strCurrent);
		for (string sNext : strNextMoveList)
		{
			if (!mapDeadends[sNext])
			{
				if (sNext == target) return num;
				mapDeadends[sNext] = true;
				qLockNum.push(sNext);
			}
		}
	}
	return -1;
}
``` 
