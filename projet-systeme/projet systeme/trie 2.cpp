void trie2(int m){
			int n=taille();
			if(n==1) cout<<endl;//cout<<"- La liste de processus est deja triee !"<<endl;
			else{ int i=0;
			  processus t[n],*aux; aux=tete; 
			  while(aux!=NULL && i<n){
				  t[i]=*aux; i++;
			  	aux=aux->next;
			  }
			  int min; processus x;
			  for(int a=0;a<n-1;a++){
			  	min=a;
				  for(int b=a+1;b<n;b++){
			  		if((t[a].dat_arrive ==t[b].dat_arrive) &&(t[min].temp_execution > t[b].temp_execution)) min =b;
			  		else if(t[min].dat_arrive!=0 &&t[min].temp_execution > t[b].temp_execution) min=b; 
			  	}
			  	x=t[a]; t[a]=t[min]; t[min]=x;
			  }
			  aux=tete; int k=0;
			while(aux!=NULL&& k<n){
				*aux=t[k]; k++;
				aux=aux->next;
		    }	
			//cout<<endl<<"- La liste de processus a ete triee avec succes !"<<endl;	
			} cout<<endl; //system("pause");
		}
