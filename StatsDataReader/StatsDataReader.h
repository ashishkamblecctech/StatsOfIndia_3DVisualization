#include "pch.h"
#include <vector>
#include <string>

struct RegionInfo1 {
	std::string filePath;
	float r, g, b;
	long statePopulation;
	float stateEducation, stateArea;
};

// This class is exported from the dll
class STATSDATAREADER_API StatsDataReader {
public:
	StatsDataReader();
	~StatsDataReader();

public:
	void dataReader(std::vector <std::string>& stateNames, std::vector <RegionInfo1>& region1);

private:
	std::vector <long> statePopulation;
	std::vector <float> stateEducation;
	std::vector <float>	stateArea;
};