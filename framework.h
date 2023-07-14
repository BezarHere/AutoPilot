#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>

#define peek(p) std::cout << #p << ": " << (p) << '\n'
#define print(p) std::cout << (p) << '\n'
#define printe(p) std::cout << (#p) << '\n'
