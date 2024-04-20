#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "tev.h"

using namespace std;

int main()
{
    /*
    Return info:
    0 totul e bine :)
    1 inchis de utilizator :0
    3 erroare :(
    */

    //menu :)
    char m[9]={'<',' ', ' ', ' ', ' ', ' ', ' ',' '},v,fname[20];
    int i=0, n=0,d;
    while(true){
    i=0;
    swap(m[n],m[0]);
    while(true){
    system("cls");
    cout<<"Afiseaza date "<<m[0]<<endl; //0
    cout<<"Import data "<<m[1]<<endl;   //1
    cout<<"Delete data "<<m[2]<<endl;   //2
    cout<<"Sort data "<<m[3]<<endl;     //3
    cout<<"Find "<<m[4]<<endl;          //4
    cout<<"Filter data "<<m[5]<<endl;   //5
    cout<<"Export Data "<<m[6]<<endl;   //6
    cout<<"Text Color "<<m[7]<<endl;    //7
    cout<<"Exit "<<m[8]<<endl;          //8
    v=getch();
    if(v==32){
        if(i==8){ swap(m[8],m[0]); i=0;}
        else{ swap(m[i],m[i+1]);i++;}
    }
    else {n=i; break;}
    }
    // cout<<n;
    system("cls");
    switch(n){
        case 0:{
        ShowData();
        getch();
        break;
        }
        case 1:{
            cout<<"| Import data |\n(filename.extension)\n";
            cin>>fname;
            ImportData(fname);
        break;
        }
        case 2:{
            cout<<"| Delete data |\n(Product id)\n";
            cin>>d;
            DeleteProduct(d);
        break;        }
        case 3:{
        //submenu
        char m3[4]={'<',' ',' '};
        cout<<"| Sort data |\n(type)\n";
                char v3; int i3=0,n3=0,dir=2;
            while(true){
                system("cls");
                cout<<"Nume "<<m3[0]<<endl;
                cout<<"Cantitate "<<m3[1]<<endl;
                cout<<"Price "<<m3[2]<<endl;
                v3=getch();
                if(v3==32){
                    if(i3==2){ swap(m3[2],m3[0]); i3=0;}
                    else{ swap(m3[i3],m3[i3+1]); i3++;}
                }
                else {n3=i3; break;}
            }
            cout<<"| Crescator 1 |\n| Descrescator 0 |\n";
            cin>>dir;
            sort(n3,dir);
        break;
        }
        case 4:{
        //submenu
        char m4[4]={'<',' ',' '};
        cout<<"| Sort data |\n(type)\n";
                char v4; int i4=0,n4=0,dir=2;
            while(true){
                system("cls");
                cout<<"Nume "<<m4[0]<<endl;
                cout<<"An "<<m4[1]<<endl;
                cout<<"Expirat "<<m4[2]<<endl;
                v4=getch();
                if(v4==32){
                    if(i4==2){ swap(m4[2],m4[0]); i4=0;}
                    else{ swap(m4[i4],m4[i4+1]); i4++;}
                }
                else {n4=i4; break;}
            }
        switch(n4){
            case 0:{
            char nume[20];
            system("cls");
            cout<<"| Find by name |\n";
            cin>>nume;
            find1(nume);
            getch();
            break;
            }
            case 1:{
            int year1;
            system("cls");
            cout<<"| Find by year |\n";
            cin>>year1;
            find1(year1);
            getch();
            break;
            }
            case 2:{
                int day,month;
            system("cls");
            cout<<"| Find Expired |\n(day month):";
            cin>>day>>month;
            expired(day,month);
            getch();
            break;
            }
        }

        break;
        }
        case 5:{
        //submenu
        char m5[4]={'<',' ',' '};
        cout<<"| Filter data |\n(type)\n";
                char v5; int i5=0,n5=0,dir=2; double money;
            while(true){
                system("cls");
                cout<<">Price "<<m5[0]<<endl;
                cout<<"<Price "<<m5[1]<<endl;
                cout<<"Stock "<<m5[2]<<endl;
                v5=getch();
                if(v5==32){
                    if(i5==2){ swap(m5[2],m5[0]); i5=0;}
                    else{ swap(m5[i5],m5[i5+1]); i5++;}
                }
                else {n5=i5; break;}
            }
            if(n5!=2){
                cout<<"Price:"; cin>>money; filter(money,n5);
            }
            else filter(n5);
            getch();
        break;
        }
        case 6:{
            cout<<"| Export data |\n(filename.extension)\n";
            cin>>fname;
            ExportData(fname);
        break;
        }
        case 7:{
        color();
        break;
        }
        case 8:{
            delete[] t;
        return 1;
        }
        default: {cout<<"erroare :(";delete[] t; return 3;}    }
    }

    return 0;
}
