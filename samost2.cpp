#include <iostream>
#include <cstdlib>

void check(float voltage, unsigned short robot_id, unsigned short& alarms){
    if(voltage < 12.5f || voltage > 14.5f){
        std::cout << "[Авария] Робот №" << robot_id << " Имеет критическое значение напряжения " << voltage << "В!\n";
        alarms++;
    }
    else{
        std::cout << "[ЧЕТКОСТЬ] Робот №" << robot_id << " Имеет допустимое значение напряжения " << voltage << "В\n";
    }

}

int main(){
    system("chcp 65001 -> nul");
    setlocale(LC_ALL, "ru_RU.UTF-8");

    bool is_running = true;
    srand(time(0));
    float volt[100]={};
    short choise = 0;
    unsigned short alarms = 0;

    while(is_running){
        std::cout << "\n--- СИСТЕМА МОНИТОРИНГА РОБОТОВ ---\n";
       
        for(unsigned short i=0; i<100; i++){
            float random_volt = 10.0f + (rand()%61)/10.0f;
            volt[i]=random_volt;
        }
        for(unsigned short i=0; i<100; i++){
            check(volt[i], i+1, alarms);
        }


        std::cout << "Всего аварий:" << alarms << std::endl;
        std::cout << "[1]Повторить опрос линий\n";
        std::cout << "[2]Закончить опрос линий\n";
        std::cin >> choise;
        if(choise == 2){
            is_running=false;
        }
    }
    return 0;
}