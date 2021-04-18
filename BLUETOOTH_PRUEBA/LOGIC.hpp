#ifndef LOGIC_HPP_
#define LOGIC_HPP_

#include "Arduino.h"

#include "MAP.hpp"
#include "PATH.hpp"
#include "COMMON_TYPES.hpp"

class Logic {
    public:
        // CONSTRUCTOR
        Logic();

        class Way {
          public:
            const bool WAY_HOME = false;
            const bool WAY_TO_FOOD = true;
        
            Way(): way_ (WAY_TO_FOOD) {}
            bool WAY() const { return way_; }
            void WAY(bool way) { way_ = way; }
            String toString () const {
              String str = "";
              if(way_ == WAY_HOME) str = "Way Home"; 
              else str = "Way to Food";

              return str;
            }
          private:
            bool way_;
        };

        /*
         * uint8_t Proceed()
         * Precondition: -
         * Postcondition: Returns de grades from the next node
         */
        uint8_t Proceed(Color);
        uint8_t correction() const;
        bool isGoal(Color) const;
        bool isHome(Color) const;
        bool isNone(Color) const;
        bool toogle() const;
        bool& toogle();
        String actual_node_str() const;
        String path_str() const;
        String print_pheromones() const;
        void modify_pheromones(String);
        //String actual_adjacent_list() const;
        String way_str() const;
        
    private:
        Map map_;
        Path path_;
        bool first_;
        uint8_t correction_;
        Way way_;
        bool toogle_;
};



#endif
