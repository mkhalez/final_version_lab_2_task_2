#ifndef CAR_H
#define CAR_H

#include <QString>

class Car {
   public:
    Car();
    void CountrySet(QString country);
    void MarkSet(QString mark);
    void EngineSet(QString engine);
    void FuelSet(int fuel);
    void CostSet(int cost);
    void ReliabilitySet(int reliability);
    void ComfortSet(int comfort);

    QString CountryGet();
    QString MarkGet();
    QString EngineGet();
    int FuelGet();
    int CostGet();
    int ReliabilityGet();
    int ComfortGet();

   private:
    QString country_of_origin_;
    QString mark_of_car_;
    QString engine_type_;
    int cost_;
    int fuel_consumption_per_100_km_;
    int reliability_;
    int comfort_;
};

#endif	// CAR_H
