#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {

    ifstream file("synthetic_sort_data.csv");
    if (!file.is_open()) {
        cout << "Cannot open file.\n";
        return 1;
    }

    string line;

    // ===============================
    // 1. ĐỌC HEADER
    // ===============================
    getline(file, line);
    stringstream headerStream(line);

    const int MAX_COL = 50;
    string headers[MAX_COL];

    int colCount = 0;
    string cell;

    while (getline(headerStream, cell, ',')) {
        headers[colCount++] = cell;
    }

    // ===============================
    // 2. ĐẾM SỐ DÒNG
    // ===============================
    int rowCount = 0;
    while (getline(file, line)) {
        rowCount++;
    }

    file.close();

    // ===============================
    // 3. CẤP PHÁT MẢNG 2 CHIỀU
    // ===============================
    double** data = new double*[colCount];
    for (int i = 0; i < colCount; i++) {
        data[i] = new double[rowCount];
    }

    // ===============================
    // 4. ĐỌC LẠI FILE
    // ===============================
    file.open("synthetic_sort_data.csv");
    getline(file, line); // bỏ header

    int r = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        int c = 0;

        while (getline(ss, cell, ',')) {
            if (!cell.empty())
                data[c][r] = stod(cell);
            c++;
        }
        r++;
    }

    file.close();

    // ===============================
    // 5. SORT & ĐO THỜI GIAN
    // ===============================
    ofstream out("cpp_sort_results.csv");
    out << "Dataset,CPP_sort_ms\n";

    for (int i = 0; i < colCount; i++) {

        // copy sang mảng tạm
        double* temp = new double[rowCount];
        for (int j = 0; j < rowCount; j++)
            temp[j] = data[i][j];

        auto start = high_resolution_clock::now();

        sort(temp, temp + rowCount);

        auto end = high_resolution_clock::now();

        double duration =
            duration_cast<milliseconds>(end - start).count();

        out << headers[i] << "," << duration << "\n";

        cout << "Sorted: " << headers[i] << endl;

        delete[] temp;
    }

    out.close();

    // ===============================
    // 6. GIẢI PHÓNG BỘ NHỚ
    // ===============================
    for (int i = 0; i < colCount; i++) {
        delete[] data[i];
    }
    delete[] data;

    return 0;
}
