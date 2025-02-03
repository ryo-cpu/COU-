#include <iostream>
#include<Windows.h>
#include <thread>
#include <chrono>

int main()
{

    // カウントダウンの開始値
    int countdown;
    std::cin >> countdown;
    const HANDLE hConsloe = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX info = { sizeof info };
    info.dwFontSize.X = 12;
    info.dwFontSize.Y = 27;
    SetCurrentConsoleFontEx(hConsloe, 0, &info);


    while (countdown >= 0) {
        // 行の先頭にカーソルを戻し、行をクリアする
        std::cout << "\r\033[Kカウントダウン: " << countdown << std::flush;  // 行をクリアしてから出力

        // 1秒待つ
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // カウントを減らす
        countdown--;
    }
    // 周波数（Hz）
    DWORD frequency = 440; // 音の高さ（440HzはA4の音）
    // 継続時間（ミリ秒）
    DWORD duration = 1000; // 1秒間音を出す

    // Beep関数を使用して音を出す
    Beep(frequency, duration);


    // 最後に改行を出力して行を終わらせる
    std::cout << std::endl;
    return 0;
}