#ifndef PATH_HPP_
#define PATH_HPP_

#include "Arduino.h"

class Path {
    public:
        Path();
        Path(const Path&);
        void add_path(uint8_t);
        void clear_path();
        uint8_t remove_last();
        uint8_t last_element() const;
        bool is_empty() const;
        String path() const;
        ~Path();
    private:
        uint8_t *path_;
        unsigned int path_length_;
        unsigned int n_;
};

#endif
