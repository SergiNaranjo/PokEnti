#pragma once

enum class Scenes
{
    SPLASH_SCREEN,
    MENU,
    MAP,
    COUNT
};

struct SceneManager
{
    Scenes currentScene;
};