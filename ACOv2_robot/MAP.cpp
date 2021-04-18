#include "MAP.hpp"
const uint8_t Map::INF = 255;
void Map::modify_pheromones_from_str(String str) {
  String rational_number_string = "";
  Rational_number r;
  size_t i = 0, j = 0;  
  for(size_t it = 0; it < str.length(); it++) {
    if(str.charAt(it) != ',' && str.charAt(it) != 'E') {
      rational_number_string += str.charAt(it);
    } else {
      rational_number_string += 'E';
      r.from_str(rational_number_string);
      PHEROMONES[i][j] = r;
      PHEROMONES[j][i] = PHEROMONES[i][j];
      rational_number_string = "";      
      j++;
      if(j == n_) {
        j = 0;
        i ++;
      }
    }
  }   
}
void Map::grades_toogle_conversion() {
  int conversion = 0;
  uint8_t equivalence[4][2] = 
    {
      {0, 2},
      {1, 3},
      {2, 0},
      {3, 1}
    };
     for (int i = 0; i < n_; i++)
      for (int j = 0; j < n_; j++)
        if (grades[i][j] != INF && i != j) {
            grades[i][j] = equivalence[
                                grades[i][j]
                               ][1];
            stragihten_grades[i][j] = equivalence[
                                stragihten_grades[i][j]
                               ][1];
        }
}
Map::Map (Map::summit initial): 
  initial_ (initial),
  actual_node_ (initial_),
  previous_node_(initial_)
  {     
    /*for(size_t i = 0; i < n_; i++)
      for(size_t j = 0; j < n_; j++)
        PHEROMONES[i][j] = 1;*/
    for(size_t i = 0; i < n_; i++)
        VISITED[i] = false;
    VISITED[initial_] = true;
  }
typename Map::summit Map::next_node(Map::summit x){
    randomSeed(analogRead(A0));
    size_t vector_adjacent_position;
    adjacent_list(x);   
    size_t n_adjacents = number_of_adjacents();
    Rational_number p[n_];
    Rational_number aux (0);
    Rational_number p_random(0);   
    if(n_adjacents == 0) {
      actual_node_ = previous_node_;
      previous_node_ = x;
    } else {   
      /*Serial.println("GRADES MATRIX");
      for(int i = 0; i < n_; i++) {
        for(int j = 0; j < n_; j++) {
          Serial.print(String(grades[i][j]));
          Serial.print(" ");
        }
        Serial.println();
      }  
      Serial.println("CORRECTION GRADES MATRIX");
      for(int i = 0; i < n_; i++) {
        for(int j = 0; j < n_; j++) {
          Serial.print(String(stragihten_grades[i][j]));
          Serial.print(" ");
        }
        Serial.println();
      }*/      
      //NEXT NODE ACO      
      for(size_t i = 0; i < n_adjacents; i++)
        aux = 
          aux + (PHEROMONES[x][adjacent_[i]] * Rational_number(1 , distance(x, adjacent_[i])));     
      for(size_t i = 0; i < n_adjacents; i++) {       
        p[ adjacent_[i] ] =
            (
              (
                (PHEROMONES[x][adjacent_[i]]) * Rational_number(1, distance(x, adjacent_[i])) 
                  / 
                aux
              )
            );

            if(i > 0) {
              p[ adjacent_[i] ] = p[ adjacent_[i] ] + p[adjacent_ [i-1]];
            }
            /*Serial.print("PROBABILITY TO GET NODE ");
            Serial.print(adjacent_[i]);
            Serial.print(": ");
            p[ adjacent_[i] ].printR();*/
      }
      p_random.modify_rational_number(
        random(0,100), 
        100
      );      
      //p_random.printR();
      previous_node_ = x;
      for(size_t i = 0; i < n_adjacents; i++) {
        if(i == 0) {
          if(p_random >= Rational_number(0,1) && p_random <= p[ adjacent_[i] ]) 
            actual_node_ = adjacent_[i];
        } else {       
          if(p_random > p[ adjacent_[i - 1] ] && p_random <= p[ adjacent_[i] ])
            actual_node_ = adjacent_[i];
        }        
      }
      /*Serial.print("SELECTED NODE: ");
      Serial.println(actual_node_);*/      
      VISITED[actual_node_] = true;
    }
    return actual_node_;
}
uint8_t Map::distance(Map::summit x, Map::summit y){
    return map_[x][y];
}
int Map::number_of_adjacents() const {
  int i = 0;
  for(; i < 4 && adjacent_[i] != -1; i++);
  return i;
}
void Map::adjacent_list(Map::summit x){ 
    uint8_t it = 0;
    for(uint8_t i = 0; i < n_; i++)
      if(map_[x][i] != INF && i != x && !VISITED[i]){
        adjacent_[it] = i;
        ++it;
      }
    if(it < 4) adjacent_[it] = -1;   
    return adjacent_;
}
/*String Map::print_adjacent_list() const {
  String adjacent_str = "";
  for(int i = 0; i < 4 && adjacent_[i] != -1; i++)
      adjacent_str += (i == 4 - 1 || adjacent_[i] != -1)?
                        String(adjacent_[i]) :
                        String(adjacent_[i] + ", ");
  return adjacent_str;
}*/
void Map::restart_visited() {
  for(size_t i = 0; i < n_; i++)
    VISITED[i] = false;
  VISITED[initial_] = true;
}
