#include<string>

using namespace std;

class Gun{
private:
  string skin;
  float fire_rate;
  int ammo;

public:
  Gun():skin(""), fire_rate(0.0), ammo(0){};
  Gun(string skn, float fr, int amm): skin(skn), fire_rate(fr), ammo(amm){};

  string get_skin();
  float get_fire_rate();
  int get_ammo();

  void set_skin(string );
  void set_fire_rate(float );
  void set_ammo(int );

};

string Gun::get_skin(){
  return skin;
}

float Gun::get_fire_rate(){
  return fire_rate;
}

int Gun::get_ammo(){
  return ammo;
}

void Gun::set_skin(string skn){
  skin = skn;
}

void Gun::set_fire_rate(float fr){
  fire_rate = fr;
}

void Gun::set_ammo(int amm){
  ammo = amm;
}