/*
Classe evento (abstrata)
Atributos:
nome_do_evento (string).
idade_do_evento (int), correspondente ao tempo desde a criação.
lista_de_artistas (std::vector<artista>).
Métodos:
set_nome / get_nome: Manipula o nome.
set_idade / get_idade: Manipula a idade.
get_artistas: Retorna os artistas do evento.
Ordenação dos artistas: A lista de artistas é ordenada por idade.
Sobrecarga do operador <: Eventos são comparados pela idade (eventos mais antigos vêm
primeiro).
Sobrecarga dos operadores + e -:
+: Adiciona um artista à lista de um evento.
-: Remove um artista da lista, se presente.
*/

#ifndef EVENT_H
#define EVENT_H

#include "Artist.h"
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Event {
    string name;
    int age;
    vector<Artist> artist_list;
public:
    // Construtor
    Event(const string& n, int a = 0);

    // Destrutor
    virtual ~Event();

    // Gets e sets
    void set_name(const string& n);
    string get_name() const;

    void set_age(int a);
    int get_age() const;

    vector<Artist> get_artists() const;

    // Função para ordenar a lista de artistas
    void order_list();

    // Função para exibir os artistas do evento
    void display_artists() const;

    // Sobrecarga do operador <
    friend bool operator<(Event& event1, Event& event2);

    // Sobrecarga do operador +
    void operator+(const Artist& artist);

    // Sobrecarga do operador -
    void operator-(const string& name);

    // Função abstrata
    virtual void display_info() = 0;

    virtual double calculate_price() const = 0;
};

#endif