#pragma once

enum class Scenes
{
    SPLASH_SCREEN,
    MENU,
    MAP,
    COMBAT,
    GAMEOVER,
    COUNT
};

struct SceneManager
{
    Scenes currentScene;
};