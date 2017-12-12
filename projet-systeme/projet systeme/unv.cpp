#include <iostream>
#include <algorithm> // pour std::reverse()
#include <string> 

using namespace std;
main(){

string chaine = "Bonjour"; 
 
// Inversion directe de la chaîne 
reverse(chaine.begin(), chaine.end()); 
 
// Autre méthode : création d'une chaîne inversée 
string inverse( chaine.rbegin(), chaine.rend() );
cout<< chaine<<"  "<<inverse;}
