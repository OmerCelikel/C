#include<stdio.h>
//Bu metot haftalarda sýralama yapýp medyaný bulmaya yarýyor
int medyanBulma(int numberArray[], int kacadet){
 	//Bölü 7 Çünkü Her hafta bir tane
	 int medyanlar[kacadet/7];
 	int medyan;
	int haftalikArray[7];
	//döngülerde kullanmak için
	int i,j;
	int k = 0;
	int n = 0;
	int z = 0;
	int siralama = 0;
	int gecici ;
    for (i = 0; i < kacadet; i++)
	{
    	//her haftanýn deðerlerinin bulunmasý
    	//her hafta 7 gün. 7 nin modu sýfýr.
        if( (i % 7) == 0 )
		{
        	 printf("\n%d . hafta altin degerleri \n\n", (i/7) );
        	 
			 //o haftananýn her elemanýný tutmak
        	 for(j = 0; j < 7; j++)
			 {
        	 	haftalikArray[j] = numberArray[k];
        	 		 printf("Altin degeri gunluk :  %d \n",haftalikArray[j] );
        	 		
        	 		//tüm deðerleri haftada topladýðýmýzda
        	 		if(j==6){
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
						  //sýralanan sayýlarý görmek için
						  for(z= 0; z<7; z++){
						  		 printf("\nSiralandi :  %d ",haftalikArray[z] );
						  }
						  //medyan ý görmek için
						   printf("\nOrtadaki eleman :  %d \n",haftalikArray[3] );
						   medyan = haftalikArray[3];
					 }
					//tüm haftalardaki medyanlar "medyanlar[]" arrayýnda toplanýyor
					medyanlar[k/7] = medyan;
					//k 7 þer 7 þer artýyor
        	 		k ++;
			 }
		}
    }//asýl for döngüsü biter
    
	for(i = 0; i < (kacadet/7); i++){
    	printf("\nmedyanlar :  %d \n",medyanlar[i] );
	}
	
	//Alýnan deðerler "okuma.txt" dosyasýna yazýlacaktýr
      FILE *filep = fopen("output.txt","w");
      if(filep == NULL){
      	printf("dosya olusturulamadi");
	  }
     else{
     	for(i=0; i < (kacadet/7); i++){
     		fprintf(filep,"%d\n",medyanlar[i]);
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
    myFile = fopen("girdi_altin.txt", "r");
    
 	//dosya bulunamama durumu
	 if(myFile == NULL)
	 {
      	printf("dosya olusturulamadi");
	  }
    //txt deki eleman sayýsý kadar array oluþturma
    //fiyat deðerleri arrayde tutulacaktýr
    int kacadet;
    //altýn dosyasý için 406, dolar için 602
    kacadet = 406;

    int numberArray[kacadet];
    //her haftanýn deðerlerini tutmak için array
    int haftalikArray[7];
   	//döngülerde kullanýlacaklar
    int i;
    int j;
	//her elemanýn Array a yazdýrýlmasý  
    for (i = 0; i < kacadet; i++)
	{
        fscanf(myFile, "%d", &numberArray[i]);
    }
    	//medyanBulma Fonksiyonunu çaðýrdý.
     printf("%d",medyanBulma(numberArray,kacadet));
  
      fclose(myFile);
      
	return 0;
}

