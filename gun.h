#ifndef GUN_H_
#define GUN_H_
#include <iostream>
#include <string>

using namespace std;

class Gun{
    private:
        
        string name;
        int damage;
        int ammo;

    public:

        Gun(){};
        Gun(string nombre, int danio, int municion):name(nombre), damage(danio), ammo(municion){};

        string get_name() const{
            return name;
        }

        int get_damage() const{
            return damage;
        }

        int get_ammo() const{
            return ammo;
        }

        void set_damage(int danio){
            damage = danio;
        }

        void disparar();
        void reload(int ammoAccount);
};

void Gun::disparar(){
    if (ammo > 0){
        cout << name << " se ha disparado" << endl;
        ammo = ammo - 1;
    } else {
        cout << "Ya no tienes municion, recarga el arma" << endl;
    }
}

void Gun::reload(int ammoAccount){
    ammo = ammo + ammoAccount;
    cout << "Recargando..." << name << ". Municion actual: " << ammo << endl;
}

Gun pistola("Ghost", 30, 15);
Gun rifle("Vandal", 30, 30);
Gun sniper("Operator", 150, 5);
Gun smg("Spectre", 18, 25);

#endif