#ifndef CODON_H
#define CODON_H
#include <iostream>
#include "RNA.h"
using namespace std;


class Protein;

// struct representing a codon of 3 DNA/RNA characters and �\0�
struct Codon
{
    char value[4];    	    // 4th location for null character
    char AminoAcid;  	    // corresponding AminoAcid according to Table
};

// need to create one object of that class to load the AminoAcids table
// into memory
class CodonsTable
{

public:
     Codon codons[64];
    // constructors and destructor
    CodonsTable();
    ~CodonsTable();
    // function to load all codons from the given text file
    void LoadCodonsFromFile(string codonsFileName);
    char getAminoAcid(char * value);
    void setCodon(char * value, char AminoAcid, int index);
};


#endif // CODONSTABLE_H
