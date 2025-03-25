#include "dialog.h"
#include "ui_dialog.h"

#include <QPushButton>

Dialog::Dialog(QWidget* parent) : QDialog(parent), ui(new Ui::Dialog) {
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this,
            &Dialog::onAccepted);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this,
            &Dialog::onRejected);
}

Dialog::~Dialog() {
    delete ui;
}

void Dialog::InputDate(
    QString& mark_search, QString& engine_search, QString& contry_search,
    QString& start_cost_search, QString& finish_cost_search,
    QString& start_reliability_search, QString& finish_reliability_search,
    QString& start_comfort_search, QString& finish_comfort_search,
    QString& start_fuel_search, QString& finish_fuel_search) {
    mark_search = ui->markSearchEdit->text();
    engine_search = ui->engineSearchEdit->text();
    contry_search = ui->countrySearchEdit->text();
    start_cost_search = ui->startCostSearchEdit->text();
    finish_cost_search = ui->finishCostSearchEdit->text();
    ;
    start_reliability_search = ui->startRealiabilitySearchEdit->text();
    finish_reliability_search = ui->finishRealiabilitySearchEdit->text();
    start_comfort_search = ui->startComfortSearchEdit->text();
    finish_comfort_search = ui->finishComfortSearchEdit->text();
    start_fuel_search = ui->startFuelSearchEdit->text();
    finish_fuel_search = ui->finishFuelSearchEdit->text();
}

void Dialog::onAccepted() {
    accept();
}

void Dialog::onRejected() {
    reject();
}
