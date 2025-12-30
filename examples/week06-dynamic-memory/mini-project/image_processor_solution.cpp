/*
 * Mini-Project: Dynamic Image Processor (P2 Format) (Solution)
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Image {
    int** pixels;
    int width;
    int height;
    int maxVal;
};

bool loadImage(const string& filename, Image& img);
bool saveImage(const string& filename, const Image& img);
void freeImage(Image& img);
void printImage(const Image& img);
void invertImage(Image& img);
void flipHorizontal(Image& img);
void flipVertical(Image& img);

int main() {
    Image img = {nullptr, 0, 0, 0};

    cout << "=== PGM Image Processor ===" << endl << endl;

    string filename;
    cout << "Enter image filename (or 'sample' for built-in): ";
    cin >> filename;

    if (filename == "sample") {
        img.width = 8;
        img.height = 6;
        img.maxVal = 255;

        img.pixels = new int*[img.height];
        for (int r = 0; r < img.height; r++) {
            img.pixels[r] = new int[img.width];
        }

        for (int r = 0; r < img.height; r++) {
            for (int c = 0; c < img.width; c++) {
                img.pixels[r][c] = (r * img.width + c) * 5;
            }
        }

        cout << "Created sample 8x6 image." << endl;
    } else {
        if (!loadImage(filename, img)) {
            cerr << "Failed to load image." << endl;
            return 1;
        }
        cout << "Loaded " << img.width << "x" << img.height << " image." << endl;
    }

    cout << endl << "Original image:" << endl;
    printImage(img);

    int choice;
    do {
        cout << endl;
        cout << "1. Invert colors" << endl;
        cout << "2. Flip horizontal" << endl;
        cout << "3. Flip vertical" << endl;
        cout << "4. Show image" << endl;
        cout << "5. Save and quit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                invertImage(img);
                cout << "Image inverted." << endl;
                break;
            case 2:
                flipHorizontal(img);
                cout << "Image flipped horizontally." << endl;
                break;
            case 3:
                flipVertical(img);
                cout << "Image flipped vertically." << endl;
                break;
            case 4:
                printImage(img);
                break;
            case 5:
                cout << "Output filename: ";
                cin >> filename;
                if (saveImage(filename, img)) {
                    cout << "Saved to " << filename << endl;
                } else {
                    cout << "Failed to save." << endl;
                }
                break;
        }
    } while (choice != 5);

    freeImage(img);

    return 0;
}

bool loadImage(const string& filename, Image& img) {
    ifstream inFile(filename);
    if (!inFile) return false;

    string magic;
    inFile >> magic;
    if (magic != "P2") {
        cerr << "Not a P2 file!" << endl;
        return false;
    }

    inFile >> ws;
    while (inFile.peek() == '#') {
        inFile.ignore(1000, '\n');
        inFile >> ws;
    }

    inFile >> img.width >> img.height >> img.maxVal;
    if (!inFile || img.width <= 0 || img.height <= 0) {
        return false;
    }

    img.pixels = new int*[img.height];
    for (int r = 0; r < img.height; r++) {
        img.pixels[r] = new int[img.width];
    }

    for (int r = 0; r < img.height; r++) {
        for (int c = 0; c < img.width; c++) {
            if (!(inFile >> img.pixels[r][c])) {
                freeImage(img);
                return false;
            }
        }
    }

    inFile.close();
    return true;
}

bool saveImage(const string& filename, const Image& img) {
    ofstream outFile(filename);
    if (!outFile) return false;

    outFile << "P2" << endl;
    outFile << "# Created by Image Processor" << endl;
    outFile << img.width << " " << img.height << endl;
    outFile << img.maxVal << endl;

    int count = 0;
    for (int r = 0; r < img.height; r++) {
        for (int c = 0; c < img.width; c++) {
            outFile << img.pixels[r][c] << " ";
            count++;
            if (count % 12 == 0) {
                outFile << endl;
            }
        }
    }
    if (count % 12 != 0) {
        outFile << endl;
    }

    outFile.close();
    return true;
}

void freeImage(Image& img) {
    if (img.pixels != nullptr) {
        for (int r = 0; r < img.height; r++) {
            delete[] img.pixels[r];
        }
        delete[] img.pixels;
        img.pixels = nullptr;
    }
}

void printImage(const Image& img) {
    for (int r = 0; r < img.height; r++) {
        for (int c = 0; c < img.width; c++) {
            cout << img.pixels[r][c];
            if (c < img.width - 1) cout << "\t";
        }
        cout << endl;
    }
}

void invertImage(Image& img) {
    for (int r = 0; r < img.height; r++) {
        for (int c = 0; c < img.width; c++) {
            img.pixels[r][c] = img.maxVal - img.pixels[r][c];
        }
    }
}

void flipHorizontal(Image& img) {
    for (int r = 0; r < img.height; r++) {
        for (int c = 0; c < img.width / 2; c++) {
            int temp = img.pixels[r][c];
            img.pixels[r][c] = img.pixels[r][img.width - 1 - c];
            img.pixels[r][img.width - 1 - c] = temp;
        }
    }
}

void flipVertical(Image& img) {
    for (int r = 0; r < img.height / 2; r++) {
        int* temp = img.pixels[r];
        img.pixels[r] = img.pixels[img.height - 1 - r];
        img.pixels[img.height - 1 - r] = temp;
    }
}
