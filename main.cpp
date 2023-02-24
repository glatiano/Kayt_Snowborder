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
        cout<<"-------PARTECIPANTI GARA---------------"<<endl;
        while (!fin.eof()){
        getline(fin,part[righe].matricola,',');
        cout<<part[righe].matricola<<",";
        getline(fin,part[righe].cognome);
        cout<<part[righe].cognome;
        cout<<endl;
        righe++;
        }
        cout<<"---------------------------------------"<<endl;
    fin.close();
}
void gen_coordinate(){
    ofstream fout("garafinita.txt");
    for (int f=0; f<righe; f++)
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
            part[f].distanza=part[i].distanza+sqrt(pow(part[f].x1[i]-part[f].x2[i],2)+pow(part[f].y1[i]-part[f].y2[i],2));
        }
        fout<<part[f].distanza<<endl;
    }
    fout.close();
}
void vis_ris(){
    cout<<"-------RISULTATI FINALI---------------"<<endl;
    for (int f=0; f<righe; f++)
    {
        cout<<part[f].matricola<<",";
        cout<<part[f].cognome<<", ";
        cout<<part[f].distanza<<" km"<<endl;
    }
    cout<<"---------------------------------------"<<endl;
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
        a++;
    } while (b==false);
    int n=1;
    cout<<"---------------------------PODIO----------------------------"<<endl;
    for (int i=righe-1; i>righe-4; i--)
    {
        cout<<n<<"-";
        cout<<part[i].matricola<<",";
        cout<<part[i].cognome<<", ";
        cout<<part[i].distanza<<" km"<<endl;
        n++;
    }
    cout<<"-----------------------------------------------------------"<<endl;
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
