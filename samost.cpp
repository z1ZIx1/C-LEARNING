#include <iostream>

void check(float z, float v, unsigned short& a, unsigned short& w){
    if (z > 95.0 and (v < 12.0 || v > 14.5)){
        std::cout << "\n [СКЛАД] Места нет! Требуется разгрузка!\n[РОБОТ] Критическое напряжение! Робот уходит на базу! "; 
        w+=1;
        a++;
    }
    else if (v<12.0 || v>14.5){
        std::cout << "[РОБОТ] Критическое напряжение! Робот уходит на базу! \n";
        a+=1;
    }
    else if (z > 95.0){
        std::cout << "[СКЛАД] Места нет! Требуется разгрузка! \n";
        w+=1;
    }

    else{
        std::cout << "[СИСТЕМА] Все узлы работают штатно\n";
    

    }
}

int main(){
    system("chcp 65001 -> nul");
    setlocale(LC_ALL, "ru_RU.UTF-8");

    bool is_running = true;
    float zapoln = 0;
    float volt = 0;
    unsigned short avars = 0;
    unsigned short warns = 0;
    int choise = 0;

    while (is_running){

    
        std::cout << "[РАБОТАЕТ] Система контроля роботизированного склада\n";
    
        std::cout << "заполненность склада (%): \n";
        std::cin >> zapoln;

        std::cout << "Напряжение робота (вольт): \n";
        std::cin >> volt;

        check (zapoln, volt, avars, warns);

        std::cout << "\n Всего аварий по роботу: ";
        std::cout << avars;
        std::cout << "\n Всего предупреждений по складу:";
        std::cout << warns;
        std::cout << "\n [1] Продолжить работу программы\n";
        std::cout << "[2] Остановить работу программы\n";
        std::cin >> choise;

        if (choise == 2){
            is_running = false;
            std::cout << "[ВЫКЛЮЧЕН] Система контроля роботизированного склада";
        }
    }



}