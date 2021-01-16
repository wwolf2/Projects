/*
 * Main.cpp
 * Implementation of Main class
 * Author: Billy Wolf
 * Created: April 15, 2019
 * Current: April 17, 2019
 *
 * Compile with:
 * g++ -c main.cpp
 * g++ -o prog.exe main.o
 * ./prog.exe
 * 
 * Compares the runtimes of a variety of sorting algorithms
 * when starting with n amount of numbers in ascending, descending,
 * or a random order. The sorting algorithms include Bubble, Selection,
 * Double-ended Selection, Exchange, and Insertion
 */
#include <iostream>
#include <time.h>
#include "Time.cpp"
using namespace std;
template <class T>
void BubbleSort(T[], int); //Bubble Sort
template <class T>
void SelectionSort(T[], int); //Selection Sort
template <class T>
void DoubleEndSelection(T[], int); //Double Ended Selection Sort
template <class T>
void ExchangeSort(T[], int); //Exchange Sort
template <class T>
void InsertionSort(T[], int); //Insertion Sort
template <class T>
void Swap(T &a, T &b); //Swaps two elements
template <class T>
void Display(T[], int); //Displays the array

int main(){
    
    enum Types { Random, Ascending, Descending}; //holds the 3 types of array
    
    string type, start;
    int n= 16;
    int arr[n];
    clock_t t;
    
    cout << "Which Type of Sort ( Random, Ascending, Descending) " << endl;
    cin >> start;
    
    if (start == "Ascending" || start == "ascending") { //creates the Ascending Array
     
     for (int i = 0; i < n; i ++){
      arr[i] = i; 
     }
     "Ascending array ";
     Display(arr, n);
     }else if (start == "Descending" || start == "descending"){ //creates the Descending Array
         for (int i = n; i >=0; i --){
            arr[i] = n-(i+1);
         }
         "Descending array ";
         Display(arr, n);
    }else if (start == "Random" || start == "random"){ //creates the Random Array
        arr[0] = 0; arr[1] = 15; arr[2] = 1; arr[3] = 14; arr[4] = 2; arr[5] = 13;
        arr[6] = 3; arr[7] = 12; arr[8] = 4; arr[9] = 11; arr[10] = 5; arr[11] = 10;
        arr[12] = 6; arr[13] = 9; arr[14] = 7; arr[15] = 8;
        
        "Random array ";
         Display(arr, n);
    }else
        cout << "Invalid input" <<endl;
    
     
    
    cout << "Which sorting Algorithm (Bubble, Select, DESelect, Exchange, Insert) " << endl;
    cin >> type;
    t = clock();
    if (type == "Bubble" || type == "bubble"){ //Runs the Bubble Sort
    cout << "Bubble Sort" << endl;
    BubbleSort(arr, n);
    cout << "Sorted Algorithm ";
    Display(arr, n);
    cout << endl;
    }else if (type == "Select" || type == "select"){ //Runs the Selection Sort
    cout << "Selection Sort" << endl;
    SelectionSort(arr, n);
    cout << "Sorted Algorithm ";
    Display(arr, n);
    cout << endl;
    }else if (type == "DESelect" || type == "DESelect"){ //Runs the Double Ended Selection Sort
    cout << "Double Ended Sort" << endl;
    DoubleEndSelection(arr, n);
    cout << "Sorted Algorithm ";
    Display(arr, n);
    cout << endl;
    
    }else if (type == "Exchange" || type == "exchange"){ //Runs the Exchange Sort
    cout << "Exchange Sort" << endl;
    ExchangeSort(arr, n);
    cout << "Sorted Algorithm ";
    Display(arr, n);
    cout << endl;
    
    }else if (type == "Insert" || type == "insert"){ // Runs the Insertion Sort
    cout << "Insertion Sort" << endl;
    InsertionSort(arr, n);
    cout << "Sorted Algorithm ";
    Display(arr, n);
    cout << endl;
    }else 
        cout << "Invalid Input" << endl;
    

    DisplayTime(t); //Displays the execution time
 return 0;
 
}
template <class T>
void BubbleSort(T arr[], int n){ //Implementation of the Bubble Sort
    bool end;
    int count;
    int num = 0;
    
    do{
        end = false;
      
    for (count = 0; count < n-1 ; count ++) {
        if (arr[count] > arr[count +1]){
         swap(arr[count], arr[count +1]);
        end = true;
        }
}
    cout << "Pass " << num << " ";
    Display(arr, n);
    num++;
    }while (end == true);

}
template <class T>
void SelectionSort(T arr[], int n){ //Implementation of the Selection Sort
    
    int smallIndex;
    
    int count, j;
    int temp;
    
    for(count =0; count < n-1; count ++){
     smallIndex = count;
     
     for (j = count+1; j < n; j++){
      
         if (arr[j] < arr[smallIndex]){
             smallIndex = j;

         }if(smallIndex != count){
             
          temp = arr[count];
          arr[count] = arr[smallIndex];
          arr[smallIndex] = temp;
             
         }
        
     }
    cout << "Pass " << count << " ";
    Display(arr, n);
    }
}
template <class T>
void DoubleEndSelection(T arr[], int n){ //Implementation of the Double Ended Selection Sort
    
    int smallIndex;
    int largeIndex;
    
    int count, j;
    int temp;
   
    for(count =0; count < n-1; count ++){
     smallIndex = count;
     largeIndex = count;
     
     for (j = count+1; j < n-count; j++){
      
         if (arr[j] < arr[smallIndex]){
             smallIndex = j;
         }
        if (arr[j] > arr[largeIndex]){
             largeIndex = j;
     }
       
    }
     if(smallIndex != largeIndex){
             
          temp = arr[count];
          arr[count] = arr[smallIndex];
          arr[smallIndex] = temp;
          
          temp = arr[n-(count+1)];
          arr[n-(count+1)] = arr[largeIndex];
          arr[largeIndex] = temp;
             
             
         }
  cout << "Pass " << count << " ";
  Display(arr, n);
}
}
template <class T>
void ExchangeSort(T arr[], int n){ //Implementation of the Exchange Sort
    int count, i;
    
    for (count = 0; count < n-1; count ++){
     
        for (i = count+1; i < n; i++){
             if(arr[i] < arr[count]){
            swap(arr[count], arr[i]);
            }
        }
        cout << "Pass " << count << " ";
        Display(arr, n);
        
    }
    
}
template <class T>
void InsertionSort(T arr[], int n){ //Implementation of the Insertion Sort
    int count, i, key;
    
    for (count = 1; count < n; count ++){
     key = arr[count];
     i = count -1;
        while (i >= 0 && arr[i] > key){
        arr[i+1] = arr[i];
        i = i-1;
    
        }
        arr[i+1] = key;
        cout << "Pass " << count << ": ";
       Display(arr, n);
    }
    
}
template <class T>
void Swap(T &a, T &b){ //Swap Function
 
    int temp = a;
    a = b;
    b = temp;
    
    
}
template <class T>
void Display( T arr[], int n){ //Displays the Array
    
 for (int i = 0; i < n; i ++){
  cout << arr[i] <<  " ";   
 }
    cout << endl;
}
