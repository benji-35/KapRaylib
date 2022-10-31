/*
** EPITECH PROJECT, 2022
** KapRaylib
** File description:
** Draw3D
*/

#ifndef KAPRAYLIB_DRAW3D_HPP_
#define KAPRAYLIB_DRAW3D_HPP_

#include "raylib.h"
#include "KapRaylibVersion.hpp"
#include <string>

#if KAPRAYLIB_3D_ACTIVE
    #if KAPRAYLIB_BETA

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
namespace KapEngine {

    namespace Graphical {

        namespace Raylib {

            namespace Draw {

                class IDraw3D {
                    public:
                        virtual ~DrawUI() {}

                        virtual void draw() = 0;
                        virtual void clear() = 0;

                    protected:
                    private:
                };

                class Draw3D : public IDraw3D {
                    public:
                        Draw3D(RaylibEncapsulation &encapsulation) : _encap(encapsulation) {}
                        ~Draw3D() {}

                        virtual void draw() override {}
                        virtual void clear() override {}

                    protected:
                        RaylibEncapsulation &_encap;
                };

                class DrawModel : public Draw3D {
                    public:
                        DrawModel(RaylibEncapsulation &encapsulation, std::string const& pathModel) : Draw3D(encapsulation) {
                            _pathModel = pathModel;
                        }
                        ~DrawModel() {}

                        void setScale(Vector3 scale) {
                            _scale = scale;
                        }

                        void setPos(Vector3 pos) {
                            _pos = pos;
                        }

                        void setRotation(Vector3 rotation) {
                            _rotation = rotation;
                        }

                        virtual void draw() override {
                            _encap.__drawModel(_encap.getModel(_pathModel), _pos, _scale, _rotation);
                        }

                    protected:
                    private:
                        std::string _pathModel;
                        Vector3 _scale;
                        Vector3 _pos;
                        Vector3 _rotation;
                };

            }
        }
    }
}

    #endif
#endif

#endif /* !KAPRAYLIB_DRAW3D_HPP_ */
