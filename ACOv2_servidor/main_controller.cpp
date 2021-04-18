#include "main_controller.h"
Matrix& Main_controller::matrix() {
    return matrix_;
}
Path& Main_controller::path() {
    return path_;
}
const Path& Main_controller::path_from_str(QString str) {
    return path_.fromString(str);
}
