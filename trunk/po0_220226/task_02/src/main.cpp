#include <iostream>
#include <string>
#include "Transport_Vehicle.h"
#include "Car.h"
#include "Train.h"
#include "Express.h"

/*class Transport_Vehicle {
private:
    int mmaxSpeed = 0;
    Transport_Vehicle* next = nullptr;
    
protected:
    static Transport_Vehicle* begin;
    static Transport_Vehicle* last;

public:
    Transport_Vehicle() {}
    Transport_Vehicle(const int maxSpeed) : mmaxSpeed(maxSpeed) {
        this->Add();
    }
    ~Transport_Vehicle(){}

    void Add() {
        if (begin == nullptr) {
            begin = this;
        }
        next = nullptr;
        if (last != nullptr) {
            last->SetNext(this);
        }
        last = this;
    }

    void SetNext(Transport_Vehicle* nextTransport) {
        next = nextTransport;
    }

    void SetMaxSpeed(const int maxSpeed) {
        mmaxSpeed = maxSpeed;
    }
    int GetMaxSpeed() const {
        return mmaxSpeed;
    }

    static void Print() {
        Transport_Vehicle* ptr = begin;

        while (ptr != nullptr) {
            ptr->Show();
            ptr = ptr->next;
        }
    }

    virtual void Show() const {
        std::cout << "MaxSpeed: " << mmaxSpeed << std::endl;
        std::cout << "Transport Vehicle: " << this << std::endl;
    }
};

Transport_Vehicle* Transport_Vehicle::begin = nullptr;
Transport_Vehicle* Transport_Vehicle::last = nullptr;

class Car :  public Transport_Vehicle {
private:
    std::string mmark = "";
public:
    Car() {}
    Car(const std::string& mark, const int maxSpeed) : Transport_Vehicle(maxSpeed), mmark(mark) {
        this->Add();
    }
    ~Car(){}

    void SetMark(const std::string& mark) {
        mmark = mark;
    }
    std::string GetMark() const {
        return mmark;
    }

    void Show() const override{
        std::cout << "Mark: " << this->GetMark() << std::endl;
        std::cout << "MaxSpeed: " << this->GetMaxSpeed() << std::endl;
        std::cout << "Car: " << this << std::endl;
    }
};

class Train :  public Transport_Vehicle {
private:
    int mcountCarriages = 0;
public:
    Train() {}
    Train(const int countCarriages, const int maxSpeed) : Transport_Vehicle(maxSpeed), mcountCarriages(countCarriages) {
        this->Add();
    }
    ~Train() {}

    void SetCountCarriages(const int countCarriage ) {
        mcountCarriages = countCarriage;
    }
    int GetCountCarriages() const {
        return mcountCarriages;
    }

    void Show() const override{
        std::cout << "Count of train carriages: " << this->GetCountCarriages() << std::endl;
        std::cout << "MaxSpeed: " << this->GetMaxSpeed() << std::endl;
        std::cout << "Train: " << this << std::endl;
    }
};

class Express : public Train {
private:
    int mcountPlaces = 0;
public:
    Express() {}
    Express(const int countPlaces, const int countCarriages, const int maxSpeed) : Train(countCarriages, maxSpeed), mcountPlaces(countPlaces) {
        this->Add();
    }
    ~Express() {}

    void SetCountPlaces(const int countPlaces) {
        mcountPlaces = countPlaces;
    }
    int GetCountPlaces() const {
        return mcountPlaces;
    }

    void Show() const override{
        std::cout << "Count of places: " << this->GetCountPlaces() << std::endl;
        std::cout << "MaxSpeed: " << this->GetMaxSpeed() << std::endl;
        std::cout << "Express: " << this << std::endl;
    }
};*/

int main()
{
    Car car1("BMW", 200);
    Train train1(10, 90);
    Express express1(100, 10, 150);
    Transport_Vehicle transport1;

    train1.SetCountCarriages(15);
    express1.SetCountPlaces(120);
    transport1.SetMaxSpeed(180);
    transport1.Add();
   
    Transport_Vehicle::Print();

    return 0;
}
