/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** RaylibCache
*/

#ifndef KAPRAYLIB_CACHE_HPP_
#define KAPRAYLIB_CACHE_HPP_

#include "raylib.h"
#include <string>

namespace KapEngine
{
    namespace Graphical
    {

        namespace Raylib
        {

            class RaylibEncapsulation;

        }
    } // namespace Graphical
} // namespace KapEngine

namespace KapEngine
{
    namespace Graphical
    {

        namespace Raylib
        {

            namespace Cache
            {

                class IRaylibCache
                {
                  public:
                    virtual ~IRaylibCache() {}

                    virtual void clear() = 0;

                  protected:
                  private:
                };

                class RaylibCache : public IRaylibCache
                {
                  public:
                    RaylibCache(RaylibEncapsulation &e) : encap(e) {}
                    ~RaylibCache() {}

                    virtual void clear() {}
                    virtual std::string getName() const { return ""; }

                  protected:
                    RaylibEncapsulation &encap;
                };

                #if KAPRAYLIB_2D_ACTIVE
                    class ImageCache : public RaylibCache
                    {
                      public:
                        ImageCache(RaylibEncapsulation &e) : RaylibCache(e) {}
                        ~ImageCache() {}

                        bool operator==(ImageCache const &c) { return (pathImage == c.pathImage); }

                        std::string getName() const override { return "Image"; }

                        void init(std::string const &imagePath);

                        Image &getImage() { return img; }

                        void clear() override;

                        std::string getPath() const { return pathImage; }

                      private:
                        std::string pathImage;
                        Image img;
                    };

                    class FontCache : public RaylibCache
                    {
                      public:
                        FontCache(RaylibEncapsulation &e, std::string const &path);
                        ~FontCache() {}

                        bool operator==(FontCache const &font) { return (_path == font._path); }

                        std::string getName() const override { return "Font"; }

                        std::string getpath() const { return _path; }

                        Font &getFont() { return _font; }

                        void clear() override;

                      private:
                        std::string _path;
                        Font _font;
                    };

                #endif

                #if KAPRAYLIB_SOUND_ACTIVE
                    class MusicCache : public RaylibCache
                    {
                      public:
                        MusicCache(RaylibEncapsulation &e, std::string const &path);
                        ~MusicCache() {}

                        bool operator==(MusicCache const &mc) { return _path == mc.getpath(); }

                        std::string getName() const override { return "Music"; }

                        std::string getpath() const { return _path; }

                        Music &getMusic() { return _music; }

                        void clear() override;

                      private:
                        std::string _path;
                        Music _music;
                    };

                    class SoundCache : public RaylibCache
                    {
                      public:
                        SoundCache(RaylibEncapsulation &e, std::string const &path);
                        ~SoundCache() {}

                        bool operator==(MusicCache const &mc) { return _path == mc.getpath(); }

                        std::string getName() const override { return "Sound"; }

                        std::string getpath() const { return _path; }

                        Sound &getSound() { return _sound; }

                        void clear() override;

                      private:
                        std::string _path;
                        Sound _sound;
                    };
                #endif

                #if KAPRAYLIB_3D_ACTIVE

                    #if KAPRAYLIB_BETA
                        class ModelCache : public RaylibCache
                        {
                            public:
                                ModelCache(RaylibEncapsulation &e, std::string const &path);
                                ~ModelCache() {}

                                bool operator==(ModelCache const &mc) { return _path == mc.getpath(); }

                                std::string getName() const override { return "Model"; }

                                std::string getpath() const { return _path; }

                                Model &getModel() { return _model; }

                                void clear() override;

                                private:
                                    std::string _path;
                                    Model _model;
                        };

                    #endif
                #endif
            } // namespace Cache

        } // namespace Raylib

    } // namespace Graphical
} // namespace KapEngine

#endif /* !KAPRAYLIB_CACHE_HPP_ */
