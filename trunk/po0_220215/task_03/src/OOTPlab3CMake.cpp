#include <iostream>
#include "ErrorCollection.h"
#include "MemoryAccessError.h"
#include "DivisionByZeroError.h"
#include "OverflowError.h"

int main() {
    std::cout << "Program demonstrates a hierarchy of errors and a collection to store them.\n";

    ErrorCollection errorCollection;

    errorCollection.addError(new MemoryAccessError("Null pointer dereference"));
    errorCollection.addError(new DivisionByZeroError());
    errorCollection.addError(new OverflowError());

    std::cout << "The collection contains " << errorCollection.size() << " errors.\n";

    try {
        for (size_t i = 0; i < errorCollection.size(); ++i) {
            errorCollection[i]->print();
        }
        errorCollection[3]->print(); // This will throw an exception
    }
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
