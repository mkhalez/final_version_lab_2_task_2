#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "programmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

   private:
    Ui::MainWindow* ui;
    ProgramManager manager_;
    void Init();


   private slots:
    void AddToListHelper();
    void DeleteElementHelper();
    void CorrectElementsHelper();
    void SortByMarkHelper();
};
#endif	// MAINWINDOW_H
