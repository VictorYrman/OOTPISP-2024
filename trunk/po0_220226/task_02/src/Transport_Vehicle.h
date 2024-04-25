#pragma once
#include <string>
#ifndef TRANSPORT_VEHICLEH
#define TRANSPORT_VEHICLEH

class Transport_Vehicle
{
private:
	int mmaxSpeed = 0;
	Transport_Vehicle* next = nullptr;
protected:
	static Transport_Vehicle* begin;
	static Transport_Vehicle* last;
public:
	Transport_Vehicle() = default;
	explicit Transport_Vehicle(const int maxSpeed);
	virtual ~Transport_Vehicle() = default;
	void Add();
	void SetNext(Transport_Vehicle* nextTransport);
	virtual void Show() const;
	static void Print();
	void SetMaxSpeed(const int maxSpeed);
	int GetMaxSpeed() const;
};

#endif