#include<iostream>
#include<string>
#include<windows.h>
#include<stdlib.h>
#include "processus.h"
#include "traitement.h"
#include "echelle.h"

using namespace std;
// Fonction Processus
liste_p Processus(){
liste_p l; int te,da,choix; string ch;
		do{
		cout<<"* Entrer le nom de processus : "; cin>>ch;
		cout<<"* Entrer le temp d'execution : "; cin>>te;
		cout<<"* Entrer la date d'arrive : ";    cin>>da;
		processus *p=new processus(ch,da,te);
		l.ajout_fin(p);
		cout<<endl<<"- Voulez-vous entrer un autre processus ?" 
		    <<endl<<'\t'<<"  1: Oui/ 2: Non  ";
		cin>>choix; cout<<endl;
		}while(choix==1);
		return(l);
}
// Fonction test de la fonction menu
bool test(char y){
	if(isnan(y)) {
	cout<<"# Choix invalide !"<<endl;
	return(false);}
	else{
	if(y=='0'||y=='1'||y=='2'||y=='3'||y=='4'||y=='5'||y=='6')
	return(true);
	else{ cout<<"# Choix invalide !"<<endl;
	     return(false); }
}
}
//Diagramme RR
void diagramme_RR( liste_p L,int q){
	echelle E; liste_t tr;
processus*p; int c=L.tete->dat_arrive,x,d; int a=18,b=c*2+3;

	while(L.tete!=NULL){
		p=L.supp_deb();
		
		E.mat[a][0]=p->nom[0]; E.mat[a][1]=p->nom[1];
		traitement*t=new traitement(p->nom);
		x=c;
		
		if(q < p->temp_execution && L.tete==NULL){
			for(int i=1;i<p->temp_execution*2;i++){
				E.mat[a][b]='-';
				b++; 
			}d=p->dat_arrive;
			c+=p->temp_execution;
			delete p;
		}
		else if(q>= p->temp_execution){
			for(int i=1;i<p->temp_execution*2;i++){
				E.mat[a][b]='-';
				b++; 
			}
			d=p->dat_arrive;
			c+=p->temp_execution;
			delete p;
		}else{
		    p->temp_execution-=q;
			for(int i=1;i<q*2;i++){
				E.mat[a][b]='-';
				b++;
			}
			d=p->dat_arrive; 
			c=c+q;
			p->dat_arrive=c;
			L.ajout_fin(p);
		} 
		    E.mat[a][b]='ฟ';
	        for(int j=a+1;j<20;j++){ 
			if(j%2==1)
			E.mat[j][b]='ณ';}
	        b++;
		    a-=2;
		    t->ta=(x - d);
	        t->ts=(c - d); 
	        tr.ajout_fin(t);
	}
    E.affiche();
    system("pause");
	tr.ts_ta_RR();
	tr.affiche();	
}
// Diagramme PAPS
void diagramme_PAPS(const liste_p l){
echelle e; liste_t tr;
processus *aux=l.tete; int c=aux->dat_arrive,x; int a=18,b=c*2 +3;
while(aux!=NULL){
	e.mat[a][0]=aux->nom[0]; e.mat[a][1]=aux->nom[1];
	if(b <aux->dat_arrive*2+3){
	b=b+((aux->dat_arrive*2+3)-b);
	c=c+(aux->dat_arrive-c);	
	} 
	x=c;
	traitement*t=new traitement(aux->nom);
	
	for(int i=1;i<aux->temp_execution*2;i++){
		e.mat[a][b]='-'; b++; 
	}
	c=c+aux->temp_execution;
	e.mat[a][b]='ฟ';
	for(int j=a+1;j<20;j++){ e.mat[j][b]='ณ';}
	  a=a-2; 
	 t->ta=(x -  aux->dat_arrive);
	 t->ts=(c -  aux->dat_arrive); 
	 b++;
	aux=aux->next;
	tr.ajout_fin(t);
}
e.affiche();
system("pause");
tr.affiche();
}
// diagramme SJF
void diagramme_SJF(liste_p l){
echelle e; liste_t tr;
processus *aux=l.tete,*p; 
int a=18,c=aux->dat_arrive,x,b=c*2 +3;
while(aux!=NULL){
	e.mat[a][0]=aux->nom[0]; e.mat[a][1]=aux->nom[1];
	if(b <aux->dat_arrive*2+3){
	b=b+((aux->dat_arrive*2+3)-b);
	c+=	c-aux->dat_arrive;
	} 
	x=c;
	traitement*t=new traitement(aux->nom);
	for(int i=1;i<aux->temp_execution*2;i++){
		e.mat[a][b]='-'; b++;
	}
	c+=aux->temp_execution;
	e.mat[a][b]='ฟ';
	for(int j=a+1;j<20;j++){ e.mat[j][b]='ณ';}
	b++; a=a-2;
	
	t->ta=(x -  aux->dat_arrive);
	t->ts=(c -  aux->dat_arrive); 
	tr.ajout_fin(t);
	
	l.supp_deb();
	if(l.tete!=NULL){
	l.tete=l.trie2(c);
	}
	aux=l.tete;	
}
e.affiche();
system("pause");
tr.affiche();
}

processus* elu(liste_p&l,processus*x,int &i,int temp){
	processus*aux=l.tete,*p=NULL;
			while(aux!=NULL){
			if(aux->dat_arrive<=i && aux->temp_execution< temp){ 	
			   if(aux->next)
			   i=aux->next->dat_arrive;
			   else i+=aux->temp_execution;
			   
			   //p=l.supp_mil(aux);
			   l.ajout_fin(x);
			   return p;
			   }
			   else aux=aux->next;
			}
			return x;
			}
// Diagramme SRT
void diagramme_SRT(liste_p l){
	echelle E; int interrompu,n;
processus*p=l.tete,*p1=p,*aux; int a=18,b=l.tete->dat_arrive*2+3;
      while(p!=NULL){
      
		if(l.taille()==1){
			E.mat[a][0]=p->nom[0]; E.mat[a][1]=p->nom[1];
			for(int i=1;i<p->temp_execution*2;i++){
				E.mat[a][b]='-';
				b++; 
			}
			E.mat[a][b]='ฟ';
	        for(int j=a+1;j<20;j++){ 
			E.mat[j][b]='ณ';}

			l.supp_deb(); p=l.tete;
		} 
		else{ 
	     n=interrompu=p1->next->dat_arrive;
	    
		if(p->temp_execution < interrompu) n=p->temp_execution; 
		
		E.mat[a][0]=p->nom[0]; E.mat[a][1]=p->nom[1];
		for(int i=1;i < n*2;i++){
				E.mat[a][b]='-';
				b++; 
			}
			E.mat[a][b]='ฟ';
	        for(int j=a+1;j<20;j++){ 
			E.mat[j][b]='ณ';}
	        b++; a-=2;
	        
			p->temp_execution-=interrompu;
			p1=p1->next;
			if(p->temp_execution<=0){
				l.supp_mil(p);
			}
			p=l.trie2(interrompu);
			
	    }
	}
E.affiche();	
}



// PAPS
void PAPS(const liste_p& L){
	if(L.tete!=NULL){
	liste_p l=L;
	l.trie();
	system("cls");
	cout<<endl<<'\t'<<'\t'<<"- Diagramme de Gantt : PAPS -"<<endl;
	diagramme_PAPS(l);
	cout<<endl ;system("pause");
	} cout<<endl<<"- La liste de processus est vide ! "<<endl;
}
//RR
void RR(const liste_p& l){
	if(l.tete!=NULL){
	int q;
	liste_p L=l;
	L.trie();	
	cout<<endl<<"- Entrer la valeur de quantum : "; cin>>q;
	cout<<endl<<'\t'<<'\t'<<"- Diagramme de Gantt : RR -"<<endl;
	diagramme_RR(L,q);
	system("pause");
    }cout<<endl<<"- La liste de processus est vide ! "<<endl;
}
// SJF
void SJF(const liste_p &l){
	if(l.tete!=NULL){
	liste_p L=l;
	L.trie();	
	cout<<endl<<'\t'<<'\t'<<"- Diagramme de Gantt : SJF Non Preemptif -"<<endl;
	diagramme_SJF(L);
	system("pause");
    }cout<<endl<<"- La liste de processus est vide ! "<<endl;

}
// SRT
void SRT(const liste_p &l){
	if(l.tete!=NULL){
	liste_p L=l;
	L.trie();	
	cout<<endl<<'\t'<<'\t'<<"- Diagramme de Gantt : SRT -"<<endl;
	diagramme_SRT(L);
	system("pause");
    }cout<<endl<<"- La liste de processus est vide ! "<<endl;

}

// Fonction menu 
char menu(){ char x; cout<<endl; system("cls");
	cout<<'\t'<<"----------------------------------------------"<<endl;
	cout<<'\t'<<"-"<<'\t'<<"      Abbes Houdhaifa                -"<<endl;
	cout<<'\t'<<"-"<<'\t'<<"        groupe A2-01                 -"<<endl;
	cout<<'\t'<<"----------------------------------------------"<<endl<<endl;
	
	
	cout<<'\t'<<'\t'<<"ษอออออออออออ MENU ออออออออออป"<<endl;
	cout<<'\t'<<'\t'<<"บ    [0]:  Processus        บ"<<endl;
	cout<<'\t'<<'\t'<<"บ    [1]:  PAPS             บ"<<endl;
	cout<<'\t'<<'\t'<<"บ    [2]:  SJF              บ"<<endl;
	cout<<'\t'<<'\t'<<"บ    [3]:  SRT              บ"<<endl;
	cout<<'\t'<<'\t'<<"บ    [4]:  RR               บ"<<endl;
    cout<<'\t'<<'\t'<<"บ    [5]:  Affiche          บ"<<endl;
	cout<<'\t'<<'\t'<<"บ    [6]:  Quitter          บ"<<endl;
	cout<<'\t'<<'\t'<<"ศอออออออออออออออออออออออออออผ"<<endl;
	do{
    cout<<endl<<"- Entre votre Choix: "; cin>>x;
	} while(test(x)==false);
      return(x);
}
// Fonction quitter
void quit(){
	cout<<"\n"<<"- Vouz avez quitte le programme !"<<endl;
}
main(){

liste_p l1,l2,l3,l4;  char b; 
do{	
    b=menu();
	switch(b){
	case '0':  system("cls"); l1=Processus(); break;
	case '1':  system("cls");        PAPS(l1);break;
	case '2':  system("cls"); l2=l1; SJF(l2); break;
	case '3':  system("cls"); l3=l1; SRT(l3); break;
	case '4':  system("cls"); l4=l1; RR(l4);  break;
	case '5':  system("cls"); l1.affiche();   break;
	case '6':  system("cls"); quit();         break;
	}
} while(b!='6');
return 0;
}

