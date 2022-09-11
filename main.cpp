//
//  main.cpp
//  C++ ДЗ №20
//
//  Created by Павел on 09.09.2022.
//
#include <iostream>
#include <time.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

//создаем массив
int array_start ( int arr[], const int size, int from , int to) {
    srand(time(0));

  for (int i = 0; i < size; ++i)
    arr[i] = rand () % (to+1-from)+from;
    return arr[size];
    }
// выводим массив
void show_arr (int arr[], int size){
    cout<<"[";
    for (int i=0; i<size;i++)
        cout << arr[i]<<" ";
    cout<<"]\n";
}

//индекс первого вхождения элемента  в массив
template <typename T>
int search_index(T arr[], int length, T value, int begin=0){
    for(int i=begin; i < length; i++)
        if(arr[i] == value)
            return i;
    return -1;// элемент не обнаружен
}

//индекс последнего вхождения элемента  в массив
template <typename T>
int search_Last_Index(T arr[],const int length, T value, int begin=0){
    
    for(int i=begin; i >=0; i--)
        if(arr[i] == value)
            return i;
    return -1;
}

   //Максимальный элемент массива
int maxElement(int arr[], const int  length){
    int max=arr[0];
    for(int i=0;i<length;i++ ){
        if(max < arr[i+1])
            max = arr[i+1];
    }
    return max;
}
    
//Минимальный элемент массива
int minElement(int arr[], const int  length){
 int min=arr[0];
 for(int i=0;i<length;i++ ){
     if(min > arr[i+1])
         min = arr[i+1];
 }
    return min;
}

//Среднее арифметическое
int meanValue (int arr[], const int  length){
    int sum=0;
    int MV=0;
 for(int i=0;i<length;i++ ){
    sum=arr[i]+sum;
 }
    
    return MV=sum/length;
}

//Элементы, входящие в диапазон
void range (int arr[], const int  length, int from, int to){
    int to1=0;
    if(from>to){
        to1=to;
        to=from;
        from=to1;
             }
    cout<<"Элементы, входящие в этот диапазон: ";
    for(int i=0; i<length; i++)
        if(arr[i]>from and arr[i]<to)
           cout<<arr[i]<<", ";
            
    }
 
//Количество вхождений элемента  в массив
int counter(int arr[],const int length,int c){
    int count=0;
    cout<<"Количество вхождений этого числа в массив: ";
    for(int i=0; i < length; i++)
        if(arr[i] == c){
      count++;
        }
return count;
}

int main(int argc, const char * argv[]) {
    int n;
    
    //Создаем  и выводим массив
    const int size = 100;
    int arr[size];
    array_start (arr, size, -100, 100);
    show_arr(arr, size);
   
    //поиск первого вхождения
    cout<<"Введите число : ";
    cin>>n;
   if(search_index(arr, size, n, 0 )==-1)
        cout <<"Такого числа нет  в массиве\n\n";
    else
        cout<<"Позиция числа в массиве (первое вхождение): ";
    cout<< search_index (arr, size,n, 0)<<"\n";
    
    // поиск последнего вхождения
   if(search_Last_Index(arr, size, n, 100 )==-1)
        cout <<"Такого числа нет  в массиве\n\n";
   else
        cout<<"Позиция числа в массиве(последнее вхождение): ";
   cout<<search_Last_Index (arr, size,n, 100 )<<"\n";
    
   //Максимальный элемент массива
    cout<<"Максимальный элемент массива: ";
    cout<<maxElement(arr,size);
    cout<<endl;
    
    //Минимальный элемент массива
    cout<<"Минимальный элемент массива: ";
    cout<<minElement(arr,size);
    cout<<endl;
    
    //Среднее арифметическое
    cout<<"Среднее арифметическое  массива: ";
    cout<<meanValue(arr,size);
    cout<<endl;
    
    //Элементы входящие  в диапазон
    cout<<"\nВедите диапазон из двух чисел: ";
    int a,b;
    cin>>a>>b;
    range(arr,size, a, b);
    cout<<endl;
    
    //Количество вхождений элемента  в массив
    cout<<"\nВедите  число: ";
    int c=0;
    cin>>c;
    cout<<counter(arr,size,c);
    cout<<"\n\n";
    
    return 0;
}
