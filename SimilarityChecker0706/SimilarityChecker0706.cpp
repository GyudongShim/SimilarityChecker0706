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


	int GetLegthPoints(const string& matchingString)
	{
		if (matchingString.length() == originalString.length())
			return MAX_LENGTH_POINT;

		// Too short to be checked
		if (matchingString.length() * 2 <= originalString.length())
			return 0;

		// Too long to be checked
		if (matchingString.length() >= originalString.length() * 2)
			return 0;

		// Defense divided by zero
		if (matchingString.length() == 0)
			throw invalid_argument("Zero string is not allowed.");

		// Gab
		return GetPartialLengthPoint(matchingString);
	}


private:

	int GetPartialLengthPoint(const string& matchingString)
	{
		int point = 0;
		if (originalString.length() > matchingString.length())
		{
			const int gap = static_cast<int>(originalString.length() - matchingString.length());
			// Avoid integer divide which can make invalid number
			point = static_cast<int>(60 - (gap * 60.0 / matchingString.length()));
		}
		else
		{
			const int gap = static_cast<int>(matchingString.length() - originalString.length());
			// Avoid integer divide which can make invalid number
			point = static_cast <int>(60 - (gap * 60.0 / originalString.length()));
		}

		return point;
	}

	string originalString;
	static constexpr int MAX_LENGTH_POINT = 60;
};