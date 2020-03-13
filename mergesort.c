#include <stdio.h>
#include <stdlib.h>

void merge(int *vetor, int init, int middle, int final){
  int meio = middle;
  meio++;
  int *v = malloc((final-init)+1 * sizeof(int));
  int pos = 0;

  while(init <= middle && meio <= final){
    if(vetor[init]<vetor[meio]){
      v[pos] = vetor[init];
      pos++;
      init++;
    }
    else{
      v[pos] = vetor[meio];
      pos++;
      meio++;
    }
  }

  if(init > middle){
    while(meio <= final){
      v[pos] = vetor[meio];
      pos++;
      meio++;
    }
  }
  else{
    while(init <= middle){
      v[pos] = vetor[init];
      pos++;
      init++;
    }
  }
}

void mergesort(int *vetor, int init, int final){
  int middle = (final+init)/2;
  printf("(%i %i), ", init, final);
  if(init < final){
    mergesort(vetor, init, middle);
    mergesort(vetor, middle+1, final);
  }
  merge(vetor,init,middle,final);
}

int main(){
  int vetor[10] = {53,45634,5356,435,7257,25,143,1};
  mergesort(vetor,0,7);
  printf("\n");
  for(int i = 0; i < 8; i++)
    printf("%i, ", vetor[i]);
  printf("\n");
  return 0;
}
