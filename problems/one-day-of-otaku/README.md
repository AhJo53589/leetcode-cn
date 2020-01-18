# `（中等）` [100266.one-day-of-otaku 小胖子的日常](https://leetcode-cn.com/problems/one-day-of-otaku/)

[contest](https://leetcode-cn.com/contest/sf-2020/problems/one-day-of-otaku/)

### 题目描述
<p>Usopp&nbsp;周末在家出题的时候，小胖子不小心打翻了水杯，热水瞬间让机器沸腾了起来；再次开机之后，结果发现题目变成了下面这样：</p>
<p><img alt="" src="./question.jpg" style="height: 331px; width: 1185px;"><img alt="" src="./question2.jpg" style="height: 171px; width: 1170px;"></p>
<p>来吧年轻人，想要知道这道题是什么吗？那就去探索吧，所有的信息都放在这里面。</p>
<p>&nbsp;</p>
<p>提示：<br>
<br>
1. 小胖子是一头奇胖无比的猫；</p>

​            

---
### 思路
```
// 给一个长度为N的自然数序列 values ,  可以对这个序列做以下两种操作（每种操作次数不限）：
//    1. 交换序列中任意两个位置的 数字；
//    2. 选择序列中某一个数字 0 替换成任意的整数；
// 判断是否能通过一些操作，使得 values 中的元素是否满足 values[i 1]=values[i] 1  (0 <= i < N-1)。

// 1 <=  N <= 10^6
// 0 <= Values[I] <= 10^9
```



### 答题
``` C++
bool otaku(vector<int>& nums) {
    if (nums.size() <= 1) return true;
    sort(nums.begin(),nums.end());
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i]!=0) break;
        cnt++;
    }
    if (cnt == nums.size()) return true;
    for (int i = cnt; i < nums.size()-1; i++) {
        if (nums[i] == nums[i+1]) return false;
        else cnt -= nums[i+1]-nums[i]-1;

    }
    return cnt >= 0;
}
```




