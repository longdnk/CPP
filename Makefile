run:
	g++ -std=c++17 -Ofast -O2 -O3 -m64 -Wall -Wextra -march=native -finline-functions -funroll-loops -unroll-loops new.cpp -o new && start cmd /c new ^& echo. ^& pause
