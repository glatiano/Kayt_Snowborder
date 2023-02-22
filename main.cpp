#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <cctype>
#include <math.h>
using namespace std;
struct partecipante{
    string matricola;
    string cognome;
    int x1, x2, y1, y2;
    float distanza;
};
partecipante part[40];
int righe=0;
void riempi_vet(){
    string app;
    ifstream fin("gara.txt");
    if (!fin) cout<<"Errore di apertura del file";
        cout<<"---------------------------GARA----------------------------"<<endl;
        while (!fin.eof()){
        getline(fin,part[righe].matricola,',');
        cout<<part[righe].matricola<<",";
        getline(fin,part[righe].cognome);
        cout<<part[righe].cognome;
        cout<<endl;
        righe++;
        }
        cout<<endl<<"-----------------------------------------------------------"<<endl;
    fin.close();
}
void gen_coordinate(){
    cout<<"righe="<<righe<<endl;
    for(int i=0; i<righe; i++){
        part[i].x1=rand()%101;
        part[i].x2=rand()%101;
        part[i].y1=rand()%101;
        part[i].y2=rand()%101;
        part[i].distanza=part[i].distanza*sqrt(pow(part[i].x1-part[i].x2,2)+pow(part[i].y1-part[i].y2,2));
    }
}
void vis_ris(){
}
void vis_podio(){
}
int main(){

    srand(time(NULL));
    int s;
    do{
        cout<<"------- MENU -------"<<endl;
        cout<<"1 - Visualizza partecipanti"<<endl;
        cout<<"2 - Simula gara"<<endl;
        cout<<"3 - Visualizza risultati finali"<<endl;
        cout<<"4 - Visualizza podio"<<endl;
        cout<<"5 - Uscita";
        cout<<endl<<"Inserire il numero equivalente all' operazione da eseguire : ";
        cin>>s;
        switch(s)
        {
            case 1:
                riempi_vet();
            break;
            case 2:
                gen_coordinate();
            break;
            case 3:
                vis_ris();
            break;
            case 4:
                vis_podio();
            break;
        }
    }while(s!=5);
    return 0;
}
