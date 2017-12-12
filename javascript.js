//Le modele qu'on va utiliser dans l'application
var model={
    prioriteeNeeded:false,
    tempExecutionMoyen:0,
    processusList:[{
    nomProcessus:"p1",
    tempExecution:3,
    tempExecutionRestant:3,
    dateArrivee:5,
    prioritee:0,
    pret:false,
debutExecution:0,
finExecution:0}]
};

var modelRR={
    rrModel:true,
    tempExecutionMoyen:0,
    processusList:[{
    nomProcessus:"p2",
    debutExecution:0,
    lastProcess:false,
    finExecution:0}]
};

var modelSRT={
    rrModel:true,
    tempExecutionMoyen:0,
    processusList:[{
    nomProcessus:"p2",
    debutExecution:0,
    lastProcess:false,
    finExecution:0}]
};

//sjf
var modelExecutionMoyen={
    ExecutionMoyen:true,
    processusList:[
        {
            nomProcessus:"p1",
            dateArrivee:0,
            tempExecution:0,
            tempAttente:0,
        }
    ]
};


//srt
var modelExecutionMoyenSrt={
    ExecutionMoyen:true,
    processusList:[
        {
            nomProcessus:"p1",
            dateArrivee:0,
            tempExecution:0,
            tempAttente:0,
        }
    ]
};


//rr
var modelExecutionMoyenRr={
    ExecutionMoyen:true,
    processusList:[
        {
            nomProcessus:"p1",
            dateArrivee:0,
            tempExecution:0,
            tempAttente:0,
        }
    ]
};



//objet qui sert a determiner les fonctions utilisé d'après l'utilisateur, sert a l'affichage dans la page HTML
var usedFunction={
    sjf:false,
    rr:false,
    srt:false
};


var todoApp=angular.module("todoApp",[]);
todoApp.controller("ToDoCtrl",function ($scope){
   

   //fonction qui control le control d'un processus saisie depuis la page HTML
   $scope.valide=function(nomProcessus_,tempExecution_,dateArrivee_,prioritee_)
   {
        if (($scope.todo.prioriteeNeeded)&&(typeof nomProcessus_=='string')&&(!isNaN(tempExecution_))&&(!isNaN(dateArrivee_))&&(!isNaN(prioritee_))&&(!nomProcessus_=="")&&(tempExecution_!="")&&(dateArrivee_!="")&&(prioritee_!=""))
        return true;
        else
       return ((typeof nomProcessus_=='string')&&(!isNaN(tempExecution_))&&(!isNaN(dateArrivee_))&&(!nomProcessus_=="")&&(!tempExecution_=="")&&(!dateArrivee_==""));
   }
   
   //fonction qui ajoute un processus, utilisé depuis le boutton dans index.html
    $scope.ajouterProcessus=function(nomProcessus_,tempExecution_,dateArrivee_,prioritee_)
    {
        if($scope.valide(nomProcessus_,tempExecution_,dateArrivee_,prioritee_))
        $scope.todo.processusList.push({nomProcessus:nomProcessus_,debutExecution:0,finExecution:0,tempExecution:tempExecution_,dateArrivee:dateArrivee_,prioritee:prioritee_,tempExecutionRestant:tempExecution_});
    }
    
    $scope.ajouterProcessusDiagrameSrt=function(nomProcessus_,debut_,fin_)
    {
        modelSRT.processusList.push({nomProcessus:nomProcessus_,debutExecution:debut_,finExecution:fin_,lastProcess:false});
    }
    
    //efface le processus saisie en parametre
    $scope.effacerProcessus=function(proces)
    {
        var processusAEfface=$scope.todo.processusList.indexOf(proces);
        $scope.todo.processusList.splice(processusAEfface,1);
    }

   //fonction qui initialise les processus a l'etat non pret
    $scope.inintList=function(tab)
    {
        for (var i=0;i<tab.length;i++)
        {
        tab[i].pret=false;
        tab[i].tempExecutionRestant=tab[i].tempExecution;
        }

    }
   
   $scope.updateList=function(temp,processusList_)
   {
    for (var i=0;i<processusList_.length;i++)
    if(processusList_[i].dateArrivee<=temp){processusList_[i].pret=true;}
   }
    
   

    //fonction qui definie et retourne les processus pret
    $scope.getReady=function(temp,ProcessusListUpdate)
    {
        var tab=[];
        for(var i=0; i<ProcessusListUpdate.length; i++)  
        {
        if(ProcessusListUpdate[i].pret){tab.push(ProcessusListUpdate[i]);}
        }
        return tab;
    }
        
    //retourne le processus qui a le minum du temps d'execution
        $scope.processusMinTempExecution=function(tabTest)
        {
            var minProcessus=tabTest[0];
            var minTempExecution=tabTest[0].tempExecution;
            for(var i=1; i<tabTest.length; i++)
            {
                if (tabTest[i].tempExecution*1<minTempExecution*1){minTempExecution=tabTest[i].tempExecution;minProcessus=tabTest[i];}
            }
              return(minProcessus);
        }
        
        //fonction qui minimiz la taille d'un diagramme 
        $scope.minimize=function(diagrame)
        {
            for (var i=0;i<diagrame.length-1;i++)
            {
                while(diagrame[i].nomProcessus==diagrame[i+1].nomProcessus)
                {
                    diagrame[i].finExecution=diagrame[i+1].finExecution;
                    diagrame.splice(i+1,1);
                }
            }
        }
        
        
        

        //fonction qui retourne la date d'arrivee d'un processus par son nom
        $scope.getDateByName=function(nomProcessus_)
        {
            var i=0;
            var tab=model.processusList;
            while((nomProcessus_!=tab[i].nomProcessus)&&(i<tab.length))
            {
                i++;
            }
            if (i==tab.length) return -1;
            else return tab[i].dateArrivee;
        }

//determine le temp d'execution moyen en chaine de caractere et valeur
        $scope.tempExecutionMoyenTodo=function(diagramme)
        {
         
            modelExecutionMoyen.processusList=[]

            var ch="[";
            var sm=0;
            for(var i=0;i<diagramme.length;i++)
            {
                modelExecutionMoyen.processusList.push({nomProcessus:diagramme[i].nomProcessus,dateArrivee:diagramme[i].dateArrivee,tempExecution:diagramme[i].finExecution,tempAttente:0});
                ch=ch+"("+diagramme[i].finExecution+"-"+diagramme[i].dateArrivee+")+";
                sm+=(diagramme[i].finExecution-diagramme[i].dateArrivee);
            }
            sm/=diagramme.length;
            ch=ch+"0]/"+diagramme.length;
            ch+="=";
            $scope.ExecutionMoyentoDo=modelExecutionMoyen.processusList;
            return {chaine:ch,moyenne:sm};
        }


//determine le temp d'execution moyen en chaine de caractere et valeur
$scope.tempExecutionMoyenTodoRr=function(diagramme)
{
    modelExecutionMoyenRr.processusList=[]            
    var ch="[";
    var sm=0;
    var processTreated=[];
    var i=(diagramme.length)*1-1;
    var dateArriveeP;
    while(i>=0)
    {
        if(processTreated.indexOf(diagramme[i].nomProcessus)==-1)
        {
            
            processTreated.push(diagramme[i].nomProcessus);
            dateArriveeP=$scope.getDateByName(diagramme[i].nomProcessus)*1;
            modelExecutionMoyenRr.processusList.push({nomProcessus:diagramme[i].nomProcessus,dateArrivee:dateArriveeP,tempExecution:diagramme[i].finExecution,tempAttente:0});
            ch=ch+"("+diagramme[i].finExecution+"-"+dateArriveeP+")+";
            sm+=(diagramme[i].finExecution-dateArriveeP);
        }
        i--;
    }
    sm/=model.processusList.length;
    ch=ch+"0]/"+model.processusList.length;
    ch+="=";
    $scope.ExecutionMoyentoDoRr=modelExecutionMoyenRr.processusList;
    return {chaine:ch,moyenne:sm};
    
}


        //determine le temp d'execution moyen en chaine de caractere et valeur
        $scope.tempExecutionMoyenTodoSrt=function(diagramme)
        {
            modelExecutionMoyenSrt.processusList=[]            
            var ch="[";
            var sm=0;
            var processTreated=[];
            var i=(diagramme.length)*1-1;
            var dateArriveeP;
            while(i>=0)
            {
                if(processTreated.indexOf(diagramme[i].nomProcessus)==-1)
                {
                    
                    processTreated.push(diagramme[i].nomProcessus);
                    dateArriveeP=$scope.getDateByName(diagramme[i].nomProcessus)*1;
                    modelExecutionMoyenSrt.processusList.push({nomProcessus:diagramme[i].nomProcessus,dateArrivee:dateArriveeP,tempExecution:diagramme[i].finExecution,tempAttente:0});
                    ch=ch+"("+diagramme[i].finExecution+"-"+dateArriveeP+")+";
                    sm+=(diagramme[i].finExecution-dateArriveeP);
                }
                i--;
            }
            sm/=model.processusList.length;
            ch=ch+"0]/"+model.processusList.length;
            ch+="=";
            $scope.ExecutionMoyenSrttoDo=modelExecutionMoyenSrt.processusList;
            return {chaine:ch,moyenne:sm};
            
        }
        
        //fonction qui retourne le premier pret element
        $scope.getFirstDate=function(processusListUpdate)
        { 
            var minDateArrivee=processusListUpdate[0].dateArrivee;
            var minProcessus=processusListUpdate[0];
            for (var i=1;i<processusListUpdate.length;i++)
            {
                if(processusListUpdate[i].dateArrivee<minDateArrivee)
                {
                    minProcessus=processusListUpdate[i];
                    minDateArrivee=processusListUpdate[i].dateArrivee;
                }
            }
            return minProcessus;
        }
        




    

    //fonction qui ajoute un processus a la liste du diagrameRR
    $scope.ajouterProcessusRR=function(nomProcessus_,debutExecution_,finExecution_)
    {
        modelRR.processusList.push({nomProcessus:nomProcessus_,debutExecution:debutExecution_,finExecution:finExecution_,lastProcess:false});
    }

  

        //fonction qui retourne un tableau des elements pret du tableau rr
        $scope.getReadyRR=function(tabProcess,temp1,temp2)
        {
            var tabResultat=[];
            for(var i=0;i<tabProcess.length;i++)
            {
                if ((tabProcess[i].dateArrivee>=temp1)&&(tabProcess[i].dateArrivee<=temp2))
                tabResultat.push(tabProcess[i]);
            }
            return tabResultat;
        }

        //fonction qui verifie si tous les processus sont terminé
        $scope.allProcessTreated=function(tabProcess)
        {
            var test=true;
            var i=0;
            while((test)&&(i<tabProcess.length))
            {
                test=tabProcess[i].tempExecutionRestant==0;
                i++;
            }
            return test;
        }
    //fonction d'affichage
    $scope.afficheListProcessus=function(processusList)
    {
        for(var i=0;i<processusList.length;i++)
        {
            alert("i = "+i+" nom= "+processusList[i].nomProcessus+" debut= "+processusList[i].debutExecution+" fin= "+processusList[i].finExecution);
        }
    }


        //fonction de test
        $scope.rrDiagramme=function()
        {
            var tempCourant=prompt('Saisir le temp de depart',0)*1;
            var quauntinum=prompt('Saisir le quantum',0)*1;
            if (!isNaN(tempCourant)&&!(isNaN(tempCourant))&&(quauntinum>0))
            {
            $scope.inintList(model.processusList);
            $scope.usedFunctions.rr=true;
            modelRR.processusList=[];
            var rr=model.processusList.slice();
            var tabReady=[];
            var file=[];
            tabReady=$scope.getReadyRR(rr,0,tempCourant*1);
            tabReady.sort(function(a, b) {
                return parseFloat(a.dateArrivee) - parseFloat(b.dateArrivee);
            });
            
            //si aucun processus est pret en temp courant
            if(tabReady.length==0){tabReady[0]=$scope.getFirstDate(rr);tempCourant=tabReady[0].dateArrivee*1;}
            for(var i=0;i<tabReady.length;i++)
            {
                file.push(tabReady[i]);
            }
            
            //tempCourant=$scope.executerProcessus(file[0],tempCourant,quauntinum);
            
            while(!$scope.allProcessTreated(rr))
            {
                
                if(file.length!=0)
                {
                    file[0].debutExecution=tempCourant*1;
                    if(file[0].tempExecutionRestant*1<=quauntinum*1)
                    {
                        tempCourant=tempCourant*1+file[0].tempExecutionRestant*1;
                        file[0].tempExecutionRestant=0;
                    }
                    else{
                        tempCourant=tempCourant*1+quauntinum*1;
                        file[0].tempExecutionRestant-=quauntinum*1;
                    }
                    file[0].finExecution=tempCourant*1;
                    $scope.ajouterProcessusRR(file[0].nomProcessus,file[0].debutExecution,file[0].finExecution);
                }
                tabReady=$scope.getReadyRR(rr,file[0].debutExecution*1+1,file[0].finExecution*1);
                if (tabReady.length!=0)
                tabReady.sort(function(a, b) {
                    return parseFloat(a.dateArrivee*1) - parseFloat(b.dateArrivee*1);
                });
                
                for(var i=0;i<tabReady.length;i++)
                {
                    file.push(tabReady[i]);
                }
                if(file[0].tempExecutionRestant!=0)
                {
                    file.push(file[0]);
                }
                if((file.length==0)&&(tabReady.length==0)){tempCourant++;}
                file.splice(0,1);
                
            }
            
            //function(nomProcessus_,debutExecution_,finExecution_,tab)
            $scope.rrDiagrameTodo=modelRR.processusList;
            var tempExecutionMoyen=$scope.tempExecutionMoyenTodoRr($scope.rrDiagrameTodo);
            $scope.chaineTempExecutionMoeyenTodoRr=tempExecutionMoyen.chaine;
            $scope.tempExecutionMoyenNumberTodoRr=tempExecutionMoyen.moyenne;
            $scope.minimize($scope.rrDiagrameTodo);
        }else alert("champ invalide");
        }


        //fonction qui retourne un tableau representant le trie selon l'algorithme SJF
$scope.srt=function()
{
    var tempCourant=prompt('Saisir le temp de depart',0)*1;
    if (!isNaN(tempCourant))
    {
    $scope.inintList(model.processusList);
    var diagramme=[];
    var srt=model.processusList.slice();
    var tab=[];
    var i=0;
    var processusAEfface;
    modelSRT.processusList=[];
    
    while(srt.length!=0)
    {
        $scope.updateList(tempCourant,srt);
        tab=$scope.getReady(tempCourant*1,srt);
        tab.sort(function(a, b) {
            return parseFloat(a.tempExecutionRestant) - parseFloat(b.tempExecutionRestant);
        });
        
        if (tab.length==0) tempCourant++;
        else{
            tab[0].tempExecutionRestant--;
            tab[0].debutExecution=tempCourant;
            tempCourant++;
            tab[0].finExecution=tempCourant;
            $scope.ajouterProcessusDiagrameSrt(tab[0].nomProcessus,tab[0].debutExecution,tab[0].finExecution);
            
            if(tab[0].tempExecutionRestant==0)
            {
            processusAEfface=srt.indexOf(tab[0]);
            srt.splice(processusAEfface,1);
            }
            }
        }

    modelSRT.processusList.sort(function(a, b) {
            return parseFloat(a.debutExecution) - parseFloat(b.debutExecution);
        });      
  $scope.srtTodo=modelSRT.processusList;
  $scope.usedFunctions.srt=true;
  var tempExecutionMoyen=$scope.tempExecutionMoyenTodoSrt($scope.srtTodo);
  $scope.chaineTempExecutionMoeyenTodoSrt=tempExecutionMoyen.chaine;
  $scope.tempExecutionMoyenNumberTodoSrt=tempExecutionMoyen.moyenne;
  $scope.minimize($scope.srtTodo);
  
  
  
 
    }else alert("champ invalide");
}
    

//fonction qui retourne un tableau representant le trie selon l'algorithme SJF
$scope.sjfDiagrame=function()
{
    var tempCourant=prompt('Saisir le temp de depart',0)*1;
    if (!isNaN(tempCourant))
    {
    $scope.inintList(model.processusList);
    var diagramme=[];
    var sjf=model.processusList.slice();
    var tab=[];
    var i=0;
    var processusAEfface;
    while(sjf.length!=0)
    {
        $scope.updateList(tempCourant,sjf);
        tab=$scope.getReady(tempCourant*1,sjf);
        
        if (tab.length==0) tempCourant++;
        else{
            diagramme.push($scope.processusMinTempExecution(tab));
            diagramme[i].debutExecution=tempCourant;
            tempCourant=tempCourant+($scope.processusMinTempExecution(tab).tempExecution*1);
            diagramme[i].finExecution=tempCourant;
            processusAEfface=sjf.indexOf($scope.processusMinTempExecution(tab));
            sjf.splice(processusAEfface,1);
            i++;
            }
        }


  $scope.sjfTodo=diagramme;
  var tempExecutionMoyen=$scope.tempExecutionMoyenTodo($scope.sjfTodo);
  $scope.usedFunctions.sjf=true;
  $scope.chaineTempExecutionMoeyenTodo=tempExecutionMoyen.chaine;
  $scope.tempExecutionMoyenNumberTodo=tempExecutionMoyen.moyenne;
  return diagramme;
    }
}

$scope.todo=model;
$scope.usedFunctions=usedFunction;
})
