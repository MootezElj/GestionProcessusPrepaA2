#include <iostream>
#include <algorithm> // pour std::reverse()
#include <string> 

using namespace std;
main(){

string chaine = "Bonjour"; 
 
// Inversion directe de la cha�ne 
reverse(chaine.begin(), chaine.end()); 
 
// Autre m�thode : cr�ation d'une cha�ne invers�e 
string inverse( chaine.rbegin(), chaine.rend() );
cout<< chaine<<"  "<<inverse;}
