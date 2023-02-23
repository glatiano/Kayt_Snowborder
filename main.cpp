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
    int x1[30], x2[30], y1[30], y2[30];
    float distanza=0;
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
    for (int f=0; f<righe; f++)
    {
        for(int i=0; i<30; i++)
        {
            part[f].x1[i]=rand()%101;
            part[f].x2[i]=rand()%101;
            part[f].y1[i]=rand()%101;
            part[f].y2[i]=rand()%101;
            part[f].distanza=part[i].distanza+sqrt(pow(part[f].x1[i]-part[f].x2[i],2)+pow(part[f].y1[i]-part[f].y2[i],2));
        }
    }
}
void vis_ris(){
    for (int f=0; f<righe; f++)
    {
        cout<<part[f].matricola<<",";
        cout<<part[f].cognome<<", ";
        cout<<part[f].distanza<<" km"<<endl;
    }
}
void vis_podio(){
    partecipante podio[righe];
    partecipante app;
    bool b;
    int a=0;
    do{
        b=true;
        for (int i=a+1; i<righe; i++)
        {
            if (part[a].distanza>part[i].distanza)
                {
                    app=part[a];
                    part[a]=part[i];
                    part[i]=app;
                    b=false;
                }
        }
    } while (b==false);

    cout<<"righe="<<righe<<endl;
    cout<<"---------------------------PODIO----------------------------"<<endl;
    for (int i=0; i<righe; i++)
    {
        cout<<part[righe].matricola<<", ";
        cout<<part[righe].cognome<<", ";
        cout<<part[righe].distanza<<endl;
    }
    cout<<endl<<"-----------------------------------------------------------"<<endl;
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
