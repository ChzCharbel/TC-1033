#include<string>

using namespace std;

class Gun{
private:
  string name;
  string type;
  float fire_rate;
  int ammo;

public:
  Gun():name(""), type(""), fire_rate(0.0), ammo(0){};
  Gun(string nm, string typ, float fr, int amm): name(nm), type(typ),fire_rate(fr), ammo(amm){};

  string get_name();
  string get_type();
  float get_fire_rate();
  int get_ammo();

  void set_name(string );
  void set_type(string );
  void set_fire_rate(float );
  void set_ammo(int );

};

string Gun::get_name(){
  return name;
}

string Gun::get_type(){
  return type;
}

float Gun::get_fire_rate(){
  return fire_rate;
}

int Gun::get_ammo(){
  return ammo;
}

void Gun::set_name(string nm){
  name = nm;
}

void Gun::set_type(string typ){
  type = typ;
}

void Gun::set_fire_rate(float fr){
  fire_rate = fr;
}

void Gun::set_ammo(int amm){
  ammo = amm;
}
