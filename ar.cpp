#include <iostream>

void check(unsigned short robot_id, float voltage, unsigned short& alarms ){
    if (voltage < 12.0f || voltage > 14.5f){
        std::cout << "[АВАРИЯ] Робот №" << robot_id << " Имеет критическое напряжение " << voltage << "B!\n";
        alarms++;
    
    }
    else {
        std::cout << "[ОК] Робот №"<<robot_id<< " работает штатно (" << voltage << "B).\n";

    }
}

int main (){
    system("chcp 65001 -> nul");
    setlocale(LC_ALL, "ru_RU.UTF-8");

    bool is_running = true;
    unsigned short total_alarms = 0;
    unsigned short choise = 0;

    float robot_volts[3] = {0.0f, 0.0f, 0.0f};

    while (is_running){
        std::cout << "\n--- СИСТЕМА МОНИТОРИНГА РОБОТОВ ---\n";
        for (unsigned short i = 0; i<3; i++ ){
            std::cout << "Введите напряжение для робота №" << i + 1 << ":";
            std::cin >> robot_volts[i];
        }
        
        std::cout << "\n--- РЕЗУЛЬТАТЫ ПРОВЕРКИ ЛИНИИ ---\n";

        for (unsigned short i = 0; i < 3; i++){
            check(i+1, robot_volts[i], total_alarms);

        }

        std::cout << "\nВсего аварий на линии за все время:" << total_alarms << "\n";

        std::cout << "\n[1] Повторить опрос линий\n";
        std::cout << "[2] Выключить систему\n";
        std::cout << "Выбор:";
        std::cin >> choise;

        if (choise == 2){
            is_running=false;
        }



    }
    return 0;
}