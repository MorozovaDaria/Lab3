#pragma once

class ResourcePackage {
private:
	double energy_; 
	double oxygen_;
	int safetyLevel_;
public:
	ResourcePackage(double energy, double oxygen, int safetyLevel);
	double getEnergy() const;
	double getOxygen() const;
	int getSafetyLevel() const;
};