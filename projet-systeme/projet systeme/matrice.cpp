#ifndef DEF_echelle
#define DEF_echelle
#include<iostream>

using namespace std;
class echelle{
	public:
	char mat[20][65];
	public:
		echelle(){
		for(int i=0;i<20;i++)
	     for(int j=0;j<65;j++){
	      mat[i][j]=' ';
	      if(j==2) mat[i][j]='|';
	      if(i==19 && j>1) mat[i][j]='-';
	     }	  
	    mat[0][2]=''; 	
	    mat[19][2]='À';
        mat[19][64]='';	
		}
		void affiche(){
		  for(int i=0;i<20;i++){
	      cout<<endl;
	      for(int j=0;j<65;j++)
	      cout<<mat[i][j];
          }
		}
};
#endif
