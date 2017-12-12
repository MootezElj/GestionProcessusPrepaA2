#include<iostream>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std;
class liste_p;
class processus{
	friend class liste_p;
	char* nom;
	int dat_arrive,temp_execution;
	processus* next;
	
	public:
		processus(char* ch="",int d=-1,int t=-1){
			dat_arrive=d;
			temp_execution=t;
			nom=new char[strlen(ch)+1]; 
			strcpy(nom,ch);
			next=NULL;
		}
		~processus(){
			//delete &nom;
		}
		void affiche_p(){
			cout<<"- Nom = "<<nom<<endl;
			cout<<"- Date d'arrive = "<<dat_arrive<<endl;
			cout<<"- Temp d'execution = "<<temp_execution<<endl;
		}
	
};
class liste_p{
	processus *tete;
	public:
	liste_p(){
		tete=NULL;
	}
	~liste_p(){
		processus*p;
		while(tete->next!=NULL){
			p=tete; tete=tete->next;
			delete p;
		} delete tete; cout<<" liste deleted";
	}
	processus* ajout(){
		int te,da; char c[10];
		cout<<"* Entrer le nom de processus : "; cin>>c;
		cout<<"* Entrer le temp d'execution : "; cin>>te;
		cout<<"* Entrer la date d'arrive : ";    cin>>da;
		processus p(c,da,te);
		processus*aux;  aux=tete;
		if(tete==NULL){
		tete=&p;}
		else{
	     while(aux->next!=NULL){
	     aux=aux->next; }
		 aux->next=&p; 
		} return tete;
	}
	void affiche(){
		processus *aux; aux=tete;
		if(tete==NULL) cout<<"- La liste est vide !"<<endl;
		else{
			while(aux->next!=NULL){
				aux->affiche_p();
				aux=aux->next;
			}
		}
	}
		processus* ajout_deb(){
		int te,da; char c[10];
		cout<<"* Entrer le nom de processus : "; cin>>c;
		cout<<"* Entrer le temp d'execution : "; cin>>te;
		cout<<"* Entrer la date d'arrive : ";    cin>>da;
		processus p(c,da,te);
	    p.next=tete;
	    tete=&p;
	    return(tete);
		}	
};
// Fonction quitter
void quit(){
	cout<<endl<<"# Vouz avez quitte le programme !";
}
// Fonction test de la fonction menu
bool test(char y){
	if(isnan(y)) {
	cout<<"# Choix invalide !"<<endl;
	return(false);}
	else{
	if(y=='1'||y=='2'||y=='3'||y=='4'||y=='5')
	return(true);
	else{ cout<<"# Choix invalide !"<<endl;
	     return(false); }
}
}
// Fonction menu
char menu(){ char x; cout<<endl;
	cout<<"********* MENU **********"<<endl;
	cout<<"* [1]: PAPS             *"<<endl;
	cout<<"* [2]: SJF              *"<<endl;
	cout<<"* [3]: SRT              *"<<endl;
	cout<<"* [4]: PR               *"<<endl;
    cout<<"* [5]: Quitter          *"<<endl;
	cout<<"*************************"<<endl;
	do{
    cout<<endl<<"- Entre votre Choix: "; cin>>x;
	} while(test(x)==false);
      return(x);
}
main(){
/*	char b=menu();
do{	b=menu();
	switch(b){
	case '1':  break;
	case '2':  break;
	case '3':  break;
	case '4':  break;
	case '5':  break;
	case '6': quit(); break;
	}
}while(b!='6');
*/
processus p("abc",5,7); //p.affiche_p();
liste_p l;
//l.ajout_deb();
//l.affiche();
return 0;
}
