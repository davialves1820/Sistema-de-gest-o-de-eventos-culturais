/*
show: Atributo adicional: genero_musical (string).
*/

#ifndef SHOW_H
#define SHOW_H

#include "Event.h"

class Show : public Event {
    string music_genre;
public:
    // Construtor
    Show(const string& n, int a, const string& m_g);
    
    // Get e set
    void set_music_genre(const string& m_g);
    string get_music_genre() const;

    // Escrita do metodo abstrato
    void display_info() override;

    double calculate_price() const override;

    // Sobrecarga do operador <<
    friend std::ostream& operator<<(std::ostream& out, const Show& show);
};

#endif