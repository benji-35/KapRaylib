/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** RaylibEncapsulation
*/

#include "RaylibEncapsulation.hpp"
#include "Errors.hpp"
#include "KapEngineDebug.hpp"
#include <iostream>

void KapEngine::Graphical::Raylib::RaylibEncapsulation::clearCache() {
    for (std::size_t i = 0; i < _cache.size(); i++) {
        _cache[i]->clear();
    }
    _cache.clear();
    std::cout << "Cache cleared !" << std::endl;
}

#if KAPRAYLIB_2D_ACTIVE

    void KapEngine::Graphical::Raylib::RaylibEncapsulation::unloadFont(std::string const& path) {
        for (std::size_t i = 0; i < _cache.size(); i++) {
            if (_cache[i]->getName() == "Font") {
                auto _fcache = (Cache::FontCache *)_cache[i].get();
                if (_fcache->getpath() == path) {
                    _cache[i]->clear();
                    _cache.erase(_cache.begin() + i);
                    return;
                }
            }
        }
    }

    void KapEngine::Graphical::Raylib::RaylibEncapsulation::unloadAllFonts() {
        for (std::size_t i = 0; i < _cache.size(); i++) {
            if (_cache[i]->getName() == "Font") {
                _cache[i]->clear();
                _cache.erase(_cache.begin() + i);
                i--;
            }
        }
    }

    void KapEngine::Graphical::Raylib::RaylibEncapsulation::loadFont(std::string const& path) {
        for (std::size_t i = 0; i < _cache.size(); i++) {
            if (_cache[i]->getName() == "Font") {
                auto fcache = (Cache::FontCache *)_cache[i].get();
                if (fcache->getpath() == path) {
                    //font already exists
                    return;
                }
            }
        }
        //create new font
        auto nFont = std::make_shared<Cache::FontCache>(*this, path);
        _cache.push_back(nFont);
    }

    Font &KapEngine::Graphical::Raylib::RaylibEncapsulation::getFont(std::string const& path, bool alreadyTry) {
        for (std::size_t i = 0; i < _cache.size(); i++) {
            if (_cache[i]->getName() == "Font") {
                auto &fcache = (Cache::FontCache &)*_cache[i];
                if (fcache.getpath() == path) {
                    //font found
                    return fcache.getFont();
                }
            }
        }
        //font does not found
        if (alreadyTry) {
            throw Errors::GraphicalSystemError("No font found: " + path);
        } else {
            loadFont(path);
            return getFont(path, true);
        }
    }

    void KapEngine::Graphical::Raylib::RaylibEncapsulation::__drawTexture(std::string const& imagePath, float posX, float posY, float width, float heigth, Rectangle rect, float rot, Color col) {
        try {
            Image &img = getImage(imagePath);
            Texture2D texture = __getTextureFromImage(img);
            _cacheTexture.push_back(texture);
            SetTextureFilter(texture, TEXTURE_FILTER_POINT);
            DrawTexturePro(texture, rect, {posX, posY, width, heigth}, {0, 0}, rot, col);
        } catch(std::exception e) {
            DEBUG_ERROR(e.what());
            return;
        }
    }

    void KapEngine::Graphical::Raylib::RaylibEncapsulation::loadImage(std::string const& imagePath) {
        for (std::size_t i = 0; i < _cache.size(); i++) {
            if (_cache[i]->getName() == "Image") {
                auto img = (Cache::ImageCache *)_cache[i].get();
                if (img->getPath() == imagePath)
                    return;
            }
        }
        auto nImg = std::make_shared<Cache::ImageCache>(*this);
        nImg->init(imagePath);
        _cache.push_back(nImg);
    }

    Image &KapEngine::Graphical::Raylib::RaylibEncapsulation::getImage(std::string const& imagePath, bool alreadyTry) {
        for (std::size_t i = 0; i < _cache.size(); i++) {
            if (_cache[i]->getName() == "Image") {
                auto img = (Cache::ImageCache *)_cache[i].get();
                if (img->getPath() == imagePath)
                    return img->getImage();
            }
        }

        if (alreadyTry) {
            DEBUG_ERROR("[RAYLIB] : no image found: " + imagePath);
            throw Errors::GraphicalSystemError("No image found: " + imagePath);
        }
        loadImage(imagePath);
        return getImage(imagePath, true);
    }

    void KapEngine::Graphical::Raylib::RaylibEncapsulation::drawRectangle(float posX, float posY, float width, float heigth, Color color)
    {
        auto sprite = std::make_shared<Draw::DrawSpriteColor>(*this, posX, posY, width, heigth, color);
        _drawUi.push_back(sprite);
    }

    void KapEngine::Graphical::Raylib::RaylibEncapsulation::drawText(std::string const &fontPath, std::string const &text, Vector2 pos, float fontSize, float spacing, Color col)
    {
        auto txt = std::make_shared<Draw::DrawText>(*this);
        txt->setColor(col);
        txt->setPos(pos);
        txt->setSize(fontSize);
        txt->setSpacing(spacing);
        txt->setText(text);
        if (fontPath != "")
        {
            try
            {
                txt->setFont(getFont(fontPath));
            }
            catch (...)
            {
            }
        }
        _drawUi.push_back(txt);
    }

    void KapEngine::Graphical::Raylib::RaylibEncapsulation::drawTexture(std::string const &path, float posX, float posY, float width, float heigth, float rot, Rectangle rect,
                                    Color col)
    {
        auto texture = std::make_shared<Draw::DrawSpriteTexture>(*this);
        texture->setPathTexture(path);
        texture->setHeigth(heigth);
        texture->setWidth(width);
        texture->setPosX(posX);
        texture->setPosY(posY);
        texture->setColor(col);
        texture->setRectangle(rect);
        texture->setRot(rot);
        _drawUi.push_back(texture);
    }

#endif

#if KAPRAYLIB_SOUND_ACTIVE

    void KapEngine::Graphical::Raylib::RaylibEncapsulation::loadMusic(std::string const& path) {
        for (std::size_t i = 0; i < _cache.size(); i++) {
            if (_cache[i]->getName() == "Music") {
                auto &fcache = (Cache::MusicCache &)*_cache[i].get();
                if (fcache.getpath() == path) {
                    //music already exists
                    return;
                }
            }
        }
        //create new font
        auto nMusic = std::make_shared<Cache::MusicCache>(*this, path);
        _cache.push_back(nMusic);
    }

    void KapEngine::Graphical::Raylib::RaylibEncapsulation::loadSound(std::string const& path) {
        for (std::size_t i = 0; i < _cache.size(); i++) {
            if (_cache[i]->getName() == "Sound") {
                auto &fcache = (Cache::SoundCache &)*_cache[i].get();
                if (fcache.getpath() == path) {
                    //sound already exists
                    return;
                }
            }
        }
        //create new font
        auto nSound = std::make_shared<Cache::SoundCache>(*this, path);
        _cache.push_back(nSound);
    }

    void KapEngine::Graphical::Raylib::RaylibEncapsulation::playMusic(std::string const& music) {
        if (_musicPlaying != "") {
            if (_musicPlaying == music) {
                restartMusic();
                return;
            }
            //there is a music currently played
            stopMusic();
        }
        _musicPlaying = "";
        try {
            getMusic(music);
        } catch(...) {
            DEBUG_ERROR("Music " + music + " not found / error to load");
            return;
        }
        _musicPlaying = music;
        startMusic();
    }

    void KapEngine::Graphical::Raylib::RaylibEncapsulation::playSound(std::string const& sound, float volume) {
        try {
            auto &s = getSound(sound);
            SetSoundVolume(s, volume);
            PlaySoundMulti(s);
        } catch(...) {
            DEBUG_ERROR("Failed to play sound");
        }
    }

    Sound &KapEngine::Graphical::Raylib::RaylibEncapsulation::getSound(std::string const& imagePath, bool alreadyTry) {
        for (std::size_t i = 0; i < _cache.size(); i++) {
            if (_cache[i]->getName() == "Sound") {
                auto img = (Cache::SoundCache *)_cache[i].get();
                if (img->getpath() == imagePath)
                    return img->getSound();
            }
        }

        if (alreadyTry) {
            DEBUG_ERROR("[RAYLIB] : no sound found: " + imagePath);
            throw Errors::GraphicalSystemError("No sound found: " + imagePath);
        }
        loadSound(imagePath);
        return getSound(imagePath, true);
    }

    Music &KapEngine::Graphical::Raylib::RaylibEncapsulation::getMusic(std::string const& imagePath, bool alreadyTry) {
        for (std::size_t i = 0; i < _cache.size(); i++) {
            if (_cache[i]->getName() == "Music") {
                auto img = (Cache::MusicCache *)_cache[i].get();
                if (img->getpath() == imagePath)
                    return img->getMusic();
            }
        }

        if (alreadyTry) {
            DEBUG_ERROR("[RAYLIB] : no music found: " + imagePath);
            throw Errors::GraphicalSystemError("No music found: " + imagePath);
        }
        loadMusic(imagePath);
        return getMusic(imagePath, true);
    }

#endif

void KapEngine::Graphical::Raylib::RaylibEncapsulation::stopDrawing() {
    if (_firstRun)
    {
        _firstRun = false;
        return;
    }
    if (!opened)
        return;
    canDraw = false;
    if (camSet)
    {
        #if KAPRAYLIB_3D_ACTIVE
            #if KAPRAYLIB_BETA
            BeginMode3D(_camera);
            // draw 3D elements
            EndMode3D();
            #endif
        #endif
        #if KAPRAYLIB_2D_ACTIVE
            for (std::size_t i = 0; i < _drawUi.size(); i++)
            {
                _drawUi[i]->draw();
                _drawUi[i]->clear();
            }
            _drawUi.clear();
        #endif
    }
    if (_drawFps)
    {
        drawFps();
    }
    EndDrawing();
    #if KAPRAYLIB_2D_ACTIVE
        for (std::size_t i = 0; i < _cacheTexture.size(); i++)
        {
            __unloadTexture(_cacheTexture[i]);
        }
        _cacheTexture.clear();
    #endif
}
