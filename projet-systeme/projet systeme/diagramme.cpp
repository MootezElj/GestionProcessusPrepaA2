#include<iostream>
#include<string>
#include<stdlib.h>
#include<math.h>
#include "processus.h"
using namespace std;
void tracer(char** m,processus p,int a,int b){
	m[a][0]=p.nom[0]; 
	
}
char* matrice(liste_p& l){
	char mat[15][56]; 
	 for(int i=0;i<15;i++)
	  for(int j=0;j<56;j++){
	  mat[i][j]=' ';
	  if(j==2) mat[i][j]='³';
	  if(i==14&&j>1) mat[i][j]='Ä';
	  }
    mat[0][2]='';
    mat[14][2]='À';
	mat[14][55]='';	

processus *aux=l.r_tete(); int a=13,b=2;
while(aux!=NULL){
	
	for(int i=0;i<aux->temp_execution*2;i++){
		m[a][b]='-'; b++;
	}
	aux=aux->next;
	a=a-2;
}
	for(int i=0;i<15;i++){
	cout<<endl;
	  for(int j=0;j<56;j++)
	  cout<<mat[i][j];
    }
cout<<endl<<"  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ";
}

	

main(){

}
