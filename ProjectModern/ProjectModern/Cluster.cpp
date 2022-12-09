#include "Cluster.h"

#define PositionRating (std::get<0>(sumOfPositions))
#define PositionCategory (std::get<1>(sumOfPositions))
#define PositionYear (std::get<2>(sumOfPositions))
#define PositionDuration (std::get<3>(sumOfPositions))
#define PositionAgeRestriction (std::get<4>(sumOfPositions))

Cluster::Cluster(uint8_t id, Position clusterPosition)
	:m_id(id)
	, m_clusterPosition(clusterPosition)
{
}

void Cluster::AddPoint(Position positionPoint)
{
	m_points.push_back(positionPoint);
}

void Cluster::UpdateClusterPosition()
{
	Position sumOfPositions = {0.0f, 0.0f, 0, 0, 0.0f };
	auto& [rating, category, year, duration, ageRestriction] = sumOfPositions;
	for (const auto& point : m_points)
	{
		rating += PositionRating;
		category += PositionCategory;
		year += PositionYear;
		duration += PositionDuration;
		ageRestriction += PositionAgeRestriction;
	}
}

void Cluster::RemovePoints()
{
	m_points.clear();
}

Position Cluster::GetPosition() const
{
	return m_clusterPosition;
}