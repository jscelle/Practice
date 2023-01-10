#include <iostream>
#include <numeric>


typedef int MyArr[5];

void f (MyArr a)                                    //Функция получает массив
 {                                                  //и обнуляет 5 член массива
  a[4] = 0;
 }

int prod (int* begin, int* end)                     //Функция получает начало и
 {                                                  //конец массива и вычисляет
  int r = std::accumulate(begin, end, 1, std::multiplies<int>());
  return r;                                         //произведение всех его членов
 }


int main()
 {
  MyArr a = {1 , 2 , 3 , 4 , 5};            //Инициализация и заполнение массива
  int *begin = std::begin(a);               //Инициализация указателя на начало массива
  int *end = std::end(a);                   //Инициализация указателя на конец массива

  std :: cout << " Prod1 : " << prod(begin, end) << '\n'; //Произведение массива до обнуления 5 члена
  f(a);                                             //Обнуление 5 члена массива
  std :: cout << " Prod2 : " << prod(begin, end) << '\n';  //Произведение массива после обнуления 5 члена
  
  return 0;
 }
