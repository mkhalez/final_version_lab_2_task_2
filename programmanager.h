#ifndef PROGRAMMANAGER_H
#define PROGRAMMANAGER_H

#include <QStandardItemModel>
#include "car.h"
#include "filemanager.h"

class ProgramManager {
   public:
    ProgramManager();
    ~ProgramManager();

   private:
    Car* list_of_cars_;
    int size_;
    void AddElement(Car*& list_of_cars, int& size);


   public:
    FileManager our_file;
    Car* GetListOfCar();
    void SetListOfCar(Car* new_list);

    void AddToList(QString countr_of_origin, QString mark_of_car,
                   QString engine_type, const QString& cost,
                   const QString& fuel_consumption_per_100_km,
                   const QString& reliability, const QString& comfort);
    QStandardItemModel* model;
    QString path;
    void SetSize(int size);
    int GetSize();
    void SetList();
    void DeleteElementFromList(int index);
    void CorrectElemetsList();
    void Sort(int left, int right, int index_for_getter);
    QVariant Getter(int index_for_getter, int j);

    void UpdateModel();
    void SortAdditional(int index_for_getter);
    QVector<Car> Search(QString mark_search, QString engine_search,
                        QString contry_search, QString start_cost_search,
                        QString finish_cost_search,
                        QString start_reliability_search,
                        QString finish_reliability_search,
                        QString start_comfort_search,
                        QString finish_comfort_search,
                        QString start_fuel_search, QString finish_fuel_search);
};

#endif	// PROGRAMMANAGER_H
