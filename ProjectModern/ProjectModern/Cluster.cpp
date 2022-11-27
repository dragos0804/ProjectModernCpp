#include "Cluster.h"

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
	Position sumOfPositions = {0.0f, {}, 0, 0, 0.0f };

	for (const auto& point : m_points)
	{
		//TODO how should we keep track of movie categories when there are multiple ones? 
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