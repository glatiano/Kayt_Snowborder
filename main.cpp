/*!
\file main.cpp
\brief gara di Kayt-Snowboarder
\author Giuseppe Latiano
\version 1.0
\date 26/02/2023
*/
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <cctype>
#include <math.h>
using namespace std;
/*!
\class partecipante
\brief Struttura alla base del programma
*/
struct partecipante{
    //! \var matricola
    //! \brief numero che identifica univocamente il partecipante alla gara
    string matricola;
    //! \var cognome
    //! \brief cognome del partecipante alla gara
    string cognome;
    //! \var minutaggio
    //! \brief variabile che viene utilizzata per tenere conto dei minuti
    int minutaggio;
    //! \var x1
    //! \brief coordinata x1 utilizzata per il calcolo della distanza totale
    //! \var y1
    //! \brief coordinata y1 utilizzata per il calcolo della distanza totale
    int x1[30], y1[30];
    //! \var distanza
    //! \brief variabile utlizzata per indicare la distanza percorsa da ogni pertecipante
    float distanza=0;
};
//! \var part
//! \brief vettore di tipo partecipante
partecipante part[40];
//! \var n_par
//! \brief utlizzata per contare i partecipanti
int n_par=0;
/*!
\fn riempi_vet()
\brief Funzione utilizzata per riempire il vettore e per visualizzare i partecipanti alla gara
*/
void riempi_vet(){
    ifstream fin("gara.txt"); //! \brief apertura del file gara.txt
    if (!fin) cout<<"Errore di apertura del file";
        cout<<"-------PARTECIPANTI GARA---------------"<<endl;
        while (!fin.eof()){ //! \brief ciclo while che leggerà fino alla fine del file
        getline(fin,part[n_par].matricola,','); //! \brief getline che prenderà tutti i caratteri presenti finchè non incontrerà la virgola
        cout<<part[n_par].matricola<<",";  //! \brief cout che stamperà la matricola del partecipante
        getline(fin,part[n_par].cognome);
        cout<<part[n_par].cognome;
        cout<<endl;
        n_par++; //! \brief incremento del numero dei partecipanti
        }
        cout<<"---------------------------------------"<<endl;
    fin.close(); //! \brief chiusura del canale di comunicazione con il file
}
/*!
\fn gen_coordinate()
\brief Funzione utilizzata per generare le coordinate
*/
void gen_coordinate(){
    ofstream fout("garafinita.txt"); //! \brief apertura de file garafinita.txt
    for (int f=0; f<n_par; f++) //! \brief for che va da 0 al numero dei partecipanti
    {
        fout<<part[f].matricola<<","; //! \brief scrittura nel file della matricola
        fout<<part[f].cognome<<", "; //! \brief scrittura nel file del cognome
        part[f].x1[0]=0; //! \brief inizializzazione della variabile x1 per far partire il partecipante a 0,0
        part[f].y1[0]=0; //! \brief inizializzazione della variabile y1 per far partire il partecipante a 0,0
        fout<<part[f].x1[0]<<" ; "; //! \brief scrittura nel file della coordinata x1
        fout<<part[f].y1[0]<<" || "; //! \brief scrittura nel file della coordinata y1
        part[f].minutaggio=rand()%11+20; //! \brief randomizzazione del minutaggio di ogni partecipante da 20 a 30
        for(int i=0; i<part[f].minutaggio; i++) //! \brief for che va da 0 ai minuti in cui è stato in gara il partecipante
        {
            part[f].x1[i]=rand()%101; //! \brief randomizzazione della coordinata x1 da 0 a 100
            fout<<part[f].x1[i]<<" ; "; //! \brief scrittura nel file della coordinata x1
            part[f].y1[i]=rand()%101; //! \brief randomizzazione della coordinata y1 da 0 a 100
            fout<<part[f].y1[i]<<" || "; //! \brief scrittura nel file della coordinata y1
            part[f].distanza=part[f].distanza+sqrt(pow(part[f].x1[i]-part[f].x1[i-1],2)+pow(part[f].y1[i]-part[f].y1[i-1],2)); //! \brief calcolo della distanza parziale
        }
        part[f].distanza=part[f].distanza/10; //! \brief distanza divisa per 10 (semplicemente per rendere più credibile il risultato)
        fout<<part[f].distanza<<" km, "; //! \brief scrittura nel file della distanza totale
        fout<<part[f].minutaggio<<" min"<<endl; //! \brief scrittura nel file del minutaggio
    }
    fout.close(); //! \brief chiusura del canale di comunicazione con il file
}
/*!
\fn vis_ris()
\brief Funzione utilizzata per visualizzare i risultati finali della gara
*/
void vis_ris(){
    cout<<"-------RISULTATI FINALI---------------"<<endl;
    for (int f=0; f<n_par; f++) //! \brief for che va da 0 al numero dei partecipanti
    {
        cout<<part[f].matricola<<","; //! \brief stampa della matricola a video
        cout<<part[f].cognome<<", "; //! \brief stampa del cognome a video
        cout<<part[f].distanza<<" km, "; //! \brief stampa della distanza a video
        cout<<part[f].minutaggio<<" min"<<endl; //! \brief stampa del minutaggio a video
    }
    cout<<"---------------------------------------"<<endl;
}
/*!
\fn vis_podio()
\brief Funzione utilizzata per visualizzare il podio
*/
void vis_podio(){
    /*!
    \var app
    \brief variabile d'appoggio per stampare il podio
    */
    partecipante app;
    /*!
    \var b
    \brief variabile per controllare se è avvenuto l'ordinamento
    */
    bool b;
    /*!
    \var a
    \brief variabile per il funzionamento dell'algoritmo
    */
    int a=0;
    do{ //! \brief ciclo do while finchè b=false
        b=true; //! \brief inizializzazione di b a true
        for (int i=a+1; i<n_par; i++) //! \brief ciclo for che va da i+1 al numero dei partecipanti in gara
        {
            if (part[a].distanza>part[i].distanza) //! \brief if per controllare se la distanza di un partecipante è maggiore di quella del successivo
                {
                    //! \brief se la condizione dell'if è vera
                    app=part[a]; //! \brief immagazzinamento in app del partecipante alla posizione a
                    part[a]=part[i]; //! \brief immagazzinamento in part alla posizione a del partecipante alla posizione i
                    part[i]=app; //! \brief immagazzinamento in part alla posizione i la variabile app
                    b=false; //! \brief b=false per rimanere nel ciclo do while
                }
        }
        a++; //! \brief incremento della variabile a
    } while (b==false);
    //! \var n
    //! \brief utlizzata per stampare il numero del podio
    int n=1;
    cout<<"------------------PODIO-------------------"<<endl;
    for (int i=n_par-1; i>n_par-4; i--) //! \brief ciclo for che va da numero dei partecipanti - 1 al numero dei partecipanti - 4 e viene utilizzato per prendere i 3 migliori punteggi
    {
        cout<<n<<"-"; //! \brief stampa della posizione in classifica
        cout<<part[i].matricola<<","; //! \brief stampa della matricola a video
        cout<<part[i].cognome<<", "; //! \brief stampa del cognome a video
        cout<<part[i].distanza<<" km, "; //! \brief stampa della distanza a video
        cout<<part[i].minutaggio<<" min"<<endl; //! \brief stampa del minutaggio a video
        n++; //! \brief incremento di n
    }
    cout<<"------------------------------------------"<<endl;
}
int main(){
    srand(time(NULL));
    int s;
    do{ //! \brief menu contenente le scelte possibili da fare nel programma
        cout<<endl<<"------- MENU -------"<<endl;
        cout<<"1 - Visualizza partecipanti"<<endl;
        cout<<"2 - Simula gara"<<endl;
        cout<<"3 - Visualizza risultati finali"<<endl;
        cout<<"4 - Visualizza podio"<<endl;
        cout<<"5 - Uscita";
        cout<<endl<<"Inserire il numero equivalente all' operazione da eseguire : ";
        cin>>s;
        switch(s)
        {
            case 1:{
                cout<<endl;
                riempi_vet();
            }
            break;
            case 2:{
                gen_coordinate();
                cout<<endl<<"Gara in corso......."<<endl;
            }
            break;
            case 3:{
                cout<<endl;
                vis_ris();
            }
            break;
            case 4:{
                cout<<endl;
                vis_podio();
            }
            break;
        }
    }while(s!=5);
    return 0;
}
