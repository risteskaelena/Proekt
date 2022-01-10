// Elena Risteska INKI876
// Kodiranje i dekodiranje na tekst spored daden kluc - zadaca 47

#include <iostream>
//potrebni biblioteki
#include <cstring>
#include <cctype>

using namespace std;

//funkcija za proverka na vnesen string
bool proverka (string niza, int dolzina)
{
    int i;
    bool p=true;
    for(i=0;i<dolzina;i++)
    {
        if((!isalpha(niza[i]) && !isdigit(niza[i]) && !isblank(niza[i])) || dolzina>600)
        {
            p=false;
            break;
        }
    }
    return p;
}
//funkcija za presmetuvanje razlika
int presmetajRazlika()
{
    int broj, najmala=9, cifra;
    cout<<"Vnesete cetiricifren pozitiven broj. Brojot ne smee da bide 0000."<<endl;
    cin>>broj;
    //postavuvanje granici
    while((broj<1000 || broj>9999) || broj==0000)
    {
        cout<<"Ne go pocituvate limitot. Obidete se povtorno..."<<endl;
        cin>>broj;
    }
    //izdeluvanje najmala cifra
    while(broj>0)
    {
        cifra=broj%10;
        if(cifra<najmala)
        {
            najmala=cifra;
        }
        broj/=10;
    }
    //dobivanje na razlikata
    return 4-najmala;
}
//funkcija za kodiranje na vnesen string
string kodiranje(string nizaZnaci, int dolzina, int razlika)
{
    int i;
    for(i=0;i<dolzina;i++)
    {
        nizaZnaci[i]=(char)(nizaZnaci[i]+razlika);
    }
    return nizaZnaci;
}
//funkcija za dekodiranje na vnesen string
string dekodiranje(string nizaZnaci, int dolzina, int razlika)
{
    int i;
    for(i=0;i<dolzina;i++)
    {
        nizaZnaci[i]=(char)(nizaZnaci[i]-razlika);
    }
    return nizaZnaci;
}
int main()
{
    //deklariranje promenlivi
    int razlika, opcija, dolzina;
    string niza, kodiranString, dekodiranString;
    bool proveri;
    //izbiranje opcija od meni
    do
    {
        cout<<"Izberete opcija: \n1. Kodiranje \n2. Dekodiranje \nVnesete 0 za izlez..."<<endl;
        cin>>opcija;
        //proverka na vnesena opcija
        while(opcija!=1 && opcija!=2 && opcija!=0)
        {
            cout<<"Nevalidno. Obidete se povtorno..."<<endl;
            cin>>opcija;
        }
        //kodiranje
        if(opcija==1)
        {
            cout<<"Vnesete string so maksimalna dolzina od 600 karakteri. Moze da sodrzi bukvi, brojki i prazni mesta."<<endl;
            cin.clear();
            cin.sync();
            getline(cin,niza);
            dolzina=niza.length();
            proveri=proverka(niza,dolzina);
            //proverka dali stringot e spored dadenite kriteriumi
            while(proveri==false)
            {
                cout<<"Ne gi pocituvate pravilata. Obidete se povtorno..."<<endl;
                cin.clear();
                cin.sync();
                getline(cin,niza);
                dolzina=niza.length();
                proveri=proverka(niza,dolzina);
            }
            //pretvoranje na string vo niza znaci
            char nizaZnaci[dolzina];
            strcpy(nizaZnaci,niza.c_str());
            razlika=presmetajRazlika();
            kodiranString=kodiranje(nizaZnaci, dolzina, razlika);
            cout<<"Kodiraniot string e: "<<kodiranString<<endl;
        }
        //dekodiranje
        if(opcija==2)
        {
            cout<<"Vnesete string so maksimalna dolzina od 600 karakteri. Moze da sodrzi bukvi, brojki i prazni mesta."<<endl;
            cin.clear();
            cin.sync();
            getline(cin,niza);
            dolzina=niza.size();
            //za opcijata dekodiranje proverkata na stringot se izostava bidejki tuka moze da se sodrzat i drugi karakteri
            //pretvoranje na string vo niza znaci
            char nizaZnaci[dolzina];
            strcpy(nizaZnaci,niza.c_str());
            razlika=presmetajRazlika();
            dekodiranString=dekodiranje(nizaZnaci, dolzina, razlika);
            cout<<"Dekodiraniot string e: "<<dekodiranString<<endl;
        }
    } while (opcija!=0);
    return 0;
}
