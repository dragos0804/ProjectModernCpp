#pragma once
#include <crow.h>
#include <cstdint>

using Position = std::tuple<float, float, uint16_t, uint16_t, float>;

class Cluster
{

public:
	Cluster(uint8_t id, Position clusterPosition);

	void AddPoint(Position positionPoint);
	void UpdateClusterPosition();
	void RemovePoints();
	std::vector<Position> GetPoints();
	Position GetPosition() const;

private:
	uint8_t m_id;
	Position m_clusterPosition;
	std::vector<Position> m_points;
};