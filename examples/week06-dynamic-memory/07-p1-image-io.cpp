/*
 * 07-p1-image-io.cpp
 * Reading and writing a P1 (PBM) image using a dynamic 2D array.
 *
 * To extend this to P3:
 * - Read three values per pixel (r, g, b) instead of one.
 * - Store them in a Pixel struct with red/green/blue fields.
 * - Write three values per pixel when saving.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool readToken(ifstream& inFile, string& token) {
    while (inFile >> token) {
        if (!token.empty() && token[0] == '#') {
            string rest;
            getline(inFile, rest);
            continue;
        }
        return true;
    }
    return false;
}

int** createImage(int rows, int cols) {
    int** image = new int*[rows];
    for (int r = 0; r < rows; r++) {
        image[r] = new int[cols];
    }
    return image;
}

void deleteImage(int** image, int rows) {
    for (int r = 0; r < rows; r++) {
        delete[] image[r];
    }
    delete[] image;
}

bool loadP1(const string& filename, int**& image, int& rows, int& cols) {
    ifstream inFile(filename.c_str());
    if (!inFile) {
        return false;
    }

    string token;
    if (!readToken(inFile, token) || token != "P1") {
        return false;
    }

    if (!readToken(inFile, token)) return false;
    cols = stoi(token);
    if (!readToken(inFile, token)) return false;
    rows = stoi(token);

    image = createImage(rows, cols);

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (!readToken(inFile, token)) {
                deleteImage(image, rows);
                image = nullptr;
                return false;
            }
            image[r][c] = stoi(token);
        }
    }

    return true;
}

bool saveP1(const string& filename, int** image, int rows, int cols) {
    ofstream outFile(filename.c_str());
    if (!outFile) {
        return false;
    }

    outFile << "P1" << endl;
    outFile << cols << " " << rows << endl;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            outFile << image[r][c] << " ";
        }
        outFile << endl;
    }

    return true;
}

void invertImage(int** image, int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            image[r][c] = 1 - image[r][c];
        }
    }
}

int main() {
    int** image = nullptr;
    int rows = 0;
    int cols = 0;

    if (!loadP1("data/input.pbm", image, rows, cols)) {
        cerr << "Could not read data/input.pbm" << endl;
        cerr << "Create a small P1 file in data/ first." << endl;
        return 1;
    }

    invertImage(image, rows, cols);

    if (!saveP1("data/output.pbm", image, rows, cols)) {
        cerr << "Could not write data/output.pbm" << endl;
        deleteImage(image, rows);
        return 1;
    }

    deleteImage(image, rows);
    cout << "Wrote data/output.pbm" << endl;

    return 0;
}
