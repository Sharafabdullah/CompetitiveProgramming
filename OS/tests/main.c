#include <windows.h>
#include <stdio.h>

int main() {
    printf("Before Loop\n");
    int n = 3;

    for (int i = 0; i <= n; i++) {
        PROCESS_INFORMATION processInfo;
        STARTUPINFO startupInfo;
        ZeroMemory(&startupInfo, sizeof(startupInfo));
        startupInfo.cb = sizeof(startupInfo);
        ZeroMemory(&processInfo, sizeof(processInfo));

        // Create a new process
        if (CreateProcess(NULL, // No module name
                          "child_process.exe", // Command to execute
                          NULL, NULL, FALSE, 0, NULL, NULL, &startupInfo, &processInfo)) {
            printf("Inside Loop\n");
            // Close process handles
            CloseHandle(processInfo.hProcess);
            CloseHandle(processInfo.hThread);
        } else {
            printf("Failed to create process.\n");
        }

        if (i == n) break;
    }

    printf("After Loop\n");
    return 0;
}
