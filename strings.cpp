#include <iostream>
#include <string>

int main(){
    system("chcp 65001 -> nul");
    setlocale(LC_ALL, "ru_RU.UTF-8");

    //СОЗДАЕМ СТРОКОВУЮ ПЕРЕМЕННУЮ ДЛЯ КОМАНД ОПЕРАТОРА
    std::string command ="";
    bool is_running = true;
    std::cout << "\n---СИСТЕМА УПРАВЛЕНИЯ КОНВЕЙЕРОМ---\n";
    std::cout << "Доступные команды: START, STATUS, STOP\n";

    while (is_running){
        std::cout << "Введите команду:";
        std::cin >> command;

        if (command == "START"){
            std::cout << "[СИСТЕМА] Конвейер запущен! Двигатели на полную.\n";

        }

        else if(command == "STOP"){
            is_running=false;
            std::cout << "[СИСТЕМА] Внимание! Аварийная остановка конвейера.\n";
        }

        else if(command == "STATUS"){
            std::cout << "[СИСТЕМА] Все узлы работают в штатном режиме, перегрева нет.\n";
            
        }

        else{
            std::cout << "[ОШИБКА] Команда " << command << " не распознана\n";
        }

    }
    
    std::cout << "\nПрограмма завершена. Панель управления отключена.\n";
    return 0;
}

