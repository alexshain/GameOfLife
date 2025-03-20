cmake_minimum_required(VERSION 3.29)

project(game_of_life LANGUAGES CXX)

# Стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Исполняемый файл с указанием исходных файлов
add_executable(game_of_life 
			src/main.cpp
			src/gameConfigReader.cpp
			src/commandLineParser.cpp
			src/model/gameState.cpp
			src/model/stateProcessor.cpp
			src/view/gameView.cpp 
			src/controller/gameController.cpp
			src/game_strategy/gameContext.cpp
			src/game_strategy/gameStrategy.cpp
			src/game_strategy/offlineStrategy.cpp
			src/game_strategy/onlineStrategy.cpp)
