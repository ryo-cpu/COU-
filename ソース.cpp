#include <iostream>
#include<Windows.h>
#include <thread>
#include <chrono>

int main()
{

    // �J�E���g�_�E���̊J�n�l
    int countdown;
    std::cin >> countdown;
    const HANDLE hConsloe = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX info = { sizeof info };
    info.dwFontSize.X = 12;
    info.dwFontSize.Y = 27;
    SetCurrentConsoleFontEx(hConsloe, 0, &info);


    while (countdown >= 0) {
        // �s�̐擪�ɃJ�[�\����߂��A�s���N���A����
        std::cout << "\r\033[K�J�E���g�_�E��: " << countdown << std::flush;  // �s���N���A���Ă���o��

        // 1�b�҂�
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // �J�E���g�����炷
        countdown--;
    }
    // ���g���iHz�j
    DWORD frequency = 440; // ���̍����i440Hz��A4�̉��j
    // �p�����ԁi�~���b�j
    DWORD duration = 1000; // 1�b�ԉ����o��

    // Beep�֐����g�p���ĉ����o��
    Beep(frequency, duration);


    // �Ō�ɉ��s���o�͂��čs���I��点��
    std::cout << std::endl;
    return 0;
}