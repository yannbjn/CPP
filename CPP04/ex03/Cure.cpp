#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const &other) : AMateria(other) {}

Cure &Cure::operator=(Cure const &other) {
    if (this != &other) {
        this->_type = other._type;
    }
    return *this;
}

Cure::~Cure() {}

AMateria *Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
