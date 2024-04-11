#include <stdio.h>
#include <windows.h>
#include <winerror.h>
int main()
{
    DWORD actlen;
    char buf[100] = "";
    char filename[] = "file.txt"; 
    HANDLE hfile, hstdout;
    COORD cord;
    
    printf("Hello!\n");
    printf("Lab 3: Multiusers block files\n");

    cord.X = 23;
    cord.Y = 10;
    hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hstdout == INVALID_HANDLE_VALUE) {
        printf("Error output handle");
        return 0;
    }
    SetConsoleCursorPosition(hstdout, cord);
    SetConsoleTextAttribute(hstdout, FOREGROUND_RED);

    while ((hfile = CreateFile(L"file.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0)) == INVALID_HANDLE_VALUE) {
        if (GetLastError() == ERROR_FILE_NOT_FOUND) {
            printf("File doesn't exist\n");
            getsher();
            return 0;
        }
        printf("Permission denied. Somebody used executed file. Please wait… Be patient\n"); 
        system("cls");
    };
    if (hfile == INVALID_HANDLE_VALUE)
    {
    printf("Invalid handle hfile");
    }
    SetConsoleCursorPosition(hstdout, cord); 
    SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN); 
    ReadFile(hfile, buf, 40, &actlen, NULL);
    
    printf("%s", buf);
    getchar();
    CloseHandle(hfile);
    return 0;
}