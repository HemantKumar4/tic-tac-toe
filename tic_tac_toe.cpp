#include <iostream>
#include <time.h>

using namespace std;

void print(string array[])
{
    int j = 0;
    int a = 3;
    int b = 2;
    for (int i = 0 ; i<3 ; i++){
        cout<<" ";
        for (j ; j<a ; j++){
            cout << array[j];
            if (j<b){
                cout<<" | ";
            }
        }
        if (i<2){cout<<endl<<"---+---+---"<<endl;}
        a += 3;
        b += 3;
    }
}

void comp_chance_1(string array[]){

    srand(time(0)); 
    int a =  rand()%10; 

    if(array[4] == " "){array[4] = "X";return;}

    if(a==1 or a==2 or a==3){array[0] = "X";return;}
    else if(a==0 or a==4 or a==5){array[2] = "X";return;} 
    else if(a==6 or a==7 or a==8){array[6] = "X";return;} 
    else{array[8] = "X";return;}    
}

int D = 2;
void defence(string array[])
{
    for (int i = 0 ; i<9 ; i+=3){
        for(int j = 0 ; j<2 ; j++){
            if (array[i+j] == array[i+j+1] && array[i+j] == "0"){D=i+j;}
        }
    }

    for(int n=0;n<3;n++){
        for(int o=0; o<4;o+=3){
            if (array[n+o] == array[n+o+3] && array[n+o] == "0"){D=n+o+8;}
        }
    }

    for(int k=0 ; k<5 ; k+=4){
        if (array[k] == array[k+4] && array[k] == "0"){D=k+16;}
        if (array[k+2] == array[4] && array[k+2] == "0"){D=k+21;}
    }
    //special cases
    if (array[0] == array[2] && array[0] == "0"){D=26;}
    if (array[6] == array[8] && array[6] == "0"){D=27;}
    if (array[0] == array[6] && array[0] == "0"){D=28;}
    if (array[2] == array[8] && array[2] == "0"){D=29;}
}

void comp_chance_2(string array[]){

    defence(array);
    if(D!=2){
        if(D==0){array[2] = "X";}    
        else if(D==1){array[0] = "X";}
        else if(D==3){if(array[5]=="X"){array[8]="X";}else{array[5] = "X";}}
        else if(D==4){if(array[3]=="X"){array[0]="X";}else{array[3] = "X";}}
        else if(D==6){array[8] = "X";}
        else if(D==7){array[6] = "X";}
        else if(D==8){array[6] = "X";}
        else if(D==9){if(array[7]=="X"){array[8]="X";}else{array[7] = "X";}}
        else if(D==10){array[8] = "X";}
        else if(D==11){array[0] = "X";}
        else if(D==12){if(array[1]=="X"){array[0]="X";}else{array[1] = "X";}}
        else if(D==13){array[2] = "X";}
        else if(D==16){if(array[8]=="X"){array[6]="X";}else{array[8] = "X";}}
        else if(D==20){if(array[0]=="X"){array[3]="X";}else{array[0] = "X";}}
        else if(D==21){if(array[6]=="X"){array[8]="X";}else{array[6] = "X";}}
        else if(D==25){if(array[2]=="X"){array[3]="X";}else{array[2] = "X";}}
        else if(D==26){array[1] = "X";}
        else if(D==27){array[7] = "X";}
        else if(D==28){array[3] = "X";}
        else if(D==29){array[5] = "X";}
    }
    else{        
        srand(time(0)); 
        int a =  rand()%10; 

        if(a==0 or a==8 or a==4){a=5;}
        for(int i=0; i<9 ; i++){
            if(a==i){
                if(array[i]==" "){
                    array[i]="X";
                }else{
                    a+=1;
                }
            }
        }      
    }
}

void comp_chance_3_4(string array[]){

    int temparr[4];
    int count = 0;

    for(int j=0 ; j<9 ; j++){
        if(array[j]==" "){
            temparr[count] = j;
            count++;
        }
    }

    srand(time(0)); 
    int a =  rand()%10;

    if(count==4){
        if(a==1 || a==4){array[temparr[0]] = "X";}
        if(a==2 || a==5 || a==0){array[temparr[1]] = "X";}
        if(a==3 || a==6){array[temparr[2]] = "X";}
        if(a==7 || a==8 || a==9){array[temparr[3]] = "X";}
    }else{
        if(a%2==0){array[temparr[0]] = "X";}
        else{array[temparr[1]] = "X";}
    }
}

bool check(string array[],string z)
{
    int x = 0;
    for (int i = 0 ; i<9 ; i+=3){
        if (array[i] == array[i+1] && array[i] == array[i+2] && array[i] == z){x+=1;}
    }
    for (int i = 0; i < 3; i++){
        if (array[i] == array[i+3] && array[i] == array[i+6] && array[i] == z){x+=1;}
    }

    if (array[0] == array[4] && array[0] == array[8] && array[0] == z){x+=1;}
    if (array[2] == array[4] && array[2] == array[6] && array[2] == z){x+=1;}

    return x > 0;
}

int main()
{
    string arr[9] = {" "," "," "," "," "," "," "," "," "};

    print(arr);
    cout<<endl<<"you are playing against computer"<<endl<<endl;

    for(int m=1 ; m<=5 ; m++){

        cout<<endl<<"select boxes marked from 1 to 9 :";
        int a;
        cin>>a;
        arr[a-1] = "0";
        print(arr);
        cout<<endl<<endl;

        if(check(arr,"0")){
            cout<<"0 won ";
            return -1;
        }

        if(m==1){
            comp_chance_1(arr);
        }
        else if(m==2){
            comp_chance_2(arr);
        }else if(m==3 || m==4){
            comp_chance_3_4(arr);
        }

        system("cls");

        print(arr);
        cout<<endl<<endl;

        
        if(check(arr,"X")){
            cout<<"X won ";
            return -1;
        }
        if(m==5 and !check(arr,"X") and !check(arr,"0")){
            cout<<"tie!";
            return -1;
        }
    }
}