#include "Application.h"

extern xse::Application* xse::CreateApplication(int argc, char **argv);

int main(int argc, char* argv[]) {
    xse::Application* app = xse::CreateApplication(argc, argv);
    if (!app) return -1;

    app->Initialize();
    app->Terminate();
    delete app;
    return 0;
}