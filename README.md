# Sterownik_diody_LED

Projekt sterownika diody LED, napisany w języku C, z wykorzystaniem mikrokontrolera ATmega2560.

Do tego projektu wykorzystano następujące elementy:
* Mikrokontroler ATmega2560 na płytce uruchomieniowej Arduino Mega
* Przycisk
* Wyświetlacz LCD 2x16
* Potencjometr

Sterownik został zaprogramowany w taki sposób, aby dioda LED działała w 3 trybach:
* tryb regulacji jasności świecenia
* tryb migania
* tryb modulowanej zmiany jasności

Wciśnięcie przycisku powoduje zmianę trybu jasności świecenia. Zmiana nastawy potencjometru powoduje zmianę jasności świcenia w trybie regulacji jasności świecenia lub w pozostałych trybach, zmianę czestotliwości okresu w jakim dioda przechodzi przez cykl zapalona -> zgaszona -> zapalona. Wyświetlacz LCD służy do wyświetlania aktualnie działającego trybu wraz z parametrami ustawionymi za pomocą potencjometru. Wyświetlacz wskazuje również czy sterowanie parametrami sterownika odbywa się aktualnie za pomocą potencjometru czy poprzez ręczne komendy wysyłane z komputera za pomocą USART.
