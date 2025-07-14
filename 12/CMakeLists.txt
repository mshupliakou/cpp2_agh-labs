# ============================================================================
# 📦 CMakeLists.txt — Szablon edukacyjny z komentarzami i flagami
# ============================================================================

cmake_minimum_required(VERSION 3.10)
project(template_project LANGUAGES CXX)

# ============================================================================
# 🎛️ OPCJE UŻYTKOWNIKA (ustawiane przy konfiguracji, np. cmake .. -DDEBUG_MODE=ON)
# ============================================================================
option(COMPILATION_ISSUE "Enable artificial compilation issue (for testing)" OFF)
option(DEBUG_MODE "Enable debug logging code" OFF)

# ============================================================================
# 🛑 ZABEZPIECZENIE przed budowaniem w katalogu źródłowym
# ============================================================================
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)

if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(SEND_ERROR "🛑 Nie buduj w katalogu źródłowym! Użyj mkdir build && cd build && cmake ..")
endif()

# ============================================================================
# 🧠 WYBÓR STANDARDU C++ I FLAGR KOMPILATORA
# ============================================================================
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # Bez GNU extensions typu gnu++17

# Przykładowe flagi (Debug/Release mogą być nadpisane przez -DCMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE Debug)

# Flagi domyślne (Debug / Release)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall -Wextra -pedantic -g")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-O2 -Wall")

# ============================================================================
# 📁 STRUKTURA KATALOGÓW PROJEKTU
# ============================================================================
# include/ zawiera nagłówki, src/ zawiera źródła
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")

# Dodaj katalog nagłówków do include paths
include_directories(${INCLUDE_DIR})

# Zbieramy wszystkie pliki .cpp w katalogu src/
file(GLOB SOURCES "${SOURCE_DIR}/*.cpp")

# ============================================================================
# 🔨 TWORZENIE PROGRAMU WYKONYWALNEGO
# ============================================================================
add_executable(${PROJECT_NAME}
    Main.cpp
    ${SOURCES}
)

# ============================================================================
# 📌 FLAGI KOMPILATORA — MANUALNE DODAWANIE
# ============================================================================
# Możemy ręcznie dodać dowolne flagi:
target_compile_options(${PROJECT_NAME} PRIVATE
    # zawsze dołącz te ostrzeżenia
    -Wall -Wextra -pedantic

    # opcjonalnie inne, zależnie od build type
    $<$<CONFIG:Debug>:-DDEBUG_BUILD=1>
    $<$<CONFIG:Release>:-DNDEBUG>
)

# ============================================================================
# 🔖 WŁASNE DEFINE Z PODSTAWIENIEM ŚCIEŻKI
# ============================================================================
# Dodajemy flagę kompilatora PROJECTPATH="..." jako string
target_compile_definitions(${PROJECT_NAME} PRIVATE
    PROJECTPATH="${PROJECT_SOURCE_DIR}"
)

# W kodzie źródłowym:
#   std::cout << "Project root: " << PROJECTPATH << "\n";

# ============================================================================
# 💡 WARUNKOWE DEFINICJE Z OPCJI KONFIGURACYJNYCH
# ============================================================================
if(COMPILATION_ISSUE)
    target_compile_definitions(${PROJECT_NAME} PRIVATE COMPILATION_ISSUE=1)
endif()

if(DEBUG_MODE)
    target_compile_definitions(${PROJECT_NAME} PRIVATE DEBUG_MODE=1)
endif()

# ============================================================================
# 🧪 PRZYKŁADOWE UŻYCIE OPCJI W KODZIE C++:
# ============================================================================
# #ifdef DEBUG_MODE
#     std::cerr << "Debug info enabled!\n";
# #endif
#
# #ifdef COMPILATION_ISSUE
#     static_assert(false, "Ta linia wymusza błąd kompilacji");
# #endif

# ============================================================================
# 🛠️ PRZYKŁADOWA KONFIGURACJA W TERMINALU
# ============================================================================
# mkdir build
# cd build
# cmake .. -G Ninja -DDEBUG_MODE=ON -DCMAKE_BUILD_TYPE=Release
# cmake --build .
# ./template_project
# ============================================================================

