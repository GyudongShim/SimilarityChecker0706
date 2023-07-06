#include "pch.h"
#include "../SimilarityChecker0706/SimilarityChecker0706.cpp"


using namespace std;


class SimilarityCheckerTestFixture : public testing::Test
{
public:
	SimilarityChecker* m_pChecker = nullptr;

	void SetUp() override
	{
		m_pChecker = new SimilarityChecker(string("ABCD"));
	}

	void TearDown() override
	{
		delete m_pChecker;
	}

	void AssertIllegalArgument(string inputString)
	{
		try
		{
			m_pChecker->GetLengthPoint(inputString);
			FAIL();
		} catch (exception e)
		{
			// PASS
		}
	}
};

TEST_F(SimilarityCheckerTestFixture, AssertIllegalInputs) {
	AssertIllegalArgument("");
	// Check small character
	AssertIllegalArgument("AAAaaBBBB"); 
}

TEST_F(SimilarityCheckerTestFixture, GetTotalLengthWithSameLength) {
	int lengthPoint = m_pChecker->GetLengthPoint("ABCD");
	EXPECT_EQ(60, lengthPoint);
}


TEST_F(SimilarityCheckerTestFixture, GetTotalLegnthMoreThanDouble) {
	// Half of given length
	EXPECT_EQ(0, m_pChecker->GetLengthPoint("AB"));

	// Half of given length
	EXPECT_EQ(0, m_pChecker->GetLengthPoint("A"));

	// doubles of given length
	EXPECT_EQ(0, m_pChecker->GetLengthPoint("ABCDABCD"));
	EXPECT_EQ(0, m_pChecker->GetLengthPoint("ABCDABCDEFGH"));
}


TEST_F(SimilarityCheckerTestFixture, GetPartialLengthPoints) {
	// Half of given length
	EXPECT_EQ(40, m_pChecker->GetLengthPoint("ABC"));
	EXPECT_EQ(45, m_pChecker->GetLengthPoint("ABCDE"));
}

TEST_F(SimilarityCheckerTestFixture, SameAlphabet) {
	EXPECT_EQ(40, m_pChecker->GetAlphabetPoint("DCBA"));
}

TEST_F(SimilarityCheckerTestFixture, OneDiff) {
	EXPECT_EQ(32, m_pChecker->GetAlphabetPoint("ABCDE"));
}

TEST_F(SimilarityCheckerTestFixture, AllDiff) {
	EXPECT_EQ(0, m_pChecker->GetAlphabetPoint("EFGHI"));
}

