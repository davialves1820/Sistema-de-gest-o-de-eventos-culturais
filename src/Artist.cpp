#include "Artist.h"

const char* Negative_age_exception::what() const noexcept { return "Negative Age";}

Artist::Artist(const string& n, int a) : name(n), age(a) {
    if (age < 0) { // Verifica se a idade é negativa, caso for lança a exceção
        age = 0;
        throw Negative_age_exception();
    }
}

void Artist::set_name(const string& n) { name = n; }

string Artist::get_name() const { return name; }

void Artist::set_age(int a) { 
    if (a < 0) { // Verifica se a idade é negativa, caso for lança a exceção
        throw Negative_age_exception();
    }
    age = a; 
}

int Artist::get_age() const { return age; }

bool operator<(const Artist& artist1, const Artist& artist2) {
    return (artist1.age < artist2.age);
}

std::ostream& operator<<(std::ostream& out, const Artist& artist) {
    out << "Name: " << artist.name << endl;
    out << "Age: " << artist.age << endl;
    return out;
}