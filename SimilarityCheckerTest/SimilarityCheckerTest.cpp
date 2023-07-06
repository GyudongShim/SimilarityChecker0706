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
			m_pChecker->GetLegthPoints(inputString);
			FAIL();
		} catch (exception e)
		{
			// PASS
		}
	}
};


// To be used for 2nd
TEST_F(SimilarityCheckerTestFixture, AssertIllegalInputs) {

	// Long length
	// AssertIllegalArgument("DDDDDDDD");
}

TEST_F(SimilarityCheckerTestFixture, GetTotalLengthWithSameLength) {
	int lengthPoint = m_pChecker->GetLegthPoints("ABCD");
	EXPECT_EQ(60, lengthPoint);
}


TEST_F(SimilarityCheckerTestFixture, GetTotalLegnthMoreThanDouble) {
	// Half of given length
	EXPECT_EQ(0, m_pChecker->GetLegthPoints("AB"));

	// doubles of given length
	EXPECT_EQ(0, m_pChecker->GetLegthPoints("ABCDABCD"));
}


TEST_F(SimilarityCheckerTestFixture, GetPartialPoints) {
	// Half of given length
	EXPECT_EQ(40, m_pChecker->GetLegthPoints("ABC"));
	EXPECT_EQ(45, m_pChecker->GetLegthPoints("ABCDE"));
}
