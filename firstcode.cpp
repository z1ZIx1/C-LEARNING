#include <iostream>
int main () {
    system("chcp 65001 -> null");
    setlocale(LC_ALL, "ru_RU.UTF-8");        // Включаем поддержку русского языка в консоли Windows;

    float temp = 0;
    float pres = 0;
    
    std::cout << " САСУ ТП\n";
    std::cout << " Температуру введи\n";
    std::cin >> temp;

    std::cout <<"Введите текущее давление (бар):";
    std::cin >> pres;

    if (pres > 4.5f || temp > 110.0f){
        std::cout << "\n[АВАРИЯ] Критические показатели! Сброс давления!\n";

    }
    else if (pres < 0.5f){
        std::cout << "\n[Предупреждение] малое давление! Возможна утечка!\n";

    }

    else {
        std::cout << "\n[OK]Система работает отлично!\n";

    }

    return 0;
}