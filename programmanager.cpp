#include "programmanager.h"
#include <validstring.h>
#include <QDebug>
#include <QVector>


ProgramManager::ProgramManager() {
    size_ = 0;
    list_of_cars_ = new Car[size_];
}

ProgramManager::~ProgramManager() {
    delete[] list_of_cars_;
}

void ProgramManager::AddToList(QString countr_of_origin, QString mark_of_car,
                               QString engine_type, const QString& cost,
                               const QString& fuel_consumption_per_100_km,
                               const QString& reliability,
                               const QString& comfort) {

    AddElement(list_of_cars_, size_);

    list_of_cars_[size_ - 1].CountrySet(std::move(countr_of_origin));
    list_of_cars_[size_ - 1].MarkSet(std::move(mark_of_car));
    list_of_cars_[size_ - 1].EngineSet(std::move(engine_type));
    list_of_cars_[size_ - 1].CostSet((cost).toInt());
    list_of_cars_[size_ - 1].FuelSet(fuel_consumption_per_100_km.toInt());
    list_of_cars_[size_ - 1].ReliabilitySet(reliability.toInt());
    list_of_cars_[size_ - 1].ComfortSet(comfort.toInt());


    /*for (int i = 0; i < size_; i++) {
        qDebug() << list_of_cars_[i].MarkGet() << list_of_cars_[i].EngineGet()
                 << list_of_cars_[i].CostGet() << list_of_cars_[i].CountryGet()
                 << list_of_cars_[i].FuelGet()

                 << list_of_cars_[i].ReliabilityGet()
                 << list_of_cars_[i].ComfortGet();
    }*/
}


void ProgramManager::AddElement(Car*& list_of_cars, int& size) {
    Car* new_array = new Car[size + 1];


    for (int i = 0; i < size; i++) {
        new_array[i] = list_of_cars[i];
    }
    delete[] list_of_cars;

    list_of_cars = new_array;

    size++;
}

Car* ProgramManager::GetListOfCar() {
    return list_of_cars_;
}

void ProgramManager::SetListOfCar(Car* new_list) {
    list_of_cars_ = new_list;
}

void ProgramManager::SetSize(int size) {
    this->size_ = std::move(size);
}

int ProgramManager::GetSize() {
    return size_;
}

void ProgramManager::SetList() {
    delete[] list_of_cars_;
    list_of_cars_ = new Car[size_];
}

void ProgramManager::DeleteElementFromList(int index) {
    Car* new_array = new Car[size_ - 1];


    for (int i = 0, j = 0; i < size_; i++) {


        if (i == index) {
            continue;
        }
        new_array[j] = list_of_cars_[i];
        j++;
    }

    delete[] list_of_cars_;

    list_of_cars_ = new_array;
    new_array = nullptr;
    size_--;


    for (int i = 0; i < size_; i++) {
        qDebug() << list_of_cars_[i].ComfortGet() << list_of_cars_[i].CostGet()
                 << list_of_cars_[i].CountryGet()
                 << list_of_cars_[i].EngineGet() << list_of_cars_[i].FuelGet()
                 << list_of_cars_[i].MarkGet()
                 << list_of_cars_[i].ReliabilityGet();
    }
}

void ProgramManager::CorrectElemetsList() {

    ValidString check_correct;

    for (int i = 0; i < model->rowCount(); i++) {

        QString value_list[7];


        for (int j = 0; j < 7; j++) {
            value_list[j] = model->item(i, j)->text();
        }

        if (list_of_cars_[i].MarkGet() != value_list[0]) {
            list_of_cars_[i].MarkSet(value_list[0]);
        }

        if (list_of_cars_[i].EngineGet() != value_list[1]) {
            list_of_cars_[i].EngineSet(value_list[1]);
        }

        if (list_of_cars_[i].CostGet() != value_list[2].toInt() &&
            check_correct.ValidCorrectCost(value_list[2])) {
            list_of_cars_[i].CostSet(value_list[2].toInt());
        }

        if (list_of_cars_[i].CountryGet() != value_list[3]) {
            list_of_cars_[i].CountrySet(value_list[3]);
        }

        if (list_of_cars_[i].FuelGet() != value_list[4].toInt() &&
            check_correct.ValidCorrectFuel(value_list[4])) {
            list_of_cars_[i].FuelSet(value_list[4].toInt());
        }

        if (list_of_cars_[i].ReliabilityGet() != value_list[5].toInt() &&
            check_correct.ValidCorrectReliability(value_list[5])) {
            list_of_cars_[i].ReliabilitySet(value_list[5].toInt());
        }

        if (list_of_cars_[i].ComfortGet() != value_list[6].toInt() &&
            check_correct.ValidCorrectComfort(value_list[6])) {
            list_of_cars_[i].ComfortSet(value_list[6].toInt());
        }


        UpdateModel();

        /*manager_.model->setHeaderData(kCol0, Qt::Horizontal, "mark of car:");
        manager_.model->setHeaderData(kCol1, Qt::Horizontal, "engine type:");
        manager_.model->setHeaderData(kCol2, Qt::Horizontal, "cost:");
        manager_.model->setHeaderData(kCol3, Qt::Horizontal, "country of origin:");
        manager_.model->setHeaderData(kCol4, Qt::Horizontal,
                                      "fuel consumption per 100 km:");
        manager_.model->setHeaderData(kCol5, Qt::Horizontal, "reliability:");
        manager_.model->setHeaderData(kCol6, Qt::Horizontal, "comfort");

        QStandardItem* item_0 = model->item(i, 0);
        QStandardItem* item_1 = model->item(i, 1);
        QStandardItem* item_2 = model->item(i, 2);
        QStandardItem* item_3 = model->item(i, 3);
        QStandardItem* item_4 = model->item(i, 4);
        QStandardItem* item_5 = model->item(i, 5);
        QStandardItem* item_6 = model->item(i, 6);*/
    }


    for (int i = 0; i < size_; i++) {
        qDebug() << list_of_cars_[i].MarkGet() << list_of_cars_[i].EngineGet()
                 << list_of_cars_[i].CostGet() << list_of_cars_[i].CountryGet()
                 << list_of_cars_[i].FuelGet()

                 << list_of_cars_[i].ReliabilityGet()
                 << list_of_cars_[i].ComfortGet();
    }
}

void ProgramManager::Sort(int left, int right, int index_for_getter) {
    Car pivot;
    int index;
    int l_hold = left;
    int r_hold = right;
    pivot = list_of_cars_[left];

    if (index_for_getter != 0 && index_for_getter != 1 &&
        index_for_getter != 3) {


        while (left < right) {
            while (
                (/*list_of_cars_[right].MarkGet()*/ (
                     Getter(index_for_getter, right))
                     .toInt() >
                 /*pivot.MarkGet()*/ Getter(index_for_getter, left).toInt()) &&
                (left < right)) {
                right--;
            }

            if (left != right) {
                list_of_cars_[left] = list_of_cars_[right];
                left++;
            }
            while ((/*list_of_cars_[left].MarkGet()*/ Getter(index_for_getter,
                                                             left)
                        .toInt() < Getter(index_for_getter, left).toInt()) &&
                   (left < right)) {
                left++;
            }
            if (left != right) {
                list_of_cars_[right] = list_of_cars_[left];
                right--;
            }
        }
    } else {


        while (left < right) {
            while ((/*list_of_cars_[right].MarkGet()*/ (
                        Getter(index_for_getter, right))
                        .toString() >
                    /*pivot.MarkGet()*/ Getter(index_for_getter, left)
                        .toString()) &&
                   (left < right)) {
                right--;
            }

            if (left != right) {
                list_of_cars_[left] = list_of_cars_[right];
                left++;
            }
            while (
                (/*list_of_cars_[left].MarkGet()*/ Getter(index_for_getter,
                                                          left)
                     .toString() < Getter(index_for_getter, left).toString()) &&
                (left < right)) {
                left++;
            }
            if (left != right) {
                list_of_cars_[right] = list_of_cars_[left];
                right--;
            }
        }
    }


    list_of_cars_[left] = pivot;
    index = left;
    left = l_hold;
    right = r_hold;


    if (left < index) {
        Sort(left, index - 1, index_for_getter);
    }


    if (right > index) {
        Sort(index + 1, right, index_for_getter);
    }
}

/*


    for (int i = 0; i < size_; i++) {
        qDebug() << list_of_cars_[i].ComfortGet() << list_of_cars_[i].CostGet()
                 << list_of_cars_[i].CountryGet()
                 << list_of_cars_[i].EngineGet() << list_of_cars_[i].FuelGet()
                 << list_of_cars_[i].MarkGet()
                 << list_of_cars_[i].ReliabilityGet();
    }*/

void ProgramManager::SortAdditional(int index_for_getter) {
    QString current_mark = list_of_cars_[0].MarkGet();
    int start = 0;


    for (int i = 0; i < size_; i++) {
        if (current_mark != list_of_cars_[i].MarkGet()) {
            Sort(start, i - 1, index_for_getter);
            start = i;
            current_mark = list_of_cars_[i].MarkGet();
        }
        if (i == size_ - 1) {
            Sort(start, i, index_for_getter);
        }
    }
}

QVector<Car> ProgramManager::Search(
    QString mark_search, QString engine_search, QString contry_search,
    QString start_cost_search, QString finish_cost_search,
    QString start_reliability_search, QString finish_reliability_search,
    QString start_comfort_search, QString finish_comfort_search,
    QString start_fuel_search, QString finish_fuel_search) {

    QVector<Car> vector;


    for (int i = 0; i < size_; i++) {
        if (mark_search.isEmpty() ||
            list_of_cars_[i].MarkGet() == mark_search) {
            if (engine_search.isEmpty() ||
                list_of_cars_[i].EngineGet() == engine_search) {
                if (contry_search.isEmpty() ||
                    list_of_cars_[i].CountryGet() == contry_search) {
                    if (start_cost_search.isEmpty() ||
                        list_of_cars_[i].CostGet() >=
                            start_cost_search.toInt()) {
                        if (finish_cost_search.isEmpty() ||
                            list_of_cars_[i].CostGet() <=
                                finish_cost_search.toInt()) {
                            if (start_reliability_search.isEmpty() ||
                                list_of_cars_[i].ReliabilityGet() >=
                                    start_reliability_search.toInt()) {
                                if (finish_reliability_search.isEmpty() ||
                                    list_of_cars_[i].ReliabilityGet() <=
                                        finish_reliability_search.toInt()) {
                                    if (start_comfort_search.isEmpty() ||
                                        list_of_cars_[i].ComfortGet() >=
                                            start_comfort_search.toInt()) {
                                        if (finish_comfort_search.isEmpty() ||
                                            list_of_cars_[i].ComfortGet() <=
                                                finish_comfort_search.toInt()) {
                                            if (start_fuel_search.isEmpty() ||
                                                list_of_cars_[i].ComfortGet() >=
                                                    start_fuel_search.toInt()) {
                                                if (finish_fuel_search
                                                        .isEmpty() ||
                                                    list_of_cars_[i]
                                                            .ComfortGet() <=
                                                        finish_fuel_search
                                                            .toInt()) {
                                                    vector.append(
                                                        list_of_cars_[i]);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }


    for (int i = 0; i < vector.size(); i++) {
        qDebug() << vector[i].MarkGet() << vector[i].EngineGet()
                 << vector[i].CostGet() << vector[i].CountryGet()
                 << vector[i].FuelGet() << vector[i].ReliabilityGet()
                 << vector[i].ComfortGet();
    }
    return vector;
}

QVariant ProgramManager::Getter(int index_for_getter, int j) {


    switch (index_for_getter) {
        case 0: {
            return list_of_cars_[j].MarkGet();
        }
        case 1: {
            return list_of_cars_[j].EngineGet();
        }
        case 2: {
            return list_of_cars_[j].CostGet();
        }
        case 3: {
            return list_of_cars_[j].CountryGet();
        }
        case 4: {
            return list_of_cars_[j].FuelGet();
        }
        case 5: {
            return list_of_cars_[j].ReliabilityGet();
        }
        case 6: {
            return list_of_cars_[j].ComfortGet();
        }
    }
    return 0;
}

void ProgramManager::UpdateModel() {

    model->removeRows(0, model->rowCount());


    for (int i = 0; i < size_; i++) {
        QList<QStandardItem*> new_row;
        new_row
            << new QStandardItem(list_of_cars_[i].MarkGet())
            << new QStandardItem(list_of_cars_[i].EngineGet())
            << new QStandardItem(QString::number(list_of_cars_[i].CostGet()))
            << new QStandardItem(list_of_cars_[i].CountryGet())
            << new QStandardItem(QString::number(list_of_cars_[i].FuelGet()))
            << new QStandardItem(
                   QString::number(list_of_cars_[i].ReliabilityGet()))
            << new QStandardItem(
                   QString::number(list_of_cars_[i].ComfortGet()));
        model->appendRow(new_row);
    }
}

/*
    ui->comboBox->addItem("only mark of car");
    ui->comboBox->addItem("engine type");
    ui->comboBox->addItem("cost");
    ui->comboBox->addItem("country of origin");
    ui->comboBox->addItem("fuel consumption per 100 km");
    ui->comboBox->addItem("reliability");
    ui->comboBox->addItem("comfort");
*/
