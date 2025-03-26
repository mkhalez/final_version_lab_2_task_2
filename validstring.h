#ifndef VALIDSTRING_H
#define VALIDSTRING_H
#include <QString>

class ValidString {
   public:
    ValidString();
    void SetCost(QString cost);
    void SetFuel(QString fuel);
    void SetReliability(QString reliability);
    void SetComfort(QString comfort);
    bool ValidInput();
    bool ValidDelete(int number_of_rows, const QString& delete_element);
    bool ValidSearch(const QString& start_cost_search,
                     const QString& finish_cost_search,
                     const QString& start_reliability_search,
                     const QString& finish_reliability_search,
                     const QString& start_comfort_search,
                     const QString& finish_comfort_search,
                     const QString& start_fuel_search,
                     const QString& finish_fuel_search);

    bool ValidCorrectCost(const QString& cost_from_table);
    bool ValidCorrectFuel(const QString& fuel_from_table);
    bool ValidCorrectReliability(const QString& reliability);
    bool ValidCorrectComfort(const QString& comfort);


   private:
    QString cost_;
    QString fuel_;
    QString reliability_;
    QString comfort_;
};

#endif	// VALIDSTRING_H
