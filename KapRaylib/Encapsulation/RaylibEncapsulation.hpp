/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** RaylibEncapsulation
*/

#ifndef KAPRAYLIB_ENCAPSULATION_HPP_
#define KAPRAYLIB_ENCAPSULATION_HPP_

#include <string>
#include <memory>
#include <vector>
#include <map>
#include <iostream>

#include "KapRaylib/KapRaylibVersion.hpp"
#include "KapRaylib/Graphical/RaylibGraphical.hpp"
#include "KapRaylib/Cache/RaylibCache.hpp"
#include "KapRaylib/DrawSystem/Draw3D.hpp"
#include "KapRaylib/DrawSystem/DrawUI.hpp"

#include "KapEngine.hpp"

#include "raylib.h"

namespace KapEngine
{

    namespace Graphical
    {

        namespace Raylib
        {

            class RaylibEncapsulation
            {
              public:
                RaylibEncapsulation(int const &windowWidth, int const &windowHeight, std::string const &title, int const &fps)
                {
                    _widthWindow = windowWidth;
                    _heightWindow = windowHeight;
                    _title = title;
                    _fps = fps;
                    setVisibleFps(true);
                    SetTraceLogLevel(LOG_NONE);
                }
                ~RaylibEncapsulation() { closeWindow(); }

                void openWindow()
                {
                    if (opened)
                        return;
                    InitWindow(_widthWindow, _heightWindow, _title.c_str());
                    setWindowsResizable(true);
                    SetTargetFPS(_fps);
                    InitAudioDevice();
                    SetExitKey(-1);
                    initCam();
                    opened = true;
                }

                Vector2 getScreenSize()
                {
                    Vector2 result;

                    result.x = GetScreenWidth();
                    result.y = GetScreenHeight();

                    return result;
                }

                void closeWindow()
                {
                    if (!opened)
                        return;
                    // stopAllMsuics();
                    CloseWindow();
                    CloseAudioDevice();
                    stopCam();
                    clearCache();
                    opened = false;
                    #if KAPENGINE_DEBUG_ACTIVE
                        DEBUG_WARNING("[KAP RAYLIB] Clearing RAYLIB ! " + _path);
                    #endif
                }

                bool windownShouldClose() { return WindowShouldClose(); }

                void startDrawing()
                {
                    if (!opened)
                        return;
                    BeginDrawing();
                    clearWindow();
                    if (!camSet)
                    {
                        drawNoCamText();
                        stopDrawing();
                        canDraw = false;
                        return;
                    }
                    // update music
                    canDraw = true;
                }

                void stopDrawing();

                void setVisibleFps(bool b) { _drawFps = b; }

                void setIcon(std::string const &iconPath)
                {
                    try
                    {
                        SetWindowIcon(getImage(iconPath));
                    }
                    catch (...)
                    {
                        DEBUG_ERROR("Failed to load windows icon");
                    }
                }

                void clearWindow()
                {
                    if (!opened)
                        return;
                    ClearBackground(_background);
                }

                void setBackgroundColor(Color background) { _background = background; }

                void initCam()
                {
                    if (camSet)
                        return;
                    _camera.position = {20.0f, 20.0f, 20.0f};
                    _camera.target = {0.0f, 8.0f, 0.0f};
                    _camera.up = {0.0f, 1.6f, 0.0f};
                    _camera.fovy = 45.0f;
                    _camera.projection = CAMERA_PERSPECTIVE;
                    camSet = true;
                }

                void stopCam()
                {
                    if (!camSet)
                        return;
                    camSet = false;
                }

                void updateCam(Vector3 pos, Vector3 target, Vector3 up, float fov)
                {
                    _camera.position = pos;
                    _camera.target = target;
                    _camera.up = up;
                    _camera.fovy = fov;
                }

                void updateCamProjection(int proj) { _camera.projection = proj; }

                void clearCache();

                void drawFps() { DrawFPS(10, 10); }

                void setWindowsResizable(bool b)
                {
                    if (b)
                    {
                        SetWindowState(FLAG_WINDOW_RESIZABLE);
                    }
                }

                Vector2 getMousePosition() const { return GetMousePosition(); }

                #if KAPRAYLIB_2D_ACTIVE

                    void unloadFont(std::string const &fontPath);

                    void unloadAllFonts();

                    void __unloadFont(Font const &font) { UnloadFont(font); }

                    void __unloadImage(Image const &img) { UnloadImage(img); }

                    void __unloadTexture(Texture2D const &texture) { UnloadTexture(texture); }

                    void loadFont(std::string const &fontPath);
                    void loadImage(std::string const &imagePath);

                    Font &getFont(std::string const &fontPath, bool alreadyTry = false);
                    Image &getImage(std::string const &imagePath, bool alreadyTry = false);

                    Image __loadImage(std::string const &imagePath) { return LoadImage(imagePath.c_str()); }
                    Font __loadFont(std::string const &fontPath) { return LoadFont(fontPath.c_str()); }
                    Texture2D __getTextureFromImage(Image const &img) { return LoadTextureFromImage(img); }

                    /**
                     * @brief Draw part
                     *
                     */

                    void drawRectangle(float posX, float posY, float width, float heigth, Color color);

                    void __drawRectangle(float posX, float posY, float width, float hiegth, Color color)
                    {
                        DrawRectangle(posX, posY, width, hiegth, color);
                    }

                    void drawText(std::string const &fontPath, std::string const &text, Vector2 pos, float fontSize, float spacing, Color col);

                    void __drawText(Font font, std::string const &text, Vector2 pos, float fontSize, float spacing, Color col)
                    {
                        DrawTextEx(font, text.c_str(), pos, fontSize, spacing, col);
                    }

                    void __drawText(std::string const &text, Vector2 pos, float fontSize, float spacing, Color col)
                    {
                        DrawText(text.c_str(), pos.x, pos.y, fontSize, col);
                    }

                    void drawTexture(std::string const &path, float posX, float posY, float width, float heigth, float rot, Rectangle rect,
                                    Color col);

                    void __drawTexture(std::string const &imagePath, float posX, float posY, float width, float heigth, Rectangle rect,
                                    float rot, Color col);

                #endif

                #if KAPRAYLIB_SOUND_ACTIVE
                    void playMusic(std::string const &music);
                    void playSound(std::string const &sound, float volume = 1.f);

                    void updateMusic()
                    {
                        if (_musicPlaying == "")
                            return;
                        UpdateMusicStream(getMusic(_musicPlaying));
                    }
                    void setMusicVolume(float f)
                    {
                        if (_musicPlaying == "")
                            return;
                        SetMusicVolume(getMusic(_musicPlaying), f);
                    }
                    void stopMusic()
                    {
                        if (_musicPlaying == "")
                            return;
                        StopMusicStream(getMusic(_musicPlaying));
                    }
                    void pauseMusic()
                    {
                        if (_musicPlaying == "")
                            return;
                        PauseMusicStream(getMusic(_musicPlaying));
                    }
                    void resumeMusic()
                    {
                        if (_musicPlaying == "")
                            return;
                        ResumeMusicStream(getMusic(_musicPlaying));
                    }
                    void restartMusic()
                    {
                        stopMusic();
                        startMusic();
                    }

                    void startMusic()
                    {
                        if (_musicPlaying == "")
                            return;
                        PlayMusicStream(getMusic(_musicPlaying));
                    }


                    void __unloadMusic(Music const &music) { UnloadMusicStream(music); }

                    void __unloadSound(Sound const &sound) { UnloadSound(sound); }

                    void loadMusic(std::string const &musicPath);
                    void loadSound(std::string const &soundPath);
                    Music &getMusic(std::string const &musicPath, bool alreadyTry = false);
                    Sound &getSound(std::string const &musicPath, bool alreadyTry = false);

                    Music __loadMusic(std::string const &music) { return LoadMusicStream(music.c_str()); }
                    Sound __loadSound(std::string const &sound) { return LoadSound(sound.c_str()); }

                #endif

                #if KAPRAYLIB_3D_ACTIVE
                    #if KAPRAYLIB_BETA

                        void __unloadModel(Model const &model) { UnloadModel(model); }

                        Model &getModel(std::string const &modelPath, bool alreadyTry = false);

                        Model __loadModel(std::string const &model) { return LoadModel(model.c_str()); }

                        void drawModel(std::string const &modelPath, Vector3 pos, float scale, Color col)
                        {
                            auto model = std::make_shared<Draw::Draw3DModel>(*this, modelPath);
                            model->setPos(pos);
                            model->setScale({scale, 0.f, 0.f});

                            _drawModel.push_back(model);
                        }

                    #endif
                #endif

                /**
                 * @brief Input part
                 *
                 */

                bool isGamepadConnected(int gpId) { return IsGamepadAvailable(gpId); }

                int maxJoystickGamepad(int gpId)
                {
                    if (!isGamepadConnected(gpId))
                        return 0;
                    return GetGamepadAxisCount(gpId);
                }

                float getGamepadJoystickValue(int gpId, int joystickId)
                {
                    if (!isGamepadConnected(gpId))
                        return 0.0f;
                    if (maxJoystickGamepad(gpId) <= joystickId)
                        return 0.0f;
                    return GetGamepadAxisMovement(gpId, joystickId);
                }

                int getKeyPressed() { return GetKeyPressed(); }

                bool isKeyReleased(int key) { return IsKeyReleased(key); }

                bool isMouseButtonReleased(int btn) { return IsMouseButtonReleased(btn); }

                bool isMouseButtonPressed(int btn) { return IsMouseButtonPressed(btn); }

                bool isGamepadButtonReleased(int gpId, int btn) { return IsGamepadButtonReleased(gpId, btn); }

                bool isGamepadButtonPressed(int gpId, int btn) { return IsGamepadButtonPressed(gpId, btn); }

              protected:
                void drawNoCamText() { DrawText("No camera found !", _widthWindow / 2 - 65.f, _heightWindow / 2 - 20.f, 15.0f, WHITE); }

              private:
                // cam
                Camera3D _camera;
                bool camSet = false;
                bool opened = false;
                Color _background;

                // windown settings
                int _widthWindow;
                int _heightWindow;
                std::string _title;
                int _fps;

                // draw settings
                bool canDraw = false;
                bool _drawFps = false;
                bool _debug = false;
                bool _firstRun = true;

                // cache
                #if KAPRAYLIB_SOUND_ACTIVE
                    std::string _musicPlaying = "";
                #endif
    
                std::vector<std::shared_ptr<Cache::RaylibCache>> _cache;

                #if KAPRAYLIB_2D_ACTIVE
                    std::vector<Texture2D> _cacheTexture;
    
                    std::vector<std::shared_ptr<Draw::RaylibDrawing>> _drawUi;
                #endif

                #if KAPRAYLIB_3D_ACTIVE
                    #if KAPRAYLIB_BETA

                    std::vector<std::shared_ptr<Draw::Draw3D>> _drawModel;

                    #endif
                #endif
            };

        } // namespace Raylib

    } // namespace Graphical

} // namespace KapEngine

#endif /* !KAPRAYLIB_ENCAPSULATION_HPP_ */
