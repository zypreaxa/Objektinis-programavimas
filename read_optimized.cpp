#include "fun.h"

void show_loading_indicator(std::atomic_bool& loading) //function for displaying a spinning loading indicator (requires threads to use).
{
    int counter = 0;
    while (loading)
    {
        switch (counter % 4) {
        case 0:
            std::cout << "\r- Working on it... -";
            break;
        case 1:
            std::cout << "\r\\ Working on it... \\";
            break;
        case 2:
            std::cout << "\r| Working on it... |";
            break;
        case 3:
            std::cout << "\r/ Working on it... /";
            break;
        }

        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(250));

        counter++;
    }
}

void progress_bar() {
    const int barWidth = 70;
    int progress = 0;

    std::cout << "[          ] 0%" << std::flush;
    std::cout << "\r[" << std::flush;

    while (progress < 100) {
        progress++;
        int pos = barWidth * progress / 100;
        for (int i = 0; i < barWidth; i++) {
            if (i < pos) {
                std::cout << "=" << std::flush;
            }
            else if (i == pos) {
                std::cout << ">" << std::flush;
            }
            else {
                std::cout << " " << std::flush;
            }
        }
        std::cout << "] " << progress << "%" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    std::cout << std::endl;
}


