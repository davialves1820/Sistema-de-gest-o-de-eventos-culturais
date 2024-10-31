#include "EventManager.h"

Event_manager::~Event_manager() {
    for (auto event : event_list) {
        delete event; // Libera memória
    }
    event_list.clear(); // Esvazia o vector
}

void Event_manager::add_event(Event* event) {
    *this + event;
}

void Event_manager::remove_event(const string& name) {
    *this - name;
}

void Event_manager::order_events() {
    // Ordena do maior para o menor
    std::sort(event_list.begin(), event_list.end(), [](Event* e1, Event* e2) {
    return e1->get_age() > e2->get_age(); // Desreferencia os ponteiros brutos
}); 
}

Event* Event_manager::get_event(const string& name) {
    for (auto it = event_list.begin(); it != event_list.end(); it++) {
        if ((*it)->get_name() == name) {
            return (*it);
        }
    }
    return nullptr; // Significa que o evento não foi encontrado
}

void Event_manager::operator+(Event* event) {
    event_list.push_back(event);
}

void Event_manager::operator-(const string& name) {
    for (auto it = event_list.begin(); it != event_list.end(); it++) {
        if ((*it)->get_name() == name) { // Compara se o nome do evento a remover é compativel com um evento presente na lista
            delete *it; // Libera memória
            event_list.erase(it); // Remove do vector
            return;
        }
    }
    // Exibir mensagem se não for encontrado o evento no vector
    cout << "Nenhum evento encontrado" << endl;
}

void Event_manager::display_events() {
    order_events(); // Ordenar os eventos do mais antigo para o mais novo
    if (event_list.empty()) {
        cout << "Nenhum evento encontrado." << std::endl;
        return;
    }

    for (auto& event : event_list) { // Exibir todos os eventos
        event->display_info();
    }
}