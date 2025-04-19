#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <windows.h>
#pragma execution_character_set("utf-8")
int main() {
    SetConsoleOutputCP(65001);
    std::cout << "======================================================================" << std::endl;
    std::cout << "Bài tập 1. Làm quen với C++ và Visual Studio.Net/Visual Studio Code" << std::endl;
    std::cout << "MSSV: 066206005044" << std::endl;
    std::cout << "Họ và tên: Hoàng Việt Quang" << std::endl;
    std::cout << "======================================================================" << std::endl;
    std::ifstream file("data.txt");
    if (!file.is_open()) {
        std::cerr << "Không thể mở file hoặc file không tồn tại!" << std::endl;
        return 1;
    }

    std::cout << "----------------------------------------------------------------------" << std::endl;

    std::string dong;
    int tongsodong = 0;
    int sodongbatdaubangdaugachngang = 0;
    std::string cacdongbatdaubangdaugachngang[100];

    while (std::getline(file, dong)) {
        tongsodong++;
        
        if (!dong.empty()) {
            if (tongsodong == 1 && dong.size() >= 3) {
                if ((unsigned char)dong[0] == 0xEF && 
                    (unsigned char)dong[1] == 0xBB && 
                    (unsigned char)dong[2] == 0xBF) {
                    dong.erase(0, 3);
                }
            }
            
            size_t vitrikytudautien = dong.find_first_not_of(" \t\r\n");
            if (vitrikytudautien != std::string::npos && dong[vitrikytudautien] == '-') {
                cacdongbatdaubangdaugachngang[sodongbatdaubangdaugachngang] = dong;
                sodongbatdaubangdaugachngang++;
            }
        }
    }

    std::cout << "Có " << tongsodong << " dòng trong file data.txt" << std::endl;
    std::cout << "Có " << sodongbatdaubangdaugachngang << " dòng bắt đầu bằng dấu gạch ngang:" << std::endl;
    for (int i = 0; i < sodongbatdaubangdaugachngang; i++) {
        std::cout << cacdongbatdaubangdaugachngang[i] << std::endl;
    }
    if (sodongbatdaubangdaugachngang == 0) {
        std::cout << "Không có dòng nào bắt đầu bằng dấu gạch ngang" << std::endl;
    }
    std::cout << "----------------------------------------------------------------------" << std::endl;
    file.close();
    return 0;
}
