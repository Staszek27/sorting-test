#include <iostream>
#include <algorithm>
#include <sys/time.h>
using namespace std;

const int S = 1e6 + 7;
int n, tab[S], result; // zmienne globalne z ktorych korzystamy (tab[0] .. tab[n-1])
int tab_buf[S]; 

void bubble_sort(){
    // sortowanie bąbelkowe 
    
    // TOOD
}

void selection_sort(){
    // sortowanie przez wybor 

    // TODO
}

void insertion_sort(){
    // sortowanie przez wstawianie 

    // TODO
}

void quick_sort(int poc = 0, int kon = n - 1){
    // sortowanie szybkie 
    
    // TODO
}

void hoere_iter(int k){
    // algorytm hoera'a iteracyjnie. Znajdz k-ty najmniejszy element w tab_buf
    // WSADZAMY WYNIK DO ZMIENNEJ GLOBALNEJ RESULT!
    
    // TODO
}

void hoere_rec(int k){
    // algorytm hoera'a rekurencyjnie. Znajdz k-ty najmniejszy element w tab_buf
    // WSADZAMY WYNIK DO ZMIENNEJ GLOBALNEJ RESULT!
    // W WERSJI REKURENCYJNEJ NALEZY UZYC FUNKCJI POMOCNICZEJ (KTORA JEST REKURENCYJNA)!

    // TODO
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

bool check(bool its_hoere, int k){
    sort(tab_buf, tab_buf + n);
    if (!its_hoere){
        for (int i = 0; i < n; i ++){
            if (tab_buf[i] != tab[i]){
                return false;
            }
        }
        return true;
    } else {
        return tab_buf[k - 1] == result;
    }
}

long long current_ms(){
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long long ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;

    return ms;
}


int main(int argc, char* argv[]){
    srand(time(NULL));
    string s;
    if (argc != 3){
        n = 10;
        s = "selection_sort";
        // TESTING MODE HERE
    } else {
        n = atoi(argv[1]);
        s = argv[2];
    }

    gen_tab();
    
    int k = rnd(1, n); 
    long long time_start = current_ms();
    if (s == "bubble_sort"){
        bubble_sort();
    } else if (s == "insertion_sort"){
        insertion_sort();
    } else if (s == "quick_sort"){
        quick_sort();
    } else if (s == "selection_sort"){
        selection_sort();
    } else if (s == "hoere_iter"){
        hoere_iter(k);
    } else if (s == "hoere_rec"){
        hoere_rec(k);
    } else {
        return 1; 
    }

    long long t =  current_ms() - time_start;
    cout << (check(s == "hoere_iter" || s == "hoere_rec", k) ? "OK\n" : "WA\n");
    cout << t << endl;    

    return 0;
}