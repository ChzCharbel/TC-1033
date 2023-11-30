#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "gun.h"
#include <iostream>
#include <string>

using namespace std;

class Character{
  protected:

    //atributos
    string name;
    int life = 100;
    int defense;
    Gun gun;

  public:

    //constructores
    Character(){};
    Character(string nombre, int defensa, const Gun& arma, int vida = 100):name(nombre),defense(defensa), gun(arma){};
    
    // getters
    string getName() const{
      return name;
    }

    int getLife() const{
      return life;
    }

    int getDefense() const{
      return defense;
    }
    
    //setters
    void setName(string nombre){
      name = nombre;
    }

    void setDefense(int defensa){
      defense = defensa;
    }

    void mostrarInfo() const;
    void recargar(int );
    void equippedGun() const;
    void changeGun(const Gun& newGun);
    void recibirDanio(int);
    void atacar(Character& objetivo);
};

void Character::mostrarInfo()const{
  cout << "Nombre: " << name << endl;
  cout << "Vida: " << life << endl;
  cout << "Defensa: " << defense << endl;
  cout << "Arma: " << gun.get_name() << endl;;
  cout << "Daño de Arma: " << gun.get_damage() << endl;
}

void Character::recargar(int ammoAccount){
  cout << name << " recargo... ";
  gun.reload(ammoAccount);
}

void Character::equippedGun() const{
  cout << "El arma que esta utilizando en este instante es: " << gun.get_name() << endl;  
}

void Character::changeGun(const Gun& newGun){
  gun = newGun;
  cout << "Ahora estas utilizando: " << gun.get_name() << endl;
}

void Character::recibirDanio(int cantidadDanio) {
  if (defense >= cantidadDanio) {
    cout << name << " no ha recibido daño" << endl;
  } else {
      int danioReal = cantidadDanio - defense;
      life = life - danioReal;
      if (life < 0) {
      life = 0;
    }
    cout << name << " ha recibido " << danioReal << " de daño." << endl;
    cout << "Vida restante de " << name << ": " << life << endl;
  }
}

void Character::atacar(Character& objetivo){
  int danio = gun.get_damage() - objetivo.getDefense();
        if (danio < 0) {
            danio = 0; // No se realiza daño si la defensa del objetivo es mayor que el poder de ataque del personaje
        }
        cout << name << " ataca a " << objetivo.getName() << " y causa " << danio << " de daño." << endl;
        objetivo.recibirDanio(danio);
        gun.disparar();
}

class Duelist: public Character{
  public:
    Duelist(){};
    Duelist(string nombre, int defensa, const Gun& arma, int vida = 100):Character(nombre, defensa, arma, vida){};

    void aumentar_ataque(int aumento);
    
};

void Duelist::aumentar_ataque(int aumento){
  int danio = aumento + gun.get_damage();
  gun.set_damage(danio);
  cout << name << " aumento su ataque a " << gun.get_damage() << endl;
  
}

class Healer: public Character{
  public:
    Healer(){};
    Healer(string nombre, int defensa, const Gun& arma, int vida = 100):Character(nombre, defensa, arma, vida){};

    void heal(int cura);
};

void Healer::heal(int cura){
  life = life + cura;
  cout << name << " se ha curado, ahora tiene " << life << " de vida" << endl;
}

class Tank: public Character{
  public:
    Tank(){};
    Tank(string nombre, int defensa, const Gun& arma, int vida = 100):Character(nombre, defensa, arma, vida){};

    void defender(int aumentoDefensa);

};

void Tank::defender(int aumentoDefensa){
  defense = defense + aumentoDefensa;
  cout << "La nueva defensa de " << name << " ahora es: " << defense << endl;
}


Duelist duelista1("Reyna", 25, rifle);
Healer healer1("Sage", 10, pistola);
Tank tanque1("Omen", 80, sniper);

#endif