#include<stdio.h>
//Bu metot haftalarda s�ralama yap�p medyan� bulmaya yar�yor
int medyanBulma(double numberArray[], int kacadet){
 	double medyanlar[kacadet/7];
 	double medyan;
	double haftalikArray[7];
	 int i;
    int j;
		int k = 0;
	int n = 0;
	int z = 0;
	int siralama = 0;
	double gecici ;
    for (i = 0; i < kacadet; i++)
	{
    	//her haftan�n de�erlerinin bulunmas�
    	//her hafta 7 g�n. 7 nin modu s�f�r.
        if( (i % 7) == 0 )
		{
        	 printf("\n%d . hafta dolar degerleri \n\n", (i/7) );
        	 
			 //o haftanan�n her eleman�n� tutmak
        	 for(j = 0; j < 7; j++)
			 {
        	 	haftalikArray[j] = numberArray[k];
        	 		 printf("Dolar degeri gunluk :  %lf \n",haftalikArray[j] );
        	 		
        	 		//t�m de�erleri haftada toplad���m�zda
        	 		if(j==6){
        	 			 //printf("seaeaeri :  %d \n",haftalikArray[2] );
        	 			 
        	 			 //bubble sort yap�ld�
        	 			 for(siralama = 0; siralama < 6; siralama++){
        	 			 	for(n = 0; n < (7-siralama-1); n++){
        	 			 		if(haftalikArray[n] > haftalikArray[n+1]){
        	 			 			gecici = haftalikArray[n];
        	 			 			haftalikArray[n] = haftalikArray[n+1];
        	 			 			haftalikArray[n+1] = gecici;
								  }
							  }
						  }
						  for(z= 0; z<7; z++){
						  		 printf("\nSiralandi :  %lf ",haftalikArray[z] );
						  }
						  
						   printf("\nOrtadaki eleman :  %lf \n",haftalikArray[3] );
						    medyan = haftalikArray[3];
        	 			 
					 }
					//k 7 �er 7 �er art�yor
					medyanlar[k/7] = medyan;
        	 		k ++;
			 }
		}
    }//as�l for d�ng�s� biter
    
	for(i = 0; i < (kacadet/7); i++){
    	printf("\nmedyanlar :  %lf \n",medyanlar[i] );
	}
	
	      //Al�nan de�erler "okuma.txt" dosyas�na yaz�lacakt�r
      FILE *filep = fopen("output2.txt","w");
      if(filep == NULL){
      	printf("dosya olusturulamadi");
	  }
     else{
     	for(i=0; i < (kacadet/7); i++){
     		fprintf(filep,"%lf\n",medyanlar[i]);
     		//printf("MEDYANLAR %d\n\n" , medyanlar[i]);
		 }
	 } 
      printf("Dosya Olusturuldu...");
      fclose(filep);
	
    return 0;
}//fonksiyon biter


int main() {
	   FILE *myFile;
	//dosyam� se�ip okutma   
    myFile = fopen("girdi_dolar.txt", "r");
    
 	//dosya bulunamama durumu
	 if(myFile == NULL)
	 {
      	printf("dosya olusturulamadi");
	  }
    //txt deki eleman say�s� kadar array olu�turma
    //fiyat de�erleri arrayde tutulacakt�r
    int kacadet;
    //alt�n dosyas� i�in 406, dolar i�in 602
    kacadet = 602;

    double numberArray[kacadet];
    //her haftan�n de�erlerini tutmak i�in array
    double haftalikArray[7];
   	//d�ng�lerde kullan�lacaklar
    int i;
    int j;
	//her eleman�n Array a yazd�r�lmas�  
    for (i = 0; i < kacadet; i++)
	{
        fscanf(myFile, "%lf", &numberArray[i]);
       // printf("Yazilan deger %lf\n\n" , numberArray[i]);
    }
    
    
    printf("%lf",medyanBulma(numberArray,kacadet));
  
      fclose(myFile);
  
	return 0;
}

