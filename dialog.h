#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog {
    Q_OBJECT

   public:
    explicit Dialog(QWidget* parent = nullptr);
    ~Dialog();
    void InputDate(QString& mark_search, QString& engine_search,
                   QString& contry_search, QString& start_cost_search,
                   QString& finish_cost_search,
                   QString& start_reliability_search,
                   QString& finish_reliability_search,
                   QString& start_comfort_search,
                   QString& finish_comfort_search, QString& start_fuel_search,
                   QString& finish_fuel_search);

   private:
    Ui::Dialog* ui;

   private slots:
    void onAccepted();
    void onRejected();
};

#endif	// DIALOG_H
