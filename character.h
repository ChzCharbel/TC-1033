#include<string>

using namespace std;

class Character{
private:
  string name;
  string role;
  string genre;
  string ultimate;

public:
  Character():name(""), role(""), genre(""), ultimate(""){};
  Character(string nm, string rl, string gnr, string ult): name(nm), role(rl), genre(gnr), ultimate(ult){};

  string get_name();
  string get_role();
  string get_genre();
  string get_ultimate();

  void set_name(string );
  void set_role(string );
  void set_genre(string );  
  void set_ultimate(string );

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

string Character::get_ultimate(){
  return ultimate;
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

void Character::set_ultimate(string ult){
  ultimate = ult;
}
