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

void FileManager::AppendvenLinesToFile(
    const QString& countr_of_origin, const QString& mark_of_car,
    const QString& engine_type, const QString& cost,
    const QString& fuel_consumption_per_100_km, const QString& reliability,
    const QString& comfort) {
    QFile file(path_);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qWarning() << "Could not open file for appending:" << path_;
        return;
    }

    QTextStream out(&file);

    // 3. Записываем свойства нового объекта (каждое свойство на новой строке)
    out << mark_of_car << "\n";
    out << engine_type << "\n";
    out << cost << "\n";
    out << countr_of_origin << "\n";
    out << fuel_consumption_per_100_km << "\n";
    out << reliability << "\n";
    out << comfort << "\n";

    file.close();
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

void FileManager::UpdateFile(Car* list_of_car, const int& size) {
    QFile input_file(path_);
    if (input_file.open(QIODevice::WriteOnly | QIODevice::Text)) {


        QTextStream out(&input_file);

        for (int i = 0; i < size; i++) {
            out << list_of_car[i].MarkGet() << "\n";
            out << list_of_car[i].EngineGet() << "\n";
            out << QString::number(list_of_car[i].CostGet()) << "\n";
            out << list_of_car[i].CountryGet() << "\n";
            out << QString::number(list_of_car[i].FuelGet()) << "\n";
            out << QString::number(list_of_car[i].ReliabilityGet()) << "\n";
            out << QString::number(list_of_car[i].ComfortGet()) << "\n";
        }
        input_file.close();
    }
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
