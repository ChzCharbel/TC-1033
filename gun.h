/*
Clase gun.h
Charbel Isaias Chavez Zavala
A01711950

Esta clase sirve para crear armas y asignarselas a los personajes a traves de agregacion.
*/

#ifndef GUN_H_
#define GUN_H_
#include <iostream>
#include <string>

using namespace std;

class Gun{
    private:
        //atributos
        string name;
        int damage;
        int ammo;

    public:
        //contructores
        Gun(){};
        Gun(string nombre, int danio, int municion):name(nombre), damage(danio), ammo(municion){};

        /**
        * getter name
        *
        * @param
        * @return string: name
        */
        string get_name() const{
            return name;
        }

        /**
        * getter damage
        *
        * @param
        * @return int: damage
        */
        int get_damage() const{
            return damage;
        }

        /**
        * getter ammo
        *
        * @param
        * @return int: ammo
        */
        int get_ammo() const{
            return ammo;
        }

        /**
        * setter damage
        *
        * @param int: damage
        * @return 
        */
        void set_damage(int danio){
            damage = danio;
        }

        void disparar();
        void reload(int ammoAccount);
};

/**
	* El arma se dispara y por ende su municion disminuye 
	*
	* @param 
	* @return 
	*/
void Gun::disparar(){
    if (ammo > 0){
        cout << name << " se ha disparado" << endl;
        ammo = ammo - 1;
    } else {
        cout << "Ya no tienes municion, recarga el arma" << endl;
    }
}

/**
	* El arma se recarga segun la cantidad de balas
    * señalada por el usuario
	*
	* @param int: ammoAccount
	* @return 
	*/
void Gun::reload(int ammoAccount){
    ammo = ammo + ammoAccount;
    cout << "Recargando..." << name << ". Municion actual: " << ammo << endl;
}

Gun pistola("Ghost", 30, 15);
Gun rifle("Vandal", 30, 30);
Gun sniper("Operator", 150, 5);
Gun smg("Spectre", 18, 25);

#endif