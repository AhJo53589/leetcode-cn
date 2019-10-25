// 744.find-smallest-letter-greater-than-target.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

char nextGreatestLetter(vector<char>& letters, char target)
{
	auto getValue = [](char c) { return c - 'a'; };
	int low = 0;
	int high = letters.size();
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (getValue(letters[mid]) < getValue(target) + 1) low = mid + 1;
		else high = mid;
	}
	return (low < letters.size()) ? letters[low] : letters[0];
}

int main()
{
	vector<string> str;
	vector<char> target;
	vector<char> answer;

	str.push_back("[c, f, j]");
	target.push_back('a');
	answer.push_back('c');

	str.push_back("[c, f, j]");
	target.push_back('c');
	answer.push_back('f');

	str.push_back("[c, f, j]");
	target.push_back('d');
	answer.push_back('f');

	str.push_back("[c, f, j]");
	target.push_back('g');
	answer.push_back('j');

	str.push_back("[c, f, j]");
	target.push_back('j');
	answer.push_back('c');

	str.push_back("[c, f, j]");
	target.push_back('k');
	answer.push_back('c');

	for (int i = 0; i < str.size(); i++)
	{
		cout << endl << "///////////////////////" << endl;
		vector<char> letters = StringToVectorChar(str[i]);
		for (auto c : letters) cout << c << ", ";
		cout << endl;
		cout << "Target = " << target[i] << endl;
		cout << "Answer = " << answer[i] << endl;
		cout << "nextGreatestLetter = " << nextGreatestLetter(letters, target[i]) << endl;
	}
}
