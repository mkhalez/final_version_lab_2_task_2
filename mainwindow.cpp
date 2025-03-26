#include "mainwindow.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include "validstring.h"

const int kCols = 7;
const int kCol0 = 0;
const int kCol1 = 1;
const int kCol2 = 2;
const int kCol3 = 3;
const int kCol4 = 4;
const int kCol5 = 5;
const int kCol6 = 6;

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->comboBox->addItem("only mark of car");
    ui->comboBox->addItem("engine type");
    ui->comboBox->addItem("cost");
    ui->comboBox->addItem("country of origin");
    ui->comboBox->addItem("fuel consumption per 100 km");
    ui->comboBox->addItem("reliability");
    ui->comboBox->addItem("comfort");


    Init(manager_.our_file.GetPath());

    connect(ui->addToListButton, &QPushButton::clicked, this,
            &MainWindow::AddToListHelper);
    connect(ui->deleteButton, &QPushButton::clicked, this,
            &MainWindow::DeleteElementHelper);
    connect(ui->correctButton, &QPushButton::clicked, this,
            &MainWindow::CorrectElementsHelper);
    connect(ui->sortButton, &QPushButton::clicked, this,
            &MainWindow::SortByMarkHelper);
    connect(ui->searchButton, &QPushButton::clicked, this,
            &MainWindow::SearchDialog);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::AddToListHelper() {
    QString countr_of_origin = ui->countryEdit->text();
    QString mark_of_car = ui->markCarEdit->text();
    QString engine_type = ui->EngineTypeEdit->text();
    QString cost = ui->costEdit->text();
    QString fuel_consumption_per_100_km = ui->fuelEdit->text();
    QString reliability = ui->relabilityEdit->text();
    QString comfort = ui->comfortEdit->text();

    ValidString check_input;
    check_input.SetComfort(comfort);
    check_input.SetCost(cost);
    check_input.SetFuel(fuel_consumption_per_100_km);
    check_input.SetReliability(reliability);

    try {
        if (!check_input.ValidInput()) {
            throw std::invalid_argument("Invalid input format or value");
        }

        manager_.AddToList(countr_of_origin, mark_of_car, engine_type, cost,
                           fuel_consumption_per_100_km, reliability, comfort);

        QList<QStandardItem*> new_row;
        new_row << new QStandardItem(mark_of_car)
                << new QStandardItem(engine_type) << new QStandardItem(cost)
                << new QStandardItem(countr_of_origin)
                << new QStandardItem(fuel_consumption_per_100_km)
                << new QStandardItem(reliability) << new QStandardItem(comfort);
        manager_.model->appendRow(new_row);

        ui->countryEdit->clear();
        ui->markCarEdit->clear();
        ui->EngineTypeEdit->clear();
        ui->costEdit->clear();
        ui->fuelEdit->clear();
        ui->relabilityEdit->clear();
        ui->comfortEdit->clear();

    } catch (const std::invalid_argument& e) {
        ui->countryEdit->clear();
        ui->markCarEdit->clear();
        ui->EngineTypeEdit->clear();
        ui->costEdit->clear();
        ui->fuelEdit->clear();
        ui->relabilityEdit->clear();
        ui->comfortEdit->clear();
    }


    QHeaderView* header_1 = ui->view->horizontalHeader();
    QHeaderView* header_2 = ui->view->verticalHeader();
    header_1->setSectionResizeMode(QHeaderView::Stretch);
    header_2->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::DeleteElementHelper() {
    QString number_str = ui->deleteEdit->text();
    ValidString check_delete;
    try {
        if (!check_delete.ValidDelete(manager_.model->rowCount(), number_str)) {
            throw std::invalid_argument("Invalid delete format or value");
        }

        int number_int = number_str.toInt();

        manager_.DeleteElementFromList(number_int - 1);

        manager_.model->removeRow(number_int - 1);
        ui->deleteEdit->clear();

    } catch (const std::invalid_argument& e) {
        ui->deleteEdit->clear();
    }
}

void MainWindow::CorrectElementsHelper() {
    manager_.CorrectElemetsList();
}

void MainWindow::SortByMarkHelper() {
    if (manager_.GetSize() > 0) {
        manager_.Sort(0, manager_.GetSize() - 1, 0);

        if (ui->comboBox->currentIndex() != 0) {
            manager_.SortAdditional(ui->comboBox->currentIndex());
        }

        manager_.UpdateModel();
    }
}


void MainWindow::Init(QString path) {
    manager_.our_file.SetPath(std::move(path));
    manager_.model = new QStandardItemModel(0, kCols);
    // установка заголовков таблицы
    manager_.model->setHeaderData(kCol0, Qt::Horizontal, "mark of car:");
    manager_.model->setHeaderData(kCol1, Qt::Horizontal, "engine type:");
    manager_.model->setHeaderData(kCol2, Qt::Horizontal, "cost:");
    manager_.model->setHeaderData(kCol3, Qt::Horizontal, "country of origin:");
    manager_.model->setHeaderData(kCol4, Qt::Horizontal,
                                  "fuel consumption per 100 km:");
    manager_.model->setHeaderData(kCol5, Qt::Horizontal, "reliability:");
    manager_.model->setHeaderData(kCol6, Qt::Horizontal, "comfort");

    ui->view->setModel(manager_.model);

    manager_.SetSize(0);
    manager_.SetList();

    int new_size = manager_.GetSize();

    Car* new_list =
        manager_.our_file.ReadFromFile(manager_.GetListOfCar(), new_size);
    manager_.SetSize(new_size);
    manager_.SetListOfCar(new_list);

    for (int i = 0; i < manager_.GetSize(); i++) {
        qDebug() << manager_.GetListOfCar()[i].MarkGet()
                 << manager_.GetListOfCar()[i].EngineGet()
                 << manager_.GetListOfCar()[i].CostGet()
                 << manager_.GetListOfCar()[i].CountryGet()
                 << manager_.GetListOfCar()[i].FuelGet()

                 << manager_.GetListOfCar()[i].ReliabilityGet()
                 << manager_.GetListOfCar()[i].ComfortGet();
    }

    for (int i = 0; i < manager_.GetSize(); i++) {
        QString mark_of_car = manager_.GetListOfCar()[i].MarkGet();
        QString engine_type = manager_.GetListOfCar()[i].EngineGet();
        int cost = manager_.GetListOfCar()[i].CostGet();
        QString countr_of_origin = manager_.GetListOfCar()[i].CountryGet();
        int fuel_consumption_per_100_km = manager_.GetListOfCar()[i].FuelGet();
        int reliability = manager_.GetListOfCar()[i].ReliabilityGet();
        int comfort = manager_.GetListOfCar()[i].ComfortGet();


        QList<QStandardItem*> new_row;
        new_row << new QStandardItem(mark_of_car)
                << new QStandardItem(engine_type)
                << new QStandardItem(QString::number(cost))
                << new QStandardItem(countr_of_origin)
                << new QStandardItem(
                       QString::number(fuel_consumption_per_100_km))
                << new QStandardItem(QString::number(reliability))
                << new QStandardItem(QString::number(comfort));
        manager_.model->appendRow(new_row);
    }


    //выравнивание таблицы по tableview
    QHeaderView* header_1 = ui->view->horizontalHeader();
    QHeaderView* header_2 = ui->view->verticalHeader();
    header_1->setSectionResizeMode(QHeaderView::Stretch);
    header_2->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::SearchDialog() {
    Dialog dialog(this);
    QVector<Car> copy;
    ValidString check_search;
    if (dialog.exec() == QDialog::Accepted) {
        ui->listWid->clear();
        QString mark_search, engine_search, contry_search, start_cost_search,
            finish_cost_search, start_reliability_search,
            finish_reliability_search, start_comfort_search,
            finish_comfort_search, start_fuel_search, finish_fuel_search;
        dialog.InputDate(mark_search, engine_search, contry_search,
                         start_cost_search, finish_cost_search,
                         start_reliability_search, finish_reliability_search,
                         start_comfort_search, finish_comfort_search,
                         start_fuel_search, finish_fuel_search);

        try {
            if (!check_search.ValidSearch(
                    start_cost_search, finish_cost_search,
                    start_reliability_search, finish_reliability_search,
                    start_comfort_search, finish_comfort_search,
                    start_fuel_search, finish_fuel_search)) {
                throw std::invalid_argument("Invalid search format or value");
            }

            copy = manager_.Search(
                mark_search, engine_search, contry_search, start_cost_search,
                finish_cost_search, start_reliability_search,
                finish_reliability_search, start_comfort_search,
                finish_comfort_search, start_fuel_search, finish_fuel_search);

            QVector<QString> list_of_string_element_car;
            for (int i = 0; i < copy.size(); i++) {
                list_of_string_element_car.append(
                    copy[i].MarkGet() + " " + copy[i].EngineGet() + " " +
                    QString::number(copy[i].CostGet()) + " " +
                    copy[i].CountryGet() + " " +
                    QString::number(copy[i].FuelGet()) + " " +
                    QString::number(copy[i].ReliabilityGet()) + " " +
                    QString::number(copy[i].ComfortGet()));
            }


            for (int i = 0; i < list_of_string_element_car.size(); i++) {
                QListWidgetItem* item = new QListWidgetItem(
                    list_of_string_element_car[i], ui->listWid);

                ui->listWid->addItem(item);

                QListWidgetItem* space = new QListWidgetItem;
                space->setSizeHint(QSize(0, 2));
                space->setFlags(Qt::NoItemFlags);

                space->setBackground(Qt::gray);
                ui->listWid->addItem(space);
            }

        } catch (const std::invalid_argument& e) {
            QListWidgetItem* item =
                new QListWidgetItem("search error", ui->listWid);

            ui->listWid->addItem(item);
        }
    }

    /*for (int i = 0; i < copy.size(); i++) {
        qDebug() << copy[i].MarkGet() << copy[i].EngineGet()
                 << copy[i].CostGet() << copy[i].CountryGet()
                 << copy[i].FuelGet() << copy[i].ReliabilityGet()
                 << copy[i].ComfortGet();
    }*/
}
