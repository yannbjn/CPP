#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        this->_materias[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const &other) {
    *this = other;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (this->_materias[i])
            delete this->_materias[i];
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (this->_materias[i])
                delete this->_materias[i];
            if (other._materias[i])
                this->_materias[i] = other._materias[i]->clone();
            else
                this->_materias[i] = 0;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (this->_materias[i] == 0) {
            this->_materias[i] = m;
            return;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (this->_materias[i] && this->_materias[i]->getType() == type)
            return this->_materias[i]->clone();
    }
    return 0;
}
