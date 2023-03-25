

int *tab;
// fonction écrivant sur un seul afficheur
void choisirNumero(void);
void choisirPIN(void);

void uneseconde()
{
	for(int i=0;i<2000000;i++)
	{
		
	}
}


int main(void){
	
	RCC->APB2ENR |= 0x8; // là où se situe le B
	
	GPIOB->CRL &=~ 0x0FF00FFF; 
	
	GPIOB->CRL |= 0x02200222; 
	
	GPIOB->CRH &=~ 0xFF; 
	
	GPIOB->CRH |= 0x22;
	
		while(1){
		GPIOB->BSRR |= 0x3E7; 
		uneseconde();
			
		GPIOB->BSRR |= 0x3E70000; 
		uneseconde();
	}
	return 0 ;
}

void choisirNumero(void){
	
}
