#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string **file_scan(int fileCount, char const *files[])
{
    ifstream fin;
    string **file = new string *[fileCount - 1];

    for (int i = 1; i < fileCount; i++)
    {
        int linesCount = 0;
        fin.open(files[i]);

        // 파일 여는데 실패했을 경우 처리
        if (!fin.is_open())
        {
            cerr << "Error opening file: " << files[i] << endl;
            // 실패한 파일에 대한 메모리는 해제
            for (int k = 0; k < i - 1; k++)
            {
                delete[] file[k];
            }
            delete[] file;
            return nullptr;
        }

        string line;
        while (getline(fin, line))
            linesCount++;

        fin.clear();
        fin.seekg(0, ios::beg);

        file[i - 1] = new string[linesCount];

        int j = 0;
        while (getline(fin, line))
        {
            file[i - 1][j++] = line;
        }

        fin.close();
    }

    return file;
}

int *line_count(int fileCount, char const *files[])
{
    int *lineCounts = new int[fileCount - 1];

    for (int i = 0; i < fileCount - 1; i++)
    {
        int linesCount = 0;
        ifstream fin(files[i + 1]);

        // 파일 여는데 실패했을 경우 처리
        if (!fin.is_open())
        {
            cerr << "Error opening file: " << files[i + 1] << endl;
            // 실패한 파일에 대한 메모리는 해제
            delete[] lineCounts;
            return nullptr;
        }

        string line;
        while (getline(fin, line))
            linesCount++;
        lineCounts[i] = linesCount;
        fin.close();
    }

    return lineCounts;
}

bool scan_error(string **file, int *lineCounts, int fileCount) {
    if (file == nullptr)
    {
        return true; // 파일 열기 실패로 프로그램 종료
    }

    if (lineCounts == nullptr)
    {
        // lineCounts가 nullptr이면 어떤 파일이든 열기 실패
        // 메모리를 할당했으면 해제해주어야 함
        for (int i = 0; i < fileCount - 1; i++)
        {
            delete[] file[i];
        }
        delete[] file;
        return true;
    }
}

void print_file(string **file, int *lineCounts, int fileCount)
{
    for (int i = 0; i < fileCount - 1; i++)
    {
        for (int j = 0; j < lineCounts[i]; j++)
        {
            cout << file[i][j] << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    string **file = file_scan(argc, argv);
    int *lineCounts = line_count(argc, argv);

    if (scan_error(file, lineCounts, argc)) return 1;

    print_file(file, lineCounts, argc);

    for (int i = 0; i < argc - 1; i++)
        delete[] file[i];
    delete[] file;
    delete[] lineCounts;

    return 0;
}
