#include "validstring.h"

ValidString::ValidString() {}


bool ValidString::ValidInput() {
    bool ok;
    int new_cost = cost_.toInt(&ok);


    if (!ok) {
        return false;
    }

    int new_fuel = fuel_.toInt(&ok);


    if (!ok) {
        return false;
    }

    int new_reliability = reliability_.toInt(&ok);


    if (!ok) {
        return false;
    }

    int new_comfort = comfort_.toInt(&ok);


    if (!ok) {
        return false;
    }


    if (new_cost <= 0 || new_comfort <= 0 || new_comfort >= 10 ||
        new_fuel <= 0 || new_reliability <= 0) {
        return false;
    }

    return true;
}

bool ValidString::ValidDelete(int number_of_rows,
                              const QString& delete_element) {
    bool ok = true;
    int new_delete_element = delete_element.toInt(&ok);


    if (new_delete_element < 0 || new_delete_element > number_of_rows) {
        return false;
    }


    if (!ok) {
        return false;
    }

    return true;
}

bool ValidString::ValidSearch(const QString& start_cost_search,
                              const QString& finish_cost_search,
                              const QString& start_reliability_search,
                              const QString& finish_reliability_search,
                              const QString& start_comfort_search,
                              const QString& finish_comfort_search,
                              const QString& start_fuel_search,
                              const QString& finish_fuel_search) {
    bool ok_1 = true, ok_2 = true;
    int new_start_cost_search = start_cost_search.toInt(&ok_1);
    int new_finish_cost_search = finish_cost_search.toInt(&ok_2);


    if ((!start_cost_search.isEmpty() && !ok_1) ||
        (!finish_cost_search.isEmpty() && !ok_2)) {
        return false;
    }
    if ((!start_cost_search.isEmpty() && new_start_cost_search < 0) ||
        (!finish_cost_search.isEmpty() && new_finish_cost_search < 0) ||
        (!start_cost_search.isEmpty() && !finish_cost_search.isEmpty() &&
         new_start_cost_search > new_finish_cost_search)) {
        return false;
    }

    int new_start_reliability_search = start_reliability_search.toInt(&ok_1);
    int new_finish_reliability_search = finish_reliability_search.toInt(&ok_2);


    if ((!start_reliability_search.isEmpty() && !ok_1) ||
        (!finish_reliability_search.isEmpty() && !ok_2)) {
        return false;
    }
    if ((!start_reliability_search.isEmpty() &&
         new_start_reliability_search < 0) ||
        (!finish_reliability_search.isEmpty() &&
         new_finish_reliability_search < 0) ||
        (!start_reliability_search.isEmpty() &&
         !finish_reliability_search.isEmpty() &&
         new_start_reliability_search > new_finish_reliability_search)) {
        return false;
    }

    int new_start_comfort_search = start_comfort_search.toInt(&ok_1);
    int new_finish_comfort_search = finish_comfort_search.toInt(&ok_2);


    if ((!start_comfort_search.isEmpty() && !ok_1) ||
        (!finish_comfort_search.isEmpty() && !ok_2)) {
        return false;
    }
    if ((!start_comfort_search.isEmpty() && new_start_comfort_search < 0) ||
        (!finish_comfort_search.isEmpty() && new_finish_comfort_search < 0) ||
        (!start_comfort_search.isEmpty() && !finish_comfort_search.isEmpty() &&
         new_start_comfort_search > new_finish_comfort_search)) {
        return false;
    }

    int new_start_fuel_search = start_fuel_search.toInt(&ok_1);
    int new_finish_fuel_search = finish_fuel_search.toInt(&ok_2);


    if ((!start_fuel_search.isEmpty() && !ok_1) ||
        (!finish_fuel_search.isEmpty() && !ok_2)) {
        return false;
    }
    if ((!start_fuel_search.isEmpty() && new_start_fuel_search < 0) ||
        (!finish_fuel_search.isEmpty() && new_finish_fuel_search < 0) ||
        (!start_fuel_search.isEmpty() && !finish_fuel_search.isEmpty() &&
         new_start_fuel_search > new_finish_fuel_search)) {
        return false;
    }

    return true;
}

bool ValidString::ValidCorrectCost(const QString& cost_from_table) {
    bool ok;
    int new_cost = cost_from_table.toInt(&ok);


    if (!ok) {
        return false;
    }


    if (new_cost <= 0) {
        return false;
    }
    return true;
}

bool ValidString::ValidCorrectFuel(const QString& fuel_from_table) {
    bool ok;
    int new_fuel = fuel_from_table.toInt(&ok);


    if (!ok) {
        return false;
    }


    if (new_fuel <= 0) {
        return false;
    }
    return true;
}

bool ValidString::ValidCorrectReliability(const QString& reliability) {
    bool ok;
    int new_reliabiliry = reliability.toInt(&ok);


    if (!ok) {
        return false;
    }


    if (new_reliabiliry <= 0) {
        return false;
    }
    return true;
}

bool ValidString::ValidCorrectComfort(const QString& comfort) {
    bool ok;
    int new_comfort = comfort.toInt(&ok);


    if (!ok) {
        return false;
    }


    if (new_comfort <= 0 || new_comfort >= 10) {
        return false;
    }
    return true;
}

void ValidString::SetCost(QString cost) {
    this->cost_ = std::move(cost);
}

void ValidString::SetFuel(QString fuel) {
    this->fuel_ = std::move(fuel);
}

void ValidString::SetReliability(QString reliability) {
    this->reliability_ = std::move(reliability);
}

void ValidString::SetComfort(QString comfort) {
    this->comfort_ = std::move(comfort);
}
