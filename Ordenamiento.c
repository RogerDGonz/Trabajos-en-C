#include<stdio.h>
// cuadro comparativo al final 
int array[]={20, 34, 11, 54, 33, 10, 15, 55, 99, 40},size=10;


void Cambio(int array[],int a , int b , int *IntCambios){
	int x=array[b];
	array[b]=array[a];
	array[a]=x;
	*IntCambios=*IntCambios+1;
}

void intercambio(int array[],int size,int *comparar, int *IntCambios){
int i,j;

for(i=0;i<size-1;i++)
	for(j=i+1;j<size;j++){
		*comparar=*comparar+1;
		if (array[i]>array[j])
			Cambio(array,i,j,IntCambios);
	}
	
}
void Quicksort(int array[],int left,int right,int *comparar, int *IntCambios){
	if(left>=right) return;
	int pivot=(left+right)/2, pElem=array[pivot], first=left,last=right;

	while(left<right){
		while (array[left]<=pElem || left==pivot){
			left++;*comparar=*comparar+1;
		}	
		while(array[right]>pElem || right==pivot){
			right--;*comparar=*comparar+1;
		}
		if(left< right) Cambio(array,left++,right--,IntCambios);
	}

	if(left<pivot){
		if (right<pivot){
			Cambio(array,left,pivot,IntCambios);
			pivot=right;		
		}
	}else{
		if(right>pivot){
			Cambio(array,pivot,right,IntCambios);
			pivot=right;		
		}
	}
	Quicksort(array,first,pivot-1,comparar,IntCambios);
	Quicksort(array,pivot+1,last,comparar,IntCambios);
}

void seleccion(int array[],int size,int *comparar,int *IntCambios){
int e,i,j;
	for(i=0;i<size-1;i++){
		e=i;
		for(j=i+1;j<size;j++){
			*comparar=*comparar+1;
			if(array[e]>array[j])
				e=j;
		}	
		if(i!=e)
			Cambio(array,i,e,IntCambios);
	} 
	
}

void insercion(int array[],int size,int *comparar,int *IntCambios ){
	int t,i,j;
	for(i=1;i<size;i++){
		t=array[i];
		j=i;
		while(j>0){
			*comparar=*comparar+1;
			if (t<array[j-1]){
				*IntCambios=*IntCambios+1;
				array[j]=array[j-1];	
				j--;			
			}else break;
				
		}
		array[j]=t;
	}
}
	
int main (){
	int comparar=0, IntCambios=0,menu;	
	do{  
		printf("Introduzca una opcion\n\t1-Intercambio\n\t2-seleccion\n\t3-insercion\n\t4-Quicksort\n\tOpcion:");
		scanf("%d",&menu);
		system("clear");
		switch(menu){
		case 1:intercambio(array,size,&comparar,&IntCambios);break;
		case 2:seleccion(array,size,&comparar,&IntCambios);break;
		case 3:insercion(array,size,&comparar,&IntCambios);break;
		case 4:Quicksort(array,0,size-1,&comparar,&IntCambios);break;
		}
	}while(menu<0 && menu>5 );
	printf("cantidad de compararciones: %d\ncantidad de Intercambios: %d\n",comparar,IntCambios);
	int i;
	for (i=0;i<size;i++)
		printf("%d ",array[i]);
	return 0;
}

/*

	CUADRO COMPARATIVO DE METODOS DE ORDENAMIENTO DE ARREGLOS 

	X	INTERCAMBIO	SELECCIÓN	INSERCIÓN	QUICKSORT

 Comparaciones:|     45	     |	   45	   |       23        |	   22     |

 Intercambios :|     16      |     8	   |       16        |      8     |



*/
