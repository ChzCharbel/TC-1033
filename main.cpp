#include <iostream>
#include <string>
#include "character.h"
#include "gun.h"
#include "map.h"

using namespace std;

int charac(){

  Character wind("Jett", "Duelista", "Femenino", "Dagas");
  cout << wind.get_name() << endl;
  cout << wind.get_role() << endl;
  cout << wind.get_genre() << endl;
  cout << wind.get_ultimate() << endl;
  

  Character fire;
  fire.set_name("Phoenix");
  fire.set_role("Duelista");
  fire.set_genre("Masculino");
  fire.set_ultimate("Cenizas");

  cout << fire.get_name() << endl;
  cout << fire.get_role() << endl;
  cout << fire.get_genre() << endl;
  cout << fire.get_ultimate() << endl;

  return 0;

}

int guun(){

  Gun revolver("Sheriff", "Pistol", 0.7, 6);
  cout << revolver.get_name() << endl;
  cout << revolver.get_type() << endl;
  cout << revolver.get_fire_rate() << endl;
  cout << revolver.get_ammo() << endl;

  Gun rifle;
  rifle.set_name("Vandal");
  rifle.set_type("Rifle");
  rifle.set_fire_rate(1.7);
  rifle.set_ammo(30);

  cout << rifle.get_name() << endl;
  cout << rifle.get_type() << endl;
  cout << rifle.get_fire_rate() << endl;
  cout << rifle.get_ammo() << endl;

  return 0;

}

int maps(){

  Map africa("Bind", "Morocco", 2766.66, "A");
  cout << africa.get_name() << endl;
  cout << africa.get_location() << endl;
  cout << africa.get_size() << endl;
  cout << africa.get_site() << endl;

  Map america;
  america.set_name("Breeze");
  america.set_location("Brasil");
  america.set_size(3543.43);
  america.set_site("B");

  cout << america.get_name() << endl;
  cout << america.get_location() << endl;
  cout << america.get_size() << endl;
  cout << america.get_site() << endl;

  return 0;

}

int main(){
    charac();
    guun();
    maps();
    return 0;
}
