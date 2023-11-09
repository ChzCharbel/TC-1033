#include<string>

using namespace std;

class Map{
private:
  string name;
  string location;
  float size;

public:
  Map():name(""), location(""), size(0.0){};
  Map(string nm, string lctn, float sz): name(nm), location(lctn), size(sz){};

  string get_name();
  string get_location();
  float get_size();

  void set_name(string );
  void set_location(string );
  void set_size(float );

};

string Map::get_name(){
  return name;
}

string Map::get_location(){
  return location;
}

float Map::get_size(){
  return size;
}

void Map::set_name(string nm){
  name = nm;
}

void Map::set_location(string lctn){
  location = lctn;
}

void Map::set_size(float sz){
  size = sz;
}