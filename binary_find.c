#include<stdio.h>

int main()
{
	int i,j,r,decimal,binary[20],k;

		//74 adet yap�lacak
		k = 74;
		while(k>0){
			//say�m� decimal e e�itledim
			decimal = k;
			//ayn� say�m� da n e e�itledim i�lemler i�in
			int n = decimal;
		//s�f�rdan t�m de�erleri array imin i�ine yerle�tirecek
		//array 1 ve s�f�rlar� tutacak yani binary say�s� ortaya ��kacak
		i=0;
		while(decimal>0){
		//tek veya �iftli�i ilk s�tunda kontrol ederiz
		r = decimal%2;
		binary[i] = r;
		//2 ye b�le b�le gideriz binaryde
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
