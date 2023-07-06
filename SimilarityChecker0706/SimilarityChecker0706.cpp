#pragma once

#include <stdexcept>
using namespace std;

class SimilarityChecker
{
public:
	explicit SimilarityChecker(const string& str)
	{
		m_originalString = str;
	}

	int GetLengthPoint(const string& matchingString)
	{
		AssertInvalidAlphabetInput(matchingString);

		if (matchingString.length() == m_originalString.length())
			return MAX_LENGTH_POINT;

		// Too short to be checked
		if (matchingString.length() * 2 <= m_originalString.length())
			return 0;

		// Too long to be checked
		if (matchingString.length() >= m_originalString.length() * 2)
			return 0;

		return GetPartialLengthPoint(matchingString);
	}

	int GetAlphabetPoint(const string& matchingString)
	{
		// Defense divided by zero
		if (matchingString.length() == 0)
			throw invalid_argument("Zero string is not allowed.");

		AssertInvalidAlphabetInput(matchingString);

		// 1. Use count sorting to check alphabet
		int numberOfAlphabetMine[NUMBER_OF_ALPHABETS] = {0, };
		int numberOfAlphabetGiven[NUMBER_OF_ALPHABETS] = {0, };


		for (const auto alphabet : matchingString)
		{
			numberOfAlphabetGiven[alphabet - 'A']++;
		}

		for (const auto alphabet : m_originalString)
		{
			numberOfAlphabetMine[alphabet - 'A']++;
		}

		// Count same character
		int sameAlphabets = 0;
		int differentAlphabets = 0;
		for (int index = 0; index < NUMBER_OF_ALPHABETS; index++)
		{
			if (numberOfAlphabetMine[index] == 0 && numberOfAlphabetGiven[index] == 0)
			{
				continue;
			}

			if (numberOfAlphabetMine[index] != 0 && numberOfAlphabetGiven[index] != 0)
			{
				sameAlphabets++;
				continue;
			}

			differentAlphabets++;
		}

		return (sameAlphabets * 40 / (differentAlphabets + sameAlphabets));
	}

private:
	int GetPartialLengthPoint(const string& matchingString)
	{
		int point = 0;
		if (m_originalString.length() > matchingString.length())
		{
			const int gap = static_cast<int>(m_originalString.length() - matchingString.length());
			// Avoid integer divide which can make invalid number
			point = static_cast<int>(60 - (gap * 60.0 / matchingString.length()));
		}
		else
		{
			const int gap = static_cast<int>(matchingString.length() - m_originalString.length());
			// Avoid integer divide which can make invalid number
			point = static_cast <int>(60 - (gap * 60.0 / m_originalString.length()));
		}

		return point;
	}

	void AssertInvalidAlphabetInput(const string& matchingString)
	{
		// Defense divided by zero
		if (matchingString.length() == 0)
			throw invalid_argument("Zero string is not allowed.");

		// All large capital
		for (const auto alphabet : matchingString)
		{
			if (alphabet < 'A')
				throw invalid_argument("Only large capital of alphabet is allowed.");

			if (alphabet > 'Z')
				throw invalid_argument("Only large capital of alphabet is allowed.");
		}
	}

	string m_originalString;
	static constexpr int MAX_LENGTH_POINT = 60;
	static constexpr int NUMBER_OF_ALPHABETS = 'Z' - 'A' + 1;
;};