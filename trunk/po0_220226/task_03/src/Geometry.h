#pragma once
#ifndef GEOMETRYH
#define GEOMETRYH

class Geometry
{
private:
	float volume = 0.00;
	float area = 0.00;

public:
	Geometry() = default;
	Geometry(const float _volume, const float _area);
	~Geometry() = default;

	void SetVolume(const float _volume);
	float GetVolume() const;
	void SetArea(const float _area);
	float GetArea() const;

	virtual void CountVolume();
	virtual void CountArea();
	virtual void Print() const;

	void operator=(const Geometry right);
	bool operator==(const Geometry right) const;
	bool operator!=(const Geometry right) const;
};

#endif