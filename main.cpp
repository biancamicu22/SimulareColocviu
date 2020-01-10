#include <iostream>

using namespace std;

class admitere
{
    //float nota_oral;
    float nota_mate_bac;
    string program;
    static bool I2;

public:
    admitere(){}

    friend ifstream& operator >> (istream& in, admitere& adm)
    {
        cout<<"Care este programul absolvit anterior?"<<endl;
        in>>adm.program;
    }

    void afisare()
    {
            cout<<"Programul absolvit anterior: "<<program<<endl;
    }

    virtual float medie_admitere() = 0;
};

class IF : public admitere
{
    string nume;
    float nota_proba_scrisa1, nota_proba_scrisa2;
    int nr_inreg;
    bool IF2;
    float nota_absolvire_fac;
    float medie_bac;
    float nota_oral, medie_absolvire;

public:
    IF()
    {
        nume = "---";
        nr_inreg=0;
    }

    IF(const IF& a): admitere(a)
    {
        nume = a.nume;

        cout<<"CC IF"<<endl;
    }

    friend istream& operator >> (istream& in, IF& a)
    {
        cout<<"Numar de inregistrare: "<<a.nr_inreg<<endl;
        cout<<"Numele studentului este:"<<endl;
        in>>a.nume;
        cout<<"Studentul este la a 2-a facultate?"<<endl;
        in>>a.IF2;
        if(a.IF2 == 1)
        {
        in>>(admitere&)a;
        cout<<"Care este media sa de absolvire a facultatii?"<<endl;
        in>>a.nota_absolvire_fac;
        }
        else
        {
            cout<<"Care este media sa de BAC?"<<endl;
            in>>a.medie_bac;
            cout<<"Nota de la prima proba scrisa:"<<endl;
            in>>a.nota_proba_scrisa1;
            cout<<"Nota de la a doua proba scrisa:"<<endl;
            in>>a.nota_proba_scrisa2;
        }
    }

    void afisare()
    {
        cout<<endl;
        cout<<"Nume student:"<<nume<<endl;
        //admitere::afisare();
        if(IF2 == 0)
        {
            cout<<"Nota proba 1:"<<nota_proba_scrisa1<<endl;
            cout<<"Nota proba 2:"<<nota_proba_scrisa2<<endl;
            cout<<"Medie admitere:"<<medie_admitere()<<endl;
        }
        else
        {
            admitere::afisare();
            cout<<"Medie absolvire facultate:"<<medie_absolvire<<endl;
            cout<<"Nota proba orala admitere:"<<nota_oral<<endl;
            cout<<"Media sa de admitere: "<<medie_admitere()<<endl;
        }
    }

    float medie_admitere()
    {
        float MA;
        if(IF2 == 0)
            MA = 0.8 * ((nota_proba_scrisa1 + nota_proba_scrisa2)/2) + 0.2 * medie_bac;
        else if (IF2 == 1)
            MA = 0.6 * nota_oral + 0.4 * medie_absolvire;
        return MA;
    }
};

class ID: public admitere
{
    string nume;
    float nota_bac_mate;
    int nr_inreg;
    bool ID2;
    float nota_absolvire_fac;
    float medie_bac;
    float nota_oral;
    float medie_absolvire;

public:
    ID()
    {
        nume = "---";
        nr_inreg=0;
    }

    ID(const ID& a): admitere(a)
    {
        nume = a.nume;
        nr_inreg = a.nr_inreg;

        cout<<"CC IF"<<endl;
    }

    friend istream& operator >> (istream& in, ID& a)
    {
        a.nr_inreg++;
        cout<<"Numele studentului este:"<<endl;
        in>>a.nume;
        cout<<"Studentul este la a 2-a facultate?"<<endl;
        in>>a.ID2;
        if(a.ID2 == 1)
        {
        in>>(admitere&)a;
        cout<<"Care este media sa de absolvire a facultatii?"<<endl;
        in>>a.nota_absolvire_fac;
        cout<<"Care este nota la proba orala?"<<endl;
        in>>a.nota_oral;
        }
        else
        {
            cout<<"Nota de la matematica de la bac:"<<endl;
            in>>a.nota_bac_mate;
        }
    }

    void afisare()
    {
        cout<<endl;
        cout<<"Numar de inregistrare:"<<nr_inreg<<endl;
        cout<<"Nume student:"<<nume<<endl;
        if(ID2 == 0)
        {
            cout<<"Nota BAC mate:"<<nota_bac_mate<<endl;
            cout<<"Nota proba orala"<<nota_oral<<endl;
            cout<<"Medie admitere:"<<medie_admitere()<<endl;
        }
        else
        {
            admitere::afisare();
            cout<<"Medie absolvire facultate:"<<medie_absolvire<<endl;
            cout<<"Nota proba orala admitere:"<<nota_oral<<endl;
            cout<<"Media sa de admitere: "<<medie_admitere()<<endl;
        }
    }

    float medie_admitere()
    {
        float MA;
        if(ID2 == 0)
            MA = 0.6 * nota_oral + 0.4 * nota_bac_mate;
        else if (ID2 == 1)
            MA = 0.6 * nota_oral + 0.4 * medie_absolvire;
        return MA;
    }

};
int main()
{
    /*IF S;
    cin>>S;
    S.afisare();*/

    ID S1;
    cin>>S1;
    S1.afisare();
    return 0;
}
