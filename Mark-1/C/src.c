#include "LPC17xx.H" // LPC17xx definitions
void delay(int count)
{
	int i;
	for (i = 0; i < count; i++); //Just count for delay
}
int main (void) 
{
	int a;
	int count_f=1;//frequency mode to change the speed of 8 LEDs
	int count_m=1; //mode to change the pattern of 8 LEDs
	int mask_val= 1<<11; //KEY1
	int mask_val2= 1<<12; //Key2
	int frequency;
	int on_val = 0;
	
	LPC_GPIO2->FIODIR = 0x000000FF; // P2.0, P2.1,...P2.7 pins/LEDs on port2 set as output
	//urn on/off the LED driven by P2.0; 
	while(1){
		if((LPC_GPIO2->FIOPIN & mask_val)==0) //checks if KEY1 is pressed
		{   
			count_m++;
			if(count_m>4)
				count_m=1;
		}
		if((LPC_GPIO2->FIOPIN & mask_val2)==0) //checks if KEY2 is pressed
		{   
			count_f++;
			if(count_f>3)
				count_f=1;
		}
		
		if(count_f==1)
			frequency=12000000;
		if(count_f==2)
			frequency=3000000;
		if(count_f==3)
			frequency=24000000;
		
		if(count_m==1)
		{
			a=7;
			while(a>=0){
				LPC_GPIO2->FIOPIN |= 1 << a; // make P2.0 high 
				delay(frequency); // delay of about 1 s implemented in software;
				LPC_GPIO2->FIOPIN &= ~1 << a; // make P2.0 low
				delay(frequency);
				a--;
			}
		}
		if(count_m==2)
		{
			a=0;		
			while(a<=7){
				LPC_GPIO2->FIOPIN |= 1 << a; // make P2.0 high 
				delay(frequency); // delay of about 1 s implemented in software;
				LPC_GPIO2->FIOPIN &= ~1 << a; // make P2.0 low
				delay(frequency);
				a++;
			}
		}
		if(count_m==3)
		{
			a=7;
			while(a>0){
				LPC_GPIO2->FIOPIN |= 1 << a; // make P2.0 high 
				delay(frequency); // delay of about 1 s implemented in software;
				LPC_GPIO2->FIOPIN &= ~1 << a; // make P2.0 low
				delay(frequency);
				a--;
			}
			a=0;
			while(a<7){
				LPC_GPIO2->FIOPIN |= 1 << a; // make P2.0 high 
				delay(frequency); // delay of about 1 s implemented in software;
				LPC_GPIO2->FIOPIN &= ~1 << a; // make P2.0 low
				delay(frequency);
				a++;
			
			}
		}
		if(count_m==4)
		{
			LPC_GPIO2->FIOPIN |= 0x000000FF; // make P2.0 high 
			delay(frequency); // delay of about 1 s implemented in software;
			LPC_GPIO2->FIOPIN &=~0x000000FF; // make P2.0 low
			delay(frequency);
		}
	}
}
