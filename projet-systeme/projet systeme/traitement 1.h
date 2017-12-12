#ifndef DEF_TRAITEMENT
#define DEF_TRAITEMENT
class liste_t;
class traitement{
	friend class liste_t;
	public:
	string nom;
	int ts;// temps sejour
	int ta;// temps d'attente
	traitement*next;
	public:
		traitement(string ch="",int a=0,int b=0){
			nom=ch;
			ts=a;
			ta=b;
			next=NULL;
		}
		void affiche(){
			cout<<'\t'<<" "<<nom;
			cout<<"           "<<ta;
			cout<<"                 "<<ts <<endl;
		}
};
class liste_t{

	traitement*tete;
	public:
		liste_t(){
			tete=NULL;
		}
		~liste_t(){
			traitement*t;
		 while(tete!=NULL){
				t=tete;
				tete=tete->next;
				delete t;
			}
		}
		void ajout_fin(traitement *t){
		traitement *aux;  aux=tete;
		if(tete==NULL){tete=t;}
		else{
	     while(aux->next!=NULL){
	     aux=aux->next; }
		 aux->next=t;
		}
	}
		void affiche(){
			traitement*t=tete;
			cout<<endl<<'\t'<<"---------------------------------------------------------"<<endl;
			cout<<'\t'<<"Processus"<<"    "<<"Temps d'attente"<<"   "<<"Temps de sejour"<<endl;
			while(t!=NULL){
				t->affiche();
				t=t->next;
			}
			cout<<'\t'<<"---------------------------------------------------------"<<endl;
		    ts_ta_moyen();
		}
		int taille(){
		traitement *aux; aux=tete; int n=0;
		while(aux!=NULL){
			n++; aux=aux->next;
		}
		return n;
	    }
		void ts_ta_moyen(){
			int som1=0,som2=0;
			traitement*t=tete;
			while(t){
				som1+=t->ts;
				som2+=t->ta;
				t=t->next;
			}
			int n=taille();
			cout<<'\t'<<"- Temps de sejour moyen : "<<(float)som1/n <<endl;
		    cout<<'\t'<<"- Temps d'attente moyen : "<<(float)som2/n <<endl;
		}
		void supp_mil(traitement*x){
			traitement*aux=tete,*p1;
			if(x!=NULL){
			while(aux->next!=x) aux=aux->next;
			aux->next=x->next;
			x->next=NULL;
			delete x;
			}
			}
		void ts_ta_RR(){
			traitement *t=tete,*t1,*t2,*aux; t1=t->next;
			while(t->next!=NULL){

				while(t1!=NULL){
					aux=NULL;
				if(t->nom==t1->nom){
					t->ta+=t1->ta;
					t->ts+=t1->ts;
				    aux=t1;
				}
				t1=t1->next;
				supp_mil(aux);
				}
				t=t->next;
			}
		}
		
};

#endif
