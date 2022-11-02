/*
** EPITECH PROJECT, 2022
** gameExample
** File description:
** Draw3D
*/

#include "Draw3D.hpp"
#include "KapRaylib/Encapsulation/RaylibEncapsulation.hpp"

void KapEngine::Graphical::Raylib::Draw::Draw3DModel::draw() {
    _encap.__drawModel(_model, _pos, _scale, _color);
}
