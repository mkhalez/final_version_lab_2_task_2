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
    void AppendLineToFile();
    void ReplaceLineInFile();
    Car* ReadFromFile(Car* list_of_car, int& size);
    void Save();

   private:
    QString path_;
    void AddElement(Car*& list_of_cars, int& size);
};

#endif	// FILEMANAGER_H
