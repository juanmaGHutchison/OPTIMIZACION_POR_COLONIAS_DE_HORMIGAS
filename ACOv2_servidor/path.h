#ifndef PATH_HPP_
#define PATH_HPP_
#include <cstdint>
#include <QString>
#include <QStringList>
#include "matrix.h"
class Path {
    public:
        Path();
        Path(const Path&);
        Path(QString);
        void add_path(int);
        void clear_path();
        int remove_last();
        int last_element() const;
        bool is_empty() const;
        QString path() const;
        int cost();
        const Path& fromString(QString);
        Matrix update_pheromones(Matrix&);
        ~Path();
    private:
        int *path_;
        unsigned int path_length_;
        unsigned int n_;
};
#endif
