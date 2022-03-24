/*
 * Function: main
 * PURPOSE: USES FUNCTIONS FROM THE stringHash
 *          CLASS CREATED
 * Name: Daniel Pellegrino
 * Written: 4/18/2021; Last Modified 3/24/2022
 * Language: C++
 */

#include <iostream>

using namespace std;

#include "stringHash.h"

int main( void )
{
    stringHash hashing(10);

    hashing.store(cout, cin);

    cout << endl << hashing << endl;

    hashing.query(cout, cin);

    return 0;
}
