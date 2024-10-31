#include "Exposure.h"

Exposure::Exposure(const string& n, int a, const string& t_a) : Event(n, a), type_of_art(t_a) {}

void Exposure::set_type_art(const string& t_a) { type_of_art = t_a; }

string Exposure::get_type_art() const { return type_of_art; }

double Exposure::calculate_price() const {
    return 85 + (get_artists().size() * 5); // Adiciona 5 reais por artista
}

std::ostream& operator<<(std::ostream& out, const Exposure& exposure) {
    out << "Exposure" << endl;
    out << "Name: " << exposure.get_name() << endl;
    out << "Age: " << exposure.get_age() << endl;
    out << "Type of art: " << exposure.type_of_art << endl;
    out << "Ticket price: " << exposure.calculate_price() << endl;
    out << "---------------------" << endl;
    out << "Artist list" << endl;
    if (exposure.get_artists().empty()) { // Informa que a lista está vazia
        out << "Nenhum artista foi relacionado" << endl;
        out << "---------------------" << endl;
        return out;
    }
    for (auto& art : exposure.get_artists()) {
        out << art;
        out << "---------------------" << endl;
    }
    return out;
}

void Exposure::display_info() {
    cout << *this;
}