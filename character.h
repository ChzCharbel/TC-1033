/*
Clase character.h
Charbel Isaias Chavez Zavala
A01711950

Esta clase sirve para crear personajes y habilidades,
ademas aqui encontramos la herencia de la clase madre Character,
a las clase hijas Duelist, Healer and Tank.
*/

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
    
    /**
    * getter name
    *
    * @param
    * @return string: name
    */
    string getName() const{
      return name;
    }

    /**
    * getter life
    *
    * @param
    * @return int: life
    */
    int getLife() const{
      return life;
    }

    /**
    * getter defense
    *
    * @param
    * @return int: defense
    */
    int getDefense() const{
      return defense;
    }
    

    /**
	  * setter nombre
	  *
	  * @param string: name
	  * @return 
	  */
    void setName(string nombre){
      name = nombre;
    }

    /**
	  * setter defense
	  *
	  * @param int: defensa
	  * @return 
	  */
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

/**
	* Este metodo muestra las caracteristicas de un personaje
  * como su nombre, vida, defensa, el arma que esta usando y el daño que hace.
	*
	* @param 
	* @return 
	*/
void Character::mostrarInfo()const{
  cout << "Nombre: " << name << endl;
  cout << "Vida: " << life << endl;
  cout << "Defensa: " << defense << endl;
  cout << "Arma: " << gun.get_name() << endl;;
  cout << "Daño de Arma: " << gun.get_damage() << endl;
}

/**
	* El usuario aumenta la cantidad de municion presente
  * en el arma que esta usando el personaje elegido
	*
	* @param int: ammoAccount
	* @return 
	*/
void Character::recargar(int ammoAccount){
  cout << name << " recargo... ";
  gun.reload(ammoAccount);
}

/**
	* Este metodo imprime el arma que esta siendo utilizada
  * actualmente por el personaje elegido por el usuario
	*
	* @param 
	* @return 
	*/
void Character::equippedGun() const{
  cout << "El arma que esta utilizando en este instante es: " << gun.get_name() << endl;  
}

/**
	* El usuario cambia el arma que esta usando su personaje por una nueva arma de su eleccion. 
	*
	* @param Gun&: newGun
	* @return 
	*/
void Character::changeGun(const Gun& newGun){
  gun = newGun;
  cout << "Ahora estas utilizando: " << gun.get_name() << endl;
}

/**
	* Este metodo es llamado por el metodo ataque, donde se calcula, 
  * la vida restante del personaje elegido para ser atacado.
	*
	* @param int: cantidadDanio
	* @return 
	*/
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

/**
	* El usuario elige el personaje con el que va a atacar,
  * donde tambien elige al enemigo, y se calcula el daño realizado
  * a partir de los atributos orignales de los personajes 
	*
	* @param Character&: objetivo
	* @return 
	*/
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
    //constructores
    Duelist(){};
    Duelist(string nombre, int defensa, const Gun& arma, int vida = 100):Character(nombre, defensa, arma, vida){};

    void aumentar_ataque(int aumento);
    
};

/**
	* Aumenta el daño que realiza el personaje Duelist, cambiando el valor
	* de el atributo damage de la clase Gun.
	*
	* @param int: aumento
	* @return
	*/
void Duelist::aumentar_ataque(int aumento){
  int danio = aumento + gun.get_damage();
  gun.set_damage(danio);
  cout << name << " aumento su ataque a " << gun.get_damage() << endl;
  
}

class Healer: public Character{
  public:
    //constructores
    Healer(){};
    Healer(string nombre, int defensa, const Gun& arma, int vida = 100):Character(nombre, defensa, arma, vida){};

    void heal(int cura);
};

/**
	* Aumenta la vida del personaje Healer, tras usar la habilidad
	* cura, donde el usuario aumenta su vida en la cantidad deseada  
	*
	* @param int: cura
	* @return 
	*/
void Healer::heal(int cura){
  life = life + cura;
  cout << name << " se ha curado, ahora tiene " << life << " de vida" << endl;
}

class Tank: public Character{
  public:
    //contructores
    Tank(){};
    Tank(string nombre, int defensa, const Gun& arma, int vida = 100):Character(nombre, defensa, arma, vida){};

    void defender(int aumentoDefensa);

};

/**
  * Aumenta el atributo defensa del personaje Tanque
	* despues de que el usuario ingrese la cantidad a aumentar en la defensa.  
	*
	* @param int: aumentoDefensa
	* @return
	*/
void Tank::defender(int aumentoDefensa){
  defense = defense + aumentoDefensa;
  cout << "La nueva defensa de " << name << " ahora es: " << defense << endl;
}

//Personajes predeterminados para el juego
Duelist duelista1("Reyna", 25, rifle);
Healer healer1("Sage", 10, pistola);
Tank tanque1("Omen", 80, sniper);

#endif