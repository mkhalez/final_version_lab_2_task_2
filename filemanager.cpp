#include "filemanager.h"
#include <QFile>

FileManager::FileManager() {
    path_ = "/home/mkh-alez/oaip_lab/lab_2/task2/task_2/example.txt";
}

void FileManager::SetPath(QString path) {
    this->path_ = std::move(path);
}

QString FileManager::GetPath() {
    return path_;
}

Car* FileManager::ReadFromFile(Car* list_of_car, int& size) {
    QFile input_file(path_);
    if (input_file.open(QIODevice::ReadOnly)) {
        QTextStream in(&input_file);
        int lineCounter = 0;

        int i = -1;

        while (!in.atEnd()) {


            if (lineCounter % 7 == 0) {
                AddElement(list_of_car, size);
                i++;
            }


            QString line = in.readLine().trimmed();


            switch (lineCounter % 7) {
                case 0:
                    list_of_car[i].MarkSet(line);
                    break;
                case 1:
                    list_of_car[i].EngineSet(line);
                    break;
                case 2:
                    list_of_car[i].CostSet(line.toInt());
                    break;
                case 3:
                    list_of_car[i].CountrySet(line);
                    break;
                case 4:
                    list_of_car[i].FuelSet(line.toInt());
                    break;
                case 5:
                    list_of_car[i].ReliabilitySet(line.toInt());
                    break;
                case 6: {
                    list_of_car[i].ComfortSet(line.toInt());
                    break;
                }
            }

            lineCounter++;
        }
        input_file.close();
    }
    return list_of_car;
}

void FileManager::AddElement(Car*& list_of_cars, int& size) {
    Car* new_array = new Car[size + 1];


    for (int i = 0; i < size; i++) {
        new_array[i] = list_of_cars[i];
    }
    delete[] list_of_cars;

    list_of_cars = new_array;

    size++;
}
