#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "led_matrix.h"
void wait();
void pointless_calculation(){
  int amount_of_pointlessness = 100000000;
  int x = 0;
  for (int i = 0; i < amount_of_pointlessness; i++){
    x += i;
  }
}

void run_child(int n){
  int row = n;
  for (int col = 0; col<8; col++){
    pointless_calculation();
    set_led(row,col,RGB565_BLUE);
    sleep(1);
     clear_leds();
  }
}

int main()
{
  open_led_matrix();
  clear_leds();
  for(int num_children = 1; num_children<9; num_children++)
  {
    for(int n=0; n<num_children; n++)
      {
      pid_t pid = fork();
      if (pid<0)
	{
	return -1;
         }
      else if (pid > 0)
	   {
	printf("parent of child %d \n",n);
           }
      else if (pid ==0)
	     {
        nice(n);
	run_child(n);
	return 0;
             }
      }
    for(int j =0; j < num_children; j++)
      {
      wait(NULL);
       }
    
    wait(NULL);
    pointless_calculation();
  
  clear_leds();
  pointless_calculation();
   }
  close_led_matrix();
  return 0;
} 
