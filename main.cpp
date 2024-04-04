#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

void masV(int *n, int i){
    for(int g = 0; g < i; g++){
        cout << n[g] << " ";
    }
}
void masZ(int *n, int i){
    for(int g = 0; g < i; g++){
        n[g] = rand() % 201 - 100;
    }
}
void multiplicate2(int *n, int i){
    int h;
    cout << endl << "Введите число на, которое будет умножен массив: " << endl;
    cin >> h;
    for(int g = 0; g < i; g++){
        n[g] = n[g] * h;
        cout << n[g] << " ";
    }
}

int reverse1(int *n, int i){
    for(int g = 1; g < i; g += 2){
        n[g] = n[g] * -1;

    }
}

int comparison3(int *n1, int *n2, int i1, int i2){
    int maxL1 = -101, maxL2 = -101, a;
    for(int g = 0; g < i1; g++){
        if (abs(n1[g]) > maxL1){
            maxL1 = abs(n1[g]);
        }
    }
    for(int g = 0; g < i2; g++){
        if (abs(n2[g]) > maxL2){
            maxL2 = abs(n2[g]);
        }
    }
    if(maxL1 > maxL2){
        a = 1;
    } else{
        a = 2;
    }
    return a;
}

int main(){
    ofstream fout;
    fout.open("/Users/admin/pr2/result.txt");
    fout << "Пчелинцев В.И. БББО-08-23 Вариант 13 " << endl;
    int i1, i2, a;
    cout << "Введите количество элементов первого масива: " << endl;
    cin >> i1;
    cout << "Введите количество элементов второго масива: " << endl;
    cin >> i2;
    srand(time(nullptr));
    int *n1 = new int[i1];
    int *n2 = new int[i2];
    masZ(n1,i1);
    masZ(n2,i2);

    if(!fout.is_open()){
        cout << "Ошибка";
    }
    else{
        masV(n1, i1);
        fout << "Первый массив: ";
        for(int g = 0; g < i1; g++){
            fout << n1[g] << " ";
        }
        fout << endl;
        fout << "Второй массив: ";
        for(int g = 0; g < i2; g++){
            fout << n2[g] << " ";
        }

        reverse1(n1,i1);
        fout << endl << "Массив с противоположными знаками: ";
        for(int g = 0; g < i1; g++){
            fout << n1[g] << " ";
        }
        multiplicate2(n2,i2);
        fout << endl << "Массив умноженный на число: ";
        for(int g = 0; g < i2; g++){
            fout << n2[g] << " ";
        }

        comparison3(n1, n2, i1, i2);
        a = comparison3(n1, n2, i1, i2);
        if(a == 1){
            fout << endl << "Максимальный элемент первого массива больше" << endl;
        } else{
            fout << endl << "Максимальный элемент второго массива больше" << endl;
        }


        delete [] n1;
        delete [] n2;
        return 0;
    }
}
