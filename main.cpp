/*!
\file Kayt-Snowboarder.h
\brief gara di Kayt-Snowboarder
\author Giuseppe Latiano
\version 1.0
\date 25/02/2023
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
    //! \var x1
    //! \brief coordinata x1 utilizzata per il calcolo della distanza totale
    //! \var x2
    //! \brief coordinata x1 utilizzata per il calcolo della distanza totale
    //! \var y1
    //! \brief coordinata x1 utilizzata per il calcolo della distanza totale
    //! \var y2
    //! \brief coordinata x1 utilizzata per il calcolo della distanza totale
    int x1[30], x2[30], y1[30], y2[30];
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
\fn riempi_vet
\brief Funzione utilizzata per riempire il vettore
*/
void riempi_vet(){
    string app;
    ifstream fin("gara.txt");
    if (!fin) cout<<"Errore di apertura del file";
        cout<<"-------PARTECIPANTI GARA---------------"<<endl;
        while (!fin.eof()){
        getline(fin,part[n_par].matricola,',');
        cout<<part[n_par].matricola<<",";
        getline(fin,part[n_par].cognome);
        cout<<part[n_par].cognome;
        cout<<endl;
        n_par++;
        }
        cout<<"---------------------------------------"<<endl;
    fin.close();
}
/*!
\fn gen_coordinate
\brief Funzione utilizzata per generare le coordinate
*/
void gen_coordinate(){
    ofstream fout("garafinita.txt");
    for (int f=0; f<n_par; f++)
    {
        fout<<part[f].matricola<<",";
        fout<<part[f].cognome<<", ";
        for(int i=0; i<30; i++)
        {
            part[f].x1[i]=rand()%101;
            fout<<part[f].x1[i]<<", ";
            part[f].x2[i]=rand()%101;
            fout<<part[f].x2[i]<<"; ";
            part[f].y1[i]=rand()%101;
            fout<<part[f].y1[i]<<", ";
            part[f].y2[i]=rand()%101;
            fout<<part[f].y2[i]<<" || ";
            part[f].distanza=part[f].distanza+sqrt(pow(part[f].x1[i]-part[f].x2[i],2)+pow(part[f].y1[i]-part[f].y2[i],2));
        }
        part[f].distanza=part[f].distanza/10;
        fout<<part[f].distanza<<endl;
    }
    fout.close();
}
/*!
\fn vis_ris
\brief Funzione utilizzata per visualizzare i risultati finali della gara
*/
void vis_ris(){
    cout<<"-------RISULTATI FINALI---------------"<<endl;
    for (int f=0; f<n_par; f++)
    {
        cout<<part[f].matricola<<",";
        cout<<part[f].cognome<<", ";
        cout<<part[f].distanza<<" km"<<endl;
    }
    cout<<"---------------------------------------"<<endl;
}
/*!
\fn vis_podio
\brief Funzione utilizzata per visualizzare il podio
*/
void vis_podio(){
    partecipante app;
    bool b;
    int a=0;
    do{
        b=true;
        for (int i=a+1; i<n_par; i++)
        {
            if (part[a].distanza>part[i].distanza)
                {
                    app=part[a];
                    part[a]=part[i];
                    part[i]=app;
                    b=false;
                }
        }
        a++;
    } while (b==false);
    int n=1;
    cout<<"------------------PODIO-------------------"<<endl;
    for (int i=n_par-1; i>n_par-4; i--)
    {
        cout<<n<<"-";
        cout<<part[i].matricola<<",";
        cout<<part[i].cognome<<", ";
        cout<<part[i].distanza<<" km"<<endl;
        n++;
    }
    cout<<"------------------------------------------"<<endl;
}
int main(){
    srand(time(NULL));
    int s;
    do{
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
