#include <stdio.h>
#include <string.h>

int main() {
   int num = 20; 
   for(int i = 0; i < 6; i++) {
       if(i == 0) {
           printf("%d, ", num);
       }
       else if(i == 5){
           num-=6;
	   printf("%d", num);
       }
       else{
	   num-=6;
           printf("%d, ", num);
       }
       if(i == 5) printf("\n");
   }
}
