#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char title[50];
    int year;
} Movie;

typedef struct {
    Movie movies[MAX];
    int count;
} Watchlist;

void insertMovieSorted(Watchlist *w, char title[], int year) {
    // Your code here
    if(w->count >= MAX) {
        printf("Maximum capacity reached\n");
        return;
    }

    int idx = 0;
    while(idx < w->count && w->movies[idx].year <= year) idx++;

    for(int i = w->count; i > idx; w->movies[i] = w->movies[i - 1], i--) {}

    strcpy(w->movies[idx].title, title);
    w->movies[idx].year = year;
    w->count++;
}

void printMovies(Watchlist w) {
    // Your code here
    if(w.count == 0) {
        printf("No movies in your list\n");
        return;
    }

    printf("Watchlist:\n");
    for(int i = 0; i < w.count; i++) printf("%s (%d)\n", w.movies[i].title, w.movies[i].year);
    printf("\n");
}

int main() {
    Watchlist w = {.count = 0};

    insertMovieSorted(&w, "Dune", 2021);
    insertMovieSorted(&w, "Inception", 2010);
    insertMovieSorted(&w, "Interstellar", 2014);

    printMovies(w);

    return 0;
}