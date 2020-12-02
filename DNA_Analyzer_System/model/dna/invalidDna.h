#ifndef __INVALIDDNA_H__
#define __INVALIDDNA_H__

#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

class InvalidDna : public exception{
public:
    const char * what () const throw () {
        return "Invalid dna error 1";

    }
};

#endif
