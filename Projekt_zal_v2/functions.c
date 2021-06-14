//#define F_CPU 16000000UL
//#define BAUD 9600
//#include <avr/io.h>
//#include <util/delay.h>
//#include <avr/interrupt.h>
//#include <util/atomic.h>
//#include "functions.h"
//
//int ButtonWasON = 0;							//Flaga sprawdzaj¹ca wciœniêcie przycisku
//int FunctionNumber = 0;							//Zmienna numeru funkcji (do ustawienia trybu pracy sterownika)
//int global_adc_change_check = 0;
//uint8_t global_variable_adc;					//unsigned integer 8 bitowy
//int global_last_adc_value = 0;
//volatile uint8_t global_variable_USART_UDR0;	//Zmienna przechowuj¹ca znak wpisany w terminalu przez USART0 (volatile - zmienna ulotna)
//int global_USART_mode_set = 0;
//int global_USART_instruction_detected = 0;
//int global_USART_adc_override = 0;				//Flaga recznego sterowania wartoscia ADC (przez komendy wpisywane w usart)
//int global_USART_adc_override_value = 0;
//
////Przerwanie timera1
//SIGNAL(TIMER1_OVF_vect){
	//ButtonChecker_FunctionSet();
	////PORTB ^= (1<<PB7);			//Tylko dla testu dzialania timera!
	//ADCChangeCheck();				//Do sprawdzenia czy nastapila zmiana wartosci potencjometru
//}
//
////Przerwanie ADC
//ISR(ADC_vect){
	//
	//if(global_USART_adc_override == 0)
	//{
		//unsigned int a = ADC >> 2;					//poniewa¿ rejestr OCR0A posiada zakres od 0 do 255, a ADC 1023 to ADC trzba podzieliæ przez 4 zeby siê zmieœci³
		//a *= a;										//¿eby zmiana janosci diody byla bardziej zauwazalna w calym zakresie
		//global_variable_adc = a >> 8;
	//}
	//else if (ButtonWasON == 1 && global_USART_adc_override == 1)
	//{
		//global_USART_adc_override = 0;
		//print("---STOP, TRYB RECZNEGO USTAWIANIA ADC WYLACZONY (on button request)---");
	//}
	//else
	//{
		//global_variable_adc = global_USART_adc_override_value;
	//}
	//
//}
//
////Przerwania USART0
//ISR(USART0_RX_vect){
	//global_variable_USART_UDR0 = UDR0;
//
	//switch(global_variable_USART_UDR0){
		//case 'r':								//r - read, odczytywanie parametrow pracy sterownika
		//read_parameters();
		//break;
//
		//case 'w':								//w - write, nadpisanie parametrow pracy sterownika
		//adc_override_routine();
		//break;
//
		//case 's':								//s - stop, zatrzymanie recznego ustawiania parametrow pracy sterownika
		//global_USART_adc_override = 0;
		//print("---STOP, TRYB RECZNEGO USTAWIANIA ADC WYLACZONY (on USART request)---");
		//break;
//
		//case '0':
		//global_USART_instruction_detected = 1;
		//global_USART_mode_set = 0;
		//print("\n---Ustawiono tryb 0 (on USART request)---\n");
		//break;
//
		//case '1':
		//global_USART_instruction_detected = 1;
		//global_USART_mode_set = 1;
		//print("\n---Ustawiono tryb 1 (on USART request)---\n");
		//break;
//
		//case '2':
		//global_USART_instruction_detected = 1;
		//global_USART_mode_set = 2;
		//print("\n---Ustawiono tryb 2 (on USART request)---\n");
		//break;
	//}
//}
//
////Procedura recznego ustawiania wartoœci ADC
//void adc_override_routine(void){
	//global_USART_adc_override = 1;							//Ustawiamy flagê recznego ustawiania ADC
//
	//print("---TRYB RECZNEGO USTAWIANIA ADC---\n");
	//while(1){												//Nieskoñczona pêtla która czeka a¿ zostanie wpisana wartoœæ ADC (po wpisaniu nowej wartoœci ADC, break pêtli)
		//global_variable_USART_UDR0 = UDR0;
		//if (global_variable_USART_UDR0 >= '0' && global_variable_USART_UDR0 <= '9')
		//{
			//int temp_value1 = global_variable_USART_UDR0 - '0';			//z wartoœci ascii do tekiej wartoœci jaka zosta³a podana w terminalu
			//float temp_value2 = temp_value1*25.5;						//25.5 to 10% wartosci ADC
//
			//global_USART_adc_override_value = temp_value2;				//reczna wartosc ADC zapisujemy do globalnej zmiennej
			//
			//print("Podana wartosc: ");									//Wypisanie podanej wartosci adc w terminalu
			//char temp[5];
			//itoa(global_USART_adc_override_value, temp, 10);
			//print(temp);
			//print("\n\n");
//
			//break;
		//}
	//}
//}
//
////Funkcja wypisuj¹ca na terminal aktualne ustawienia pracy sterownika
//void read_parameters(void){
//
	//char fn[1];
	//itoa(FunctionNumber, fn, 10);
	//print("\nNumer Funkcji: ");
	//print(fn);
//
	//
	//char varadc[5];
	//itoa(global_variable_adc, varadc, 10);
	//print("\nWartosc Potencjometru: ");
	//print(varadc);
//
//
	//print("\nTryb pracy potencjometru: ");
	//if(global_USART_adc_override == 1){
		//print("wpisywanie wartosci ADC przez USART");
	//}
	//else{
		//print("automatyczne sczywywanie wartosci ADC z potencjometru");
	//}
//
	//print("\n\n");
//}
//
////Funkcja sprawdzaj¹ca wcisniecie przycisku oraz ustawiaj¹ca aktualnie dzialajacy numer funkcji
//void ButtonChecker_FunctionSet(void){
//
	//if(global_USART_instruction_detected == 1){			//je¿eli ustawiono tryb pracy przez USART to to ustaw
		//FunctionNumber = global_USART_mode_set;
		//global_USART_instruction_detected = 0;
	//}
	//else if(bit_is_set(PINB, 5)){						//Sprawdzenie czy przycisk jest wcisniety
		//ButtonWasON = 1;
	//}
	//else{												//Je¿eli przycisk ju¿ nie jest wciœniêty to zmieñ numer funkcji
		//if (ButtonWasON == 1){
			//FunctionNumber++;
			//
			//if(FunctionNumber >= 3){
				//FunctionNumber = 0;
			//}
			//
			////wyœwietlanie numeru funkcji w terminalu
			//char fn[1];
			//itoa(FunctionNumber, fn, 10);
			//print(fn);
			//print("\n");
//
			//ButtonWasON = 0;
		//}
	//}
//}
//
////Funkcja sprawdzaj¹ca zmiane wartosci ADC
//void ADCChangeCheck(void){
//
	////wypisujemy w terminalu wartosc ADC dopiero gdy bêdzie jakaœ zmiana (jak bêdzie zmiana o 20, dlatego ¿e potenjometr jest niedok³adny i czasami sam delikatnie zmienia wartosc, wiec sprawdzenie wartosci powinno byc dopiero po jakiej konkretnej zmianie wartosci)
	//if((global_last_adc_value-20 >= global_variable_adc) || (global_last_adc_value+20 <= global_variable_adc)){
		////char napis[5];
		////print("wartosc ADC:");
		////itoa (global_variable_adc, napis, 10);
		////print(napis);
//
		//global_adc_change_check = 1;
		//global_last_adc_value = global_variable_adc;		//zapisujemy wartosc ADC zeby potem porównaæ z now¹ wartoœci¹ ADC
//
	//}
//}
//
////TRYB PRACY 0
//void mode0(void){
	//OCR0A = global_variable_adc;
//}
//
////TRYB PRACY 1
//void mode1(void){
	//float blink_time = 0;
	//int last_function = 1;
//
	//if (global_variable_adc >= 250)
	//{
		//blink_time = 2000;
	//}
	//else if (global_variable_adc <= 12)				//bo np.: 12*7.78=93.36, czyli mniej niz wymagany minimalny czas
	//{
		//blink_time = 100;
	//}
	//else
	//{
		//blink_time = global_variable_adc*7.78;
	//}
//
	//OCR0A = 255;									//Zapalona dioda
	//for(int i=0; i<blink_time; i++){
		//_delay_ms(1);
		//if(global_adc_change_check == 1){			//sprawdzamy czy podczas migania zmienila sie wartosc potencjometru
			//global_adc_change_check = 0;
//
			//break;
		//}
		//else if(last_function != FunctionNumber){	//je¿eli zmiana funkcji to wyjdz z funkcji
			//return;
		//}
//
		//last_function = FunctionNumber;
	//}
//
	//OCR0A = 0;										//Zgaszona dioda
	//for(int i=0; i<blink_time; i++){
		//_delay_ms(1);
		//if(global_adc_change_check == 1){
			//global_adc_change_check = 0;
//
			//break;
		//}
		//else if(last_function != FunctionNumber){	//je¿eli zmiana funkcji to wyjdz z funkcji
			//return;
		//}
//
		//last_function = FunctionNumber;
	//}
//}
//
////TRYB PRACY 2
//void mode2(void){
	//float polowa_okresu = ((global_variable_adc*11.76)+1000)/2;				//okres -> (global_variable_adc*11,76)+1000) oblicza potrzebny czas w ms dla 3s w zaleznosci od wartosci adc + 1000 aby by³o dla 4s, polowa okresu -> wszystko /2
	//int mode3_delay = polowa_okresu/255;									//liczba zapêtleñ pêtli opóŸniaj¹cej dla po³owy okresu
	//int last_function = 2;
//
	//for(int i=0; i<256; i++){						//rozjaœnianie
		//for(int i=0; i<mode3_delay; i++){			//pêtla opóŸniaj¹ca
			//_delay_ms(1);
		//}
//
		//OCR0A = i;
//
		//if(global_adc_change_check == 1){
			//global_adc_change_check = 0;
			//break;
		//}
		//else if(last_function != FunctionNumber){	//je¿eli zmiana funkcji to wyjdz z funkcji
			//return;
		//}
//
		//last_function = FunctionNumber;
	//}
	//for(int i=255; i>=0; i--){						//przygaszanie
		//for(int i=0; i<mode3_delay; i++){			//pêtla opóŸniaj¹ca
			//_delay_ms(1);
		//}
//
		//OCR0A = i;
//
		//if(global_adc_change_check == 1){
			//global_adc_change_check = 0;
			//break;
		//}
		//else if(last_function != FunctionNumber){	//je¿eli zmiana funkcji to wyjdz z funkcji
			//return;
		//}
//
		//last_function = FunctionNumber;
	//}
//}
//
//void USART_Init()
//{
	//UBRR0H = 0;
	//UBRR0L = 207;										/* fosc = 16MHz, U2Xn = 1, chce 9600bps wiec z tabelki UBBRRnL bedzie 207 */
	//
	///* Enable receiver and transmitter */
	//UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);
	//
	///* Set frame format: 8data, 2stop bit */
	//UCSR0C = (1<<USBS0)|(3<<UCSZ00);
	//
	///* w³¹czenie opcji Double the USART Transmission Speed poprzez ustawienie bitu U2Xn w odpowiednim rejestrze */
	//UCSR0A = (1<<U2X0);
//}
//
//void lcd_routine(void){
//
	////wartoœæ ADC
	//LCDGotoXY(0,0);
	//LCDstring("ADC:", 4);
//
	//char temp[5];
	//itoa(global_variable_adc, temp, 10);
	//LCDGotoXY(4,0);
	//LCDstring(temp, 3);
//
//
	////tryb pracy potencjometru
	//LCDGotoXY(8,0);
	//LCDstring("Ster:", 5);
//
	//if (global_USART_adc_override == 0)
	//{
		//LCDGotoXY(13,0);
		//LCDstring("Au.", 3);
	//}
	//else if (global_USART_adc_override == 1)
	//{
		//LCDGotoXY(13,0);
		//LCDstring("Re.", 3);
	//}
	//else
	//{
		//LCDGotoXY(13,0);
		//LCDstring("???", 3);
	//}
//
//
	////tryb pracy sterownika
	//LCDGotoXY(0,1);
	//LCDstring("Tryb:", 5);
//
	//if (FunctionNumber == 0)
	//{
		//LCDGotoXY(6,1);
		//LCDstring("Regul.jasn.", 11);
	//}
	//else if (FunctionNumber == 1)
	//{
		//LCDGotoXY(6,1);
		//LCDstring("Migania   ", 11);
	//}
	//else if (FunctionNumber == 2)
	//{
		//LCDGotoXY(6,1);
		//LCDstring("Mod.zm.ja.", 11);
	//}
	//else
	//{
		//LCDGotoXY(6,1);
		//LCDstring("Blad odcz.", 11);
	//}
//}
//
//unsigned char USART_Receive( void )
//{
	///* Wait for data to be received */
	//while ( !(UCSR0A & (1<<RXC0)) )
	//;
	///* Get and return received data from buffer */
	//return UDR0;
//}
//
//void print(char* txt)
//{
	//unsigned int i = 0;
	//while(txt[i])
	//{
		//UDR0 = txt[i];
		//while(!(UCSR0A & 0b01000000));
		//_delay_ms(20);
		//i++;
	//}
//}