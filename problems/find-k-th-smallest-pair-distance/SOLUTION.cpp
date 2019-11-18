
//////////////////////////////////////////////////////////////////////////
//寻找距离不超过distance的个数（nums已经按照升序排序）
int findDistaceShort(vector<int>& nums, int distance) {
	//rightIndex代表的是在index左边且与nums[index]的距离不超过distanc的下标
	int numsSize = nums.size(), res = 0, rightIndex = numsSize - 1;
	for (int index = numsSize - 2; index >= 0; --index) {
		//修正index左边与与nums[index]的距离不超过distanc的下标
		while (rightIndex > index && nums[rightIndex] - nums[index] > distance) {
			--rightIndex;
		}
		res += (rightIndex - index);//则以index为一端，距离不超过distance的个数就是rightIndex - index
	}
	return res;
}

int smallestDistancePair(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end());//按照升序排序
	//二分搜索的三个指针，left初始化为0，right初始化为最大的距离
	int left = 0, right = nums.back() - nums[0], mid;
	while (left < right) {
		mid = (left + right) / 2;
		int shortDisMid = findDistaceShort(nums, mid);//获取距离大小不超过k的距离对的个数
		//缩小[left, right]区间
		if (shortDisMid < k) {
			//<= mid的距离对个数小于k，则第k小的距离必定不会出现在[left, mid]
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return left;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int k)
{
	return smallestDistancePair(nums,k);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/find-k-th-smallest-pair-distance/tests.txt";
}

