#ifndef MAIN_CONTROLLER_HPP_
#define MAIN_CONTROLLER_HPP_
#include "PERCEPTION.hpp"
#include "LOGIC.hpp"
#include "ACTUATION.hpp"
#include "COMMON_TYPES.hpp"
class Main_controller {
    public:
        //DEFAULT CONSTRUCTOR       
        void run_main_controller();
        Perception this_perception() const;
        Logic this_logic() const;
        Actuation this_actuation() const;
    private:
        Perception perception_;
        Logic logic_;
        Actuation actuation_;
        String inputString_;
        char inChar_;
        char continue_ = 'y';
};
#endif
