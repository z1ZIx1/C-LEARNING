#include <iostream>
#include <string>


void check(float p, unsigned short& warnings, unsigned short& avar){
    if (p>6.5f){
        std::cout << "[КРИТИЧЕСКИ] Избыточное давление! Гидроудар! Снижаю обороты." << std::endl;
        avar++;
    }

    else if (p<1.5f){
        std::cout << "[ВНИМАНИЕ] Давление упало ниже нормы! Возможен сухой ход!";
        warnings++;
    }

    else{
        std::cout << "Система работает в норме";
    }
}

int main(){
    setlocale(LC_ALL, "ru_RU.UTF-8");

    float pressure = 0.0f;
    unsigned short warn = 0;
    unsigned short avar = 0;
    std::string command = "";
    bool is_launch = true;
    bool is_running = false;
    bool choise = true;

    while (is_launch){
        std::cout << "\n---Пульт насосной станции готов к работе. Опрос датчиков отключен.---\n";
        std::cout << "Для старта системы введите LAUNCH:";
        std::cin >> command;

        if(command == "LAUNCH"){
            is_running = true;
            std::cout << "\n[СИСТЕМА] Насос запущен. Переход в режим непрерывного мониторинга." << std::endl;
            is_launch=false;
        }   
    }        

    while (is_running){
        choise=true;
        std::cout << "\nВведите значение давления воды(бар):";
        std::cin >> pressure;

        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(10000, '\n');

            std::cout << "[ОШИБКА] Введены некорректные символы! Введиче число в барах.";
            continue;
        }
        check(pressure, warn, avar);
                
    
        std::cout << "\nВсего аварий:" << avar << std::endl << "Всего предупреждений:" << warn;
        while(choise){
            std::cout << "\n[NEXT] - ПРОДОЛЖИТЬ МОНИТОРИНГ\n[SHUTDOWN] - Выключить программу\nВведите команду:";
            std::cin >> command;
            if (command == "SHUTDOWN"){
                is_running = false;
                choise=false;
                std::cout << "\nРежим мониторинга выключен";
                }
            else if(command == "NEXT"){
                choise=false;
            }
            else{
                std::cout << "Команда " << command << " не распознана. Введите команду еще раз\n";
            }
        }
}     
       
    return 0;
}


