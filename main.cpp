#include <iostream>
#include "Genome.h"
#include "Animal.h"
#include "Cell.h"
using namespace std;

int main() {

    Genome gen;
    gen.setRna("TTCAGAGTCA");
    string dna[2] = {"AATTAAGCTC","ATATATAT"};
    gen.setDna(dna);

    Genome genn;
    genn.setRna("TTCAGAGTCA");
    dna[0] = "TTCAGAGTCA";
    dna[1] = "AAGTCTCAGT";
    genn.setDna(dna);

    Cell c;
    c.setChromosome(gen);
    c.setChromosome(genn);
    c.reverseMutation("TTCA", 1);

    Animal animal;
    cout << animal.similarity("ASDF", "SDFHSDHDFHFD");

    return 0;
}
