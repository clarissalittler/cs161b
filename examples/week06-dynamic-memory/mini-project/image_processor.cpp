/*
 * Mini-Project: Dynamic Image Processor (P2 Format)
 *
 * Load, manipulate, and save grayscale images in PGM (P2) format.
 * This demonstrates dynamic 2D arrays with real-world data.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Image structure
struct Image {
    int** pixels;    // 2D dynamic array
    int width;
    int height;
    int maxVal;
};

// Function prototypes
bool loadImage(const string& filename, Image& img);
bool saveImage(const string& filename, const Image& img);
void freeImage(Image& img);
void printImage(const Image& img);

// Image operations
void invertImage(Image& img);
void flipHorizontal(Image& img);
void flipVertical(Image& img);

int main() {
    Image img = {nullptr, 0, 0, 0};

    cout << "=== PGM Image Processor ===" << endl << endl;

    // Try to load the test image
    string filename;
    cout << "Enter image filename (or 'sample' for built-in): ";
    cin >> filename;

    if (filename == "sample") {
        // Create a sample image programmatically
        img.width = 8;
        img.height = 6;
        img.maxVal = 255;

        // Allocate
        img.pixels = new int*[img.height];
        for (int r = 0; r < img.height; r++) {
            img.pixels[r] = new int[img.width];
        }

        // Fill with a gradient pattern
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

    // Menu loop
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

    // Clean up
    freeImage(img);

    return 0;
}

// TODO: Implement loadImage
// P2 format:
//   P2
//   # optional comment lines (start with #)
//   width height
//   maxval
//   pixel values (space/newline separated)
bool loadImage(const string& filename, Image& img) {
    ifstream inFile(filename);
    if (!inFile) return false;

    string magic;
    inFile >> magic;
    if (magic != "P2") {
        cerr << "Not a P2 file!" << endl;
        return false;
    }

    // Skip comments
    char ch;
    inFile >> ws;  // Skip whitespace
    while (inFile.peek() == '#') {
        inFile.ignore(1000, '\n');
    }

    // Read dimensions
    inFile >> img.width >> img.height >> img.maxVal;

    // TODO: Allocate the 2D array
    // img.pixels = new int*[img.height];
    // for each row, allocate img.width integers


    // TODO: Read the pixel values
    // for each row and column, read a pixel value


    inFile.close();
    return true;
}

// TODO: Implement saveImage
bool saveImage(const string& filename, const Image& img) {
    ofstream outFile(filename);
    if (!outFile) return false;

    // Write header
    outFile << "P2" << endl;
    outFile << "# Created by Image Processor" << endl;
    outFile << img.width << " " << img.height << endl;
    outFile << img.maxVal << endl;

    // TODO: Write pixel values
    // Write all pixels, maybe 10-12 per line for readability


    outFile.close();
    return true;
}

// Free the dynamic memory
void freeImage(Image& img) {
    if (img.pixels != nullptr) {
        for (int r = 0; r < img.height; r++) {
            delete[] img.pixels[r];
        }
        delete[] img.pixels;
        img.pixels = nullptr;
    }
}

// Display the image as numbers
void printImage(const Image& img) {
    for (int r = 0; r < img.height; r++) {
        for (int c = 0; c < img.width; c++) {
            cout << img.pixels[r][c];
            if (c < img.width - 1) cout << "\t";
        }
        cout << endl;
    }
}

// TODO: Implement invertImage
// Each pixel becomes: maxVal - currentVal
void invertImage(Image& img) {
    // TODO: Loop through all pixels and invert them

}

// TODO: Implement flipHorizontal
// Swap left and right sides
void flipHorizontal(Image& img) {
    // TODO: For each row, swap pixels[r][c] with pixels[r][width-1-c]

}

// TODO: Implement flipVertical
// Swap top and bottom
void flipVertical(Image& img) {
    // TODO: Swap entire rows: swap pixels[r] with pixels[height-1-r]

}

/*
 * Hints:
 *
 * loadImage allocation:
 *   img.pixels = new int*[img.height];
 *   for (int r = 0; r < img.height; r++) {
 *       img.pixels[r] = new int[img.width];
 *   }
 *
 * loadImage reading:
 *   for (int r = 0; r < img.height; r++) {
 *       for (int c = 0; c < img.width; c++) {
 *           inFile >> img.pixels[r][c];
 *       }
 *   }
 *
 * saveImage writing:
 *   int count = 0;
 *   for (int r = 0; r < img.height; r++) {
 *       for (int c = 0; c < img.width; c++) {
 *           outFile << img.pixels[r][c] << " ";
 *           if (++count % 12 == 0) outFile << endl;
 *       }
 *   }
 *
 * invertImage:
 *   img.pixels[r][c] = img.maxVal - img.pixels[r][c];
 *
 * flipHorizontal:
 *   int temp = img.pixels[r][c];
 *   img.pixels[r][c] = img.pixels[r][img.width - 1 - c];
 *   img.pixels[r][img.width - 1 - c] = temp;
 *   (Only go to width/2 to avoid double-swapping!)
 *
 * flipVertical:
 *   int* temp = img.pixels[r];
 *   img.pixels[r] = img.pixels[img.height - 1 - r];
 *   img.pixels[img.height - 1 - r] = temp;
 *   (Only go to height/2!)
 */
