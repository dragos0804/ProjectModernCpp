#include "pch.h"
#include "Cluster.h"

class ClusterTest : public ::testing::Test
{
public:
	void SetUp() override
	{
		c1 = new Cluster(1, {1.f, 1.f, 1, 1, 1.f});
		c2 = new Cluster(2, {2.f, 2.f, 2, 2, 2.f});
	}

	void TearDown() override
	{
		delete c1;
		delete c2;
	}

protected:
	Cluster* c1 = nullptr, * c2 = nullptr;
};

TEST_F(ClusterTest, CheckPositionGetter)
{
	Position a = std::make_tuple(1.f, 1.f, 1, 1, 1.f);
	Position b = std::make_tuple(2.f, 2.f, 2, 2, 2.f);
	EXPECT_EQ(c1->GetPosition(), a);
	EXPECT_EQ(c2->GetPosition(), b);
}

TEST_F(ClusterTest, CheckPointsGetter)
{
	std::vector<Position> points = c1->GetPoints();
	EXPECT_EQ(points.size(), 0);
}

TEST_F(ClusterTest, CheckAddPoint)
{
	std::vector<Position> points = c1->GetPoints();
	EXPECT_EQ(points.size(), 0);
	Position a = std::make_tuple(1.f, 1.f, 1, 1, 1.f);
	c1->AddPoint(a);
	points = c1->GetPoints();
	EXPECT_EQ(points.size(), 1);
}


TEST_F(ClusterTest, CheckDeletePoints)
{
	std::vector<Position> points = c1->GetPoints();
	EXPECT_EQ(points.size(), 0);
	Position a = std::make_tuple(1.f, 1.f, 1, 1, 1.f);
	Position b = std::make_tuple(2.f, 2.f, 2, 2, 2.f);
	Position c = std::make_tuple(3.f, 4.f, 5, 6, 2.f);
	c1->AddPoint(a);
	c1->AddPoint(b);
	c1->AddPoint(c);
	c1->RemovePoints();
	points = c1->GetPoints();

	EXPECT_EQ(points.size(), 0);
}