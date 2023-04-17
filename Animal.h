using namespace std;
#include <iostream>
#include "Cell.h"

class Animal: private Cell{
public:
    int similarity(string dna1, string dna2) {
        int size1 = dna1.length();
        int size2 = dna2.length();
        int count = 0;
        if (size1 < size2) {
            for (int i = 0; i < size1; i++) {
                if (dna1[i] == dna2[i])
                    count++;
            }
            return (count / size1) * 100;
        }
        else {
            for (int i = 0; i < size2; i++) {
                if (dna1[i] == dna2[i])
                    count++;
            }
            return (count / size2) * 100;
        }
        return 0;
    }

    bool operator==(Animal animal) const {
        if (animal.similarity(this->getDna(), animal.getDna()) > 70 && this->chromosomeCounter == animal.chromosomeCounter) {
            return true;
        }
        return false;
    }
};
