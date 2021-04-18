#include "path.h"
Path::Path() :
    path_length_ (0),
    n_ (51)
    {
        path_ = new int[n_];    
        for(size_t i = 0; i < n_; i++)
            path_[i] = -1;
        ++path_length_;
        path_[path_length_ - 1] = 0;
    }
Path::Path(const Path& p) :
    path_length_ (p.path_length_),
    n_ (p.n_)
    {
        path_ = new int[n_];
        for(size_t i = 0; i < n_; i++)
            path_[i] = p.path_[i];
    }
Path::Path(QString str) {
   QStringList pieces = str.split(",");
   QStringList numbers;
   n_ = pieces.size();
   int i = 0;
   for(const auto& p : pieces) {
       path_[i] = p.toInt();
       path_length_ ++;
   }
}
void Path::add_path(int element) {
    if(path_length_ < n_) {
        ++ path_length_;
        path_[path_length_ - 1] = element;
        path_[path_length_] = -1;
    }
}
void Path::clear_path() {
    path_length_ = 0;
    for(size_t i = 0; i < n_; i++)
            path_[i] = -1;
    ++path_length_;
    path_[path_length_ - 1] = 0;
}
int Path::remove_last() {
  int element_to_return = path_[path_length_ - 1];
  path_[path_length_ - 1] = -1;
  --path_length_;
  return element_to_return;
}
int Path::cost() {
    int previous, next;
    int cost = 0;
    for(unsigned int i = 0; i < path_length_; i++) {
        previous = path_[i];
        next = path_[(i + 1)];
        cost += Matrix::map_[previous][next];
    }
    return cost;
}
int Path::last_element() const {
    return path_[path_length_ - 1];
}
bool Path::is_empty() const {
  return path_length_ == 0;
}
QString Path::path() const {
    QString str = "";
    int aux;
    for(size_t i = 0; i < path_length_; i++) {
        aux = path_[i];
        str += (i == (path_length_ - 1))?
               QString(aux) : QString(aux) + "->";
    }
    qDebug() << "lets see: " << str;
    return str;
}
const Path& Path::fromString(QString str) {
    QStringList str_list = str.split(",");
    path_length_ = 0;
    for(int i = 0; i < (str_list.size()); i++)
        add_path(str_list[i].toInt());
    return *this;
}
Matrix Path::update_pheromones(Matrix& matrix) {
    int fnode, snode;
    float aux;
    for(size_t i = 0; i < matrix.n_; i++)
        for(size_t j = 0; j < matrix.n_; j++) {
            matrix.pheromones_[i][j].from_float_to_rational(matrix.pheromones_[i][j].resolv() * (Rational_number(1,1) - matrix.EVAPORATION_COST).resolv());
            matrix.pheromones_[j][i] = matrix.pheromones_[i][j];
            qDebug() << i << ", " << j << ": " << matrix.pheromones_[i][j].resolv();
        }
    for(size_t i = 0; i < (path_length_ - 1); i++) {
        fnode = path_[i];
        snode = path_[i + 1];
        aux = matrix.pheromones_[fnode][snode].resolv();
        aux += (float(1) / float(cost()));
        matrix.pheromones_[fnode][snode] = Rational_number(aux);
        matrix.pheromones_[snode][fnode] = matrix.pheromones_[fnode][snode];
    }
    return matrix;
}
Path::~Path() {
    delete [] path_;
}
