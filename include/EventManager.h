/*
Classe gerenciador_de_eventos
Atributo:
lista_de_eventos (std::vector<evento*>).
Métodos:
adicionar_evento / remover_evento: Manipula a lista de eventos.
Ordenação dos eventos pela idade.
Sobrecarga dos operadores + e -:
+: Adiciona um evento à lista.
-: Remove um evento da lista.
*/

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "Show.h"
#include "Exposure.h"

class Event_manager {
    vector<Event*> event_list;
public: 
    // Destrutor
    ~Event_manager();

    // Adicionar evento
    void add_event(Event* event);

    // Remover evento
    void remove_event(const string& name);

    // Ordenar os eventos de acordo com a idade
    void order_events();

    // Retorna um evento presente na lista
    Event* get_event(const string& name);

    // Sobrecarregar o operador +
    void operator+(Event* event);

    // Sobrecarregar o operador -
    void operator-(const string& name);

    // Exibir todos os eventos presentes na lista
    void display_events();
};

#endif