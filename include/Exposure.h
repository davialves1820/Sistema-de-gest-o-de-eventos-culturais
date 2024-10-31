/*
exposicao: Atributo adicional: tipo_de_arte (string).
*/

#ifndef EXPOSURE_H
#define EXPOSURE_H

#include "Event.h"

class Exposure : public Event {
    string type_of_art;
public:
    // Construtor
    Exposure(const string& n, int a, const string& t_a);
    
    // Get e set
    void set_type_art(const string& t_a);
    string get_type_art() const;

    // Escrita do metodo abstrato
    void display_info() override;

    double calculate_price() const override;

    // Sobrecarga do operador <<
    friend std::ostream& operator<<(std::ostream& out, const Exposure& exposure);
};

#endif