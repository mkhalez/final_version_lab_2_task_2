#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QStandardItemModel>
#include <QString>
#include "car.h"

class FileManager {
   public:
    FileManager();


   public:
    void SetPath(QString path);
    QString GetPath();
    void AppendvenLinesToFile(const QString& countr_of_origin,
                              const QString& mark_of_car,
                              const QString& engine_type, const QString& cost,
                              const QString& fuel_consumption_per_100_km,
                              const QString& reliability,
                              const QString& comfort);
    void ReplaceLineInFile();
    Car* ReadFromFile(Car* list_of_car, int& size);
    void UpdateFile(Car* list_of_car, const int& size);

   private:
    QString path_;
    void AddElement(Car*& list_of_cars, int& size);
};

#endif	// FILEMANAGER_H
