# `（中等）` [1396.design-underground-system 设计地铁系统](https://leetcode-cn.com/problems/design-underground-system/)

[contest](https://leetcode-cn.com/contest/weekly-contest-182/problems/design-underground-system/)

### 题目描述
<p>请你实现一个类&nbsp;<code>UndergroundSystem</code>&nbsp;，它支持以下 3 种方法：</p>

<p>1.<code>&nbsp;checkIn(int id, string stationName, int t)</code></p>

<ul>
	<li>编号为&nbsp;<code>id</code>&nbsp;的乘客在 <code>t</code>&nbsp;时刻进入地铁站&nbsp;<code>stationName</code>&nbsp;。</li>
	<li>一个乘客在同一时间只能在一个地铁站进入或者离开。</li>
</ul>

<p>2.<code>&nbsp;checkOut(int id, string stationName, int t)</code></p>

<ul>
	<li>编号为&nbsp;<code>id</code>&nbsp;的乘客在 <code>t</code>&nbsp;时刻离开地铁站 <code>stationName</code>&nbsp;。</li>
</ul>

<p>3.&nbsp;<code>getAverageTime(string startStation, string endStation)</code>&nbsp;</p>

<ul>
	<li>返回从地铁站&nbsp;<code>startStation</code>&nbsp;到地铁站&nbsp;<code>endStation</code>&nbsp;的平均花费时间。</li>
	<li>平均时间计算的行程包括当前为止所有从&nbsp;<code>startStation</code>&nbsp;<strong>直接到达</strong>&nbsp;<code>endStation</code>&nbsp;的行程。</li>
	<li>调用&nbsp;<code>getAverageTime</code>&nbsp;时，询问的路线至少包含一趟行程。</li>
</ul>

<p>你可以假设所有对&nbsp;<code>checkIn</code>&nbsp;和&nbsp;<code>checkOut</code>&nbsp;的调用都是符合逻辑的。也就是说，如果一个顾客在 <strong>t<sub>1</sub></strong>&nbsp;时刻到达某个地铁站，那么他离开的时间&nbsp;<strong>t<sub>2</sub></strong>&nbsp;一定满足&nbsp;<strong>t<sub>2</sub> &gt; t<sub>1</sub></strong>&nbsp;。所有的事件都按时间顺序给出。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>
["UndergroundSystem","checkIn","checkIn","checkIn","checkOut","checkOut","checkOut","getAverageTime","getAverageTime","checkIn","getAverageTime","checkOut","getAverageTime"]
[[],[45,"Leyton",3],[32,"Paradise",8],[27,"Leyton",10],[45,"Waterloo",15],[27,"Waterloo",20],[32,"Cambridge",22],["Paradise","Cambridge"],["Leyton","Waterloo"],[10,"Leyton",24],["Leyton","Waterloo"],[10,"Waterloo",38],["Leyton","Waterloo"]]

<strong>输出：</strong>
[null,null,null,null,null,null,null,14.0,11.0,null,11.0,null,12.0]

<strong>解释：</strong>
UndergroundSystem undergroundSystem = new UndergroundSystem();
undergroundSystem.checkIn(45, "Leyton", 3);
undergroundSystem.checkIn(32, "Paradise", 8);
undergroundSystem.checkIn(27, "Leyton", 10);
undergroundSystem.checkOut(45, "Waterloo", 15);
undergroundSystem.checkOut(27, "Waterloo", 20);
undergroundSystem.checkOut(32, "Cambridge", 22);
undergroundSystem.getAverageTime("Paradise", "Cambridge");       // 返回 14.0。从 "Paradise"（时刻 8）到 "Cambridge"(时刻 22)的行程只有一趟
undergroundSystem.getAverageTime("Leyton", "Waterloo");          // 返回 11.0。总共有 2 躺从 "Leyton" 到 "Waterloo" 的行程，编号为 id=45 的乘客出发于 time=3 到达于 time=15，编号为 id=27 的乘客出发于 time=10 到达于 time=20。所以平均时间为 ( (15-3) + (20-10) ) / 2 = 11.0
undergroundSystem.checkIn(10, "Leyton", 24);
undergroundSystem.getAverageTime("Leyton", "Waterloo");          // 返回 11.0
undergroundSystem.checkOut(10, "Waterloo", 38);
undergroundSystem.getAverageTime("Leyton", "Waterloo");          // 返回 12.0</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>总共最多有&nbsp;<code>20000</code>&nbsp;次操作。</li>
	<li><code>1 &lt;= id, t &lt;= 10^6</code></li>
	<li>所有的字符串包含大写字母，小写字母和数字。</li>
	<li><code>1 &lt;=&nbsp;stationName.length &lt;= 10</code></li>
	<li>与标准答案误差在&nbsp;<code>10^-5</code>&nbsp;以内的结果都视为正确结果。</li>
</ul>

            

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/design-underground-system/solution/design-underground-system-by-ikaruga/)

### 答题
``` C++
class UndergroundSystem {
public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        checkRecord[id] = { stationName, t };
    }

    void checkOut(int id, string stationName, int t) {
        string name = getStationName(checkRecord[id].first, stationName);
        t -= checkRecord[id].second;
        count[name].first += (double)t;
        count[name].second += 1;
    }

    double getAverageTime(string startStation, string endStation) {
        string name = getStationName(startStation, endStation);
        double ans = count[name].first / (double)count[name].second;
        return ans;
    }

private:
    string getStationName(string startStation, string endStation)
    {
        return startStation + endStation;
    }

    unordered_map<int, pair<string, int>> checkRecord;
    unordered_map<string, pair<double, int>> count;
};
```




