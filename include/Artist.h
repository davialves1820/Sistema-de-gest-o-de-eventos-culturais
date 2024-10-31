/*
Classe artista
Atributos:
nome_do_artista (string).
idade_do_artista (int).
Métodos:
set_nome / get_nome: Para definir e obter o nome.
set_idade / get_idade: Para definir e obter a idade.
Sobrecarga do operador <: Dois artistas são comparados pela idade (do mais jovem ao mais
velho).
*/

#ifndef ARTIST_H
#define ARTIST_H

#include <iostream>
#include <string>
#include <stdexcept>

using std::cout;
using std::endl;
using std::string;

// Classe de exceção para idade negativa
class Negative_age_exception : public std::exception {
public:
    const char* what() const noexcept override;
};

class Artist {
    string name;
    int age;
public:
    // Construtor
    Artist(const string& n, int a = 0);
    
    // Gets e sets
    void set_name(const string& n);
    string get_name() const;

    void set_age(int a);
    int get_age() const;

    // Sobrecarregar o operador <
    friend bool operator<(const Artist& artist1, const Artist& artist2);

    // Sobrecarga do operador<<
    friend std::ostream& operator<<(std::ostream& out, const Artist& artist);
};

#endif