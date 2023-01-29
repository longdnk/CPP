run:
	g++ -std=c++17 -Ofast -O2 -O3 -m64 -Wall -Wextra -march=native -finline-functions -funroll-loops -unroll-loops f.cpp -o f && start cmd /c f ^& echo. ^& pause