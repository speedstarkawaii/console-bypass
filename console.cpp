// warning: read license or ill come after u 👍

typedef struct _PEB {
    BYTE Reserved1[2];
    BYTE BeingDebugged;
    BYTE Reserved2[1];
    PVOID Reserved3[2];
    PVOID Ldr;
    PVOID ProcessParameters;
} PEB;

typedef struct _RTL_USER_PROCESS_PARAMETERS {
    BYTE Reserved1[16];
    HANDLE ConsoleHandle;
} RTL_USER_PROCESS_PARAMETERS;

PEB* GetCurrentPeb() {
    PEB* peb = nullptr;
    peb = (PEB*)__readgsqword(0x60);  
    return peb;
}

void inject(){
  // do console mods
   AllocConsole();
  // now do not touch while it turns off
  PEB* peb = GetCurrentPeb();
if (peb != nullptr && peb->ProcessParameters != nullptr) {
    RTL_USER_PROCESS_PARAMETERS* pm = (RTL_USER_PROCESS_PARAMETERS*)peb->ProcessParameters;

    pm->ConsoleHandle = 0;
}
else {
}
}
