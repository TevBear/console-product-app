#include <fstream>
#include <iomanip>
#include <cstring>
#ifndef TEV_H_INCLUDED
#define TEV_H_INCLUDED
#define year 2024

using namespace std;
struct product{
char name[20];
double price;
int Ed,Em,Ey;
//yyyymmdd
int quantity;
char instock[6];
}*t;
int pn;
void ImportData(char filename[]){
ifstream file;
file.open(filename);
file>>pn;
t=new product[pn];

for(int i=0;i<pn;i++){
    file>>t[i].name>>t[i].price>>t[i].Ey>>t[i].Em>>t[i].Ed>>t[i].quantity;
    if(t[i].quantity==0) strcpy(t[i].instock,"false");
    else strcpy(t[i].instock,"true");
}
file.close();
}

void ShowData(){
    system("cls");
    cout<<setw(20)<<"Name"<<setw(15)<<"Price"<<setw(26)<<"Data de expirare"<<setw(20)<<"Cantitatea"<<setw(15)<<"Stock"<<setw(5)<<"Id"<<endl;
    for(int i=0;i<102;i++)cout<<'_';
    cout<<endl;
    for(int i=0;i<pn;i++){
        cout<<setw(20)<<t[i].name<<setw(15)<<t[i].price<<setw(18)<<t[i].Ed<<' '<<t[i].Em<<' '<<t[i].Ey<<setw(13)<<t[i].quantity<<setw(22)<<t[i].instock<<setw(5)<<i<<endl;
    }
}

void DeleteProduct(int index) {
    if (index<0||index>=pn) {
        cout << "erroare :(";
    }

    for (int i=index;i<pn-1;i++) {
        t[i]=t[i+1];
    }
    pn--;
    product* newT = new product[pn];

    for (int i=0;i<pn;i++) {
        newT[i]=t[i];
    }

    delete[] t;
    t = newT;
}

void ExportData(const char* filename) {
    ofstream file;
    file.open(filename);
    file<<pn<<endl;
    for (int i=0;i<pn;i++) {
        file<<t[i].name<<' '<<t[i].price<<' '<<t[i].Ey<<' '<<t[i].Em<<' '<<t[i].Ed<<' '<<t[i].quantity<<endl;
    }
    file.close();
}
void sort(int caz,int direction){
    switch(direction){
    case 0:{
    switch(caz){
        case 0:{
                for(int i=0;i<pn-1;i++){
                    for(int j=0;j<pn-i-1;j++){
                        if (strcmp(t[j].name,t[j+1].name)>0){
                            product temp = t[j];
                            t[j] = t[j+1];
                            t[j+1] = temp;
                        }
                    }
                }
        break;
        }
        case 1:{
                for(int i=0;i<pn-1;i++){
                    for(int j=0;j<pn-i-1;j++){
                        if (t[i].quantity>t[j].quantity){
                            product temp = t[j];
                            t[j] = t[j+1];
                            t[j+1] = temp;
                        }
                    }
                }
        break;
        }
        case 2:{
                for(int i=0;i<pn-1;i++){
                    for(int j=0;j<pn-i-1;j++){
                        if (t[i].price>t[j].price){
                            product temp = t[j];
                            t[j] = t[j+1];
                            t[j+1] = temp;
                        }
                    }
                }
        break;
        }
    }
    break;
    }
    case 1:{
    switch(caz){
        case 0:{
                for(int i=0;i<pn-1;i++){
                    for(int j=0;j<pn-i-1;j++){
                        if (strcmp(t[j].name,t[j+1].name)<0){
                            product temp = t[j];
                            t[j] = t[j+1];
                            t[j+1] = temp;
                        }
                    }
                }
        break;
        }
        case 1:{
                for(int i=0;i<pn-1;i++){
                    for(int j=0;j<pn-i-1;j++){
                        if (t[i].quantity<t[j].quantity){
                            product temp = t[j];
                            t[j] = t[j+1];
                            t[j+1] = temp;
                        }
                    }
                }
        break;
        }
        case 2:{
                for(int i=0;i<pn-1;i++){
                    for(int j=0;j<pn-i-1;j++){
                        if (t[i].price<t[j].price){
                            product temp = t[j];
                            t[j] = t[j+1];
                            t[j+1] = temp;
                        }
                    }
                }
        break;
        }
    }
    break;
    }
    }
}

void filter(double money,int x){

    system("cls");
    cout<<setw(20)<<"Name"<<setw(15)<<"Price"<<setw(26)<<"Data de expirare"<<setw(20)<<"Cantitatea"<<setw(15)<<"Stock"<<setw(5)<<"Id"<<endl;
    for(int i=0;i<102;i++)cout<<'_';
    cout<<endl;
    for(int i=0;i<pn;i++){
        if(x==0)if(t[i].price>=money)
        cout<<setw(20)<<t[i].name<<setw(15)<<t[i].price<<setw(18)<<t[i].Ed<<' '<<t[i].Em<<' '<<t[i].Ey<<setw(13)<<t[i].quantity<<setw(22)<<t[i].instock<<setw(5)<<i<<endl;
        if(x==1)if(t[i].price<=money)
        cout<<setw(20)<<t[i].name<<setw(15)<<t[i].price<<setw(18)<<t[i].Ed<<' '<<t[i].Em<<' '<<t[i].Ey<<setw(13)<<t[i].quantity<<setw(22)<<t[i].instock<<setw(5)<<i<<endl;
    }

}

void filter(int y){
    system("cls");
    cout<<setw(20)<<"Name"<<setw(15)<<"Price"<<setw(26)<<"Data de expirare"<<setw(20)<<"Cantitatea"<<setw(15)<<"Stock"<<setw(5)<<"Id"<<endl;
    for(int i=0;i<102;i++)cout<<'_';
    cout<<endl;
    for(int i=0;i<pn;i++){
        if(y==2)if(t[i].quantity>0)
        cout<<setw(20)<<t[i].name<<setw(15)<<t[i].price<<setw(18)<<t[i].Ed<<' '<<t[i].Em<<' '<<t[i].Ey<<setw(13)<<t[i].quantity<<setw(22)<<t[i].instock<<setw(5)<<i<<endl;
}
}

void find1(char nume[]){
    system("cls");
        cout<<setw(20)<<"Name"<<setw(15)<<"Price"<<setw(26)<<"Data de expirare"<<setw(20)<<"Cantitatea"<<setw(15)<<"Stock"<<setw(5)<<"Id"<<endl;
        for(int i=0;i<102;i++)cout<<'_';
        cout<<endl;
        for(int i=0;i<pn;i++){
            if(strcmp(nume,t[i].name)==0)
            cout<<setw(20)<<t[i].name<<setw(15)<<t[i].price<<setw(18)<<t[i].Ed<<' '<<t[i].Em<<' '<<t[i].Ey<<setw(13)<<t[i].quantity<<setw(22)<<t[i].instock<<setw(5)<<i<<endl;
    }
}

void find1(int year1){
    system("cls");
        cout<<setw(20)<<"Name"<<setw(15)<<"Price"<<setw(26)<<"Data de expirare"<<setw(20)<<"Cantitatea"<<setw(15)<<"Stock"<<setw(5)<<"Id"<<endl;
        for(int i=0;i<102;i++)cout<<'_';
        cout<<endl;
        for(int i=0;i<pn;i++){
            if(t[i].Ey==year1)
            cout<<setw(20)<<t[i].name<<setw(15)<<t[i].price<<setw(18)<<t[i].Ed<<' '<<t[i].Em<<' '<<t[i].Ey<<setw(13)<<t[i].quantity<<setw(22)<<t[i].instock<<setw(5)<<i<<endl;
    }
}
void expired(int day,int month){
system("cls");
        cout<<setw(62)<<setfill('-')<<"| Produse expirate |"<<setw(41)<<' '<<setfill(' ')<<endl;
        for(int i=0;i<102;i++)cout<<'_';
        cout<<endl;
        cout<<setw(20)<<"Name"<<setw(15)<<"Price"<<setw(26)<<"Data de expirare"<<setw(20)<<"Cantitatea"<<setw(15)<<"Stock"<<setw(5)<<"Id"<<endl;
        for(int i=0;i<102;i++)cout<<'_';
        cout<<endl;
        for(int i=0;i<pn;i++){
        if(t[i].Ey<year) cout<<setw(20)<<t[i].name<<setw(15)<<t[i].price<<setw(18)<<t[i].Ed<<' '<<t[i].Em<<' '<<t[i].Ey<<setw(13)<<t[i].quantity<<setw(22)<<t[i].instock<<setw(5)<<i<<endl;
        else if(t[i].Ey=year) if(t[i].Em<month) cout<<setw(20)<<t[i].name<<setw(15)<<t[i].price<<setw(18)<<t[i].Ed<<' '<<t[i].Em<<' '<<t[i].Ey<<setw(13)<<t[i].quantity<<setw(22)<<t[i].instock<<setw(5)<<i<<endl;
        else if(t[i].Em=month) if(t[i].Ed<=day)
        cout<<setw(20)<<t[i].name<<setw(15)<<t[i].price<<setw(18)<<t[i].Ed<<' '<<t[i].Em<<' '<<t[i].Ey<<setw(13)<<t[i].quantity<<setw(22)<<t[i].instock<<setw(5)<<i<<endl;
    }
}
void color(){
    char m7[4]={'<',' ',' '};
    cout<<"| Color change |\n";
    char v7; int i7=0,n7=0;
        while(true){
            system("cls");
            cout<<"Blue "<<m7[0]<<endl;
            cout<<"Yellow "<<m7[1]<<endl;
            cout<<"Red "<<m7[2]<<endl;
            v7=getch();
            if(v7==32){
                if(i7==2){ swap(m7[2],m7[0]); i7=0;}
                else{ swap(m7[i7],m7[i7+1]); i7++;}
            }
            else {n7=i7; break;}
        }
    switch(n7){
    case 0: system("color 1"); break;
    case 1: system("color 6"); break;
    case 2: system("color 4"); break;
    }
}
#endif // TEV_H_INCLUDED
