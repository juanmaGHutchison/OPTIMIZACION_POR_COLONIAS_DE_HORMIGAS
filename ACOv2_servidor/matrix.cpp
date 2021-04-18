#include "matrix.h"
const int Matrix::map_[n_][n_]  =
{
  {0,4,1,INF,3,INF},
  {4,0,2,INF,INF,4},
  {1,2,0,INF,1,6},
  {INF,INF,INF,0,1,9},
  {3,INF,1,1,0,INF},
  {INF,4,6,9,INF,0}
};
Matrix::Matrix() {
    for(int i = 0; i < n_; i++)
        for(int j = 0; j < n_; j++)
            pheromones_[i][j] = (Rational_number(1,1) - EVAPORATION_COST);
}
QString Matrix::toString() const {
    QString str = "";
    for(int i = 0; i < n_; i++)
        for(int j = 0; j < n_; j++) {
            str += (i == (n_ - 1) && j == (n_ - 1))? pheromones_[i][j].toString() : (pheromones_[i][j].toString() + ",");
        }
    str += "E";
    return str;
}
QList<int> Matrix::adjacents_from_node(size_t node) {
    adjacents_.clear();
    for(size_t i = 0; i < n_; i++)
        if(map_[node][i] != INF && i != node)
            adjacents_.append(i);
    return adjacents_;
}
Matrix Matrix::operator = (const Matrix& m) {
    for(size_t i = 0; i < n_; i++)
        for(size_t j = 0; j < n_; j++)
            pheromones_[i][j] = m.pheromones_[i][j];
    return *this;
}
