#pragma once
#include <cstdint>
#include <vector>

// Background HTTPS fetcher for the user's live GitHub avatar (About screen).
// Starts a worker thread that fetches once immediately (or loads the SD
// cache if offline) and then re-fetches every few minutes for as long as
// the app runs, so the picture shown in-app stays in sync with reality
// without ever blocking the UI thread.
void avatarStart();
void avatarStop();

// Call once per frame while the About screen is visible. Returns true and
// fills `out` with PNG/JPEG bytes (ready for IMG_Load_RW) the first time a
// new image becomes available; false otherwise (nothing changed yet).
bool avatarPollNewImage(std::vector<uint8_t>& out);
