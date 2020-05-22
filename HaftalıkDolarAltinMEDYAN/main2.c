#include<stdio.h>
//Bu metot haftalarda sýralama yapýp medyaný bulmaya yarýyor
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
    	//her haftanýn deðerlerinin bulunmasý
    	//her hafta 7 gün. 7 nin modu sýfýr.
        if( (i % 7) == 0 )
		{
        	 printf("\n%d . hafta dolar degerleri \n\n", (i/7) );
        	 
			 //o haftananýn her elemanýný tutmak
        	 for(j = 0; j < 7; j++)
			 {
        	 	haftalikArray[j] = numberArray[k];
        	 		 printf("Dolar degeri gunluk :  %lf \n",haftalikArray[j] );
        	 		
        	 		//tüm deðerleri haftada topladýðýmýzda
        	 		if(j==6){
        	 			 //printf("seaeaeri :  %d \n",haftalikArray[2] );
        	 			 
        	 			 //bubble sort yapýldý
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
					//k 7 þer 7 þer artýyor
					medyanlar[k/7] = medyan;
        	 		k ++;
			 }
		}
    }//asýl for döngüsü biter
    
	for(i = 0; i < (kacadet/7); i++){
    	printf("\nmedyanlar :  %lf \n",medyanlar[i] );
	}
	
	      //Alýnan deðerler "okuma.txt" dosyasýna yazýlacaktýr
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
	//dosyamý seçip okutma   
    myFile = fopen("girdi_dolar.txt", "r");
    
 	//dosya bulunamama durumu
	 if(myFile == NULL)
	 {
      	printf("dosya olusturulamadi");
	  }
    //txt deki eleman sayýsý kadar array oluþturma
    //fiyat deðerleri arrayde tutulacaktýr
    int kacadet;
    //altýn dosyasý için 406, dolar için 602
    kacadet = 602;

    double numberArray[kacadet];
    //her haftanýn deðerlerini tutmak için array
    double haftalikArray[7];
   	//döngülerde kullanýlacaklar
    int i;
    int j;
	//her elemanýn Array a yazdýrýlmasý  
    for (i = 0; i < kacadet; i++)
	{
        fscanf(myFile, "%lf", &numberArray[i]);
       // printf("Yazilan deger %lf\n\n" , numberArray[i]);
    }
    
    
    printf("%lf",medyanBulma(numberArray,kacadet));
  
      fclose(myFile);
  
	return 0;
}

