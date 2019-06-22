# `（简单）`  [198.Rob 打家劫舍](https://leetcode-cn.com/problems/house-robber/)

### 题目描述
<p>你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，<strong>如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警</strong>。</p>

<p>给定一个代表每个房屋存放金额的非负整数数组，计算你<strong>在不触动警报装置的情况下，</strong>能够偷窃到的最高金额。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [1,2,3,1]
<strong>输出:</strong> 4
<strong>解释:</strong> 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
&nbsp;    偷窃到的最高金额 = 1 + 3 = 4 。</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [2,7,9,3,1]
<strong>输出:</strong> 12
<strong>解释:</strong> 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
&nbsp;    偷窃到的最高金额 = 2 + 9 + 1 = 12 。
</pre>



---
### 思路
```
根据这道题的条件特点：  
__如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警__  
（即相邻的数字不能同时作为最终求和的有效数字）。  

这个条件如果精简掉其他内容，很容易让人联想到奇偶数。这个解法就是从这点出发。  
  

设置两个变量，sumOdd和sumEven分别对数组的奇数和偶数元素求和。  
最后比较这两个和谁更大，谁就是最优解。  
至少在下面这个例子里，这么做是成功的了。  

|  Index  | [0] | [1] | [2] | [3] |
|---------|---|---|---|---|
| nums    | 1 | 2 | 3 | 4 |
| sumEven | 1 | 1 | 4 | 4 |
| sumOdd  | 0 | 2 | 2 | 6 |

接下来要解决的就是最优解不是纯奇数和或者偶数和的情况。  
这种情况下，最优解可能前半段出现在这边，后半段出现在另一边。  
那么只要找到一个时机，当这一段的最优解没有另一边好时，就复制对面的最优解过来。  

举个例子：  

|  Index  | [0] | [1] | [2] | [3] | [4] |
|---------|---|---|---|---|-----|
| nums    | 1 | 3 | 1 | 3 | 100 |
| sumEven | 1 | 1 | 2 | 2 => 3 |     |
| sumOdd  | 0 | 3 | 3 |   |     |

当偶数和（奇偶指的数组下标）加到第二个 1 之后，发现还不如奇数和一个 3 大，就应该将对面的3复制过来替换掉自己的 2。  

|  Index  |  [0] | [1] | [2] | [3] | [4] |
|---------|---|---|---|---|-----|
| nums    | 1 | 3 | 1 | 3 | 100 |
| sumEven | 1 | 1 | 2 | 3 | 103 |
| sumOdd  | 0 | 3 | 3 | 6 | 6   |

继续计算后得到最优解。  

完成。  
```


### 答题
``` C++
int rob(vector<int>& nums) 
{
	int sumOdd = 0;
	int sumEven = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i % 2 == 0)
		{
			sumEven += nums[i];
			sumEven = max(sumOdd, sumEven);
		}
		else
		{
			sumOdd += nums[i];
			sumOdd = max(sumOdd, sumEven);
		}
	}
	return max(sumOdd, sumEven);
}
``` 



### 其它
这道题上周五下班前没有做完，  
周日晚上想想这周结束之前还是应该把它完成。  

做完之后提交可能有bug，显示我战胜了100%的用户。  
很开心！  
算法也是纯自己研究的，  
就第一次写了个题解（已被选为精选题解）。  


学习了别人的动态规划方法。  
就感觉和我的方法很微妙的不同。
  
``` C++
int rob(vector<int>& nums) 
{
	// 动态规划
	if (nums.size() == 0) return 0;
	if (nums.size() == 1)
		return nums[0];
	if (nums.size() == 2)
		return max(nums[0], nums[1]);
	nums[2] = nums[0] + nums[2];
	if (nums.size() == 3)
		return max(nums[1], nums[2]);
	for (int i = 3; i < nums.size(); i++)
	{
		nums[i] = max(nums[i - 2] + nums[i], nums[i] + nums[i - 3]);
	}
	return max(nums[nums.size() - 1], nums[nums.size() - 2]);
}
``` 