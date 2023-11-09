#include<string>

using namespace std;

class Character{
private:
  string name;
  string role;
  string genre;
  float height;
  float weight;

public:
  Character():name(""), role(""), genre(""), height(0.0), weight(0.0){};
  Character(string nm, string rl, string gnr, float hght, float wght): name(nm), role(rl), genre(gnr), height(hght), weight(wght){};

  string get_name();
  string get_role();
  string get_genre();
  float get_height();
  float get_weight();

  void set_name(string );
  void set_role(string );
  void set_genre(string );
  void set_height(float );
  void set_weight(float );  

};

string Character::get_name(){
  return name;
}

string Character::get_role(){
  return role;
}

string Character::get_genre(){
  return genre;
}

float Character::get_height(){
  return height;
}

float Character::get_weight(){
  return weight;
}

void Character::set_name(string nm){
  name = nm;
}

void Character::set_role(string rl){
  role = rl;
}

void Character::set_genre(string gnr){
  genre = gnr;
}

void Character::set_height(float hght){
  height = hght;
}

void Character::set_weight(float wght){
  weight = wght;
}