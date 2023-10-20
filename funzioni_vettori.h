#ifndef FUNZIONI_VETTORI_H_INCLUDED
#define FUNZIONI_VETTORI_H_INCLUDED


#endif // FUNZIONI_VETTORI_H_INCLUDED

//stampa il contenuto di un vettore
void stampaVet(int v[], int n) {
    for(int k = 0; k < n; k++) {
        printf("%d ", v[k]);
    }
}

void inizializzaVetRand(int v[], int n, int lim_min, int lim_max) {
    for(int k = 0; k < n; k++) {
        v[k] = lim_min + rand() % (lim_max + 1 - lim_min);
    }
}

//chiede gli elementi di un vettore
void caricaVet(int v[], int n) {
    for(int k = 0; k < n; k++) {
        printf("inserisci l'elemento [%d]: ", k);
        scanf("%d", &v[k]);
    }
}
//void con il ciclo for classico

//void inizializzaVet(int v[], int n) {
//    for(int k = 0; k < n; k++) {

//    }
//}

int chiediDim(int dimMax) {
    int x;
    do {
        printf("inserisci la dimensione compresa tra [0] e [%d]", dimMax);
        scanf("%d", &x);
    } while (x < 0 || x > dimMax);
    return x;
}

int NonOrdDisg(int v[],int n, int x) {
    int tro,k;
    tro = -1;
    k=0;
    while ((k < n) && (tro == -1)) {
        if(x == v[k])
            tro = k;
        else
            k++;
    }
    return tro;
}

int OrdDisg(int v[],int n, int x) {
    int tro,k;
    bool continua;
    tro = -1;
    k = 0 ;
    continua = true;
    while((k < n) && (tro == -1) && (continua == true)) {
        if(x == v[ k ])
            tro = k;
        else if(v[ k ] > x )
            continua = false ;
        else
            k++ ;

    }
    return tro ;
}

int NonOrdNonDisg(int v[],int n, int x) {
    int nx,k;
    nx=0;
    for (k=0; k<n; k++) {
        if(x == v[k]) {
            printf("\nL'elemento trovato in posizione %d\n", k);
            nx++;
        }
    }
    return nx;
}

int OrdNonDisg(int v[], int n, int x) {
    int nx,k;
    bool continua;
    nx=0;
    k=0;
    continua = true;
    while(k<n && continua) {
        if(x == v[k]) {
            printf("\nL'elemento trovato in posizione %d", k);
            nx++;
            k++;
        } else if(v[k] > x)
            continua = false;
        else
            k++;

    }
    return nx;
}

int ricercaDicotomica(int v[], int n, int x) {
    int p,u,m,tro;
    p = 0;
    u = n-1;
    tro=-1;
    while((p <= u)&& tro==-1) {
        m = (p+u)/2;
        if(v[m]==x)
            tro=m;
        else if(v[m] < x)
            p = m+1;
        else // x < v[m]
            u = m-1;
    }
    return tro;
}

void selectionSort(int v[],int n) {
    int k,kmin,j
    for(k = 0; k < n-1; k++) {
        kmin = k;
        for(j = k+1; j < n; j++) {
            if(v[kmin] > v[j]) // confronti
                kmin = j;

        }
        if(kmin != k)
            scambio(&v[kmin], &v[k])
    }
    return;
}

void bubbleSort(int vett[], int n) {
    int k,sup,sca,z;
    sup= n-1 ;
    while ( sup>0 ) {
        sca=0 ;
        for (k = 0; k < sup ; k++) {
            if (vett[ k ] > vett[ k+1 ]) {
                z = vett[k];
                vett[k] = vett[k + 1];
                vett[k + 1] = z;
                sca=k ;
            }
        }
        sup=sca ;
    }
}
