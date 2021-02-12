// to jest templatka dla uczniow
// czasami uczniowie beda zmuszeni zakomentowac pare rzeczy (np. biblioteke sys/time.h)

#include <iostream>
#include <algorithm>
#include <sys/time.h>
using namespace std;

const int S = 1e6 + 7;
int n, tab[S]; // zmienne globalne z ktorych korzystamy (tab[0] .. tab[n-1])
int tab_buf[S]; 

void bubble_sort(){
    // sortowanie bąbelkowe TOOD
   
}

void selection_sort(){
    // sortowanie przez wybor TODO

}

void insertion_sort(){
    // sortowanie przez wstawianie TODO

}

void quick_sort(int poc = 0, int kon = n - 1){
    // sortowanie szybkie * TODO

}

int rnd(int poc, int kon){
    return poc + rand() % (kon - poc + 1);
}

void gen_tab(){
    for (int i = 0; i < n; i ++){
        tab[i] = rnd(1, n);
        tab_buf[i] = tab[i];
    }
}

bool check(){
    sort(tab_buf, tab_buf + n);
    for (int i = 0; i < n; i ++){
        if (tab_buf[i] != tab[i]){
            return false;
        }
    }
    return true;
}

long long current_ms(){
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long long ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    return ms;
}


int main(int argc, char* argv[]){
    string s;
    if (argc != 3){
        n = 10;
        s = "selection_sort";
        // wypelniamy tutaj co chcemy testowac
    } else {
        n = atoi(argv[1]);
        s = argv[2];
    }

    gen_tab();
    
    long long time_start = current_ms();
    if (s == "bubble_sort"){
        bubble_sort();
    } else if (s == "insertion_sort"){
        insertion_sort();
    } else if (s == "quick_sort"){
        quick_sort();
    } else if (s == "selection_sort"){
        selection_sort();
    } else {
        return 1; 
    }

    cout << (check() ? "OK\n" : "WA\n");
    cout << current_ms() - time_start << endl;

    return 0;
}