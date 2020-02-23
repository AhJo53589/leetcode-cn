# `（简单）` [5169.number-of-days-between-two-dates 日期之间隔几天](https://leetcode-cn.com/problems/number-of-days-between-two-dates/)

[contest](https://leetcode-cn.com/contest/weekly-contest-177/problems/number-of-days-between-two-dates/)

### 题目描述
<p>请你编写一个程序来计算两个日期之间隔了多少天。</p>
<p>日期以字符串形式给出，格式为&nbsp;<code>YYYY-MM-DD</code>，如示例所示。</p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<pre><strong>输入：</strong>date1 = "2019-06-29", date2 = "2019-06-30"
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>
<pre><strong>输入：</strong>date1 = "2020-01-15", date2 = "2019-12-31"
<strong>输出：</strong>15
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li>给定的日期是&nbsp;<code>1971</code>&nbsp;年到 <code>2100</code>&nbsp;年之间的有效日期。</li>
</ul>

​            

---
### 思路
```

```

[发布的题解](https://leetcode-cn.com/problems/number-of-days-between-two-dates/solution/5169-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int daysBetweenDates(string date1, string date2)
	{
		if (date1 > date2) return daysBetweenDates(date2, date1);

		tm time1, time2;
		int year;
		int month;
		int day;
		inputDate(date1, year, month, day);
		setDay(time1, year, month, day);
		inputDate(date2, year, month, day);
		setDay(time2, year, month, day);

		time_t tim1, tim2;
		tim1 = mktime(&time1);
		tim2 = mktime(&time2);
		int len = (tim2 - tim1) / (24 * 60 * 60);

		return len;
    }

	void inputDate(string date, int& y, int& m, int& d)
	{
		stringstream ss;
		while (date.find("-") != string::npos)
		{
			date = date.replace(date.find("-"), 1, " ");
		}
		ss << date;
		ss >> y;
		ss >> m;
		ss >> d;
	}

	void setDay(tm& day, int y, int m, int d)
	{
		day.tm_year = y - 1900;
		day.tm_mon = m - 1;
		day.tm_mday = d;
		day.tm_hour = day.tm_min = day.tm_sec = 0;
	}
};
```




