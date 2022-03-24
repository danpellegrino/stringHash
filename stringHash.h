/*
 * Class: stringHash
 * PURPOSE: HASHES A STRING THAT ALLOWS THE ABILITY TO
 *          1. STORE IT
 *          2. DISPLAY IT
 *          3. GET QUERIES FOR A VALUE
 * Name: Daniel Pellegrino
 * Written: 4/18/2021; Last Modified 3/24/2022
 * Language: C++
 */

#include <iostream>
#include <vector>
#include <algorithm>

#ifndef HASH
#define HASH

class stringHash
{
   public:
      stringHash(const int);
      void store( ostream& , istream& );
      friend ostream& operator<<(ostream& out, stringHash &main);
      void query( ostream & , istream & );

   private:
       int realSpace, space, temp, position;
       vector<string> names;
};

stringHash::stringHash( const int total )
{
    realSpace = total;
    space = (total * 3)/2;
    names.resize(space);
}

void stringHash::store( ostream & out , istream & in )
{
    string word;
    // Sees if the vector already has values
    fill(names.begin(),names.end(),'?');
    out << "Please enter " << realSpace << " things to store. (Enter \"stop\" if you would like to enter no more)." << endl;

    for(int i = 0; (i < realSpace) && ( word != "stop" ); i++)
    {
        out << "#" <<  i + 1 << " word: ";

        in >> word;

        if(word != "stop"){
        temp = (word[0] + word[1] + word[word.length() - 1]) % space;
        while(names[temp] != "?")
        {
            temp++;
            temp == space ? temp = 0 : temp;
        }
        names.erase(names.begin() + temp);
        names.insert(names.begin() + temp, word);
        }
    }
    return;
}

ostream& operator<<(ostream& out, stringHash &main)
{
    out << "Displaying contents of the vector...." << endl;
    for(int i = 0; i < main.space; i++)
    {
        out << "#" << i << " position: " << main.names[i] << endl;
    }
    return out;
}

void stringHash::query( ostream & out , istream & in  )
{
    string word;
    bool found = false;
    out << "Enter the word you would like to search.(Enter \"stop\" if you would like to enter no more)." << endl;
    in >> word;
    while(word != "stop")
    {
        temp = (word[0] + word[1] + word[word.length() - 1]) % space;
        while(( names[temp] != "?" ) && ( found == false ))
        {
            if(names[temp] == word)
            {
                position = temp;
                found = true;
            }
            temp++;
            temp == space ? temp = 0 : temp;
        }
        if(found == true)
        {
            out << word << " is found at position #" << position << endl;
            found = false;
        }
        else
            out << word << " was not found in the vector." << endl;

        in >> word;
    }
    return;
}

#endif
