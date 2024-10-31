#include "Event.h"

Event::Event(const string& n, int a) : name(n), age(a) {
    if (age < 0) { // Verifica se a idade é negativa, caso for lança a exceção
        age = 0;
        throw Negative_age_exception();
    }
}

Event::~Event() {}

void Event::set_name(const string& n) { name = n; }

string Event::get_name() const { return name; }

void Event::set_age(int a) { 
    if (a < 0) { // Verifica se a idade é negativa, caso for lança a exceção
        throw Negative_age_exception();
    }
    age = a; 
}

int Event::get_age() const { return age; }

vector<Artist> Event::get_artists() const { return artist_list; }

void Event::order_list() {
    sort(artist_list.begin(), artist_list.end()); // Ordena os artistas do mais jovem ao mais velho
}

void Event::display_artists() const {
    if (artist_list.empty()) { // Informa que a lista está vazia
        cout << "Nenhum artista foi relacionado" << endl;
        return;
    }
    cout << "Artist list" << endl;
    for (auto artist : artist_list) {
        cout << artist;
        cout << "---------------------" << endl;
    }
}

bool operator<(Event& event1, Event& event2) {
    return (event1.age < event2.age); // Compara pela idade
}

void Event::operator+(const Artist& artist) {
    artist_list.push_back(artist); // Adiciona o artista ao fim da lista
    order_list(); // Ordena a lista 
}

void Event::operator-(const string& name) {
    for (auto it = artist_list.begin(); it != artist_list.end(); it++) {
        if (it->get_name() == name) { // Verifica se o artista pertence a lista
            artist_list.erase(it); // Remove o artista da lista
            return;
        }
    }
    // Caso o artista não pertencer a lista informa com uma mensagem
    cout << "Artista nao encontrado" << endl;
}
