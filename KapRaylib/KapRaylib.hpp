/*
** EPITECH PROJECT, 2022
** KapRaylib
** File description:
** KapRaylib
*/

#ifndef KAPRAYLIB_HPP_
#define KAPRAYLIB_HPP_

#ifndef KAPRAYLIB_VERSION_HPP_
    #include "KapRaylibVersion.hpp"
#endif


namespace KapEngine {
    namespace Graphical {
        namespace Raylib {
            class RaylibGraphical;
            class RaylibEncapsulation;

            namespace Draw {
                #if KAPRAYLIB_2D_ACTIVE
                    class DrawUI;
                #endif
                #if KAPRAYLIB_3D_ACTIVE
                    #if KAPRAYLIB_BETA
                        class Draw3D;
                    #endif
                #endif
            }

            namespace Cache {
                class RaylibCache;
                #if KAPRAYLIB_2D_ACTIVE
                    class ImageCache;
                    class FontCache;
                #endif
                #if KAPRAYLIB_SOUND_ACTIVE
                    class MusicCache;
                    class SoundCache;
                #endif
                #if KAPRAYLIB_3D_ACTIVE
                    #if KAPRAYLIB_BETA
                        class ModelCache;
                    #endif
                #endif
            }
        }
    }
}

#ifndef KAPRAYLIB_GRAPHICAL_HPP_
    #include "Graphical/RaylibGraphical.hpp"
#endif

#ifndef KAPRAYLIB_ENCAPSULATION_HPP_
    #include "Encapsulation/RaylibEncapsulation.hpp"
#endif

#ifndef KAPRAYLIB_DRAWUI_HPP_
    #include "DrawSystem/DrawUI.hpp"
#endif

#ifndef KAPRAYLIB_DRAW3D_HPP_
    #include "DrawSystem/Draw3D.hpp"
#endif

#ifndef KAPRAYLIB_CACHE_HPP_
    #include "Cache/RaylibCache.hpp"
#endif

#endif /* !KAPRAYLIB_HPP_ */
