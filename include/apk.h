#pragma once
#include <string>
#include <vector>

struct ApkInfo {
    std::string filename;
    std::string path;
    std::string appName;
    std::string packageName;
    std::string versionName;
    std::vector<uint8_t> iconPng;
    uint64_t    fileSizeBytes = 0;
    bool        installed     = false;  // true if already extracted to games dir
};

ApkInfo              parseApk       (const std::string& path);
std::vector<ApkInfo> scanApks       (const std::string& dir);

// Returns true if <pkg_name> has an .installed marker in the games directory.
bool                 apkIsInstalled (const std::string& pkg_name);
