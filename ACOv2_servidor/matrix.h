#ifndef MATRIX_H
#define MATRIX_H
#include <QString>
#include <QtDebug>
#include <QList>
#include "rational.h"
class Matrix {
public:
    Matrix();
    QString toString() const;
    QList<int> adjacents_from_node(size_t node);
    //void evaporate (size_t);
    static const int n_ = 6;
    static const int INF = 255;
    const Rational_number EVAPORATION_COST;
    Rational_number pheromones_ [n_][n_];
    static const int map_[n_][n_];
    Matrix operator = (const Matrix&);
private:
    QList<int> adjacents_;
};
#endif // MATRIX_H
