#ifndef CHARACTER_H_
#define CHARACTER_H_
#include <iostream>
#include <string>

using namespace std;

class Character{
private:
  string name;
  string ultimate;

public:
  Character():name(""), ultimate(""){};
  Character(string nm, string ult): name(nm), ultimate(ult){};

  string get_name();
  string get_ultimate();
  void usar_ultimate();

  void set_name(string);
  void set_ultimate(string);

};

string Character::get_name(){
  return name;
}

string Character::get_ultimate(){
  return ultimate;
}

void Character::usar_ultimate(){
  cout << get_name << "uso la definitiva" << get_ultimate;
}

void Character::set_name(string nm){
  name = nm;
}

void Character::set_ultimate(string ult){
  ultimate = ult;
}

class Duelist: public Character{
  private:
    string entry;

  public:
    Duelist():entry(""){};
    Duelist(string ent): entry(ent){};

    void entrar_site();
    
};

void Duelist::entrar_site(){
  cout << get_name << "uso" << entry << endl;

}

class Initiator: public Character{
  private:
    string reveal;

  public:
    Initiator():reveal(""){};
    Initiator(string rev): reveal(rev){};

    void revelar_site();
    
};

void Initiator::revelar_site(){
  cout << get_name << "uso" << reveal;

}

class Smoker: public Character{
  private:
    string smoke;

  public:
    Smoker():smoke(""){};
    Smoker(string smog): smoke(smog){};

    void tirar_humo();
    
};

void Smoker::tirar_humo(){
  cout << get_name << "uso" << smoke;

}

class Sentinel: public Character{
  private:
    string heal;

  public:
    Sentinel():heal(""){};
    Sentinel(string cura): heal(cura){};

    void curar();
    
};

void Sentinel::curar(){
  cout << get_name << "uso" << heal;
}

#endif
