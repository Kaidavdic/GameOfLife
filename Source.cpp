#include <SDL.h>
#include <vector>
#include <string>
#include <iostream>

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;
const int CELL_SIZE = 10;

std::vector<std::vector<int>> parseStringToVector(std::string str) {
    std::vector<std::vector<int>> result;
    std::vector<int> row;

    for (char c : str) {
        if (c == ' ' || c == '\r') {
            continue;
        }
        else if (c == '#') {
            row.push_back(0);
        }
        else if (c == '1') {
            row.push_back(1);
        }
        else if (c == '\n') {
            result.push_back(row);
            row.clear();
        }
    }

    if (!row.empty()) {
        result.push_back(row);
    }

    return result;
}


void displayMatrix(const std::vector<std::vector<int>>& matrix, SDL_Renderer* renderer);
std::string tabela =
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 1 # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 1 1 # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 1 # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # 1 # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # 1 # 1 1 # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # 1 # 1 # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # 1 # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # 1 # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # 1 # 1 # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n"
"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n";




void simulateGeneration(std::vector<std::vector<int>>& currentGen, SDL_Renderer* renderer) {
    int numRows = currentGen.size();
    int numCols = currentGen[0].size();
    std::vector<std::vector<int>> nextGen(numRows, std::vector<int>(numCols, 0));

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            int numLiveNeighbors = 0;
            for (int ni = i - 1; ni <= i + 1; ni++) {
                for (int nj = j - 1; nj <= j + 1; nj++) {
                    if (ni == i && nj == j) {
                        continue;
                    }
                    int neighborRow = (ni + numRows) % numRows;
                    int neighborCol = (nj + numCols) % numCols;
                    numLiveNeighbors += currentGen[neighborRow][neighborCol];
                }
            }
            if (currentGen[i][j] == 1 && (numLiveNeighbors == 2 || numLiveNeighbors == 3)) {
                nextGen[i][j] = 1;
            }
            else if (currentGen[i][j] == 0 && numLiveNeighbors == 3) {
                nextGen[i][j] = 1;
            }
        }
    }

    displayMatrix(nextGen, renderer);

    currentGen = nextGen;
}
int main(int argc, char* argv[]) {

    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS);

    SDL_Window* window = SDL_CreateWindow("Conway's Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    std::vector<std::vector<int>> currentGen(75, std::vector<int>(75, 0));
    currentGen = parseStringToVector(tabela);

    bool gotov=false;
    displayMatrix(currentGen, renderer);
    SDL_Event event;
    while(!gotov)
    {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
            break;
        SDL_Delay(50); 
        simulateGeneration(currentGen, renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
void displayMatrix(const std::vector<std::vector<int>>& matrix, SDL_Renderer* renderer) {

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 1) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            }
            else {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            }
            SDL_Rect rect = { j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE };
            SDL_RenderFillRect(renderer, &rect);
        }
    }

    SDL_RenderPresent(renderer);
}
