/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** RaylibCache
*/

#include "RaylibCache.hpp"
#include "KapRaylib/Encapsulation/RaylibEncapsulation.hpp"
#include <iostream>
#include "KapEngineDebug.hpp"

#if KAPRAYLIB_2D_ACTIVE

    void KapEngine::Graphical::Raylib::Cache::ImageCache::init(std::string const& imagePath) {
        pathImage = imagePath;
        if (pathImage != "") {
            img = encap.__loadImage(pathImage);
            #if KAPENGINE_DEBUG_ACTIVE
                DEBUG_LOG("[RAYLIB CACHE] Load new image");
            #endif
        }
    }

    void KapEngine::Graphical::Raylib::Cache::ImageCache::clear() {
        if (pathImage == "")
            return;
        encap.__unloadImage(img);
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_LOG("[RAYLIB CACHE] Clear image : " + pathImage);
        #endif
        pathImage = "";
    }

    KapEngine::Graphical::Raylib::Cache::FontCache::FontCache(RaylibEncapsulation &e, std::string const& path) : RaylibCache(e), _path(path) {
        if (_path != "") {
            _font = encap.__loadFont(_path);
            #if KAPENGINE_DEBUG_ACTIVE
                DEBUG_LOG("[RAYLIB CACHE] Load new font");
            #endif
        }
    }

    void KapEngine::Graphical::Raylib::Cache::FontCache::clear() {
        if (_path == "")
            return;
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_LOG("[RAYLIB CACHE] Clear font : " + _path);
        #endif
        _path = "";
        encap.__unloadFont(_font);
    }

#endif

#if KAPRAYLIB_SOUND_ACTIVE

    KapEngine::Graphical::Raylib::Cache::MusicCache::MusicCache(RaylibEncapsulation &e, std::string const& path) : RaylibCache(e), _path(path) {
        if (_path != "") {
            _music = encap.__loadMusic(_path);
            #if KAPENGINE_DEBUG_ACTIVE
                DEBUG_LOG("[RAYLIB CACHE] Load new music");
            #endif
        }
    }

    void KapEngine::Graphical::Raylib::Cache::MusicCache::clear() {
        if (_path == "")
            return;
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_LOG("[RAYLIB CACHE] Clear music : " + _path);
        #endif
        _path = "";
        encap.__unloadMusic(_music);
    }

    KapEngine::Graphical::Raylib::Cache::SoundCache::SoundCache(RaylibEncapsulation &e, std::string const& path) : RaylibCache(e), _path(path) {
        if (_path != "") {
            _sound = encap.__loadSound(_path);
            #if KAPENGINE_DEBUG_ACTIVE
                DEBUG_LOG("[RAYLIB CACHE] Load new sound");
            #endif
        }
    }

    void KapEngine::Graphical::Raylib::Cache::SoundCache::clear() {
        if (_path == "")
            return;
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_LOG("[RAYLIB CACHE] Clear sound : " + _path);
        #endif
        _path = "";
        encap.__unloadSound(_sound);
    }

#endif

#if KAPRAYLIB_3D_ACTIVE

    #if KAPRAYLIB_BETA

        KapEngine::Graphical::Raylib::Cache::ModelCache::ModelCache(RaylibEncapsulation &e, std::string const& path) : RaylibCache(e), _path(path) {
            if (_path != "") {
                _model = encap.__loadModel(_path);
                #if KAPENGINE_DEBUG_ACTIVE
                    DEBUG_LOG("[RAYLIB CACHE] Load new model");
                #endif
            }
        }

        void KapEngine::Graphical::Raylib::Cache::ModelCache::clear() {
            if (_path == "")
                return;
            #if KAPENGINE_DEBUG_ACTIVE
                DEBUG_LOG("[RAYLIB CACHE] Clear model : " + _path);
            #endif
            _path = "";
            encap.__unloadModel(_model);
        }

    #endif

#endif
