#include "LPC17xx.H" // LPC17xx definitions
void delay(int count)
{
	int i;
	for (i = 0; i < count; i++); //Just count for delay
}
int main (void) 
{
	int a;
	int count_f=1;//frequency mode
	int count_m=1; //mode
	int mask_val=       0x00000800; //bit 11 in 32-bit
	int mask_val2=      0x00001000; //bit 12 in 32-bit
	int on_val = 0;
	LPC_GPIO2->FIODIR = 0x000000FF; // P2.0, P2.1,...P2.7 pins/LEDs on port2 set as output
	//urn on/off the LED driven by P2.0; 
	while(1){
		/*if((LPC_GPIO2->FIOPIN & mask_val)==0)
		{ 
			//LPC_GPIO2->FIODIR |= 1;  
			count_m++;
			if(count_m>4)
			{
				count_m=1;
			}
		}
		//else {LPC_GPIO2->FIODIR &= ~1;}
			*/
		switch(count_m)
		{
			case 1:
							if((LPC_GPIO2->FIOPIN & mask_val)==0)  
							{
								count_m=2;
								break;
							}
							switch(count_f)
							{
								case 1:
									if((LPC_GPIO2->FIOPIN & mask_va2)==0)  
									{
										count_f=2;
										break;
									}
									a=7;
									while(a>=0){
										LPC_GPIO2->FIOPIN |= 1 << a; // make P2.0 high 
										delay(12000000); // delay of about 1 s implemented in software;
										LPC_GPIO2->FIOPIN &= ~1 << a; // make P2.0 low
										delay(12000000);
										a--;
									}
									break;
								case 2:
									if((LPC_GPIO2->FIOPIN & mask_va2)==0)  
									{
										count_f=3;
										break;
									}
									a=7;
									while(a>=0){
										LPC_GPIO2->FIOPIN |= 1 << a; // make P2.0 high 
										delay(3000000); // delay of about 1 s implemented in software;
										LPC_GPIO2->FIOPIN &= ~1 << a; // make P2.0 low
										delay(3000000);
										a--;
									}
									break;
								case 3:
									if((LPC_GPIO2->FIOPIN & mask_va2)==0)  
									{
										count_f=1;
										break;
									}
									a=7;
									while(a>=0){
										LPC_GPIO2->FIOPIN |= 1 << a; // make P2.0 high 
										delay(24000000); // delay of about 1 s implemented in software;
										LPC_GPIO2->FIOPIN &= ~1 << a; // make P2.0 low
										delay(24000000);
										a--;
									}
									break;
							}	
							break;
										
			case 2:
							if((LPC_GPIO2->FIOPIN & mask_val)==0)  
							{
								count_m=3;
								break;
							}
							switch(count_f)
							{
								case 1:
								if((LPC_GPIO2->FIOPIN & mask_va2)==0)  
									{
										count_f=2;
										break;
									}							
									a=0;		
									while(a<=7){
									LPC_GPIO2->FIOPIN |= 1 << a; // make P2.0 high 
									delay(12000000); // delay of about 1 s implemented in software;
									LPC_GPIO2->FIOPIN &= ~1 << a; // make P2.0 low
									delay(12000000);
									a++;
									}
									break;
								case 2:
									if((LPC_GPIO2->FIOPIN & mask_va2)==0)  
									{
										count_f=3;
										break;
									}							
									a=0;		
									while(a<=7){
									LPC_GPIO2->FIOPIN |= 1 << a; // make P2.0 high 
									delay(3000000); // delay of about 1 s implemented in software;
									LPC_GPIO2->FIOPIN &= ~1 << a; // make P2.0 low
									delay(3000000);
									a++;
									}
									break;
								case 3:
									if((LPC_GPIO2->FIOPIN & mask_va2)==0)  
									{
										count_f=1;
										break;
									}							
									a=0;		
									while(a<=7){
									LPC_GPIO2->FIOPIN |= 1 << a; // make P2.0 high 
									delay(24000000); // delay of about 1 s implemented in software;
									LPC_GPIO2->FIOPIN &= ~1 << a; // make P2.0 low
									delay(24000000);
									a++;
									}
									break;
								}
							break;	
									
			case 3:
							if((LPC_GPIO2->FIOPIN & mask_val)==0)  
							{
								count_m=4;
								break;
							}
							switch(count_f)
							{
								case 1:
										if((LPC_GPIO2->FIOPIN & mask_va2)==0)  
										{
											count_f=2;
											break;
										}
										a=7;
										while(a>0){
											LPC_GPIO2->FIOPIN |= 1 << a; // make P2.0 high 
											delay(12000000); // delay of about 1 s implemented in software;
											LPC_GPIO2->FIOPIN &= ~1 << a; // make P2.0 low
											delay(12000000);
											a--;
										}
										a=0;
										while(a<7){
											LPC_GPIO2->FIOPIN |= 1 << a; // make P2.0 high 
											delay(12000000); // delay of about 1 s implemented in software;
											LPC_GPIO2->FIOPIN &= ~1 << a; // make P2.0 low
											delay(12000000);
											a++;
										}
										break;
								case 2:
									if((LPC_GPIO2->FIOPIN & mask_va2)==0)  
										{
											count_f=3;
											break;
										}
										a=7;
										while(a>0){
											LPC_GPIO2->FIOPIN |= 1 << a; // make P2.0 high 
											delay(3000000); // delay of about 1 s implemented in software;
											LPC_GPIO2->FIOPIN &= ~1 << a; // make P2.0 low
											delay(3000000);
											a--;
										}
										a=0;
										while(a<7){
											LPC_GPIO2->FIOPIN |= 1 << a; // make P2.0 high 
											delay(3000000); // delay of about 1 s implemented in software;
											LPC_GPIO2->FIOPIN &= ~1 << a; // make P2.0 low
											delay(3000000);
											a++;
										}
										break;
								case 3:
									if((LPC_GPIO2->FIOPIN & mask_va2)==0)  
										{
											count_f=2;
											break;
										}
										a=7;
										while(a>0){
											LPC_GPIO2->FIOPIN |= 1 << a; // make P2.0 high 
											delay(24000000); // delay of about 1 s implemented in software;
											LPC_GPIO2->FIOPIN &= ~1 << a; // make P2.0 low
											delay(24000000);
											a--;
										}
										a=0;
										while(a<7){
											LPC_GPIO2->FIOPIN |= 1 << a; // make P2.0 high 
											delay(24000000); // delay of about 1 s implemented in software;
											LPC_GPIO2->FIOPIN &= ~1 << a; // make P2.0 low
											delay(24000000);
											a++;
										}
										break;
									}
							break;
												
			case 4:
							if((LPC_GPIO2->FIOPIN & mask_val)==0)  
							{
								count_m=1;
								break;
							}
							switch(count_f)
							{
								case 1:
									if((LPC_GPIO2->FIOPIN & mask_va2)==0)  
									{
										count_f=2;
										break;
									}
									LPC_GPIO2->FIOPIN |= 0x000000FF; // make P2.0 high 
									delay(12000000); // delay of about 1 s implemented in software;
									LPC_GPIO2->FIOPIN &=~0x000000FF; // make P2.0 low
									delay(12000000);
									break;
								case 2:
									if((LPC_GPIO2->FIOPIN & mask_va2)==0)  
									{
										count_f=3;
										break;
									}
									LPC_GPIO2->FIOPIN |= 0x000000FF; // make P2.0 high 
									delay(3000000); // delay of about 1 s implemented in software;
									LPC_GPIO2->FIOPIN &=~0x000000FF; // make P2.0 low
									delay(3000000);
									break;
								case 3:
									if((LPC_GPIO2->FIOPIN & mask_va2)==0)  
									{
										count_f=1;
										break;
									}
									LPC_GPIO2->FIOPIN |= 0x000000FF; // make P2.0 high 
									delay(24000000); // delay of about 1 s implemented in software;
									LPC_GPIO2->FIOPIN &=~0x000000FF; // make P2.0 low
									delay(24000000);
									break;
								}
							break;
	}
	}
}
