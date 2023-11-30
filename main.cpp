/*
Proyecto Final Simulacion de un videojuego de Disparos
Charbel Isaias Chavez Zavala
A01711950

Descripcion: Con este programa podemos acceder a los mapas, y simular una pelea
entre 2 personajes seleccionados
*/

#include <iostream>
#include <string>
#include "character.h" //Clase de los personajes
#include "gun.h" //Clase de las armas
#include "map.h" //Clase de los mapas

using namespace std;

void maps(){
    /*Accedemos a los mapas ya creados en la clase Map
    y mostramos sus nombres en pantalla.*/
    cout << "Elige un mapa para la batalla: " << endl;
    cout << "1. " << mapa1.getMap() << endl;
    cout << "2. " << mapa2.getMap() << endl;
    cout << "3. " << mapa3.getMap() << endl;
    cout << "4. " << mapa4.getMap() << endl;
    
}

void elegir_mapa(){
    // Primero establecemos el mapa que se usara en la batalla.
    maps();
    int opcionMapa;
    cin >> opcionMapa;
    //obliga al usuario a elegir una opcion valida
    while (opcionMapa > 4){
        cout << "Opcion de mapa no valida... :'(" << endl;
        maps();
        cin >> opcionMapa;
    }
    //Imprime el mapa segun la eleccion del usuario
    cout << "El mapa elegido ha sido: " << endl;
    if (opcionMapa == 1){
        cout << mapa1.getMap() << endl;
    } else if (opcionMapa == 2){
        cout << mapa2.getMap() << endl;
    } else if (opcionMapa == 3){
        cout << mapa3.getMap() << endl;
    } else if (opcionMapa == 4){
        cout << mapa4.getMap() << endl;
    }
}

//imprime las armas creadas en la clase Gun
void armas(){
    cout << "1. " << pistola.get_name() << endl;
    cout << "2. " << rifle.get_name() << endl;
    cout << "3. " << sniper.get_name() << endl;
    cout << "4. " << smg.get_name() << endl;
}

//imprime el menu de todas las acciones que podemos realizar en el juego
void menu(){
    
    cout << "1. Mostrar informacion del personaje" << endl;
    cout << "2. Atacar" << endl;
    cout << "3. Recargar" << endl;
    cout << "4. Cambiar de arma" << endl;
    cout << "5. Revisar arma equipada" << endl;
    cout << "6. Habilidad especial" << endl;
    cout << "7. Salir" << endl;

}

//imprime los personajes creados en el documento Character.h
void personajes(){
    cout << "1. Reyna" << endl;
    cout << "2. Sage" << endl;
    cout << "3. Omen" << endl;
}

//permite al usuario elegir un personaje para usarlo
int elegir_tu_personaje(){
    cout << "Elige un personaje: " << endl;
    personajes();
    int personaje;
    cin >> personaje;
    if (personaje == 1){
        cout << duelista1.getName() << endl;
        return 1;
    } else if (personaje == 2){
        cout << healer1.getName() << endl;
        return 2;
    } else if (personaje == 3){
        cout << tanque1.getName() << endl;
        return 3;
    } else {
        cout << "Opcion no valida" << endl;
        return 0;
    }
}

//permite al usuario elegir un personaje para enfrentarlo
int elegir_enemigo(){
    cout << "Elige a tu enemigo: " << endl;
    personajes();
    int enemigo;
    cin >> enemigo;
    if (enemigo == 1){
        cout << "Tu enemigo es: " << duelista1.getName() << endl;
        return 1;
    } else if (enemigo == 2){
        cout << "Tu enemigo es: " << healer1.getName() << endl;
        return 2;
    } else if (enemigo == 3){
        cout << "Tu enemigo es: " << tanque1.getName() << endl;
        return 3;
    } else {
        cout << "Opcion no valida" << endl;
        return 0;
    }
}

//imprime la informacion del personaje seleccionado
void informacion(){
    cout << "Elige un personaje: " << endl;
    personajes();
    int info;
    cin >> info;
    if (info == 1){
        duelista1.mostrarInfo();
    } else if (info == 2){
        healer1.mostrarInfo();
    } else if (info == 3){
        tanque1.mostrarInfo();
    } else {
        cout << "Opcion no valida -_-" << endl;
    }
}

/*manda a llamar el metodo atacar de la clase Character, segun el
 *personaje elegido para atacar y el personaje elegido para ser
 *atacado*/
void ataque(){
    personajes();
    cout << "Atacante: ";
    int atacante;
    cin >> atacante;
    cout << "Enemigo: ";
    int enemigo;
    cin >> enemigo;
    if (atacante == 1 && enemigo == 1){
        duelista1.atacar(duelista1);
    } else if (atacante == 1 && enemigo == 2){
        duelista1.atacar(healer1);
    } else if (atacante == 1 && enemigo == 3){
        duelista1.atacar(tanque1);
    } else if (atacante == 2 && enemigo == 1){
        healer1.atacar(duelista1);
    } else if (atacante == 2 && enemigo == 2){
        healer1.atacar(healer1);
    } else if (atacante == 2 && enemigo == 3){
        healer1.atacar(tanque1);
    } else if (atacante == 3 && enemigo == 1){
        tanque1.atacar(duelista1);
    } else if (atacante == 3 && enemigo == 2){
        tanque1.atacar(healer1);
    } else if (atacante == 3 && enemigo == 3){
        tanque1.atacar(tanque1);
    } else {
        cout << "Opcion no valida" << endl;
    }

}

//manda a llamar el metodo recargar de la clase Character
void recarga(){
    cout << "Cuantas balas deseas recargar?" << endl;
    int balas;
    cin >> balas;
    personajes();
    int personaje;
    cin >> personaje;
    if (personaje == 1){
        duelista1.recargar(balas);
    } else if (personaje == 2){
        healer1.recargar(balas);
    } else if (personaje == 3){
        tanque1.recargar(balas);
    } else {
        cout << "Opcion no valida" << endl;
    }

}

//permite cambiar el arma del personaje que se esta usando
void cambio_arma(){
    armas();
    int newArma;
    cout << "Que arma eligiras?" << endl;
    cin >> newArma;
    if (newArma == 1){
        cout << "Elige un personaje: " << endl;
        personajes();
        int personaje;
        cin >> personaje;
        if (personaje == 1){
            duelista1.changeGun(pistola);
        } else if (personaje == 2){
            healer1.changeGun(pistola);
        } else if (personaje == 3){
            tanque1.changeGun(pistola);
        } else {
            cout << "Opcion no valida" << endl;
        }
    } else if (newArma == 2){
        cout << "Elige un personaje: " << endl;
        personajes();
        int personaje;
        cin >> personaje;
        if (personaje == 1){
            duelista1.changeGun(rifle);
        } else if (personaje == 2){
            healer1.changeGun(rifle);
        } else if (personaje == 3){
            tanque1.changeGun(rifle);
        } else {
            cout << "Opcion no valida" << endl;
        }
    } else if (newArma == 3){
        cout << "Elige un personaje: " << endl;
        personajes();
        int personaje;
        cin >> personaje;
        if (personaje == 1){
            duelista1.changeGun(sniper);
        } else if (personaje == 2){
            healer1.changeGun(sniper);
        } else if (personaje == 3){
            tanque1.changeGun(sniper);
        } else {
            cout << "Opcion no valida" << endl;
        }
    } else if (newArma == 4){
        cout << "Elige un personaje: " << endl;
        personajes();
        int personaje;
        cin >> personaje;
        if (personaje == 1){
            duelista1.changeGun(smg);
        } else if (personaje == 2){
            healer1.changeGun(smg);
        } else if (personaje == 3){
            tanque1.changeGun(smg);
        } else {
            cout << "Opcion no valida" << endl;
        }
    } else {
        cout << "Opcion no valida" << endl;
    }
}

//permite revisar el arma que esta usando nuestro personaje
void check_gun(){
    cout << "Elige un personaje: " << endl;
    personajes();
    int personaje;
    cin >> personaje;
    if (personaje == 1){
        duelista1.equippedGun();
    } else if (personaje == 2){
        healer1.equippedGun();
    } else if (personaje == 3){
        tanque1.equippedGun();
    } else {
        cout << "Opcion no valida -_-" << endl;
    }
}

/*esta funcion sirve para acceder al metodo especial de cada clase
 *derivada de nuestra clase madre Character.h, es decir de nuestras clases
 *Duelist, Healer y Tank */
void habilidad(){
    cout << "Elige un personaje: " << endl;
    personajes();
    int personaje;
    cin >> personaje;
    if (personaje == 1){
        int buff;
        cout << "El ataque aumenta: " << endl;
        cin >> buff;
        duelista1.aumentar_ataque(buff);
    } else if (personaje == 2){
        int cura;
        cout << "Cuanto se va a curar: " << endl;
        cin >> cura;
        healer1.heal(cura);
    } else if (personaje == 3){
        int aumento;
        cout << "Cuanto va a aumentar la defensa?" << endl;
        cin >> aumento;
        tanque1.defender(aumento);
    } else {
        cout << "Opcion no valida :D" << endl;
    }
}

//funcion principal donde podemos ejecutar cualquier opcion del menu
int main(){
    elegir_mapa();
    bool continua = true;
    while (continua == true){
        menu();
        cout << "Ingresa una opcion: " << endl;
        int opcion;
        cin >> opcion;
        if (opcion == 1){
            informacion();
        } else if (opcion == 2){
            ataque();
        } else if (opcion == 3){
            recarga();
        } else if (opcion == 4){
            cambio_arma();
        } else if (opcion == 5){
            check_gun();
        } else if (opcion == 6){
            habilidad();
        } else if (opcion == 7){
            cout << "Gracias por jugar :D" << endl;  
            continua = false;
        } else {
            cout << "Opcion no valida" << endl;
        }
    }
    return 0;
}