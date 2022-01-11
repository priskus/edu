//  поиск позиции элемента в массиве
//есть стандартная ф-ция std::binary_search
#include <iostream>

int main() {

    int m[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};     
    int num;
    std::cout << "enter the number:";
    std::cin >> num;
    int size = sizeof(m)/sizeof(int);  
    int med = size/2;   //медиана
    int left = 0, right = size - 1;

    do {
        med = (right+left)/2;
        if(m[med]==num)
            break;
        if(left>right) {
            med = -1;
            break;
        }
        else if(m[med]<num) 
            left = med+1;

        else if(m[med]>num) 
            right = med-1;
    } while (1);
    std::cout << "med " <<med;
}