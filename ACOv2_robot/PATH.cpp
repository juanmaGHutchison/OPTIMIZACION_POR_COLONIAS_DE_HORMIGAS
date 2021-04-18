#include "PATH.hpp"
Path::Path() :
    path_length_ (0),
    n_ (51)
    {
        path_ = new uint8_t[n_];
        
        for(int i = 0; i < n_; i++)
            path_[i] = -1;

        ++path_length_;
        path_[path_length_ - 1] = 0;
    }
Path::Path(const Path& p) :
    path_length_ (p.path_length_),
    n_ (p.n_)
    {
        path_ = new uint8_t[n_];
        for(int i = 0; i < n_; i++)
            path_[i] = p.path_[i];
    }
Path Path::operator = (Path p) {
  path_length_ = p.path_length_;
  n_ = p.n_;

  path_ = new uint8_t[n_];
        for(int i = 0; i < path_length_; i++)
            path_[i] = p.path_[i];
}
void Path::add_path(uint8_t element) {
    if(path_length_ < n_) {
        ++ path_length_;
        path_[path_length_ - 1] = element;
        path_[path_length_] = -1;
    }
}
void Path::clear_path() {
    path_length_ = 0;
    for(int i = 0; i < n_; i++)
            path_[i] = -1;
    
    ++path_length_;
    path_[path_length_ - 1] = 0;
}
uint8_t Path::remove_last() {
  uint8_t element_to_return = path_[path_length_ - 1];

  path_[path_length_ - 1] = -1;
  --path_length_;

  return element_to_return;
}
uint8_t Path::last_element() const {
    return path_[path_length_ - 1];
}
bool Path::is_empty() const {
  return path_length_ == 0;
}
String Path::path() const {
    String str = "";

    for(int i = 0; i < path_length_; i++)
        str += ((i < (path_length_ - 1)))?
                String(path_[i]) + "," : String(path_[i]);

    return str;
}
Path::~Path() {
    delete [] path_;
}
