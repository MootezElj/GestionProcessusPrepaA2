#include <string>
#include <iostream>
 
int main()
{
    using namespace std;
 
    string s; // la chaîne est vide
    cout << "size = " << s.size() << '\t'  // size = 0 
         << "capacity = " << s.capacity()  // capacity = 15
         << '\n';
 
    // on sait que l'on va faire de nombreuses concaténations,
    // alors on réserve de l'espace pour éviter de multiples allocations
    s.reserve( 26 );
    cout << "size = " << s.size() << '\t'  // size = 0 
         << "capacity = " << s.capacity()  // capacity = 31
         << '\n';
 
    // concaténer les 26 lettres de l'alphabet
    for ( char c = 'A'; c <= 'Z'; ++c )
    {
        s += c;
    }
 
    cout << "size = " << s.size() << '\t'  // size = 26 
         << "capacity = " << s.capacity()  // capacity = 31
         << '\n';
 
    s = "une assez longue chaîne qui oblige a faire une allocation";
    cout << "size = " << s.size() << '\t'  // size = 57
         << "capacity = " << s.capacity()  // capacity = 63
         << '\n';
}
