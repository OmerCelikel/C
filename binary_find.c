#include<stdio.h>

int main()
{
	int i,j,r,decimal,binary[20],k;

		//74 adet yapılacak
		k = 74;
		while(k>0){
			//sayımı decimal e eşitledim
			decimal = k;
			//aynı sayımı da n e eşitledim işlemler için
			int n = decimal;
		//sıfırdan tüm değerleri array imin içine yerleştirecek
		//array 1 ve sıfırları tutacak yani binary sayısı ortaya çıkacak
		i=0;
		while(decimal>0){
		//tek veya çiftliği ilk sütunda kontrol ederiz
		r = decimal%2;
		binary[i] = r;
		//2 ye böle böle gideriz binaryde
		decimal = decimal/2;
		i++;
	
		}
		
		printf("\n %d sayisinin binary numarasi : " , n);
	
			for(j=i-1; j>= 0; j--){
			printf("%d", binary[j]);
			}
		
			k--;
		}
	
	
	return 0;
}
