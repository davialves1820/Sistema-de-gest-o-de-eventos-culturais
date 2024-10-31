#include "Show.h"

Show::Show(const string& n, int a, const string& m_g) : Event(n, a), music_genre(m_g) {}

void Show::set_music_genre(const string& m_g) { music_genre = m_g; }

string Show::get_music_genre() const { return music_genre; }

double Show::calculate_price() const {
    return 100 + (get_artists().size() * 10); // Adiciona 10 reais por artista
}

std::ostream& operator<<(std::ostream& out, const Show& show) {
    out << "Show" << endl;
    out << "Name: " << show.get_name() << endl;
    out << "Age: " << show.get_age() << endl;
    out << "Ticket price: " << show.calculate_price() << endl;
    out << "Music genre: " << show.music_genre << endl;
    out << "---------------------" << endl;
    out << "Artist list" << endl;
    if (show.get_artists().empty()) { // Informa que a lista está vazia
        out << "Nenhum artista foi relacionado" << endl;
        out << "---------------------" << endl;
        return out;
    }
    for (auto& art : show.get_artists()) {
        out << art;
        out << "---------------------" << endl;
    }
    return out;
}

void Show::display_info() {
    cout << *this;
}