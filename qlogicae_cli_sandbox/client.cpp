#include <nanobench.h>
#include <boost/process.hpp>
#include <boost/process/v2/process.hpp>
#include <boost/asio.hpp>
#include <windows.h>
#include <cstdio>
#include <string>
#include <future>

static void bench_createprocess() {
    STARTUPINFOW si{};
    PROCESS_INFORMATION pi{};
    si.cb = sizeof(si);

    std::wstring cmd = L"cmd.exe /c echo.";
    std::vector<wchar_t> cmd_buf(cmd.begin(), cmd.end());
    cmd_buf.push_back(0); // null terminator

    CreateProcessW(
        NULL,
        cmd_buf.data(), // writable buffer
        NULL,
        NULL,
        FALSE,
        CREATE_NO_WINDOW,
        NULL,
        NULL,
        &si,
        &pi
    );
}

static void bench_createprocess_fast() {
    static STARTUPINFOW si{};
    static PROCESS_INFORMATION pi{};
    si.cb = sizeof(si);

    static wchar_t cmd_buf[] = L"cmd.exe /c echo.";

    if (CreateProcessW(
        NULL,
        cmd_buf,
        NULL,
        NULL,
        FALSE,
        CREATE_NO_WINDOW | DETACHED_PROCESS,
        NULL,
        NULL,
        &si,
        &pi
    )) {
        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
    }
}

void boost_process()
{
    namespace bp = boost::process;

    bp::child c("cmd.exe", "/c", "echo Hello");
    c.wait();
}

static void bench_popen() {
    FILE* f = _popen("cmd /c echo.", "r");
    if (f) {
        char buffer[16];
        fgets(buffer, sizeof(buffer), f);
        _pclose(f);
    }
}

static void bench_system() {
    system("cmd /c echo.");
}

int main() {
    ankerl::nanobench::Bench()
        .warmup(1)
        .relative(true)
        .minEpochIterations(100)
        // .run("bench_createprocess_fast()", [] { bench_createprocess_fast(); })
        // .run("bench_createprocess()", [] { bench_createprocess(); })
        .run("boost_process()", [] { boost_process(); });
        // .run("popen()", [] { bench_popen(); });
}
