#pragma once

enum class Scenes
{
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