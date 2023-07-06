#pragma once

#include <stdexcept>
using namespace std;

class SimilarityChecker
{
public:
	explicit SimilarityChecker(const string& str)
	{
		originalString = str;
	}

	int GetLegthPoints(const string& string)
	{
		if (string.length() == originalString.length())
			return MAX_LENGTH_POINT;

		// Too short to be checked
		if (string.length() * 2 <= originalString.length())
			return 0;

		// Too long to be checked
		if (string.length()  >= originalString.length() * 2)
			return 0;

		return 0;
	}


private:
	string originalString;
	static constexpr int MAX_LENGTH_POINT = 60;
};