#include "LOGIC.hpp"
Logic::Logic():
  map_ (0),
  first_(true),
  continue_('y')
  {
  }
uint8_t Logic::Proceed(Color color) {
  Map::summit next_node;
  uint8_t selected_grade, actual_node_path;
  String on_transmit = "0";
  char junk;
  if(isHome(color)) way_.WAY( way_.WAY_TO_FOOD );
  if(isGoal(color)) way_.WAY( way_.WAY_HOME );
  if(way_.WAY() == way_.WAY_HOME || isGoal(color)) {
    if(isGoal(color)) {
      //final_path_ = path_;
      map_.grades_toogle_conversion();
      toogle_ = true; 
      //Serial.println("IS GOAL");
      /*Serial.print("Common toogle: ");
      Serial.println(toogle_);*/
    }
    /*Serial.print("PATH POP ");
    if(way_.WAY() == way_.WAY_HOME)
      Serial.println("WAY home");
    else
      Serial.println("WAY food");*/   
    actual_node_path = path_.remove_last();
    next_node = path_.last_element();
    map_.actual(next_node);
    selected_grade = map_.grades[actual_node_path][next_node];
    correction_ = map_.stragihten_grades[actual_node_path][next_node];
    /*Serial.print("ACTUAL NODE: ");
    Serial.println(actual_node_path);
    Serial.print("NEXT_NODE: ");
    Serial.println(next_node);
    Serial.println(path_.path());*/
  } else {
      /*Serial.print("First value: ");
      Serial.println(first_);*/
      if(isHome(color) && first_) {
        while(on_transmit == "0") {
          if(Serial.available() && continue_ == 'y') {
            on_transmit = "1";
          }
        }
        while(Serial.available() && on_transmit == "1") {   
          inputString_ = "";
          do {
            if(Serial.available()) {
              inChar_ = (char)Serial.read();
              inputString_ += inChar_;
            }
          } while(inChar_ != 'E');
          modify_pheromones(inputString_);
          //print_pheromones();  
          on_transmit = "0";
          continue_ = 'n';
        }
      } else if(isHome(color) && !first_) {
        /*Serial.println("PATH...");
        Serial.write(final_path_.path().c_str());
        Serial.println();*/  
        while(on_transmit == "0") {
          if(Serial.available() && continue_ == 'y') {
            on_transmit = "1";
          }
        }
        while(Serial.available() && on_transmit == "1") {   
          while(inputString_ != "p") {
            inChar_ = (char)Serial.read();
            inputString_ = inChar_;
          }
          inputString_ = "";
          Serial.write(final_path_.path().c_str());    
          do {
            if(Serial.available()) {
              inChar_ = (char)Serial.read();
              inputString_ += inChar_;
            }
          } while(inChar_ != 'E');
          modify_pheromones(inputString_);
          //print_pheromones();         
          on_transmit = "0";
          continue_ = 'n';          
          //while(Serial.available() > 0) junk = Serial.read();
        }       
        inChar_ = 'X';       
        map_.grades_toogle_conversion();
        final_path_.clear_path();
        path_.clear_path();
        map_.restart_visited();
        toogle_ = true; 
        /*Serial.print("Common toogle: ");
        Serial.println(toogle_);*/
      } else 
        first_ = false;      
      /*Serial.print("PATH POP ");
      if(way_.WAY() == way_.WAY_HOME)
        Serial.println("WAY home");
      else
        Serial.println("WAY food");*/        
      next_node = map_.next_node(map_.actual());    
      path_.add_path(next_node); 
      final_path_.add_path(next_node);    
      /*Serial.println("INDEX OF MAP_GRADES:");
      Serial.print("MAP_.PREVIOUS(): ");
      Serial.println(map_.previous());
      Serial.print("NEXT_NODE: ");
      Serial.println(next_node);*/
      selected_grade = map_.grades[map_.previous()][next_node];
      correction_ = map_.stragihten_grades[map_.previous()][next_node];
    } 
    //p.clear_path();
    continue_ = 'y';   
  return selected_grade;
}
uint8_t Logic::correction() const {
  return correction_;
}
bool Logic::isGoal(Color color) const {
  return (color == Color::GREEN);
}
bool Logic::isHome(Color color) const {
  return (color == Color::BLUE);
}
bool Logic::isNone(Color color) const {
  return (color == Color::NONE);
}
bool Logic::toogle() const {
  return toogle_;
}
bool& Logic::toogle() {
  return toogle_;
}
String Logic::actual_node_str() const {
  return String(map_.actual());
}
String Logic::path_str() const {
  return path_.path();
}
void Logic::modify_pheromones(String inputString) {
  map_.modify_pheromones_from_str(inputString);
}
String Logic::print_pheromones() const {
  for(size_t i = 0; i < map_.n_; i++) {
    for(size_t j = 0; j < map_.n_; j++) {
      Serial.print(map_.PHEROMONES[i][j].toString() + " ");
    }
    //Serial.println();
  }
}
/*String Logic::actual_adjacent_list() const {
  return map_.print_adjacent_list();
}*/
String Logic::way_str() const {
  return way_.toString();
}
