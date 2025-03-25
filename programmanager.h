#ifndef PROGRAMMANAGER_H
#define PROGRAMMANAGER_H

#include <QStandardItemModel>
#include "car.h"

class ProgramManager {
   public:
    ProgramManager();
    ~ProgramManager();

   private:
    Car* list_of_cars_;
    int size_;
    void AddElement(Car*& list_of_cars, int& size);


   public:
    void AddToList(QString countr_of_origin, QString mark_of_car,
                   QString engine_type, const QString& cost,
                   const QString& fuel_consumption_per_100_km,
                   const QString& reliability, const QString& comfort);
    QStandardItemModel* model;
    void SetSize(int size);
    int GetSize();
    void SetList();
    void DeleteElementFromList(int index);
    void CorrectElemetsList();
    void Sort(int left, int right, int index_for_getter);
    QVariant Getter(int index_for_getter, int j);
    void UpdateModel();
    void SortAdditional(int index_for_getter);
};

#endif	// PROGRAMMANAGER_H
