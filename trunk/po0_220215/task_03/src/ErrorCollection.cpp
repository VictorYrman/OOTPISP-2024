#include "ErrorCollection.h"

void ErrorCollection::addError(Error* err) {
    errors.push_back(err);
}

Error* ErrorCollection::operator[](size_t index) {
    if (index >= errors.size()) {
        throw std::out_of_range("Index out of range");
    }
    return errors[index];
}

size_t ErrorCollection::size() const {
    return errors.size();
}
