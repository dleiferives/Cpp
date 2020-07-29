//Dylan Leifer-Ives Jul 29 2020. Given an imput like XX:XX:XXAM or the pm varient it will translate it to millatary or 24 hour time.
#include<iostream>
#include<string>

int main() {
    std::string s;

    std::cin >> s; 

    int h = std::stoi(s.substr(0));
    int m = std::stoi(s.substr(3));
    int sec = std::stoi(s.substr(6));
    bool thanos;
    if(s.substr(8,2) == "PM")
        h +=12;
        if (h == 24)
            h = 12;
    else {
        if(h==12)
            h = 0;
    }

    if (h < 10)
        std::cout << "0" << h;
    else {
        std::cout << h;
    }
    std::cout << ":";
    if (m < 10)
        std::cout << "0" << m;
    else {
        std::cout << m;
    }
    std::cout << ":";
    if (sec < 10)
        std::cout << "0" << sec;
    else {
        std::cout << sec;
    }


    std::cout << std::endl;

    return 0;
}
