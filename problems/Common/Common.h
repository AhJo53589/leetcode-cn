#ifndef COMMON_H
#define COMMON_H

#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

using namespace std;


std::vector<std::string> split(std::string str, std::string pattern);

vector<int> StringToVectorInt(string str);
string VectorIntToString(vector<int>& nums);
vector<vector<int>> StringToVectorVectorInt(string str);
string VectorVectorIntToString(vector<vector<int>>& matrix);

void printVectorVectorInt(vector<vector<int>>& matrix);


#endif //COMMON_H
