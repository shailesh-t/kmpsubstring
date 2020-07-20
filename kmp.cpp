#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::string;
// this is knuth - moriis- pratts substring search algorithm for linear time
// one of the indigenoeous algorithm , key is dfa creation, courseera princeton university algorithm part 2 , week 4 lecture
// https://www.youtube.com/watch?v=iZ93Unvxwtw
//https://www.youtube.com/watch?v=PvAngd1J5kw
void mCreateDfaFromPattern(string xPattern, vector<vector<int>>& xDfa)
{

	xDfa.at(0).at(xPattern.at(0)) = 1;
	size_t x = 0;
	for (size_t j = 1; j < xPattern.size();j++)
	{
		xDfa.at(j) = xDfa.at(x);
		xDfa.at(j).at(xPattern.at(j)) = j + 1;
		x = xDfa.at(x).at(xPattern.at(j));
	}
}

size_t m_search(string xText, string xPattern)
{
	vector<vector<int>> lDfa(xPattern.size());
	std::generate_n(begin(lDfa), xPattern.size(), []() mutable {
		vector<int> lVec(256);
		return lVec;});

	mCreateDfaFromPattern(xPattern, lDfa);

	for (size_t i = 0, j = 0; i < xText.size();i++)
	{
		j = lDfa.at(j).at(xText.at(i));
		if (j == xPattern.size()) return i - j;
	}
	return xText.size();
}

void searchUtil()
{
	string lStr = "abababdcabababababagbabababaasbabababababababababababababac";
	string lPat = "abababababababac";
	std::cout << lStr.size() << " " << lPat.size() << '\n';
	std::cout <<m_search(lStr, lPat);
	std::cout << std::endl;
} 

int main()
{
	searchUtil();
}