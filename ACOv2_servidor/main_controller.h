#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H
#include <QString>
#include "matrix.h"
#include "path.h"
class Main_controller {
public:
    Matrix& matrix();
    Path& path();
    const Path& path_from_str(QString);
private:
    Matrix matrix_;
    Path path_;
};
#endif // MAIN_CONTROLLER_H
