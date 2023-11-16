#include<string>

using namespace std;

class Map{
private:
  string name;
  string location;
  float size;
  string site;

public:
  Map():name(""), location(""), size(0.0), site(""){};
  Map(string nm, string lctn, float sz, string st): name(nm), location(lctn), size(sz), site(st){};

  string get_name();
  string get_location();
  float get_size();
  string get_site();

  void set_name(string );
  void set_location(string );
  void set_size(float );
  void set_site(string );

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

string Map::get_site(){
  return site;
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

void Map::set_site(string st){
  site = st;
}
