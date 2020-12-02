#ifndef __OUTOFRANGEDNA_H__
#define __OUTOFRANGEDNA_H__

#include <exception>

using namespace std;

struct OutOfRangeDna : public exception {
    const char * what () const throw () {
        return "The index out of range";
    }
};

#endif