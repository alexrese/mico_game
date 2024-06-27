#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int memoria[4][4] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    string mico[4][4] = {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"};
    int i = 0, num = 1;
    while(i < 16){
        int l = rand()%4;
        int c = rand()%4;
        if(memoria[l][c] == 0){
           memoria[l][c] = num;
           i++;
           num =i/2+1;
        }
    }

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<<memoria[i][j]<<"\t";
        }
        cout<<endl;
    }

    Sleep(3000);
    system("clear||cls");

    int escolha;
    cout<<"Escolha uma opção:"<<endl;
    cout<<"1-manual"<<endl;
    cout<<"2-automatico"<<endl;
    cin>> escolha;

    if(escolha == 2){
        int acertos = 0;
        int lin1, col1, lin2, col2;
        while(acertos < 8){
            cout<<"Digite duas posições validas de 0-3 para revelar"<<endl;
            do{
                cout<<"Digite a linha 1: ";
                lin1=rand()%4;
                cout<<lin1<<endl;
                //Sleep(1000);
                cout<<"Digite a coluna 1: ";
                col1=rand()%4;
                cout<<col1<<endl;
                //Sleep(1000);
            }while(mico[lin1][col1] != "#");
            mico[lin1][col1] = to_string(memoria[lin1][col1]);


            for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    cout<<mico[i][j]<<"\t";
                }
                cout<<endl;
            }
            do{
                cout<<"Digite uma posição diferente de # "<<endl;
                cout<<"Digite a linha 2: ";
                lin2=rand()%4;
                cout<<lin2<<endl;
                //Sleep(1000);
                cout<<"Digite a coluna 2: ";
                col2=rand()%4;
                cout<<col2<<endl;
                //Sleep(1000);
            }while (mico[lin2][col2] != "#");
            mico[lin2][col2] = to_string(memoria[lin2][col2]);

            for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    cout<<mico[i][j]<<"\t";
                }
                cout<<endl;
            }
            //Sleep(1000);
            system("clear||cls");

            if(memoria[lin1][col1] != memoria[lin2][col2]){
                mico[lin1][col1] = "#";
                mico[lin2][col2] = "#";
            }else{
                acertos++;
            }

            for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    cout<<mico[i][j]<<"\t";
                }
                cout<<endl;
            }
        }
    }else{
        if(escolha == 1){
            int acertos = 0;
            int lin1, col1, lin2, col2;
            while(acertos < 8){
                cout<<"Digite duas posições validas de 0-3 para revelar"<<endl;
                do{
                    cout<<"Digite a linha 1: ";
                    cin>>lin1;
                    cout<<"Digite a coluna 1: ";
                    cin>>col1;
                }while(mico[lin1][col1] != "#");
                mico[lin1][col1] = to_string(memoria[lin1][col1]);


                for(int i=0; i<4; i++){
                    for(int j=0; j<4; j++){
                        cout<<mico[i][j]<<"\t";
                    }
                    cout<<endl;
                }
                do{
                    cout<<"Digite uma posição diferente de # "<<endl;
                    cout<<"Digite a linha 2: ";
                    cin>>lin2;
                    cout<<"Digite a coluna 2: ";
                    cin>>col2;
                }while (mico[lin2][col2] != "#");
                mico[lin2][col2] = to_string(memoria[lin2][col2]);

                for(int i=0; i<4; i++){
                    for(int j=0; j<4; j++){
                        cout<<mico[i][j]<<"\t";
                    }
                    cout<<endl;
                }
                Sleep(1000);
                system("clear||cls");

                if(memoria[lin1][col1] != memoria[lin2][col2]){
                    mico[lin1][col1] = "#";
                    mico[lin2][col2] = "#";
                }else{
                    acertos++;
                }

                for(int i=0; i<4; i++){
                    for(int j=0; j<4; j++){
                        cout<<mico[i][j]<<"\t";
                    }
                    cout<<endl;
                }
            }
        }
    }

    return 0;
}
