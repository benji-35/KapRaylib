/*
** EPITECH PROJECT, 2022
** gameExample
** File description:
** Draw3D
*/

#include "Draw3D.hpp"
#include "KapRaylib/Encapsulation/RaylibEncapsulation.hpp"

#if KAPRAYLIB_3D_ACTIVE
    #if KAPRAYLIB_BETA

        void KapEngine::Graphical::Raylib::Draw::Draw3DModel::draw() {
            _encap.__drawModel(_encap.getModel(_pathModel), _pos, _scale, WHITE);
        }

    #endif
#endif
