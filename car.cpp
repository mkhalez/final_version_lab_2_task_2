#include "car.h"

Car::Car() {}

void Car::CountrySet(QString country) {
    this->country_of_origin_ = std::move(country);
}

void Car::MarkSet(QString mark) {
    this->mark_of_car_ = std::move(mark);
}

void Car::EngineSet(QString engine) {
    this->engine_type_ = std::move(engine);
}

void Car::FuelSet(int fuel) {
    this->fuel_consumption_per_100_km_ = std::move(fuel);
}

void Car::CostSet(int cost) {
    this->cost_ = std::move(cost);
}

void Car::ReliabilitySet(int reliability) {
    this->reliability_ = std::move(reliability);
}

void Car::ComfortSet(int comfort) {
    this->comfort_ = std::move(comfort);
}


QString Car::CountryGet() {
    return country_of_origin_;
}

QString Car::MarkGet() {
    return mark_of_car_;
}
QString Car::EngineGet() {
    return engine_type_;
}

int Car::FuelGet() {
    return fuel_consumption_per_100_km_;
}

int Car::CostGet() {
    return cost_;
}

int Car::ReliabilityGet() {
    return reliability_;
}
int Car::ComfortGet() {
    return comfort_;
}
