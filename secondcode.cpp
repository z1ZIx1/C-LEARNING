#include <iostream>

void Checksens(float t, float p, int& alarms, int& warnings){
    if (p > 4.5f || t > 110.0f){
        std::cout << "\n[АВАРИЯ!]СБРОС ПОКАЗАТЕЛЕЙ\n";
        alarms++;
    }
    else if  (p < 0.5) {
        std::cout << "\n[ПРЕДУПРЕЖДЕНИЕ] ДАВЛЕНИЕ УПАЛО\n";
        warnings+=1;
    }
    else{
        std::cout << "\nВсе четко\n";
    }
}


int main(){
    system("chcp 65001 -> nul");
    setlocale(LC_ALL, "ru_RU.UTF-8");

    float temp = 0.0f;
    float pres = 0.0f;
    bool is_running = true;
    int choise = 0;
    int countA = 0;
    int countD = 0;
    
    while (is_running){
        std::cout << "\n--- Мониторинг(активен)---\n";

        std::cout << "Введите температуру:\n";
        std::cin>> temp;
        
        std::cout << "Введите давление(бар)\n";
        std::cin >> pres;

        Checksens(temp, pres, countA, countD);
    
        std::cout << "Всего аварий: ";
        std::cout << countA;
        std::cout << "\nВсего предупреждений: ";
        std::cout << countD;
        std::cout << "\n[1] Продолжить мониторинг\n";
        std::cout << "\n[2] Выключить мониторинг\n";
        std::cout << "Выбор:";
        std::cin >> choise;

        if (choise == 2){
        is_running = false;
        }
    }

    std::cout << "\nСистема асу успешно обновлена! До связи.\n";

    return 0;



}