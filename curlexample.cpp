#include "Settings.h"
#include <vector>

int main()
{
    int x = 0;
    while(true)
    {
        auto portcount = std::to_string(x);
        SetConsoleTitle(L"Growtopia Port Detecter");
#pragma region downloader
        HTTPDownloader downloader;
        std::string content = downloader.download("http://growtopia2.com/growtopia/server_data.php");
#pragma endregion
#pragma region  replace
        replace(content, "server|213.179.209.168", "");
        replace(content, "port|", "");
        replace(content, "type|1", "");
        replace(content, "#maint|Server is under maintenance. We will be back online shortly. Thank you for your patience!", "");
        replace(content, "beta_server|beta.growtopiagame.com", "");
        replace(content, "beta_port|27003", "");
        replace(content, "beta_type|1", "");
        replace(content, "meta|undefined", "");
        replace(content, "RTENDMARKERBS1001", "");
#pragma endregion
#pragma region MyRegion

#pragma endregion
        
        size_t i = 0;
        for (; i < content.length(); i++) { if (isdigit(content[i])) break; }
        content = content.substr(i, content.length() - i);
        int id = atoi(content.c_str());
        auto resux = std::to_string(id);
        string result = "Port: " + resux;
        std::cout << result << endl;
        x++;
    }
    return 0;
}