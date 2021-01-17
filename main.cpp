#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
using namespace std;

class Scrisori //clasa pentru scrisorile copiilor
{
public:
    string nume;
    string prenume;
    int varsta;
    string oras;
    string wishlist[5];
    string culoare_plic;
    Scrisori(); //constructor default
    Scrisori(string n,string p, int v, string o, string w[5],string cp){//constructor cu toti parametrii unei scrisori
        nume=n;
        prenume=p;
        varsta=v;
        oras=o;
        int i;
        for(i=0;i<3;i++)
            wishlist[i]=w[i];
        culoare_plic=cp;
    }
    ~Scrisori(void){}//destructor
};

class Copii:public Scrisori{//Mostenire
public:
    string status;
    int acadele_primite;
    Copii();
    Copii(string n,string p, int v, string o, string w[5],string cp,string stat):Scrisori{n, p, v, o, w, cp}{
        status=stat;
        nume=n;
        prenume=p;
        varsta=v;
        oras=o;
        int i;
        for(i=0;i<3;i++)
            wishlist[i]=w[i];
        culoare_plic=cp;
    };
    //Overloading
    void detalii(Copii c1){
        cout<<"\nInformatiile copilului\nNume: "<<c1.nume<<"\nPrenume: "<<c1.prenume<<"\nVarsta: "<<c1.varsta<<"\nOras: "<<c1.oras<<"\n";
    }
    void detalii(Copii c1,string text){
        int i;
        cout<<"Lista de dorinte a copilului: ";
        for(i=0;i<3;i++)
            cout<<c1.wishlist[i]<<" ";
        cout<<"\n";
    }
};

class Jucarii{//incapsulare
private:
    string nume;
    int pret;
public://getters si setters
    void set_nume(string n){
        this->nume=n;
        }
    void set_pret(int p){
        this->pret=p;
        }
    string get_nume(){
        return this->nume;
    }
    int get_pret(){
        return this->pret;
    }
};

class Elfi{
public:
float cadouri(Copii c,Jucarii juc[]){//functia care repartizeaza cadourile pentru copii
    int buget;
    int i,j,k;
    k=0;
    string sac[10];
    if(c.status=="cuminte")
    {buget=100;//pentru copiii cuminti bugetul este de 100$
    for(i=0;i<3;i++)
        for(j=0;j<14;j++)
            if(c.wishlist[i]==juc[j].get_nume()&&buget>0)//copilul primeste ce isi doreste daca bugetul permite asta
                if(buget>=juc[j].get_pret())
                {
                sac[k]=c.wishlist[i];//adaugam in sac cadoul pe care copilul si-l doreste
                k++;//contorizam cate cadouri primeste copilul
                buget=buget-juc[j].get_pret();//bugetul disponibil este micsorat cu atat cat costa cadoul respectiv
                }
    if(k==0){
        cout<<c.nume<<" "<<c.prenume<<" a fost copil cuminte si primeste cadoul default de 100$\n";//copilul primeste 
        // un cadou default daca nu a putu primi ce isi dorea
        c.acadele_primite=0;
    }
    else{
    cout<<c.nume<<" "<<c.prenume<<" a fost copil cuminte si primeste urmatoarele cadouri: ";//afisam cadourile primite
    for(i=0;i<k;i++){
        cout<<sac[i]<<" ";
    }
    cout<<"si "<<buget<<" acadele\n";
    c.acadele_primite=buget;//memoram numarul acadelelor daruite pentru a calcula mai tarziu bugetul extra
    }
    }
    else if(c.status=="rau")//repetam algoritmul de mai sus
    {buget=10;
    for(i=0;i<3;i++)
        for(j=0;j<14;j++)
            if(c.wishlist[i]==juc[j].get_nume()&&buget>0)
                if(buget>=juc[j].get_pret())
                {
                sac[k]=c.wishlist[i];
                k++;
                buget=buget-juc[j].get_pret();
                }
    if(k==0) {cout<<c.nume<<" "<<c.prenume<<" a fost copil rau si primeste cadoul default de 10$\n";c.acadele_primite=0;}
    else{
    cout<<c.nume<<" "<<c.prenume<<" a fost copil rau si primeste urmatoarele cadouri: ";
    for(i=0;i<k;i++){
        cout<<sac[i]<<" ";
    }
    cout<<"si "<<buget<<" acadele\n";
    c.acadele_primite=buget;
    }
    }
    return c.acadele_primite;
}
};

class Troli{
public:
template<class T>
void ambalaje(T color1, T color2, T color3, T color4, T color5){//functia care calculeaza cate ambalaje de fiecare fel se folosesc
    int blue,pink;
    blue=0; pink=0;
    if(color1=="albastru") blue++;
    if(color1=="roz") pink++;
    if(color2=="albastru") blue++;
    if(color2=="roz") pink++;
    if(color3=="albastru") blue++;
    if(color3=="roz") pink++;
    if(color4=="albastru") blue++;
    if(color4=="roz") pink++;
    if(color5=="albastru") blue++;
    if(color5=="roz") pink++;
    cout<<"\nAu fost folosite "<<blue<<" ambalaje pentru baieti si "<<pink<<" ambalaje pentru fete.\n";
}
int nr_carbuni(Copii copil){//pentru fiecare copil rau se adauga in cadou un carbune
    if(copil.status=="rau") return 1;
    return 0;
}
};

class Mos_Craciun{
private: int distante[5][5];
public:
        friend class Doamna_Craciun;//Doamna_Craciun este o clasa prietena a clasei Mos_Craciun, deoarece
        //traseul lui Mos Craciun este impartasit sotiei lui

        void set_distanta(int km,int i, int j){
            this->distante[i][j]=km;
        }

        int get_distanta(int i, int j){
            return this->distante[i][j];
        }

        void traseu(Mos_Craciun m){//functia care calculeaza cel mai scurt traseu pentru Mos Craciun
            int oras1,oras2,oras3,oras4,o1,o2,o3;
            int i,j,urm;
            oras1=20000;//initializam toate distantele dintre orase cu 20000
            oras2=20000;//pentru ca dorim sa facem minimele
            oras3=20000;
            oras4=20000;

            j=1;
            for(i=0;i<5;i++)
                if(m.get_distanta(0,i)<oras1&&m.get_distanta(0,i)!=0){//cautam minimul de pe prima linie(distanta cea mai scurta)
                    oras1=m.get_distanta(0,i);
                    urm=i;//memoram pozitia pe care s-a gasit minimul pentru a cauta minimul pe cealalta linie care il contine
                    o1=i;
                }
            if(urm==1) cout<<"Santa Cruz de la Sierra > ";//in functie de pozitia minimului afisam orasul respectiv acestei pozitii
            if(urm==2) cout<<"Oruro > ";
            if(urm==3) cout<<"El Alto > ";
            if(urm==4) cout<<"Cochabamba > ";
            for(i=0;i<5;i++)//in acest for cautam distanta minima de pe numarul liniei egal cu cel al coloanei care contine minimul gasit anterior(schimbam i cu j)
                if(m.get_distanta(urm,i)<oras2&&m.get_distanta(urm,i)!=0&&m.get_distanta(urm,i)!=oras1&&o1!=i){// conditie pentru a nu ne intoarce in orasul de unde venim
                    oras2=m.get_distanta(urm,i);
                }
            for(i=0;i<5;i++){
                if(m.get_distanta(urm,i)==oras2){
                    urm=i;
                    o2=i;
                }
            }
            if(urm==1) cout<<"Santa Cruz de la Sierra > ";
            if(urm==2) cout<<"Oruro > ";
            if(urm==3) cout<<"El Alto > ";
            if(urm==4) cout<<"Cochabamba > ";
            for(i=0;i<5;i++)
                if(m.get_distanta(urm,i)<oras3&&m.get_distanta(urm,i)!=0&&m.get_distanta(urm,i)!=oras2&&m.get_distanta(urm,i)!=oras1&&o1!=i&&o2!=i)
                    oras3=m.get_distanta(urm,i);
            for(i=0;i<5;i++){
                if(m.get_distanta(urm,i)==oras3){
                    urm=i;
                    o3=i;
                    break;
                }
            }
            if(urm==1) cout<<"Santa Cruz de la Sierra > ";
            if(urm==2) cout<<"Oruro > ";
            if(urm==3) cout<<"El Alto > ";
            if(urm==4) cout<<"Cochabamba > ";
            for(i=0;i<5;i++)
                if(m.get_distanta(urm,i)<oras4&&m.get_distanta(urm,i)!=0&&m.get_distanta(urm,i)!=oras3&&m.get_distanta(urm,i)!=oras2&&m.get_distanta(urm,i)!=oras1&&o1!=i&&o2!=i&&o3!=i)
                    oras4=m.get_distanta(urm,i);
            for(i=0;i<5;i++){
                if(m.get_distanta(urm,i)==oras4){
                    urm=i;
                }
            }
            if(urm==1) cout<<"Santa Cruz de la Sierra";
            if(urm==2) cout<<"Oruro";
            if(urm==3) cout<<"El Alto";
            if(urm==4) cout<<"Cochabamba";

            cout<<"\nMos Craciun parcurge in total "<<oras1+oras2+oras3+oras4<<" km\n";
            cout<<oras1<<" + "<<oras2<<" + "<<oras3<<" + "<<oras4<<" = "<<oras1+oras2+oras3+oras4<<" km\n";

        }

};

class Abstractizare{
    public: virtual void cel_mai_scurt_traseu(Mos_Craciun drum)=0;//initializam o virtual void function
};

class Doamna_Craciun:public Abstractizare{
public://Doamna Craciun primeste de la troli numarul de carbuni folositi
    float buget_extra_carbuni(int numar_carbuni){//functia care calculeaza bugetul extra pentru carbuni
        if(numar_carbuni==0) throw "Nu s-a folosit niciun carbune";//exceptie
        return  numar_carbuni*0.5;
    }
    //Doamna Craciun primeste de la elfi numarul de acadele folosite
    int buget_extra_acadele(int numar_acadele){//functie care calculeaza bugetul extra pentru acadele
        if(numar_acadele==0) throw "Nu a fost daruita nicio acadea";//exceptie
        return numar_acadele;
    }
    //Doamna Craciun vrea si ea sa afle traseul lui Mos Craciun, asa ca il impartaseste si cu ea
    void cel_mai_scurt_traseu(Mos_Craciun drum){
        cout<<"Mos Craciun a impartasit traseul lui cu doamna Craciun.\nEa a aflat ca sotul ei va calatori in felul urmator: Rovaniemi > ";
        drum.traseu(drum);
    }
};

int main()
{   Jucarii stoc_Jucarii[100];
    Troli trol;
    Elfi elf;
    Doamna_Craciun domnita;
    //introducem cadourile pe care elfii le au in stoc
    stoc_Jucarii[0].set_nume("masinuta");    stoc_Jucarii[0].set_pret(20);
    stoc_Jucarii[1].set_nume("trenulet");    stoc_Jucarii[1].set_pret(55);
    stoc_Jucarii[2].set_nume("avion");    stoc_Jucarii[2].set_pret(40);
    stoc_Jucarii[3].set_nume("stilou");    stoc_Jucarii[3].set_pret(5);
    stoc_Jucarii[4].set_nume("penar");    stoc_Jucarii[4].set_pret(10);
    stoc_Jucarii[5].set_nume("ghiozdan");    stoc_Jucarii[5].set_pret(25);
    stoc_Jucarii[6].set_nume("manusi");    stoc_Jucarii[6].set_pret(15);
    stoc_Jucarii[7].set_nume("fular");    stoc_Jucarii[7].set_pret(25);
    stoc_Jucarii[8].set_nume("ghete");    stoc_Jucarii[8].set_pret(80);
    stoc_Jucarii[9].set_nume("papusi");    stoc_Jucarii[9].set_pret(50);
    stoc_Jucarii[10].set_nume("carucior");    stoc_Jucarii[10].set_pret(40);
    stoc_Jucarii[11].set_nume("ponei");    stoc_Jucarii[11].set_pret(75);
    stoc_Jucarii[12].set_nume("adidasi");    stoc_Jucarii[12].set_pret(90);
    stoc_Jucarii[13].set_nume("minge");    stoc_Jucarii[13].set_pret(10);

    int i,j;//afisam stocul de jucarii
    cout<<"\n     STOC JUCARII     \n\nNUME/PRET\n";
    for(i=0;i<14;i++){
    cout<<stoc_Jucarii[i].get_nume()<<" "<<stoc_Jucarii[i].get_pret()<<"$\n";
    }
    string lista_dorinte1[3]={"masinuta","trenulet","avion"};//lista de dorinte
    Copii copil1("Bouleanu","Viorel",12,"Santa Cruz de la Sierra",lista_dorinte1,"albastru","cuminte");//obiect de tip copil, cu toate informatiile copilului
    Scrisori scrisoare1(copil1.nume,copil1.prenume,copil1.varsta,copil1.oras,copil1.wishlist,copil1.culoare_plic);//scrisoarea primului copil

    string lista_dorinte2[3]={"stilou","ghiozdan","penar"};
    Copii copil2("Yanos","Ygen",14,"Oruro",lista_dorinte2,"albastru","rau");
    Scrisori scrisoare2(copil2.nume,copil2.prenume,copil2.varsta,copil2.oras,copil2.wishlist,copil2.culoare_plic);

    string lista_dorinte3[3]={"manusi","fular","ghete"};
    Copii copil3("Antonescu","Diana",9,"El Alto",lista_dorinte3,"roz","cuminte");
    Scrisori scrisoare3(copil3.nume,copil3.prenume,copil3.varsta,copil3.oras,copil3.wishlist,copil3.culoare_plic);

    string lista_dorinte4[3]={"papusi","carucior","ponei"};
    Copii copil4("Popescu","Mihaela",8,"El Alto",lista_dorinte4,"roz","rau");
    Scrisori scrisoare4(copil4.nume,copil4.prenume,copil4.varsta,copil4.oras,copil4.wishlist,copil4.culoare_plic);

    string lista_dorinte5[3]={"adidasi","minge","genunchere"};
    Copii copil5("Mugur","Isarescu",5,"Cochabamba",lista_dorinte5,"albastru","rau");
    Scrisori scrisoare5(copil5.nume,copil5.prenume,copil5.varsta,copil5.oras,copil5.wishlist,copil5.culoare_plic);

    cout<<"\n     SCRISORI    \n";//afisam scrisorile copiilor
    cout<<"\nScrisoare 1\n";    copil1.detalii(copil1);    copil1.detalii(copil1,"wishlist");
    cout<<"\nScrisoare 2\n";    copil2.detalii(copil2);    copil2.detalii(copil2,"wishlist");
    cout<<"\nScrisoare 3\n";    copil3.detalii(copil3);    copil3.detalii(copil3,"wishlist");
    cout<<"\nScrisoare 4\n";    copil4.detalii(copil4);    copil4.detalii(copil4,"wishlist");
    cout<<"\nScrisoare 5\n";    copil5.detalii(copil5);    copil5.detalii(copil5,"wishlist");
    cout<<"\n";

    cout<<"\n     LISTE CADOURI PRIMITE DE COPII     \n\n";//afisam cadourile primite de copii
    int buget_extra_acadele=0;
    buget_extra_acadele=buget_extra_acadele+elf.cadouri(copil1,stoc_Jucarii);
    buget_extra_acadele=buget_extra_acadele+elf.cadouri(copil2,stoc_Jucarii);
    buget_extra_acadele=buget_extra_acadele+elf.cadouri(copil3,stoc_Jucarii);
    buget_extra_acadele=buget_extra_acadele+elf.cadouri(copil4,stoc_Jucarii);
    buget_extra_acadele=buget_extra_acadele+elf.cadouri(copil5,stoc_Jucarii);

    cout<<"\n     AMBALAJE CADOURI     \n";//afisam cate cadouri de fiecare fel s-au folosit
    trol.ambalaje<string>(copil1.culoare_plic,copil2.culoare_plic,copil3.culoare_plic,copil4.culoare_plic,copil5.culoare_plic);

    int nr_carbuni=0;
    if(trol.nr_carbuni(copil1)==1) nr_carbuni++;//incepem sa numaram cati carbuni s-au folosit
    if(trol.nr_carbuni(copil2)==1) nr_carbuni++;
    if(trol.nr_carbuni(copil3)==1) nr_carbuni++;
    if(trol.nr_carbuni(copil4)==1) nr_carbuni++;
    if(trol.nr_carbuni(copil5)==1) nr_carbuni++;

    float buget_extra_carb;//bugetul extra carbuni
    try {
        buget_extra_carb=domnita.buget_extra_carbuni(nr_carbuni);
    }
    catch(const char *msg){
        cout<<msg;
        buget_extra_carb=0;
    }

    try{//buget extra acadele
        buget_extra_acadele=domnita.buget_extra_acadele(buget_extra_acadele);
    }
    catch(const char *msg){
        cout<<msg;
        buget_extra_acadele=0;
    }
    //afisam bugetul extra total
    cout<<"\n\n     BUGET EXTRA     \n\n";
    cout<<"Doamna Craciun a primit listele cu numarul de acadele folosite de elfi si cele cu numarul de carbuni folositi de troli.\n";
    cout<<"Dupa ce a facut calculele, reiese faptul ca bugetul extra este de "<<buget_extra_carb+buget_extra_acadele<<" $.\n\n";

    Mos_Craciun itinerariu,drum_minim;
    //construim matricea care contine distantele dintre toate orasele
    itinerariu.set_distanta(0,0,0);
    itinerariu.set_distanta(11768,0,1);
    itinerariu.set_distanta(11958,0,2);
    itinerariu.set_distanta(11862,0,3);
    itinerariu.set_distanta(11861,0,4);
    itinerariu.set_distanta(11768,1,0);
    itinerariu.set_distanta(0,1,1);
    itinerariu.set_distanta(415,1,2);
    itinerariu.set_distanta(551,1,3);
    itinerariu.set_distanta(320,1,4);
    itinerariu.set_distanta(11958,2,0);
    itinerariu.set_distanta(415,2,1);
    itinerariu.set_distanta(0,2,2);
    itinerariu.set_distanta(198,2,3);
    itinerariu.set_distanta(116,2,4);
    itinerariu.set_distanta(11862,3,0);
    itinerariu.set_distanta(551,3,1);
    itinerariu.set_distanta(198,3,2);
    itinerariu.set_distanta(0,3,3);
    itinerariu.set_distanta(236,3,4);
    itinerariu.set_distanta(11861,4,0);
    itinerariu.set_distanta(320,4,1);
    itinerariu.set_distanta(116,4,2);
    itinerariu.set_distanta(236,4,3);
    itinerariu.set_distanta(0,4,4);

    /*int a;
    for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++){
                a=itinerariu.get_distanta(i,j);//afisam matricea cu toate distantele
                cout<<a<<" ";
            }
            cout<<"\n";
        }
    */
    cout<<"\n     TRASEU MOS CRACIUN     \n\nMos Craciun a primit lista cu orase de la elfi.\n";
    cout<<"Pleaca in Bolivia cu sania din aeroportul din Laponia(Finlanda).\n";
    cout<<"Traseul lui este urmatorul:\nRovaniemi > ";
    itinerariu.traseu(itinerariu);//apelam functia care calculeaza cel mai scurt traseu
    cout<<"\n\n     DOAMNA CRACIUN AFLA TRASEUL SOTULUI EI     \n\n";
    domnita.cel_mai_scurt_traseu(itinerariu);//Doamna Craciun primeste traseul lui Mos Craciun, cu tot cu km parcursi
    cout<<"\n\n";
}
