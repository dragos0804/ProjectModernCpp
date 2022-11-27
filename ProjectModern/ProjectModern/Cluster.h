#pragma once
#include <crow.h>
#include <cstdint>

#define PositionSf (std::get<0>(Position))
#define PositionRating (std::get<1>(Position))
#define PositionCategory (std::get<2>(Position))
#define PositionYear (std::get<3>(Position))
#define PositionDuration (std::get<4>(Position))
#define PositionAgeRestriction (std::get<5>(Position))

using Position = std::tuple<std::string, float, std::vector<float>, uint16_t, uint16_t, float>;

class Cluster
{

public:
	Cluster(uint8_t id, Position clusterPosition);

	void AddPoint(Position positionPoint);
	void UpdateClusterPosition();
	void RemovePoints();

	Position GetPosition() const;

private:
	uint8_t m_id;
	Position m_clusterPosition;
	std::vector<Position> m_points;
};